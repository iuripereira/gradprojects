//---------------------------------------------------------------------------
#include "Unt_Principal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TBRAlarm_OPCAE *BRAlarm_OPCAE;
//---------------------------------------------------------------------------
__fastcall TBRAlarm_OPCAE::TBRAlarm_OPCAE(TComponent* Owner)
	: TService(Owner)
{
}

TServiceController __fastcall TBRAlarm_OPCAE::GetServiceController(void)
{
	return (TServiceController) ServiceController;
}

void __stdcall ServiceController(unsigned CtrlCode)
{
	BRAlarm_OPCAE->Controller(CtrlCode);
}
//---------------------------------------------------------------------------

void writeLogFile(String pathLog, string msg){

    FILE *txt;

    time_t lt = time(NULL);
    string a = asctime(localtime(&lt));

    if((txt = fopen((pathLog).c_str(), "a+")) == NULL){
        perror("Falha ao criar o arquivo de LOG");
    }else{
        fprintf(txt,"%s - ",a.substr(0,a.length()-1));
        fprintf(txt,"%s\n",msg);
        fclose(txt);
    }

}







void __fastcall TBRAlarm_OPCAE::ServiceExecute(TService *Sender)
{

    Sleep(5000);

    AnsiString path = ExtractFilePath(GetCommandLineA());
    path = path.SubString(0,path.Length()-1);
    AnsiString  pathBase = path.SubString(2,path.Length());

    AnsiString aspas = '"';
    AnsiString espaco = ' ';

    AnsiString comand = "java -jar -Xmx600m -Xrs ";

    AnsiString pastaColetor = "\\ServerSocket";
    AnsiString fileName = "\\ColetorServerSocket.jar";
    AnsiString fileNameOPC =  "\\Coletor OPC AE\\clienteAE.exe";

    AnsiString pathOPC =  path+fileNameOPC;

    AnsiString paramServico = "servico";

    pathLog = path + "\\Logs";

    pathLog = "D:\\BR-AlarmExpert\\Logs";

    MkDir(pathLog.c_str());

    fileNameLOG = "\\LOGServicoScheduler.log";

    AnsiString comando = comand+aspas+path+pastaColetor+fileName+aspas+espaco+aspas+path+pastaColetor+aspas+espaco+paramServico;

    writeLogFile((pathLog+fileNameLOG).c_str(),"**************************************************\n");
    writeLogFile((pathLog+fileNameLOG).c_str(),("Path Base: "+pathBase).c_str());
    writeLogFile((pathLog+fileNameLOG).c_str(),"Executando a inicialização do Coletor e do OPC...");
    writeLogFile((pathLog+fileNameLOG).c_str(), ("Path OPC: "+pathOPC).c_str());
    writeLogFile((pathLog+fileNameLOG).c_str(), ("Comando Coletor: "+(comando)).c_str());


    int qntMax = 20;
    int contTemp = 1;
    bool sucessoInitOPC = false;
    bool sucessoInitJAVA = false;

    int p1 = 0 ,p2 = 0;


    while(!sucessoInitOPC && contTemp <= qntMax){

        p1 = WinExec(pathOPC.c_str(),SW_SHOWNORMAL);

        if (p1 > 31){
                sucessoInitOPC = true;
        }else{

                writeLogFile((pathLog+fileNameLOG).c_str(), "Falha ao tentar iniciar o OPC. Irá dormir por 5s e tentar novamente.");
                Sleep(5000);
        }

        contTemp++;

    }

    contTemp = 1;

    while(!sucessoInitJAVA && contTemp <= qntMax){

        p2 = WinExec((comando).c_str(),SW_SHOWNORMAL);

        if (p2 > 31){
                sucessoInitJAVA = true;
        }else{

                writeLogFile((pathLog+fileNameLOG).c_str(), "Falha ao tentar iniciar o Java. Irá dormir por 5s e tentar novamente.");
                Sleep(5000);
        }

        contTemp++;

    }
    

    if(p1>31 && p2>31){
        writeLogFile((pathLog+fileNameLOG).c_str(), "Sucesso na inicialização do serviço!");

         while (!Terminated){
           ServiceThread->ProcessRequests(true);
        }
     }else{
        writeLogFile((pathLog+fileNameLOG).c_str(), "Falha ao tentar iniciar o OPC ou o Coletor");


     }


}
//---------------------------------------------------------------------------
void __fastcall TBRAlarm_OPCAE::ServiceStop(TService *Sender,
      bool &Stopped){

 HANDLE app;

 writeLogFile((pathLog+fileNameLOG).c_str(), "Parando o Serviço...");

 app = FindWindow(NULL,"ClienteAE");
 int retorno = 0;

 if(app!=NULL){
    retorno = PostMessage(app, WM_CLOSE, 0, 0);
    if (retorno != 0){
        writeLogFile((pathLog+fileNameLOG).c_str(), "Sucesso ao fechar o clienteAE.exe");
    }else{
        writeLogFile((pathLog+fileNameLOG).c_str(), "Falha ao fechar o clienteAE.exe");
    }
 }else{
        writeLogFile((pathLog+fileNameLOG).c_str(), "Janela ClienteAE.exe não foi encontrada");
 }

 app = FindWindow(NULL,"BRTCP");

 if (app == NULL){
  app = FindWindow(NULL,"BRAlarmExpert");
 }

 if(app!=NULL){
    retorno = PostMessage(app, WM_CLOSE, 0, 0);
    if (retorno != 0){
        writeLogFile((pathLog+fileNameLOG).c_str(), "Sucesso ao fechar o ColetorServerSocket");
    }else{
        writeLogFile((pathLog+fileNameLOG).c_str(), "Falha ao fechar o ColetorServerSocket");
    }
 }else{
        writeLogFile((pathLog+fileNameLOG).c_str(), "Janela ColetorServerSocket não foi encontrada");
 }


}
//---------------------------------------------------------------------------


















