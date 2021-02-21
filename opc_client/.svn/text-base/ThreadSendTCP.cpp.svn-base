//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ThreadSendTCP.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall ThreadSendTCP::ThreadSendTCP(bool CreateSuspended, TForm1 *form): TThread(CreateSuspended){
    form1 = form;
}
//---------------------------------------------------------------------------

__fastcall ThreadSendTCP::~ThreadSendTCP(void){}

//---------------------------------------------------------------------------

void __fastcall ThreadSendTCP::Execute(){

     while (!this->Terminated){

        form1->threadSendTCP();
        Sleep(125);

     }

     form1->threadSendTCP();

}

//---------------------------------------------------------------------------


