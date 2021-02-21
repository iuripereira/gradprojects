//---------------------------------------------------------------------------

#ifndef ThreadSendTCPH
#define ThreadSendTCPH
#include <vcl.h>
#include "formAE.h"

class TForm1;
class ThreadSendTCP: public TThread {

    private:

        TForm1 *form1;
        
    public:

        __fastcall ThreadSendTCP(bool CreateSuspended, TForm1 *form);
        __fastcall ~ThreadSendTCP(void);
        void __fastcall Execute();
};


//---------------------------------------------------------------------------
#endif
