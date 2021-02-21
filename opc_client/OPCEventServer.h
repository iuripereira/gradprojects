//---------------------------------------------------------------------------

#ifndef OPCEventServerH
#define OPCEventServerH

#include "bibliotecas/opc_ae.h"
#include "bibliotecas/opccomn.h"
#include "bibliotecas/opc_ae_i.c"
#include "bibliotecas/opcaedef.h"

#include <stdlib.h>

#include "OPCEventAreaBrowser.h"
#include "OPCEventSubscription.h"
#include "OPCShutDown.h"
#include "OPCBridge.h"
#include "Logger.h"

#include <queue>
#include "Buffer.h"

#include <map>

class OPCBridge;
class OPCShutDown;
class OPCEventSubscription;
class OPCEventServer
{
        private:

                IConnectionPoint *ptrCP;
                IOPCEventServer *ptrEventServer;
                IUnknown *myIUnknownShutdown;
                OPCBridge *opcBridge;
                OPCEventAreaBrowser *opcABrowser;
                OPCEVENTSERVERSTATUS *opcStatus;

                //QueryEventCategory
                DWORD countEventCategory;
                DWORD *ptEventCategories;

                bool filterByEvent;
                bool filterByCategory;
                bool filterBySeverity;
                bool filterByArea;
                bool filterBySorce;

                bool permiteBrowseArea;

                unsigned long m_dwAdvise;

                OPCHANDLE subHandle;
                queue<Buffer> *qbuffer;
                map<DWORD, AnsiString> mapEC;

                map<DWORD, AnsiString> mapAttrDesc;
                map<DWORD, VARTYPE> mapAttrTypes;

                map<OPCHANDLE,string> sbHand;
                map<string, OPCEventSubscription*> mapSub;
                string nameServer;
                string hostServer;

                Logger logger;

                bool QueryAvaibleFilters();


        public:

                const static int INVALIDBUFFERTIME = 1;
                const static int INVALIDMAXSIZE = 2;
                const static int FALHA = 3;
                const static int INTERFACE_N_SUPORTADA = 4;
                const static int OUTOFMEMORY = 5;
                const static int SUCESSO = 0;

                OPCEventServer(queue<Buffer> *qb, string nameServer, string hostServer, OPCBridge *bridge);
                ~OPCEventServer();

                OPCEventSubscription* getEvSub(string nome);

                //Funcoes para acessar as variaveis q sao setadas no QueryEventCategory pra depois setá-las na ESTRUTURA do filtro
                DWORD getCountEvCat();
                void getPtEvCat(string *lista, int tam, DWORD *selectedCategory);
                void getEvCat(DWORD *evCat, int tam, string *listRetorno);
                bool getStatus();

                int createEventSubscription(bool,int,int,string,string,string);


                bool QueryEventCategory();
                bool disconnectEventSubscription(string chave);
                bool disconnectAllEventSubscriptions();
                bool existeSubscription(string chave);
                bool release();

                bool isAvaibleFilterByEvent();
                bool isAvaibleFilterByCategory();
                bool isAvaibleFilterBySeverity();
                bool isAvaibleFilterByArea();
                bool isAvaibleFilterBySorce();

                bool isAllowedBrowseArea();

                string getNameServer();
                string getHostServer();

                bool getQualifiedAreaName();
                bool getQualifiedSourceName();

                void setNameServer(string ns);
                void setHostServer(string hs);
                void setPtrEventServer(IOPCEventServer *);
                bool disconect();
                void convertStringToFILETIME(char* str, FILETIME &ft);
                HRESULT criaConnectionPoint();
                OPCEventAreaBrowser *getAreaBrowser();
                bool getEventCategoryList(string *lista);
                bool createAreaBrowser();
                map<string, OPCEventSubscription*>* getSubscritions();
                bool AckCondition(string coment, string ator, string source, string condition, FILETIME activeTime, DWORD cookie );

                bool QueryEventAttributes(string eventCategory);
                DWORD getEventCategory(string eventCategory);

                bool getAttributes(string eventCategory, string attributes[][3]);

                string convertVarType(VARTYPE v);



};

//---------------------------------------------------------------------------
#endif
