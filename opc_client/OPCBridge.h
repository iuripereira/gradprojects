//---------------------------------------------------------------------------

#ifndef OPCBridgeH
#define OPCBridgeH

#include "formAE.h"
//#include "OPCEventServer.h"

class TForm1;
class OPCBridge{
        private:
                TForm1 *form;
                OPCEventServer *es;

        public:
                bool disconectAndDeleteInterface(string host, string server);        
                OPCBridge(TForm1 *f);
                ~OPCBridge();
                void setPtrEventServer(OPCEventServer *EventServer);

};

//---------------------------------------------------------------------------
#endif
