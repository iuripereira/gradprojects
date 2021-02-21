//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ThreadReadTCP.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall ThreadReadTCP::ThreadReadTCP(bool CreateSuspended, TForm1 *form): TThread(CreateSuspended){
    form1 = form;
}
//---------------------------------------------------------------------------

__fastcall ThreadReadTCP::~ThreadReadTCP(void){
}

//---------------------------------------------------------------------------

void __fastcall ThreadReadTCP::Execute(){

     while (!this->Terminated){

        form1->threadReadTCP();
        Sleep(200);

     }

}

//---------------------------------------------------------------------------


