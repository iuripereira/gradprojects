//---------------------------------------------------------------------------

#ifndef OPCEventSinkH
#define OPCEventSinkH

#include "System.hpp"
#include <stdlib.h>
#include <sstream.h>

#include "bibliotecas/opc_ae.h"
#include "bibliotecas/opcaedef.h"
#include <queue>
#include "Buffer.h"
#include "Logger.h"
#include "semaforo.h"
#include <map>

#include "OPCEventSubscription.h"
#include "OPCEventServer.h"

//--------------------------------------------------------------------------------//
//EventSink
//--------------------------------------------------------------------------------//
class OPCEventSubscription;
class OPCEventServer;
class OPCEventSink : public IOPCEventSink
{

private:

        FILETIME        ftLocal;
        FILETIME        activeftLocal;        
        SYSTEMTIME      stTimeStamp;
        Semaforo        sem;

        string          lpszString;
        string          qld;
        string          szMsg;
        string          szSrc;
        string          changeMask;
        string          newState;
        string          evType;
        string          evCategory;
        string          severity;
        string          conditionName;
        string          subConditionName;
        bool            ackRequired;
        string          ackRequiredStr;
        string          actorID;

        VARIANT vb;

        OPCEventSubscription *opcEventSub;
        OPCEventServer *opcEventServer;

        queue<Buffer> *qbuffer;
        map<DWORD, AnsiString> *ptmapEC;
        map<OPCHANDLE, string> *ptmapHandle;

        map<DWORD, string> ptSubCondition;
        Logger logger;
        string processChangeMask(WORD mask);
        string processNewState(WORD state);
        string convert(VARIANT x);
        void populaLista(string *list, int qntAttr, VARIANT *tag);
        

public:

OPCEventSink();
OPCEventSink(queue<Buffer> *qbuffer, map<DWORD, AnsiString> *ptmapECx, OPCEventSubscription *opcSub, OPCEventServer *opcES);

~OPCEventSink(void);

STDMETHODIMP QueryInterface(REFIID, void**);
STDMETHODIMP_(ULONG) AddRef(void);
STDMETHODIMP_(ULONG) Release(void);

STDMETHODIMP OnEvent(
        /* [in] */ OPCHANDLE hClientSubscription,
        /* [in] */ BOOL bRefresh,
        /* [in] */ BOOL bLastRefresh,
        /* [in] */ DWORD dwCount,
        /* [size_is][in] */ ONEVENTSTRUCT __RPC_FAR *pEvents);

protected:
        ULONG m_cRef;

};


#endif
