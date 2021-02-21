//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)

#include "ConectaOPC.h"
#include <map>

#define TAM_CHAVE 1024

ConectaOPC::ConectaOPC(){
        status = false;
        connected = false;
        ipOPCServerList = NULL;
        pServerInfo = NULL;
        pServerInfo2 = NULL;
        ipEnumGuid = NULL;
        ptr_temp = NULL;
}

ConectaOPC::~ConectaOPC(){
}

bool ConectaOPC::getProgId(CLSID clsid, LPOLESTR *progid){
        HRESULT hr;
        hr = ProgIDFromCLSID(clsid, progid);

        if (hr == S_OK){
                return true;
        }else{
                logger.addLinhaLog("Falha ao executar o ProgIDFromCLSID: "+logger.getError(hr));
        }
        return false;
}

bool ConectaOPC::getCLSID(string ProgID, CLSID *clsid){

        HRESULT hr;
        hr = CLSIDFromProgID(WideString(ProgID.c_str()),clsid);

        if (hr == S_OK){
                return true;
        }else{
                logger.addLinhaLog("Falha ao executar o CLSIDFromProgID: "+logger.getError(hr));
        }

        return false;
}

CLSID ConectaOPC::getCLSID(string progID){

        map<string, CLSID>::iterator iFind = mapClsidRemoto.find(progID);
        CLSID retorno;
        if (iFind != mapClsidRemoto.end()){
                retorno = iFind->second;
        }else{
            logger.addLinhaLog("Falha ao executar o getCLSID");
        }

        return retorno;
}

void ConectaOPC::clearMapa(map<string,CLSID> mapa){

        if(!mapa.empty()){
                mapa.clear();
        }
}

bool ConectaOPC::listaOpc(bool local, string *listarm, string hostname){

        if (local){
                hostname = "localhost";
        }

        clearMapa(mapClsidRemoto);

        WCHAR* hostName;

        ipOPCServerList = NULL;
        hostName = WideString(hostname.c_str());
        WCHAR* serverName;



        if (!getStatusCom()){

                HRESULT hr;

                hr = startCom();

                if (FAILED(hr)){
                        logger.addLinhaLog("Falha ao executar o startCom(): "+logger.getError(hr));
                }

        }


        CLSID clsid;
        CLSID clsidRmt;
        pServerInfo = NULL;

        ipEnumGuid = NULL;

        CATID catid = IID_OPCEventServerCATID;
        GUID resultGuid;
        ULONG fetched = 0;

        HRESULT hr;
        if (hostName != NULL && wcslen(hostName) > 0){

                pServerInfo = new COSERVERINFO();
                pServerInfo->dwReserved1 = 0;
                pServerInfo->pwszName = (LPWSTR)hostName;
                pServerInfo->pAuthInfo = NULL;
                pServerInfo->dwReserved2 = 0;
        }else {
                logger.addLinhaLog("ListaOpc --> FALHA - Host null ou vazio");
                exit(0); //return E_FAIL;
        }

        try{

                MULTI_QI multi_qi;
                memset(&multi_qi,0,sizeof(multi_qi));
                multi_qi.pIID = &IID_IOPCServerList;

                if (local){
                        hr = CoCreateInstanceEx(CLSID_OpcServerList, NULL, CLSCTX_LOCAL_SERVER, pServerInfo,1,&multi_qi);
                }else{
                        hr = CoCreateInstanceEx(CLSID_OpcServerList, NULL, CLSCTX_REMOTE_SERVER, pServerInfo,1,&multi_qi);
                }

                if (!SUCCEEDED(hr)){
                        logger.addLinhaLog("ListaOpc - CoCreateInstanceEx "+ hostname + "--> FALHA ao tentar criar instancia: "+logger.getError(hr));
                }

                if (SUCCEEDED(hr) || SUCCEEDED(multi_qi.hr)){

                        ipOPCServerList = (IOPCServerList*) multi_qi.pItf;
                        hr = ipOPCServerList->EnumClassesOfCategories(1,&catid,1,&catid,&ipEnumGuid);

                        if(hr == S_OK){

                                hr = ipEnumGuid->Reset();
                                hr = ipEnumGuid->Next(1,&resultGuid,&fetched);
                                int aux=0;

                                HRESULT hr3;

                                while (hr == S_OK && fetched > 0){

                                        WCHAR *progID,*userReadableName;

                                        hr3 = ipOPCServerList->GetClassDetails(resultGuid,&progID,&userReadableName);

                                        logger.getError(hr3);

                                        hr3 = ipOPCServerList->CLSIDFromProgID(progID, &clsidRmt);
                                        string progIdStr = WideCharToString(progID).c_str();
                                        map<string, CLSID>::iterator iter = mapClsidRemoto.find(progIdStr);
                                        if(iter == mapClsidRemoto.end()){
                                                mapClsidRemoto.insert(pair<string, CLSID>(progIdStr,clsidRmt));
                                        }
                                        
                                        map<string, CLSID>::iterator i2 = mapClsidRemoto.find(progIdStr);
                                        string x = i2->first;
                                        listarm[aux++] = i2->first;
                                        hr = ipEnumGuid->Next(1,&resultGuid,&fetched);
                                }

                        }else{
                                logger.addLinhaLog("ListaOpc - EnumClassesOfCategories --> FALHA: "+logger.getError(hr));
                                catid = IID_OPCEventServerCATID;
                                hr = ipOPCServerList->EnumClassesOfCategories(0,&catid,0,&catid,&ipEnumGuid);
                        }

                        unsigned long r = ipOPCServerList->Release();
                        ipOPCServerList = NULL;

                }else{
                        logger.addLinhaLog("ListaOpc - Host não encontrado "+ hostname + "--> FALHA: "+logger.getError(hr));
                        return false;
                }
                
        }catch(...){
        }

        delete pServerInfo;

        return true;
}


bool ConectaOPC::listaOpcByRergistro(bool local, string *listarm, string hostname){

        if (local){
                hostname = "localhost";
        }

        clearMapa(mapClsidRemoto);

        WCHAR* hostName;

        ipOPCServerList = NULL;
        hostName = WideString(hostname.c_str());
        WCHAR* serverName;


        if (!getStatusCom()){

                HRESULT hr;

                hr = startCom();

                if (FAILED(hr)){
                        logger.addLinhaLog("Falha ao executar o startCom(): "+logger.getError(hr));
                }

        }


        CLSID clsid;
        CLSID clsidRmt;

        //LPOLESTR progID,clsidName,userReadableName;
        ipEnumGuid = NULL;

        CATID catid = IID_OPCEventServerCATID;
        GUID resultGuid;
        ULONG fetched = 0;

        HRESULT hr;


	HKEY hk = HKEY_CLASSES_ROOT;
	char szKey[TAM_CHAVE];
        int aux =  0;

	for(int nIndex = 0; ::RegEnumKey(hk, nIndex, szKey, TAM_CHAVE) == ERROR_SUCCESS; nIndex++){

		HKEY hProgID;
		char szDummy[TAM_CHAVE];
		if(::RegOpenKey(hk, szKey, &hProgID) == ERROR_SUCCESS){

			LONG lSize = TAM_CHAVE;
			if(::RegQueryValue(hProgID, "OPC", szDummy, &lSize) == ERROR_SUCCESS){

                             string progIdStr = szKey;
                             getCLSID(progIdStr, &clsidRmt);

                             map<string, CLSID>::iterator iter = mapClsidRemoto.find(progIdStr);
                             if(iter == mapClsidRemoto.end()){
                                mapClsidRemoto.insert(pair<string, CLSID>(progIdStr,clsidRmt));
                             }

                             map<string, CLSID>::iterator i2 = mapClsidRemoto.find(progIdStr);
                             string x = i2->first;
                             listarm[aux++] = i2->first;


			}
			::RegCloseKey(hProgID);
		}
	}                


        return true;
}

bool ConectaOPC::connectAEServer(bool local, string hostName, CLSID clsid, OPCEventServer *ptrOPCEventServer){

        if (local){
                hostName = "localhost";
        }

        HRESULT hr1;

        pServerInfo2 = NULL;

        pServerInfo2 = new COSERVERINFO();
        pServerInfo2->dwReserved1 = 0;
        pServerInfo2->pwszName = (LPWSTR) WideString(hostName.c_str());
        pServerInfo2->pAuthInfo = NULL;
        pServerInfo2->dwReserved2 = 0;

        if (!getStatusCom()){

                HRESULT hr;

                hr = startCom();

                if (FAILED(hr)){
                        logger.addLinhaLog("listaOpc - startCom  --> FALHA "+logger.getError(hr));
                        delete pServerInfo2;
                        return hr;
                }
        }

        MULTI_QI multi_qi2;
        memset(&multi_qi2,0,sizeof(multi_qi2));
        multi_qi2.pIID = &IID_IOPCEventServer;

        if (local){

                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_LOCAL_SERVER, pServerInfo2 , 1, &multi_qi2 );

                if (hr1 != S_OK){

                        hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_INPROC_SERVER, pServerInfo2 , 1, &multi_qi2 );

                        if (hr1 != S_OK){

                                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_INPROC_HANDLER, pServerInfo2 , 1, &multi_qi2 );

                                if (hr1 != S_OK){

                                        hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_FROM_DEFAULT_CONTEXT, pServerInfo2 , 1, &multi_qi2 );

                                        if (hr1 != S_OK){

                                                hr1 = CoCreateInstanceEx (clsid, NULL, 0x40000, pServerInfo2 , 1, &multi_qi2 );

                                                 if (hr1 != S_OK){
                                                        logger.addLinhaLog("Falha ao executar o CoCreateInstanceEx(): "+logger.getError(hr1));
                                                        Form1->addMsgLog("Falha ao executar o CoCreateInstanceEx(): "+logger.getError(hr1));
                                                }
                                         }

                                }


                        }

                }

        }else{
                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_REMOTE_SERVER, pServerInfo2 , 1, &multi_qi2 );

                if (hr1 != S_OK){

                     hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_INPROC_SERVER, pServerInfo2 , 1, &multi_qi2 );

                        if (hr1 != S_OK){

                                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_INPROC_HANDLER, pServerInfo2 , 1, &multi_qi2 );

                                if (hr1 != S_OK){

                                        hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_FROM_DEFAULT_CONTEXT, pServerInfo2 , 1, &multi_qi2 );

                                        if (hr1 != S_OK){

                                                hr1 = CoCreateInstanceEx (clsid, NULL, 0x40000, pServerInfo2 , 1, &multi_qi2 );

                                                 if (hr1 != S_OK){
                                                        logger.addLinhaLog("Falha ao executar o CoCreateInstanceEx(): "+logger.getError(hr1));
                                                        Form1->addMsgLog("Falha ao executar o CoCreateInstanceEx(): "+logger.getError(hr1));
                                                }
                                         }

                                }
                        }
                        
                }

        }

        LPOLESTR prog;
        getProgId(clsid,&prog);
        string progID = WideCharToString(prog).c_str();

        if (!FAILED(hr1)){
                ptr_temp = (IOPCEventServer*) multi_qi2.pItf;
                ptrOPCEventServer->setPtrEventServer(ptr_temp);
                connected = true;
                logger.addLinhaLog("connectAEServer - CoCreateInstanceEx "+ hostName + " ProgID "+ progID +" --> S_OK");


        }else{
                logger.addLinhaLog("connectAEServer - CoCreateInstanceEx "+ hostName + " ProgID "+ progID +" --> FALHA: "+logger.getError(hr1));
        }

        delete pServerInfo2;

        if (hr1 == S_OK){
                return true;
        }

        return false;
}



bool ConectaOPC::testeConnection(bool local, string hostName, CLSID clsid){

        if (local){
                hostName = "localhost";
        }

        HRESULT hr1;

        pServerInfo2 = NULL;

        pServerInfo2 = new COSERVERINFO();
        pServerInfo2->dwReserved1 = 0;
        pServerInfo2->pwszName = (LPWSTR) WideString(hostName.c_str());
        pServerInfo2->pAuthInfo = NULL;
        pServerInfo2->dwReserved2 = 0;

        if (!getStatusCom()){

                HRESULT hr;

                hr = startCom();

                if (FAILED(hr)){
                        logger.addLinhaLog("startCom falhou: "+logger.getError(hr));
                        delete pServerInfo2;
                        return hr;
                }
        }

        MULTI_QI multi_qi2;
        memset(&multi_qi2,0,sizeof(multi_qi2));
        multi_qi2.pIID = &IID_IOPCEventServer;

        if (local){
                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_LOCAL_SERVER, pServerInfo2 , 1, &multi_qi2 );
        }else{
                hr1 = CoCreateInstanceEx (clsid, NULL, CLSCTX_REMOTE_SERVER, pServerInfo2 , 1, &multi_qi2 );
        }


        delete pServerInfo2;

        IOPCEventServer *ptr_temp1;

        if (!FAILED(hr1)){
                ptr_temp1 = (IOPCEventServer*) multi_qi2.pItf;
                ptr_temp1->Release();
                return true;
        }else{
                logger.addLinhaLog("CoCreateInstanceEx falhou no método testeConnection "+logger.getError(hr1));
                return false;
        }

        return false;
}



bool ConectaOPC::startCom(){

        HRESULT tmp;
        tmp = CoInitialize(NULL);
        //tmp = CoInitializeEx(NULL, COINIT_MULTITHREADED);
        (tmp==S_OK?status=true:status=false);

        if (tmp == S_OK){
                return true;
        }else{
                logger.addLinhaLog("CoInitializeEx falhou no método startCom "+logger.getError(tmp));
        }

        return false;
}

bool ConectaOPC::getStatusCom(){
        return status;
}

void ConectaOPC::stopCom(){
        CoUninitialize();
        status = false;
}

//---------------------------------------------------------------------------


