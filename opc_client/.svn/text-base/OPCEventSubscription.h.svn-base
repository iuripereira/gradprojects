//---------------------------------------------------------------------------

#ifndef OPCEventSubscriptionH
#define OPCEventSubscriptionH
#include "OPCEventSink.h"

#include "bibliotecas/opc_ae.h"
#include "bibliotecas/opcaedef.h"
#include "bibliotecas/opccomn.h"
#include "bibliotecas/defOPCSiga.h"
#include "Buffer.h"
#include "Logger.h"

#include <queue>
#include <map>

#define MAX_LEN_SUB 1000
#define MAX_LEN_ATTRIBUTES 1000
#define MAX_LEN_EVTCAT 100

class OPCEventSink;
class OPCEventServer;
class OPCEventSubscription
{
        private:
                IConnectionPointContainer *ptrEventSink;
                IOPCEventSubscriptionMgt *ptrEventSubMgt;
                IConnectionPoint *ptCP;
                OPCEventSink *m_IOPCESink;
                OPCEventServer *server;

                Logger logger;

                unsigned long m_dwAdvise;
                int maxBufferTime;
                int maxSize;
                HRESULT criaConnectionPoint();
                queue<Buffer> *qbuffer;
                map<DWORD, AnsiString> *ptmapEC;
                map<DWORD, DWORD*> mapAttr;
                map<OPCHANDLE,string> *ptmapHandle;
                string nomeSub;
                DWORD setEvTypeFilter(ESTRUTURA *ptrStruct);
                void convertLPWSTRtoString(LPWSTR *lista, int tam, string *listaRetorno);

                string listaStringArea[MAX_LEN_SUB];
                string listaStringSource[MAX_LEN_SUB];
                string listaStringEvtCat[MAX_LEN_SUB];

                DWORD *listaAttributosEvtCat;
                

        public:
        
                string getNomeSub();
                OPCEventSubscription(OPCEventServer *ptServer, IConnectionPointContainer *ptES,int maxBufferSize, int maxTime, queue<Buffer> *qbuffer, map<DWORD, AnsiString> *ptmapECx, string nomeSub1);
                ~OPCEventSubscription();

                bool setarFiltro(ESTRUTURA *ptrStruct);
                bool getFiltro(Filtro *ptrStruct);
                bool selectReturnedAttr(DWORD *evtCat, DWORD qntEvtCat, DWORD *dwCount, DWORD dwAttr[][MAX_LEN_ATTRIBUTES]);

                int getEventCategoriesAttr(DWORD *listEvt);
                int getAttributes(DWORD evtCat, string *listAttributes);

                int getMaxBufferTime();
                int getMaxSize();

                bool release();
                bool refresh();

                bool getAtributosSelecionados(string evtCat, string attributes[][3], string listaDeSelecionados[][3]);

               


};

//---------------------------------------------------------------------------
#endif
