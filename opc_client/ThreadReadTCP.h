//---------------------------------------------------------------------------

#ifndef ThreadReadTCPH
#define ThreadReadTCPH
#include <vcl.h>
#include "formAE.h"

class TForm1;
class ThreadReadTCP: public TThread {

    private:

        TForm1 *form1;
        
    public:

        __fastcall ThreadReadTCP(bool CreateSuspended, TForm1 *form);
        __fastcall ~ThreadReadTCP(void);
        void __fastcall Execute();
};


//---------------------------------------------------------------------------
#endif
