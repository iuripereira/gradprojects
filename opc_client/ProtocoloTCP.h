//---------------------------------------------------------------------------
#ifndef ProtocoloTCPH
#define ProtocoloTCPH
#include <sstream.h>

#include "Buffer.h"

class ProtocoloTCP  {

        public:
                ProtocoloTCP();
                ~ProtocoloTCP();
                AnsiString geraProtocol(Buffer *buf);
        private:
            string boolToString(bool value);
            string intToString(int value);

};

//---------------------------------------------------------------------------
#endif
