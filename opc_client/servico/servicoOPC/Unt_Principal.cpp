//---------------------------------------------------------------------------
#include "Unt_Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TOPCAE *OPCAE;
//---------------------------------------------------------------------------
__fastcall TOPCAE::TOPCAE(TComponent* Owner)
	: TService(Owner)
{
}

TServiceController __fastcall TOPCAE::GetServiceController(void)
{
	return (TServiceController) ServiceController;
}

void __stdcall ServiceController(unsigned CtrlCode)
{
	OPCAE->Controller(CtrlCode);
}
//---------------------------------------------------------------------------

void __fastcall TOPCAE::ServiceExecute(TService *Sender)
{
 if(WinExec("clienteAE.exe",SW_SHOWNORMAL)>31)
     while (!Terminated)
       ServiceThread->ProcessRequests(true);        
}
//---------------------------------------------------------------------------
void __fastcall TOPCAE::ServiceStop(TService *Sender,
      bool &Stopped)
{
 HANDLE app;

 app = FindWindow(NULL,"ClienteAE");
 if(app!=NULL)
    PostMessage(app, WM_CLOSE, 0, 0);
}
//---------------------------------------------------------------------------








