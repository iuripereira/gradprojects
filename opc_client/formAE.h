//---------------------------------------------------------------------------

#ifndef formAEH
#define formAEH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "ConectaOPC.h"

#include "DialogCreateSubscription.h"
#include "DialogAtributos.h"
#include "DialogFilter.h"
#include "ProtocoloTCP.h"
#include "OPCEventServer.h"
#include "OPCBridge.h"
#include "Logger.h"
#include "XML.h"
#include "Buffer.h"
#include "ThreadView.h"
#include "ThreadSendTCP.h"
#include "ThreadConectaTCP.h"

#include "bibliotecas/defOPCSiga.h"

#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ScktComp.hpp>
#include <jpeg.hpp>
#include <Menus.hpp>
#include <msxmldom.hpp>
#include <XMLDoc.hpp>
#include <xmldom.hpp>
#include <XMLIntf.hpp>
#include <oxmldom.hpp>
#include <queue>
#include <iostream.h>

#include <map>
#include <winsock.h>
#include <stdio.h>
#include <io.h>
#include <process.h>
#include <stdlib.h>

#define MAX_LEN 2048
#define MAX_LINES 80
#define MAX_BUFFER_SIZE 500000

//---------------------------------------------------------------------------
class OPCBridge;
class OPCEventServer;
class ConectaOPC;
class XML;
class ProtocoloTCP;
class Buffer;
class ThreadView;
class ThreadSendTCP;
class ThreadConectaTCP;
class TForm1 : public TForm
{

__published:	// IDE-managed Components

        TListBox *ListBox1;
        TButton *ConectarBt;
        TButton *ListBt;
        TListView *ListView1;
        TTreeView *tv1;
        TPanel *Panel1;
        TButton *subscriptionButton;
        TPanel *Panel2;
        TLabel *Label4;
        TEdit *tcpPorta;
        TButton *btLigaServidorTCP;
        TImage *Image1;
        TImage *Image2;
        TButton *ListRemoteBt;
        TEdit *campoIp;
        TLabel *Label1;
        TEdit *host;
        TLabel *Label2;
        TClientSocket *clienteTCP;
        TButton *disconnectSocketBt;
        TButton *FiltroBt;
        TButton *disconectButton;
        TButton *remSubBt;
        TButton *ClearBt;
        TXMLDocument *XMLDocument1;
        TMainMenu *MainMenu1;
        TMenuItem *Filte1;
        TMenuItem *SalvarConfiguraes1;
        TButton *btVisualizar;
        TMemo *MemoLog;
        TLabel *Label5;
        TEdit *Edit1;
        TTimer *Timer1;
    TTimer *InitSystem;
    TButton *attributosBT;

        void __fastcall ListBtClick(TObject *Sender);
        void __fastcall ConectarBtClick(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall tv1Change(TObject *Sender, TTreeNode *Node);
        void __fastcall subscriptionButtonClick(TObject *Sender);
        void __fastcall btLigaServidorTCPClick(TObject *Sender);
        void __fastcall ListRemoteBtClick(TObject *Sender);
        void __fastcall clienteTCPConnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall clienteTCPDisconnect(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall clienteTCPError(TObject *Sender,
          TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
        void __fastcall clienteTCPConnecting(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall disconnectSocketBtClick(TObject *Sender);
        void __fastcall remSubBtClick(TObject *Sender);
        void __fastcall ClearBtClick(TObject *Sender);
        void __fastcall disconectButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FiltroBtClick(TObject *Sender);
        void __fastcall SalvarConfiguraes1Click(TObject *Sender);
        void __fastcall btVisualizarClick(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
    void __fastcall InitSystemTimer(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall attributosBTClick(TObject *Sender);

private:

        void addLinhaListView(Buffer b);
        void clearProgId(string *clString);
        void preencheListBox1(string *lista);
        string getHostCompleto(bool local, string host);
        void adicionarServerListTree(string server, string host);
        void adicionarSubscriptionListTree(string server, string host, string nomeSubscrition);
        bool conectarServidor(bool local,string server,string host);
        bool disconnectServidor(OPCEventServer *ES);
        void secarBuffer(queue<Buffer> *buffer);
        void listaServidores(bool local, string host);
        bool deleteServerInterface(string host, string server);
        bool existSubscrption(string server, string host, string nome);
        void addAreaFilter(Filter& filter, ESTRUTURA& ptr, LPWSTR* listaArea);
        void addSourceFilter(Filter& filter, ESTRUTURA& ptr, LPWSTR* listaSrc);
        void addEventFilter(Filter& filter, ESTRUTURA& ptr, string* listaEvCat, DWORD *listaDwd);
        void configFilter(Subscription& opcsub, string server, string hostcompleto);
        void configSubscription(OPCServer& opcserver, string hostcompleto, string server);
        void configAttributes(list<EventCategory> evtCat, string hostcompleto, string server, string sub);
        bool checkRede(string host, string server, bool flagLocal);
        bool forceDisconect(OPCEventServer *ES);
        void configServer(XML* reader);
        void conectaTCP(int portaTCP, string hostTCP);
        void init();


        string serverName;
        string hostName;

        bool visualizaDados;

        ConectaOPC *myConection;
        queue<Buffer> qbuffer, qSendBuffer; //estrutura dinamica
        Semaforo sem;
        Semaforo sem1;
        map<string, OPCEventServer *> mapES;

        ThreadView *threadViewPtr;
        ThreadSendTCP *threadSendPtr;
        ThreadConectaTCP *threadConectaTCPPtr;

        ProtocoloTCP protocolo;

        string progIds[MAX_LEN];
        Logger logger;
        bool flagLocal;
        bool bufferCheio;
        struct hostent *nome_da_maquina;
        struct hostent *ip_da_maquina;
        struct in_addr addr;


public:
        __fastcall TForm1(TComponent* Owner);
        bool disconect(string host, string server);
        void callSubscription(string host, string server, string nome,int buffer,int maxSize);
        bool callFilter(ESTRUTURA *ptr);
        void addMsgLog(string msg);

        bool browseAreas(string server, string host, string *lista);
        bool browseSource(string server, string host, string *lista);
        bool changeAreaDown(string server, string host,string passou);
        bool changeAreaTo(string server, string host, string passou);
        bool changeAreaUp(string server, string host);

        static string getPathApplication();

        void threadCheckServer();
        void threadView();
        void threadSendTCP();
        void threadReadTCP();
        void threadConectaTCP();

        bool getflagLocal();

        OPCEventServer *getPtOPCEventServer(string server, string host);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
