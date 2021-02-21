//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)

#include "OPCEventServer.h"

OPCEventServer::OPCEventServer(queue<Buffer> *qb, string nS, string hS, OPCBridge *bridge){

        subHandle = 1;
        qbuffer = qb;

        ptrEventServer=NULL;
        ptrCP=NULL;
        myIUnknownShutdown=NULL;
        opcBridge = NULL;
        opcABrowser = NULL;

        nameServer = nS;
        hostServer = hS;
        opcBridge = bridge;
        ptEventCategories = NULL;
}


OPCEventServer::~OPCEventServer(){
}

void OPCEventServer::setPtrEventServer(IOPCEventServer *ptr){

        ptrEventServer = ptr;
        criaConnectionPoint();
        QueryAvaibleFilters();
        
}

DWORD OPCEventServer::getCountEvCat(){
        return countEventCategory;
}

int OPCEventServer::createEventSubscription(bool bActive, int bufferTime, int maxSize, string nmTxt, string server, string host){

        string chave = nmTxt+getNameServer()+getHostServer();

        OPCEventSubscription *opcESub = NULL;
        DWORD pt1;
        DWORD pt2;

        int retorno;

        IConnectionPointContainer *ptrTemp;
        IOPCEventSubscriptionMgt *ptrTemp1;

        HRESULT hr = ptrEventServer->CreateEventSubscription(bActive, (DWORD)bufferTime, (DWORD)maxSize, subHandle, IID_IOPCEventSubscriptionMgt, reinterpret_cast<LPUNKNOWN*> (&ptrTemp1) ,&pt1, &pt2);


        if (hr != S_OK){

                if (hr == OPC_S_INVALIDBUFFERTIME){
                        string bufferStr = IntToStr(bufferTime).c_str();
                        string bufferRevisado = IntToStr(pt1).c_str();
                        logger.addLinhaLog("O buffer time solicitado é diferente do buffer time revisado. Solicitado/Revisado: "+ bufferStr+ "/" + bufferRevisado);
                        retorno = INVALIDBUFFERTIME;
                }else if (hr == OPC_S_INVALIDMAXSIZE){
                        string maxSizeStr = IntToStr(maxSize).c_str();
                        string maxSizeRevisado = IntToStr(pt2).c_str();
                        retorno = INVALIDMAXSIZE;
                        logger.addLinhaLog("O max time time solicitado é diferente do max size revisado. Solicitado/Revisado: "+ maxSizeStr+ "/" + maxSizeRevisado);
                }else{

                        logger.addLinhaLog("Falha ao tentar criar subscription - CreateEventSubscription: "+logger.getError(hr));

                        if (hr == E_FAIL) {
                                return FALHA;
                        }else if (hr == E_OUTOFMEMORY){
                                return OUTOFMEMORY;
                        }else if (hr == E_NOINTERFACE){
                                return INTERFACE_N_SUPORTADA;
                        }




                }
        }else{
                retorno = SUCESSO;
        }

        HRESULT hr1;

        if (ptrTemp1 != NULL){
                hr1 = ptrTemp1->QueryInterface(IID_IConnectionPointContainer, (LPVOID*)&ptrTemp);
        }

        if (hr1 != S_OK){
                logger.addLinhaLog("Falha ao tentar buscar interface de connectionPoint durante a criação da subscription - QueryInterface: "+logger.getError(hr));
                return FALHA;
        }

        if (!QueryEventCategory()){
                return FALHA;
        }

        if (hr1 == S_OK && (hr == S_OK || hr == OPC_S_INVALIDBUFFERTIME || hr == OPC_S_INVALIDMAXSIZE)){

                sbHand.insert(pair<OPCHANDLE,string>(subHandle++,nmTxt));
                opcESub =  new OPCEventSubscription (this, ptrTemp, (int)pt1, (int)pt2, qbuffer, &mapEC, nmTxt);
                this->createAreaBrowser();
                mapSub.insert(pair<string, OPCEventSubscription*>(chave,opcESub));

        }

        ptrTemp = NULL;

        return retorno;
}

bool OPCEventServer::createAreaBrowser(){

        IOPCEventAreaBrowser *ptrTemp = NULL;
        IUnknown *ptrTemp1 = NULL;

        HRESULT hr = ptrEventServer->CreateAreaBrowser(IID_IUnknown, reinterpret_cast<LPUNKNOWN*> (&ptrTemp1));

        if (hr != S_OK){
                logger.addLinhaLog("Falha ao tentar criar area browser - CreateAreaBrowser: "+logger.getError(hr));
                return false;
        }

        if (ptrTemp1 != NULL){
                hr = ptrTemp1->QueryInterface(IID_IOPCEventAreaBrowser, (LPVOID*)&ptrTemp);
        }

        if(hr == S_OK){
                permiteBrowseArea = true;
                opcABrowser = new OPCEventAreaBrowser(ptrTemp);
        }else{

                logger.addLinhaLog("Falha ao tentar listar áreas: "+logger.getError(hr));
                permiteBrowseArea = false;
                return false;
        }

        return true;
}



OPCEventAreaBrowser * OPCEventServer::getAreaBrowser(){
        return this->opcABrowser;
}

bool OPCEventServer::isAllowedBrowseArea(){
        return permiteBrowseArea;
}

bool OPCEventServer::disconnectEventSubscription(string chave){
        OPCEventSubscription *mSub = NULL;
        bool ctrl;
        map<string, OPCEventSubscription*>::iterator iterSub = mapSub.find(chave);

        if (iterSub != mapSub.end()){
            mSub = iterSub->second;
        }

        if(mSub != NULL){
                ctrl = mSub->release();
                if(ctrl){
                        mapSub.erase(iterSub);
                        delete mSub;
                        return true;
                }else{
                        return false;
                }
        }else{
                return false;
        }
}

bool OPCEventServer::existeSubscription(string chave){
        OPCEventSubscription *controle = NULL;
        map<string, OPCEventSubscription*>::iterator buscaSub = mapSub.find(chave);
        if (buscaSub != mapSub.end()){
            controle = buscaSub->second;
        }

        if(controle != NULL){
                return true;
        }else{
                return false;
        }
}

map<string, OPCEventSubscription*>* OPCEventServer::getSubscritions(){
    return &mapSub;
}

bool OPCEventServer::disconnectAllEventSubscriptions(){

        bool result = true;
        bool erro = false;

        if(!mapSub.empty()){
                map<string, OPCEventSubscription*>::iterator iterSub;
                for( iterSub = mapSub.begin(); iterSub != mapSub.end(); iterSub++ ){

                     try{
                         result = iterSub->second->release();
                     }catch (...){
                     }

                     if (!result){
                        erro = true;
                     }

                }

                return !erro;
        }else{
                return true;
        }
}

bool OPCEventServer::release(){

        HRESULT hrD;
        unsigned long r = -1;
        bool retorno = true;
        
        if (myIUnknownShutdown != NULL){

            try{
                do{
                    r = myIUnknownShutdown->Release();
                }while (r > 0);
            }catch (...){
            }

        }

        if(ptrCP != NULL){
        
                hrD = ptrCP->Unadvise(m_dwAdvise);

                try{
                    do{
                        r = ptrCP->Release();
                    }while (r > 0);
                }catch (...){
                }

                if (hrD != S_OK){
                        retorno =  false;
                }
        }

        if(ptrEventServer != NULL){

        OPCEVENTSERVERSTATUS *ptrServerStatus;

                try{
                    do{
                        hrD = ptrEventServer->GetStatus(&ptrServerStatus);

                        if (hrD == S_OK){
                                r = ptrEventServer->Release();
                        }else{
                                r = 0;
                        }


                    }while (r > 0);
                }catch (...){
                }

        }     


       return retorno;
}

bool OPCEventServer::disconect(){

        return opcBridge->disconectAndDeleteInterface(this->getHostServer(),this->getNameServer());

}

bool OPCEventServer::QueryAvaibleFilters(){

        filterByEvent = false;
        filterByCategory = false;
        filterBySeverity = false;
        filterBySorce = false;
        filterByArea = false;

        if (ptrEventServer != NULL){

             DWORD result;
             HRESULT hr;
             
             hr = ptrEventServer->QueryAvailableFilters(&result);

             if (hr == S_OK){

                if (result & OPC_FILTER_BY_EVENT){
                        filterByEvent = true;
                }
                if (result & OPC_FILTER_BY_CATEGORY){
                        filterByCategory = true;
                }
                if (result & OPC_FILTER_BY_SEVERITY){
                        filterBySeverity=true;
                }
                if (result & OPC_FILTER_BY_AREA){
                        filterByArea=true;
                }
                if (result & OPC_FILTER_BY_SOURCE){
                        filterBySorce=true;
                }
                return true;
             }else{

                logger.addLinhaLog("Falha ao executar o QueryAvailableFilters: "+logger.getError(hr));
             }

        }else{
                logger.addLinhaLog("Falha ao executar o QueryAvailableFilters ptrEventServer é NULL: ");
        }

        return false;
}

bool OPCEventServer::QueryEventCategory(){

        mapEC.clear();

        LPWSTR *ptEventCategoriesDesc;

        HRESULT hr = ptrEventServer->QueryEventCategories(OPC_ALL_EVENTS, &countEventCategory, &ptEventCategories, &ptEventCategoriesDesc);

        if(hr == S_OK){
                for (unsigned int i=0;i<countEventCategory;i++){
                        mapEC.insert(pair<DWORD, AnsiString>(ptEventCategories[i], WideCharToString(ptEventCategoriesDesc[i])));
                }

                return true;
        }else{

                logger.addLinhaLog("Falha ao executar o QueryEventCategory: "+logger.getError(hr));
                return false;
        }
}

bool OPCEventServer::QueryEventAttributes(string eventCategory){

    if (ptrEventServer != NULL){

        DWORD evtCat = getEventCategory(eventCategory);

        DWORD pdwCount;
        DWORD *pdwAttrIDs;
        LPWSTR *pdwAttrDescs;
        VARTYPE *pdwAttrTypes;

        if (ptrEventServer > 0){
            HRESULT hr = ptrEventServer->QueryEventAttributes(evtCat,&pdwCount,&pdwAttrIDs,&pdwAttrDescs,&pdwAttrTypes);

            mapAttrDesc.clear();
            mapAttrTypes.clear();

            for (unsigned int i=0;i<pdwCount;i++){

                mapAttrDesc.insert(pair<DWORD, AnsiString>(pdwAttrIDs[i], WideCharToString(pdwAttrDescs[i])));
                mapAttrTypes.insert(pair<DWORD, VARTYPE> (pdwAttrIDs[i],pdwAttrTypes[i]));

            }

            if (hr == S_OK){
                return true;
            }else{
                logger.addLinhaLog("Falha ao executar o QueryEventAttributes: "+logger.getError(hr));
            }

        }
    }
    return false;

}

bool OPCEventServer::getAttributes(string eventCategory, string attributes[][3]){

    if (QueryEventAttributes(eventCategory)){

        int i=0;

        map<DWORD, AnsiString>::iterator iter;
        for(iter=mapAttrDesc.begin();iter!=mapAttrDesc.end();iter++){

            attributes[i][0] = IntToStr(iter->first).c_str();
            attributes[i][1] = iter->second.c_str();
            i++;
        }

        VARTYPE x;
        map<DWORD, VARTYPE>::iterator iter1;
        i=0;
        for(iter1=mapAttrTypes.begin();iter1!=mapAttrTypes.end();iter1++){
            attributes[i][2] = convertVarType(iter1->second);
            i++;
        }
    }

    return false;

}


DWORD OPCEventServer::getEventCategory(string eventCategory){
        int i=0;
        map<DWORD, AnsiString>::iterator iter;
        for(iter=mapEC.begin();iter!=mapEC.end();iter++){
            if (StrComp(iter->second.c_str(),eventCategory.c_str()) == 0){
                return iter->first;
            }

            i++;
        }
        return -1;
}

bool OPCEventServer::getEventCategoryList(string *lista){

        if (mapEC.empty()){
            QueryEventCategory();
        }

        int i=0;
        map<DWORD, AnsiString>::iterator iter;
        for(iter=mapEC.begin();iter!=mapEC.end();iter++){
            lista[i] = iter->second.c_str();
            i++;
        }
        return true;
}

void OPCEventServer::getEvCat(DWORD *evCat, int tam, string *listRetorno){

                int j=0;
                map<DWORD, AnsiString>::iterator iter;
                for(int i=0;i<tam;i++){
                        iter = mapEC.find(evCat[i]);

                        if (iter!=mapEC.end()){
                                listRetorno[j++] = iter->second.c_str();
                        }

                }

}

void OPCEventServer::getPtEvCat(string *lista, int tam, DWORD *selectedCategory){

        string strTmp;
        int j=0;
        
        if(this->QueryEventCategory()){

                map<DWORD, AnsiString>::iterator iter;
                for(iter=mapEC.begin();iter!=mapEC.end();iter++){

                        strTmp = iter->second.c_str();

                        for(int i=0;i<tam;i++){

                                if (StrComp(lista[i].c_str(),strTmp.c_str()) == 0){
                                        selectedCategory[j++] = iter->first;
                                }

                        }

                }

        }

}

HRESULT OPCEventServer::criaConnectionPoint(){

        IConnectionPointContainer *ptrShutDownConnectionPoint;
        HRESULT hr1,hcp;

        if (ptrEventServer != NULL){

                hr1 = ptrEventServer->QueryInterface(IID_IConnectionPointContainer, (LPVOID*)&ptrShutDownConnectionPoint);

                if (hr1 == S_OK){
                        //LOGAR
                }else{
                        logger.addLinhaLog("Falha ao executar o QueryInterface para o IID_IConnectionPointContainer para criar o connection Point: "+logger.getError(hr1));
                        return hr1;
                }

        }else{
                logger.addLinhaLog("Falha ao executar o ao criar connection Point: ptrEventServer é NULL");
        }

        hcp = ptrShutDownConnectionPoint->FindConnectionPoint(IID_IOPCShutdown, &ptrCP);

        if (ptrShutDownConnectionPoint != NULL){
                ptrShutDownConnectionPoint->Release();
                ptrShutDownConnectionPoint = NULL;
        }

        OPCShutDown *opcShutDown;

        if (hcp == S_OK){

                if(ptrEventServer != NULL){

                        opcShutDown = new OPCShutDown(this);
                }

                hcp = opcShutDown->QueryInterface(IID_IUnknown,(LPVOID*)&myIUnknownShutdown);

                if (hcp != S_OK){
                    logger.addLinhaLog("Falha ao executar o QueryInterface para o IID_IUnknown criar o connection Point: "+logger.getError(hcp));
                    return hcp;
                }

                hcp = ptrCP->Advise(myIUnknownShutdown,&m_dwAdvise);

                if (hcp != S_OK){
                    logger.addLinhaLog("Falha ao executar o Advise para criar o connection Point: "+logger.getError(hcp));
                }

                return hcp;
        }else{
                logger.addLinhaLog("Falha ao executar o FindConnectionPoint para criar o connection Point: "+logger.getError(hcp));
                return hcp;
        }

}

/*
Retorna um ponteiro para o OPCEventSubscription
parametros: nome ( subscription + serverName + HostName )
*/
OPCEventSubscription* OPCEventServer::getEvSub(string nome){

        map<string, OPCEventSubscription*>::iterator iterEvSub = mapSub.find(nome);

        if (iterEvSub == mapSub.end()){
                return NULL;
        }else{
                return iterEvSub->second;
        }

}

bool OPCEventServer::getStatus(){


        if (ptrEventServer == NULL){
            return false;
        }

        HRESULT hr;
        hr = ptrEventServer->GetStatus(&opcStatus);

        if(hr != S_OK){
            logger.addLinhaLog("Falha ao executar o GetStatus: "+logger.getError(hr));
            return false;
        }else{

        }

        if (opcStatus->dwServerState == OPCAE_STATUS_RUNNING){

            return true;

        }else{


            bool r1 = opcStatus->dwServerState == OPCAE_STATUS_FAILED;
            bool r2 = opcStatus->dwServerState == OPCAE_STATUS_NOCONFIG;
            bool r3 = opcStatus->dwServerState == OPCAE_STATUS_SUSPENDED;
            bool r4 = opcStatus->dwServerState == OPCAE_STATUS_TEST;

            string erro;

            if (r1){
                erro = "Falha no estado do servidor";
            }
            if (r2){
                erro = "Servidor não configurado";
            }
            if (r3){
                erro = "Servidor está temporariamente suspenso";
            }
            if (r4){
                erro = "Servidor está em estado de teste";
            }

            logger.addLinhaLog("Falha no estado de execução do servidor: "+erro);

            return false;
        }
}

bool OPCEventServer::isAvaibleFilterByEvent(){
        return filterByEvent;
}
bool OPCEventServer::isAvaibleFilterByCategory(){
        return filterByCategory;
}
bool OPCEventServer::isAvaibleFilterBySeverity(){
        return filterBySeverity;
}
bool OPCEventServer::isAvaibleFilterByArea(){
        return filterByArea;
}
bool OPCEventServer::isAvaibleFilterBySorce(){
        return filterBySorce;
}
string OPCEventServer::getNameServer(){
        return nameServer;
}
string OPCEventServer::getHostServer(){
        return hostServer;
}
void OPCEventServer::setNameServer(string ns){
        nameServer = ns;
}
void OPCEventServer::setHostServer(string hs){
        hostServer = hs;
}



bool OPCEventServer::AckCondition(string coment, string ator, string source, string condition, FILETIME activeTime, DWORD cookie ){

    if (ptrEventServer == NULL){
        return false;
    }

    LPWSTR comentLpwstr = WideString(coment.c_str()).Detach();
    LPWSTR atorLpwstr = WideString(ator.c_str()).Detach();
    DWORD count = 1;

    LPWSTR sourceLpwstr[1];
    sourceLpwstr[0] = WideString(source.c_str()).Detach();

    LPWSTR conditionLpwstr[1];
    conditionLpwstr[0] =  WideString(condition.c_str()).Detach();

    FILETIME actives[1];
    actives[0] = activeTime;

    DWORD ck[1];
    ck[0] = cookie;

    HRESULT *errors;
    HRESULT hr;

    hr = ptrEventServer->AckCondition(count,
                            atorLpwstr,
                            comentLpwstr,
                            sourceLpwstr,
                            conditionLpwstr,
                            actives,
                            ck,
                            &errors);


    if (hr == S_OK){
        return true;
    }

    if (hr != S_FALSE){
        logger.addLinhaLog("Falha ao executar o AckCondition: "+logger.getError(hr));
    }else{
        logger.addLinhaLog("Falha ao executar o AckCondition: "+logger.getError(errors[0]));
    }

    return false;

}

string OPCEventServer::convertVarType(VARTYPE v){

    if (v >= 1 && v <= 3){
        return "VT_I2";
    }else if (v == 4){
        return "VT_DATE";
    }else if (v == 5 || v == 108 || v == 201 || v == 202){
        return "VT_I4";
    }else if (v == 6){
        return "VT_R6";
    }else if (v == 302){
        return "VT_BSTR|VT_ARRAY";
    }else if (v == 101 || v==106 || v==200 || (v >= 204 && v <= 207) || (v >= 300 && v <= 305)){
        return "VT_BSTR";
    }else if (v == 203){
        return "VT_BOOL";
    }else if (v >= 306 && v<= 312){
        return "VT_R8";
    }else if (v >= 50000){
        return "Vendor Specific";
    }else{
        return "Desconhecido";
    }

}


//---------------------------------------------------------------------------
