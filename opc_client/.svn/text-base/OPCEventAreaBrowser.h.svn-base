//---------------------------------------------------------------------------

#ifndef OPCEventAreaBrowserH
#define OPCEventAreaBrowserH

#include "bibliotecas/opc_ae.h"
#include "Logger.h"

#include <System.hpp>

#include <iostream.h>

class OPCEventAreaBrowser{

        private:
                IOPCEventAreaBrowser *ptrAB;
                OPCAEBROWSETYPE dwBrowseFilterType;

                LPWSTR __RPC_FAR *pszAreaList;
                LPWSTR __RPC_FAR *pszSourceList;

                Logger logger;

        public:
                OPCEventAreaBrowser(IOPCEventAreaBrowser *ptrTemp);
                ~OPCEventAreaBrowser();

                bool getAreaName(string, LPWSTR*);
                bool getSourceName(string, LPWSTR*);

                bool browseOPCAreas(string *lista);
                bool browseOPCSource(string *lista);

                bool changeBrowseUp();
                bool changeBrowseDown(string);
                bool changeBrowseTo(string);

};

//---------------------------------------------------------------------------
#endif
