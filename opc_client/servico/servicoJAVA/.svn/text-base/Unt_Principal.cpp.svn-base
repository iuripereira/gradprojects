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

    AnsiString path = ExtractFilePath(GetCommandLineA());

    AnsiString aspas = '"';
    AnsiString espaco = ' ';

    AnsiString comand = "java -jar ";
    AnsiString fileName = "\ColetorServerSocket.jar";


    FILE *txt;
    if((txt = fopen("C:\\LOGServico.txt", "a+")) == NULL){
        perror("Descricao do erro");
        exit(1);
    }
    fprintf(txt, "%s\n", (comand+path+fileName+aspas+espaco+path).c_str());//imprime o nome, e o caracter de nova linha \n para o arquivo

    //fecha arquivo
    fclose(txt);
    


    if(WinExec((comand+path+fileName+aspas+espaco+path).c_str(),SW_SHOWNORMAL)>31);
     while (!Terminated)
       ServiceThread->ProcessRequests(true);        
}
//---------------------------------------------------------------------------
void __fastcall TOPCAE::ServiceStop(TService *Sender,
      bool &Stopped)
{
 HANDLE app;

 app = FindWindow(NULL,"BRTCP");
 if(app!=NULL)
    PostMessage(app, WM_CLOSE, 0, 0);
}
//---------------------------------------------------------------------------











