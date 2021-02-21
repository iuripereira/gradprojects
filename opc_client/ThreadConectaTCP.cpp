//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "ThreadConectaTCP.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
__fastcall ThreadConectaTCP::ThreadConectaTCP(bool CreateSuspended, TForm1 *form): TThread(CreateSuspended){
    form1 = form;
}
//---------------------------------------------------------------------------

//__fastcall ThreadConectaTCP::~ThreadConectaTCP(void){}

//---------------------------------------------------------------------------

void __fastcall ThreadConectaTCP::Execute(){

     int cont = 0;

     while (!this->Terminated){
        //form1->addMsgLog("vai dormir 500");
        Sleep(500);
        //form1->addMsgLog("acordou");
        if (cont++ == 50){

            //form1->addMsgLog("vai chamar conexao TCP");
            form1->threadConectaTCP();
            cont = 0;
        }


     }

}



//---------------------------------------------------------------------------


