//---------------------------------------------------------------------------

#ifndef ConectaOPCH
#define ConectaOPCH

#include "objbase.h"
#include "winbase.h"

#include <map>
#include <iostream.h>

#include "OPCEventServer.h"

#include "bibliotecas/opcEnum.h"
#include "bibliotecas/opccomn.h"
#include "Logger.h"

class OPCEventServer;
class ConectaOPC
{
        private:
                CLSID clsid;
                bool connected;
                bool status;
                IOPCServerList *ipOPCServerList;
                COSERVERINFO *pServerInfo;
                COSERVERINFO* pServerInfo2;
                IEnumGUID *ipEnumGuid;
                IOPCEventServer *ptr_temp;
                map<string, CLSID> mapClsidRemoto;
                void clearMapa(map<string,CLSID> mapa);
                Logger logger;

        public:
                ConectaOPC();
                ~ConectaOPC();
                bool getProgId(CLSID, LPOLESTR*); //from CLSID
                bool getCLSID(string, CLSID*); //from progID
                bool connectAEServer(bool local, string hostName, CLSID clsid, OPCEventServer *ptrOPCEventServer);
                bool testeConnection(bool local, string hostName, CLSID clsid);
                void listaOpcLocal(string *lista);
                bool listaOpcByRergistro(bool local, string *listarm, string hostname);
                bool listaOpc(bool local, string *, string hostname);
                CLSID getCLSID(string progID);
                bool startCom();
                bool getStatusCom();
                void stopCom();
};
//---------------------------------------------------------------------------
#endif
