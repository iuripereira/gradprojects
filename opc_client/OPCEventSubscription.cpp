//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)

#include "OPCEventSubscription.h"
#include "OPCEventServer.h"

#include <map>
#include <sstream>

OPCEventSubscription::OPCEventSubscription(OPCEventServer *ptServer, IConnectionPointContainer *ptES, int mxBufferTime, int mxSize, queue<Buffer> *qb, map<DWORD, AnsiString> *ptmapECx, string nomeSub1){

        m_IOPCESink = NULL;
        ptrEventSubMgt = NULL;
        ptCP = NULL;
        ptrEventSink = ptES;
        maxBufferTime = mxBufferTime;
        maxSize = mxSize;
        qbuffer=qb;
        ptmapEC =  ptmapECx;
        nomeSub = nomeSub1;
        server = ptServer;

        criaConnectionPoint();

        if (ptrEventSink != NULL){

                HRESULT hr = ptrEventSink->QueryInterface(IID_IOPCEventSubscriptionMgt,(LPVOID*)&ptrEventSubMgt);

                if (hr != S_OK){
                    logger.addLinhaLog("Falha ao executar o QueryInterface na inicialização da classe Subscription: "+logger.getError(hr));
                }

                //refresh();
        }

}

OPCEventSubscription::~OPCEventSubscription(){
}

int OPCEventSubscription::getMaxBufferTime(){
    return maxBufferTime;
}

int OPCEventSubscription::getMaxSize(){
    return maxSize;
}

bool OPCEventSubscription::refresh(){
        HRESULT hr;

        if (ptrEventSubMgt != NULL){

                hr = ptrEventSubMgt->Refresh(m_dwAdvise);

                if(hr == S_OK){
                    return true;
                }else{
                    logger.addLinhaLog("Falha ao executar o Refresh: "+logger.getError(hr));
                }
        }

        return false;
}

bool OPCEventSubscription::release(){

        HRESULT hrD;
        DWORD r;

        if(ptCP != NULL) {

            hrD = ptCP->Unadvise(m_dwAdvise);

            try{
                do{
                    r = ptCP->Release();
                }while (r > 0);
            }catch (...){
            }

        }

        if(ptrEventSink != NULL){

            try{
                do{
                    r = ptrEventSink->Release();
                }while (r > 0);
            }catch (...){
            }

        }        

        if(m_IOPCESink != NULL){

            try{
                do{
                    r = m_IOPCESink->Release();
                }while (r > 0);
             }catch (...){
             }

        }

        if(ptrEventSubMgt != NULL){

            try{
                do{
                   r = ptrEventSubMgt->Release();
                }while (r > 0);
             }catch (...){
             }

        }
        
        if (hrD == S_OK){
                return true;
        }

        return false;

}

string OPCEventSubscription::getNomeSub(){
        return nomeSub;
}


HRESULT OPCEventSubscription::criaConnectionPoint(){

        HRESULT hcp = ptrEventSink->FindConnectionPoint(IID_IOPCEventSink, &ptCP);

        if (hcp == S_OK){

                m_IOPCESink = new OPCEventSink(qbuffer,ptmapEC,this, server);

                IOPCEventSink *myCallback;
                hcp = m_IOPCESink->QueryInterface(IID_IOPCEventSink,(LPVOID*)&myCallback);

                if (hcp != S_OK){
                    logger.addLinhaLog("Falha ao executar o QueryInterface para IID_IOPCEventSink no método criaConnectionPoint: "+logger.getError(hcp));
                }

                hcp = ptCP->Advise(myCallback,&m_dwAdvise);

                if (hcp != S_OK){
                    logger.addLinhaLog("Falha ao executar o Advise no método criaConnectionPoint: "+logger.getError(hcp));
                }

                return hcp;
        }else{
                logger.addLinhaLog("Falha ao executar o FindConnectionPoint no método criaConnectionPoint: "+logger.getError(hcp));
                return hcp;
        }

}

DWORD OPCEventSubscription::setEvTypeFilter(ESTRUTURA *ptrStruct){

        DWORD evType = 0;

        short maskDefault = 1;
        short mask;

        mask = maskDefault & ptrStruct->btSEvent;
        evType += mask;

        maskDefault = maskDefault << 1;
        mask = maskDefault & (ptrStruct->btTEvent << 1);
        evType += mask;

        maskDefault = maskDefault << 1;
        mask = maskDefault & (ptrStruct->btCEvent << 2);
        evType += mask;

        return evType;
}

bool OPCEventSubscription::setarFiltro(ESTRUTURA *ptrStruct){

        HRESULT hr;

        if (ptrStruct == NULL){
                return false;
        }

        DWORD lowSev = ptrStruct->sevLow;
        DWORD highSev = ptrStruct->sevHigh;
        DWORD countEventCategory = ptrStruct->countEventCategory;
        DWORD numArea = ptrStruct->numArea;
        DWORD numSrc =  ptrStruct->numSources;
        DWORD *ptEventCategories = ptrStruct->ptEventCategories;
        LPWSTR *listaSrc = ptrStruct->pszSourceList;
        LPWSTR *listaArea = ptrStruct->pszAreaList;
        DWORD evType = setEvTypeFilter(ptrStruct);

        if(ptrEventSubMgt != NULL){

                hr = ptrEventSubMgt->SetFilter(evType, countEventCategory, ptEventCategories, lowSev, highSev, numArea, listaArea, numSrc, listaSrc);


                if(hr == S_OK){
                        return true;
                }else{

                        logger.addLinhaLog("Falha ao executar o SetFilter: "+logger.getError(hr));
                        return false;
                }
        }else{
                return false;
        }
}

void OPCEventSubscription::convertLPWSTRtoString(LPWSTR *lista, int tam, string *listaRetorno){

        for (int i=0;i<tam;i++){
            listaRetorno[i] = WideCharToString(lista[i]).c_str();
        }
}

bool OPCEventSubscription::getFiltro(Filtro *ptrStruct){

        if (ptrStruct == NULL){
                return false;
        }

       HRESULT hr;

       DWORD evType;
       DWORD countEventCategory;
       DWORD *ptEventCategories[MAX_LEN_SUB];

       DWORD lowSev;
       DWORD highSev;
       DWORD numArea;

       LPWSTR *listaArea[MAX_LEN_SUB];
       DWORD numSrc;

       LPWSTR *listaSrc[MAX_LEN_SUB];

       if(ptrEventSubMgt != NULL){

                hr = ptrEventSubMgt->GetFilter(&evType,
                                                &countEventCategory,
                                                ptEventCategories,
                                                &lowSev,
                                                &highSev,
                                                &numArea,
                                                listaArea,
                                                &numSrc,
                                                listaSrc);

                if(hr == S_OK){

                        logger.addLinhaLog("Sucesso ao executar o GetFilter: ");

                        ptrStruct->sevLow = lowSev;
                        ptrStruct->sevHigh = highSev;

                        ptrStruct->countEventCategory = countEventCategory;
                        server->getEvCat(ptEventCategories[0],countEventCategory,listaStringEvtCat);
                        ptrStruct->ptEventCategories = listaStringEvtCat;

                        ptrStruct->numArea = numArea;
                        convertLPWSTRtoString(listaArea[0],numArea,listaStringArea);
                        ptrStruct->pszAreaList = listaStringArea;

                        ptrStruct->numSources = numSrc;
                        convertLPWSTRtoString(listaSrc[0],numSrc,listaStringSource);
                        ptrStruct->pszSourceList = listaStringSource;

                        ptrStruct->btCEvent = evType & OPC_CONDITION_EVENT;
                        ptrStruct->btSEvent =  evType & OPC_SIMPLE_EVENT;
                        ptrStruct->btTEvent = evType & OPC_TRACKING_EVENT;
                        ptrStruct->evtType = evType;

                        return true;
                }else{

                        logger.addLinhaLog("Falha ao executar o GetFilter: "+logger.getError(hr));

                        return false;
                }
        }else{
                return false;
        }

}

int OPCEventSubscription::getEventCategoriesAttr(DWORD *listEvt){

        map<DWORD, DWORD*>::iterator iter;

        int count = 0;

        for(iter = mapAttr.begin(); iter != mapAttr.end(); iter++){
            listEvt[count++] = iter->first;
        }

        return count;

}

int OPCEventSubscription::getAttributes(DWORD evtCat, string *listAttributes){

        OPCEventServer *servidor = NULL;
        map<DWORD, DWORD*>::iterator buscaAttr = mapAttr.find(evtCat);

        DWORD *list;
        int count = 0;

        if (buscaAttr != mapAttr.end()){
            list = buscaAttr->second;

            while (list[count] != NULL){
                //listAttributes[count] = LongToStr( ((int)list[count])).c_str();
                ostringstream stream;
                stream << list[count];
                listAttributes[count] = stream.str();
                count++;
            }

        }
        return count;

}


bool OPCEventSubscription::selectReturnedAttr(DWORD *evtCat, DWORD qntEvtCat, DWORD *dwCount, DWORD dwAttr[][MAX_LEN_ATTRIBUTES]){

    if (ptrEventSubMgt == NULL){
        return false;
    }

    bool erro = false;

    map<DWORD, DWORD*>::iterator iter;

    for(iter = mapAttr.begin(); iter != mapAttr.end(); iter++){
        mapAttr.erase(iter);
    }

    for (int i=0;i<qntEvtCat;i++){

        HRESULT hr = ptrEventSubMgt->SelectReturnedAttributes(evtCat[i],dwCount[i],dwAttr[i]);

        if (hr == S_OK){

            map<DWORD, DWORD*>::iterator iterAttr = mapAttr.find(evtCat[i]);

            if (iterAttr != mapAttr.end()){
                mapAttr.erase(iterAttr);
            }

            listaAttributosEvtCat = new DWORD[MAX_LEN_ATTRIBUTES];

            for (int j=0;j<MAX_LEN_ATTRIBUTES;j++){
                if (dwCount[i] > j){
                    listaAttributosEvtCat[j] = dwAttr[i][j];
                }else{
                    listaAttributosEvtCat[j] = NULL;
                }
            }

            mapAttr.insert(pair<DWORD,DWORD*>(evtCat[i],listaAttributosEvtCat));

        }else{

            erro = true;
            logger.addLinhaLog("Falha ao executar o SelectReturnedAttributes: "+logger.getError(hr));

        }

    }

    return !erro;

}

bool OPCEventSubscription::getAtributosSelecionados(string evtCat, string attributes[][3], string listaDeSelecionados[][3]) {

        DWORD  pwdCount;
        DWORD  *dwAttributeIDs[1000];

        if (server != NULL){

                DWORD idVEvt = server->getEventCategory(evtCat);
                HRESULT hr = ptrEventSubMgt->GetReturnedAttributes(idVEvt, &pwdCount, dwAttributeIDs);

                if( hr != S_OK ) {
                        return false;
                }

                int size = pwdCount;

                if( size != 0 ) {

                        int k = 0;
                        string id;

                        for( int i = 0; i < size; i++ ) {

                                long longo = (long)dwAttributeIDs[0][i];

                                stringstream out;
                                out << longo;

                                id = out.str();

                                int j = 0;

                                while(StrComp(attributes[j][0].c_str(),"") != 0) {
                                        if( attributes[j][0].c_str() == id ) {
                                                listaDeSelecionados[k][0] = attributes[j][0];
                                                listaDeSelecionados[k][1] = attributes[j][1];
                                                listaDeSelecionados[k][2] = attributes[j][2];
                                                k++;
                                        }
                                        j++;
                                }
                        }
                }

                return true;
        }

        return false;

}




//---------------------------------------------------------------------------


