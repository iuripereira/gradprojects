//---------------------------------------------------------------------------

#ifndef ThreadViewH
#define ThreadViewH
#include <vcl.h>
#include "formAE.h"

class TForm1;
class ThreadView: public TThread {

    private:

        TForm1 *form1;

    public:

        __fastcall ThreadView(bool CreateSuspended, TForm1 *form);
        __fastcall ~ThreadView(void);
        void __fastcall Execute();
};


//---------------------------------------------------------------------------
#endif
