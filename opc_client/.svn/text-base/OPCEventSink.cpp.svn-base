//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)
#include "OPCEventSink.h"


using namespace std;

OPCEventSink::OPCEventSink(){
        m_cRef=0;
        return;
}

OPCEventSink::OPCEventSink(queue<Buffer> *qb, map<DWORD, AnsiString> *ptmapECx, OPCEventSubscription *opcSub, OPCEventServer *opcES){
        m_cRef=0;
        qbuffer = qb;
        ptmapEC = ptmapECx;
        opcEventSub = opcSub;
        opcEventServer = opcES;
}

OPCEventSink::~OPCEventSink(){
        return;
}

string OPCEventSink::processChangeMask(WORD mask){
        string retorno;
        switch(mask){
                case OPC_CHANGE_ACTIVE_STATE:
        	        retorno = "OPC_CHANGE_ACTIVE_STATE";
                break;
                case OPC_CHANGE_ACK_STATE:
                        retorno = "OPC_CHANGE_ACK_STATE";
                break;
                case OPC_CHANGE_ENABLE_STATE:
                        retorno = "OPC_CHANGE_ENABLE_STATE";
                break;
                case OPC_CHANGE_QUALITY:
                        retorno = "OPC_CHANGE_QUALITY";
                break;
                case OPC_CHANGE_SEVERITY:
                        retorno = "OPC_CHANGE_SEVERITY";
                break;
                case OPC_CHANGE_SUBCONDITION:
                        retorno = "OPC_CHANGE_SUBCONDITION";
                break;
                case OPC_CHANGE_MESSAGE:
                        retorno = "OPC_CHANGE_MESSAGE";
                break;
                case OPC_CHANGE_ATTRIBUTE:
                        retorno = "OPC_CHANGE_ATTRIBUTE";
                break;
                default:
                        retorno = "INDEFINIDO";
                break;
        }

        return retorno;

}
string OPCEventSink::processNewState(WORD state){

        string retorno;
        switch(state){
                case OPC_CONDITION_ACTIVE:
        	        retorno = "OPC_CONDITION_ACTIVE";
                break;
                case OPC_CONDITION_ENABLED:
                        retorno = "OPC_CONDITION_ENABLED";
                break;
                case OPC_CONDITION_ACKED:
                        retorno = "OPC_CONDITION_ACKED";
                break;
                default:
                retorno = "INDEFINIDO";
                break;
        }

        return retorno;
}


STDMETHODIMP OPCEventSink::QueryInterface(REFIID riid, void** ppv){

        *ppv=NULL;

        if (IID_IUnknown == riid || IID_IOPCEventSink == riid){
                *ppv=this;
        }

        if (NULL!=*ppv){
                ((LPUNKNOWN)*ppv)->AddRef();
                return NOERROR;
        }

        return ResultFromScode(E_NOINTERFACE);
}


STDMETHODIMP_(ULONG) OPCEventSink::AddRef(void){
        return ++m_cRef;
}


STDMETHODIMP_(ULONG) OPCEventSink::Release(void)
{
        if (0 != --m_cRef){
                return m_cRef;
        }

        delete this;
        return 0;
}
STDMETHODIMP OPCEventSink::OnEvent(
        /* [in] */ OPCHANDLE hClientSubscription,
        /* [in] */ BOOL bRefresh,
        /* [in] */ BOOL bLastRefresh,
        /* [in] */ DWORD dwCount,
        /* [size_is][in] */ ONEVENTSTRUCT __RPC_FAR *pEvents){

        char* horadata = (char *)malloc(30);
        Buffer b;

        for (unsigned int i=0;i<dwCount;i++){

                if (!FileTimeToLocalFileTime(&(pEvents[i].ftTime), &ftLocal)){
                        //MessageBox(HWND_DESKTOP,"falha na conversao de data","ERRO",MB_OK);
                }

                FileTimeToSystemTime(&ftLocal, &stTimeStamp);
                wsprintf(horadata, "%02d/%02d/%d %02d:%02d:%02d:%d",                stTimeStamp.wDay, stTimeStamp.wMonth, stTimeStamp.wYear,                stTimeStamp.wHour, stTimeStamp.wMinute,stTimeStamp.wSecond,stTimeStamp.wMilliseconds);
                b.setTime(horadata);

                if (!FileTimeToLocalFileTime(&(pEvents[i].ftActiveTime), &activeftLocal)){
                        //MessageBox(HWND_DESKTOP,"falha na conversao de data","ERRO",MB_OK);
                }

                FileTimeToSystemTime(&activeftLocal, &stTimeStamp);
                wsprintf(horadata, "%02d/%02d/%d %02d:%02d:%02d:%d",                stTimeStamp.wDay, stTimeStamp.wMonth, stTimeStamp.wYear,                stTimeStamp.wHour, stTimeStamp.wMinute,stTimeStamp.wSecond,stTimeStamp.wMilliseconds);
                b.setActiveTime(horadata);

                unsigned short qualidade = pEvents[i].wQuality;

                switch(qualidade){
	                case OPC_QUALITY_GOOD:
        	                qld = "Good";
                        break;
                        case OPC_QUALITY_BAD:
                                qld = "Bad";
                        break;
                        default:
                                qld = "Uncertain";
                        break;
                }
                b.setQualityStr(qld);
                b.setQuality(qualidade);

                //recebe uma mensagem do sistema descrevendo o evento
                szMsg = WideCharToString(pEvents[i].szMessage).c_str();
                b.setMessage(szMsg);

                //recebe o source event notification (item do opcda)
                szSrc = WideCharToString(pEvents[i].szSource).c_str();
                b.setSource(szSrc);

                //indica ao cliente que condicao foi alterada
                WORD mask = 128;
                changeMask = "";

                unsigned short cMask = pEvents[i].wChangeMask;

                while (mask != 0){
                   if (cMask & mask){
                        if (changeMask == ""){
                                changeMask = processChangeMask(mask);
                        }else{
                                changeMask = changeMask + ";" +processChangeMask(mask);
                        }

                   }
                   mask >>= 1;
                }
                b.setCMaskStr(changeMask);
                b.setCMask(cMask);

                //indica o novo estado da condicao OPCcondition
                WORD state = 128;
                newState = "";

                unsigned short nState = pEvents[i].wNewState;

                while (state != 0){
                   if (nState & state){
                        if (newState == ""){
                                newState = processNewState(state);
                        }else{
                                newState = newState + ";" +processNewState(state);
                        }

                   }
                   state >>= 1;
                }

                b.setNewStateStr(newState);
                b.setNewState(nState);

                unsigned short dwEvtType = pEvents[i].dwEventType;

                //indica o tipo do evento
                switch(dwEvtType){
	                case OPC_SIMPLE_EVENT:
        	                evType = "OPC_SIMPLE_EVENT";
                        break;
                        case OPC_CONDITION_EVENT:
                                evType = "OPC_CONDITION_EVENT";
                        break;
                        case OPC_TRACKING_EVENT:
                                evType = "OPC_TRACKING_EVENT";
                        break;
                        default:
                                evType = "INDEFINIDO";
                        break;
                }
                b.setEventTypeStr(evType);
                b.setEventType(dwEvtType);

                //indica a categoria do evento
                map<DWORD, AnsiString>::iterator iter = ptmapEC->find(pEvents[i].dwEventCategory);

                if (iter != ptmapEC->end()){
                    AnsiString evCategoryTmp = iter->second;
                    evCategory = evCategoryTmp.c_str();
                }else{
                    evCategory = "INDEFINIDO";
                }

                b.setEventCategory(evCategory);

                //mostra o nome da subscription criada
                b.setNomeSub(opcEventSub->getNomeSub());

                //indica a severidade do evento
                int severityTemp = (int)pEvents[i].dwSeverity;
                std::stringstream ss2;
                std::string str2;
                ss2 << severityTemp;
                ss2 >> str2;
                severity = str2;
                b.setSeverity(severity);

                //indica o cookie
                DWORD ck = pEvents[i].dwCookie;
                int cookie = (int)ck;
                b.setCookie(cookie);

                //O nome da condição relacionada com o evento
                conditionName = WideCharToString(pEvents[i].szConditionName).c_str();
                b.setCondName(conditionName);

                /*
                O nome da subcondição para multi-estados de condições. Para um unico estado
                contém o nome da condição
                */
                subConditionName = WideCharToString(pEvents[i].szSubconditionName).c_str();

                if (subConditionName == "" && dwEvtType == OPC_CONDITION_EVENT){

                     map<DWORD, string>::iterator iter = ptSubCondition.find(ck);
                     if(iter != ptSubCondition.end()){
                         subConditionName =  iter->second;
                     }

                }else{

                    if (nState == 3){

                        map<DWORD, string>::iterator iter = ptSubCondition.find(ck);
                        if(iter != ptSubCondition.end()){
                            ptSubCondition.erase(iter);
                        }
                        ptSubCondition.insert(pair<DWORD,string>(ck,subConditionName));
                    }

                }

                b.setSubCondName(subConditionName);

                //flag para indicar se a condição relacionada requer reconhecimento do eventoackRequired = pEvents[i].bAckRequired;
                ackRequired = pEvents[i].bAckRequired;
                if(ackRequired == true){
                        ackRequiredStr = "TRUE";
                        b.setAckRequiredString(ackRequiredStr);
                }else{
                        ackRequiredStr = "FALSE";
                        b.setAckRequiredString(ackRequiredStr);
                }

                b.setAckRequired(ackRequired);

                string listaAttr[MAX_ATTRIBUTES];
                populaLista(listaAttr, pEvents[i].dwNumEventAttrs, pEvents[i].pEventAttributes);

                b.setAttr(listaAttr,pEvents[i].dwNumEventAttrs);

                //actor id para tracking events notifications ou acknowledgerID
                if(pEvents[i].szActorID == NULL){
                        actorID = "NULL";
                }else{
                        actorID = WideCharToString(pEvents[i].szActorID).c_str();
                }
                b.setactorID(actorID);
                
                sem.P();
                qbuffer->push(b);
                sem.V();

                /* TESTE DEVE SER RETIRADO NA VERSÃO FINAL */

                    //string coment = "Reconhecimento Automático";
                    //string ator = "Sistema";
                    //opcEventServer->AckCondition(coment,ator, szSrc, conditionName, pEvents[i].ftActiveTime, ck);

                /*****************************************/

        }

        if (bRefresh && !bLastRefresh){
            opcEventSub->refresh();
        }

        return S_OK;

}
void OPCEventSink::populaLista(string *list, int qntAttr, VARIANT *tag){

    for (int i=0;i<qntAttr;i++){
       list[i] = convert(tag[i]);
    }

}

string OPCEventSink::convert(VARIANT x){

        VariantInit(&vb);
        vb.vt = VT_BSTR;
        string retorno = "";

        try{

                if (VariantChangeTypeEx(&vb, &x, 0, 0, VT_BSTR ) == S_OK){
                        retorno = WideCharToString(vb.bstrVal).c_str();
                }

            
        }catch(...){

        }

        return retorno;
}
//---------------------------------------------------------------------------


