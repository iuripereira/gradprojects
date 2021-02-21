//---------------------------------------------------------------------------


#pragma hdrstop

#include "OPCEventAreaBrowser.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

OPCEventAreaBrowser::OPCEventAreaBrowser(IOPCEventAreaBrowser *ptrTemp){
        ptrAB = ptrTemp;
        pszAreaList = NULL;
        pszSourceList = NULL;
}

OPCEventAreaBrowser::~OPCEventAreaBrowser(){
}

bool OPCEventAreaBrowser::browseOPCAreas(string *lista){

        HRESULT hr, hr2;
        //LPCWSTR __RPC_FAR szFilterCriteria = reinterpret_cast<const wchar_t*>("");
        LPCWSTR __RPC_FAR szFilterCriteria = L"*";
        LPENUMSTRING enumLista;
        LPOLESTR stValor;
        LPWSTR qualifiedValor;
        ULONG fetched = 0;

        if(ptrAB != NULL){

                hr = ptrAB->BrowseOPCAreas(OPC_AREA, szFilterCriteria, &enumLista);
                if(hr == S_OK){
                        hr2 = enumLista->Reset();
                        hr2 = enumLista->Next(1,&stValor,&fetched);
                        int count = 0;
                        while(hr2 == S_OK && fetched > 0){
                                getAreaName(WideCharToString(stValor).c_str(), &qualifiedValor);
                                lista[count++] = WideCharToString(qualifiedValor).c_str();
                                hr2 = enumLista->Next(1,&stValor,&fetched);
                        }
                        return true;
                }else{

                    //logger.addLinhaLog("Falha ao tentar executar BrowseOPCAreas: "+logger.getError(hr));

                }
        }
        return false;
}
bool OPCEventAreaBrowser::browseOPCSource(string *lista){
        HRESULT hr, hr2;
        LPENUMSTRING enumLista;
        LPOLESTR stValor;
        ULONG fetched = 0;
        //LPCWSTR __RPC_FAR szFilterCriteria = reinterpret_cast<const wchar_t*>("");
        LPCWSTR __RPC_FAR szFilterCriteria = L"*";

        if(ptrAB != NULL){
                hr = ptrAB->BrowseOPCAreas(OPC_SOURCE, szFilterCriteria, &enumLista);
                if(hr == S_OK){
                        hr2 = enumLista->Reset();
                        hr2 = enumLista->Next(1,&stValor,&fetched);
                        int count = 0;
                        while(hr2 == S_OK && fetched > 0){
                                lista[count++] = WideCharToString(stValor).c_str();
                                hr2 = enumLista->Next(1,&stValor,&fetched);
                        }
                        return true;
                }else{
                    logger.addLinhaLog("Falha ao tentar executar browseOPCSource: "+logger.getError(hr));
                }
        }
        return false;

}

bool OPCEventAreaBrowser::changeBrowseUp(){
        HRESULT hr;
        LPCWSTR __RPC_FAR stNull = reinterpret_cast<const wchar_t*>("");
        hr = ptrAB->ChangeBrowsePosition(OPCAE_BROWSE_UP, stNull);
        if(hr == S_OK){
            return true;
        }else{
            logger.addLinhaLog("Falha ao tentar executar ChangeBrowsePosition do método changeBrowseUp: "+logger.getError(hr));
        }

        return false;
}

bool OPCEventAreaBrowser::changeBrowseDown(string stDown){
        HRESULT hr;
        LPCWSTR locus = WideString(stDown.c_str());
        hr = ptrAB->ChangeBrowsePosition(OPCAE_BROWSE_DOWN, locus);
        if(hr == S_OK){
                return true;
        }else{
            logger.addLinhaLog("Falha ao tentar executar changeBrowseDown: "+logger.getError(hr));
        }
        return false;
}

bool OPCEventAreaBrowser::changeBrowseTo(string stTo){
        HRESULT hr;
        LPWSTR receba = WideString(stTo.c_str());

        hr = ptrAB->ChangeBrowsePosition(OPCAE_BROWSE_TO, receba);

        if(hr == S_OK){
                return true;
        }else{
            logger.addLinhaLog("Falha ao tentar executar ChangeBrowsePosition do método changeBrowseTo: "+logger.getError(hr));
        }

        return false;
}

bool OPCEventAreaBrowser::getAreaName(string stTo, LPWSTR *stGuarda){
        HRESULT hr;

        hr = ptrAB->GetQualifiedAreaName(WideString(stTo.c_str()), stGuarda);
        if(hr == S_OK){
                return true;
        }else{
            logger.addLinhaLog("Falha ao tentar executar GetQualifiedAreaName: "+logger.getError(hr));
        }
        return false;

}

bool OPCEventAreaBrowser::getSourceName(string stTo, LPWSTR *stGuarda){
        HRESULT hr;
        hr = ptrAB->GetQualifiedSourceName(WideString(stTo.c_str()), stGuarda);
        if(hr == S_OK){
                return true;
        }else{
            logger.addLinhaLog("Falha ao tentar executar GetQualifiedSourceName: "+logger.getError(hr));
        }

        return false;
}

