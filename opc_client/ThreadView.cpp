//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ThreadView.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall ThreadView::ThreadView(bool CreateSuspended, TForm1 *form): TThread(CreateSuspended){
    form1 = form;
}
//---------------------------------------------------------------------------

__fastcall ThreadView::~ThreadView(void){
}

//---------------------------------------------------------------------------

void __fastcall ThreadView::Execute(){

     while (!this->Terminated){

        form1->threadView();
        Sleep(17);

     }

}



//---------------------------------------------------------------------------


