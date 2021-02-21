//---------------------------------------------------------------------------

#ifndef OPCShutDownH
#define OPCShutDownH

#include "bibliotecas/opccomn.h"
#include "bibliotecas/opc_ae.h"

#include "OPCEventServer.h"
#include "Logger.h"

class OPCEventServer;
class OPCShutDown : public IOPCShutdown
{
        private:
                ULONG m_cRef;
                OPCEventServer *ptrES;
                Logger logger;

        public:

                OPCShutDown();
                OPCShutDown(OPCEventServer*);
                ~OPCShutDown();

                STDMETHODIMP ShutdownRequest(/* [string][in] */ LPCWSTR szReason);

                STDMETHODIMP QueryInterface(REFIID, void**);
                
                STDMETHODIMP_(ULONG) AddRef(void);
                STDMETHODIMP_(ULONG) Release(void);

};

//---------------------------------------------------------------------------
#endif
