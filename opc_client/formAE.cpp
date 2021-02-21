//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "formAE.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
int countEnbixas;
bool controleWatchDog;
int qntSemMensagem = 0;

static string XML_FILENAME= "XML\\opcconfig.xml";

//---------------------------------------------------------------------------

__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner){

        bufferCheio = false;
        visualizaDados = false;
        myConection =  new ConectaOPC();
        countEnbixas = 0;
        nome_da_maquina = NULL;
        ip_da_maquina = NULL;
        controleWatchDog = true;
        
}

string TForm1::getPathApplication(){

    static string path = Application->ExeName.c_str();
    static char pathChar[350];
    path.copy(pathChar,path.length(),0);
    path = strupr(pathChar);

    static int l1 = path.rfind(".EXE");
    static int l2 = path.rfind("\\");

    if (l1 != -1 && l2 != -1){
        path = path.substr(0,l2+1);
        return path;
    }

    return "";
}

//---------------------------------------------------------------------------


/*
*  Método Responsável por capturar o click do botão
*  e listar os servidores localmente disponíveis
*  na lista da interface
*/
void __fastcall TForm1::ListBtClick(TObject *Sender)
{
        flagLocal = true;
        string host = "";
        listaServidores(flagLocal,host);


}
/*
*  Método Responsável por capturar o click do botão
*  e listar os servidores remotamente disponíveis
*  na lista da interface
*/
void __fastcall TForm1::ListRemoteBtClick(TObject *Sender)
{
     flagLocal = false;

     string host = campoIp->Text.c_str();

     if(host == ""){
        logger.addLinhaLog("Tentativa de listagem remota com ip ou nome da máquina vazio");
        addMsgLog("Tentativa de listagem remota com ip ou nome da máquina vazio");
        //MessageBox(HWND_DESKTOP,"Erro na conexão! Servidor remoto inválido","ERRO",MB_OK);
     }else{
         listaServidores(flagLocal,host);
     }

}
/*
* Método que recebe a lista de servidores e coloca na interface
*/
void TForm1::listaServidores(bool local, string host){


        clearProgId(progIds);

        bool retorno;


        retorno = myConection->listaOpc(local,progIds,host);


        if (retorno && progIds != NULL){
                preencheListBox1(progIds);
                ConectarBt->Enabled = false;
                logger.addLinhaLog("Listou servidores Host " + host);
        }else{
            addMsgLog("Falha ao listar os servidores disponíveis");
        }
}

/*
* Método para preencher o listBox1 da interface
*/
void TForm1::preencheListBox1(string *lista){
        int i=0;
        ListBox1->Items->Clear();
        while (!lista[i].empty()){
                ListBox1->Items->Add(lista[i++].c_str());
        }
}
/*
* Retorna o host completo, ou seja:
* nome da maquina [IP]
*/
string TForm1::getHostCompleto(bool local, string host){

        std::string nome;
        std::string hostcompleto;
        std::string ip;

        if(local){

                hostcompleto = "localhost [127.0.0.1]";

        }else{
                nome_da_maquina = gethostbyname(host.c_str()); //pega o que foi digitado e traz o nome da maquina
                if(nome_da_maquina != NULL){
                        unsigned int addr = inet_addr(inet_ntoa(*(struct in_addr*)nome_da_maquina->h_addr)); //passa o ip para o nome da maquina real
                        ip_da_maquina = gethostbyaddr(reinterpret_cast<char *>(&addr), 4, AF_INET); //transforma o numero ip para a struct ip_da_maquina para que possa ser escrita

                        if(ip_da_maquina != NULL){
                                ip = inet_ntoa(*(struct in_addr*)ip_da_maquina->h_addr);
                                nome = ip_da_maquina->h_name;
                                hostcompleto = nome+" ["+ip+"]";
                        }
                }
        }

        return hostcompleto;
}



/*
* Conecta a um servidor local ou remoto.
*  Insere na árvore caso sucesso
*/
bool TForm1::conectarServidor(bool local, string server, string host){

        bool con;
        CLSID clsid;

        string hostcompleto = getHostCompleto(local, host);

        OPCBridge *bridge =  new OPCBridge(this);
        OPCEventServer *myES =  new OPCEventServer(&qbuffer,server,hostcompleto,bridge);

        clsid = myConection->getCLSID(server);
        con = myConection->connectAEServer(local,host,clsid,myES);

        if(con != true){

                logger.addLinhaLog("Erro na tentativa de se conectar ao servidor "+server+host);
                addMsgLog("Erro na tentativa de se conectar ao servidor "+server+host);
                //MessageBox(HWND_DESKTOP, "ERRO NA CONEXÃO!","ERRO",MB_OK);
                delete myES;
                return false;

        }else{
                // log
                if(local){
                        logger.addLinhaLog("Conectou Local "+host+" - "+server);
                }else{
                        logger.addLinhaLog("Conectou Remoto "+host+" - "+server);
                }

                string hostServer = hostcompleto+server;

                //insere o string do servidor e o ponteiro para OPCEventServer no mapa
                map<string, OPCEventServer *>::iterator iter = mapES.find(hostServer);

                if(iter == mapES.end()){
                        mapES.insert(pair<string, OPCEventServer *>(hostServer,myES));
                }else{
                        logger.addLinhaLog("Erro ao tentar se conectar a um servidor --> Servidor já em conexão.");
                        addMsgLog("Erro ao tentar se conectar a um servidor --> Servidor já em conexão.");
                        //MessageBox(HWND_DESKTOP,"Servidor já está conectado!","ERRO",MB_OK);
                        return false;
                }
        }
        
        return true;
}
/*
* Método privado para inserir um determinado host e server
* na árvore de visualização (Interface).
*/
void TForm1::adicionarServerListTree(string server, string host){

        TTreeNode *root;
        TTreeNode *no;

        if (tv1 == NULL || server == "" || host == ""){
                logger.addLinhaLog("Falha ao tentar adicionar os seguintes ítens na árvore: "+host+" e "+server);
                return;
        }

        if(tv1->Items->Count == 0){

                tv1->Items->Add(NULL, host.c_str());
                root = tv1->Items->Item[0];
                tv1->Items->AddChild(root, server.c_str());
                root->Expand(true);

        }else{
                bool test = false;
                for(int i=0; i<tv1->Items->Count; i++){
                        if(tv1->Items->Item[i]->Level == 0){
                                if(tv1->Items->Item[i]->Text == host.c_str()){
                                        if(tv1->Items->Item[i]->HasChildren){
                                                no = tv1->Items->Item[i]->GetLastChild();
                                                tv1->Items->AddChild(no->Parent, server.c_str());
                                                test = false;
                                                break;
                                        }else{
                                                tv1->Items->AddChild(tv1->Items->Item[i], server.c_str());
                                                test = false;
                                                break;
                                        }
                                }else{
                                        test = true;
                                }
                        }
                }
                if (test) {
                        tv1->Items->Add(NULL, host.c_str());
                        root = tv1->Items->Item[tv1->Items->Count - 1];
                        tv1->Items->AddChild(root, server.c_str());
                        root->Expand(true);
                }
        }
}
/*
* Método privado para inserir um determinada subscription
* na árvore de visualização (Interface).
*/
void TForm1::adicionarSubscriptionListTree(string server, string host, string nomeSubscrition){

       int index = -1;

       if(tv1->Items->Count >= 0){

                for(int i=0; i<tv1->Items->Count; i++){

                        if(tv1->Items->Item[i]->Level == 1){

                                if (tv1->Items->Item[i]->Parent->Text.c_str() == host && tv1->Items->Item[i]->Text.c_str() == server){
                                        index=i;
                                        break;
                                }
                        }

                }

       }

       if (index == -1){
                return;
       }

       tv1->Items->AddChild(tv1->Items->Item[index], nomeSubscrition.c_str());
       tv1->Items->Item[index]->Expand(true);
       ClearBt->Enabled = true;

}

/*
* Evento de clique no botão de conectar da interface.
* Ao clicar esse botão tentará se fazer a conexão local ou remota
* caso a conexão seja bem sucedida insere na árvore da interface
* o servidor e host da conexão.
*/
void __fastcall TForm1::ConectarBtClick(TObject *Sender){

        string server = ListBox1->Items->Strings[ListBox1->ItemIndex].c_str();
        string host =  campoIp->Text.c_str();
        string hostcompleto = getHostCompleto(flagLocal,host);

        bool result = conectarServidor(flagLocal,server,host);

        if (result){
                adicionarServerListTree(server,hostcompleto);
                ListBox1->Items->Clear();
                ConectarBt->Enabled = false;
        }
}

/*
* Este método tenta criar uma event subscription com os parâmetros digitados
* pelo usuário. Ele é Chamado pelo Dialog de inserção dos parâmetros.
*/
void TForm1::callSubscription(string host, string server, string nome, int buffer, int maxSize){

        OPCEventServer *servidor = NULL;
        string chaveSub = nome+server+host;

        map<string, OPCEventServer *>::iterator buscaES = mapES.find(host+server);

        if (buscaES != mapES.end()){
            servidor = buscaES->second;
        }

        if(servidor == NULL){

                logger.addLinhaLog("Falha ao tentar criar EventSubscription --> server is NULL");
                addMsgLog("Falha ao tentar criar EventSubscription --> server is NULL");
                //MessageBox(HWND_DESKTOP,"Falha ao tentar criar EventSubscription!","ERRO",MB_OK);
                return;

        }else{

                int retornoSub;

                if (!existSubscrption(server,host,nome)){

                        retornoSub = servidor->createEventSubscription(true, (DWORD)buffer, (DWORD)maxSize, nome, server, host);

                        if (retornoSub == servidor->SUCESSO || (retornoSub == servidor->INVALIDBUFFERTIME || retornoSub == servidor->INVALIDMAXSIZE)){

                                if (servidor->existeSubscription(chaveSub)){
                                        adicionarSubscriptionListTree(server, host, nome);
                                        addMsgLog("Sucesso ao criar a Subscription "+nome+" no "+host+" - "+server);
                                        if (retornoSub == servidor->INVALIDBUFFERTIME){
                                                addMsgLog("Subscription criada, porém o buffer time solicitado é diferente do buffer time revisado.");
                                        }else if (retornoSub == servidor->INVALIDMAXSIZE){
                                                addMsgLog("Subscription criada, porém o max time time solicitado é diferente do max size revisado.");
                                        }

                                }else{
                                        addMsgLog("Erro ao criar Subscription. Subscription já existente --> "+nome+" no "+host+" - "+server);
                                }

                        }else{
                                addMsgLog("Falha ao criar a subscription. Consulte o LOG para mais detalhes");
                        }

                }else{
                        logger.addLinhaLog("Falha ao tentar criar a seguinte EventSubscription: "+nome+". Subscription já existente");
                        addMsgLog("Falha ao tentar criar a seguinte EventSubscription: "+nome+". Subscription já existente");
                }

        }
}

/* Método privado que verifica se uma mesma subscription já existe */
bool TForm1::existSubscrption(string server, string host, string nome){
        string no,pai,vo;
        TTreeNode *node;
        for (int i=0;i<tv1->Items->Count;i++){

                node = tv1->Items->Item[i];

                if (node->Level == 2){

                        vo = node->Parent->Parent->Text.c_str();
                        pai = node->Parent->Text.c_str();
                        no = node->Text.c_str();

                        if (vo==host && server == pai && nome == no){
                                return true;
                        }
                }

        }
        return false;
}

/*
* Método privado para adicionar uma linha na visualização da interface.
*/
void TForm1::addLinhaListView(Buffer b){

        TListItem  *ListItem = NULL;

        ListView1->ViewStyle = vsReport;

        int qntAttr;
        string attrs[MAX_ATTRIBUTES];

        if (ListView1 == NULL){
                logger.addLinhaLog("Falha ao tentar adicionar um elemento do buffer na interface --> ListView1 is NULL");
                return;
        }

        if(ListView1->Items->Count < MAX_LINES){

                ListItem = ListView1->Items->Add();
                ListItem->Caption = b.getTime().c_str();
                ListItem->SubItems->Add(b.getActiveTime().c_str());
                ListItem->SubItems->Add(b.getNomeSub().c_str());
                ListItem->SubItems->Add(b.getSource().c_str());
                ListItem->SubItems->Add(b.getMessage().c_str());
                ListItem->SubItems->Add(b.getQualityStr().c_str());
                ListItem->SubItems->Add(b.getCMaskStr().c_str());
                ListItem->SubItems->Add(b.getNewStateStr().c_str());
                ListItem->SubItems->Add(b.getEventTypeStr().c_str());
                ListItem->SubItems->Add(b.getEventCategory().c_str());
                ListItem->SubItems->Add(b.getSeverity().c_str());
                ListItem->SubItems->Add(b.getCondName().c_str());
                ListItem->SubItems->Add(b.getSubCondName().c_str());
                ListItem->SubItems->Add(b.getAckRequiredString().c_str());
                ListItem->SubItems->Add(b.getactorID().c_str());
                char buffer[10]; /* long enough to hold your number + null */
                sprintf(buffer, "%i", b.getCookie());

                ListItem->SubItems->Add(buffer);

                 qntAttr = b.getQntAttr();
                 b.getAttr(attrs);

                 if (qntAttr > 10){
                     qntAttr = 10;
                 }

                 for (int i=0;i<qntAttr;i++){

                    ListItem->SubItems->Add(attrs[i].c_str());

                 }




        }else{

                if (ListView1->Items->Count > 0){
                        ListView1->Items->Delete(0);
                }
        }


}

/*
* Thread que recebe dados  do buffer, imprimi na tela
* e Repassa para o buffer de envio!
*/
void TForm1::threadView(){

        Buffer viewBuffer;
        sem.P();

        while(!qbuffer.empty()){

                viewBuffer = qbuffer.front();
                qbuffer.pop();

                if (visualizaDados){
                    addLinhaListView(viewBuffer);
                }

                if(qSendBuffer.size() >= MAX_BUFFER_SIZE){

                        if (!bufferCheio){
                                logger.addLinhaLog("Send Buffer cheio. Perda de DADOS!!!");
                                bufferCheio = true;
                        }

                        qSendBuffer.pop();
                        qSendBuffer.push(viewBuffer);

                }else{
                        qSendBuffer.push(viewBuffer);
                }

        }

        sem.V();
}

/*
* Thread que consome o qSendBuffer e envia via TCP
*/
void TForm1::threadSendTCP(){

        Buffer buffer;

        sem.P();

        if (clienteTCP->Active && qSendBuffer.empty()){

            if (qntSemMensagem > 40){

                qntSemMensagem = 0;
                try{
                    clienteTCP->Socket->SendText("#?#");
                }catch(...){
                }

            }else{
                qntSemMensagem++;
            }
        }

        while(!qSendBuffer.empty() && clienteTCP->Active){

            buffer = qSendBuffer.front();

            string msg = protocolo.geraProtocol(&buffer).c_str();

            try {
                clienteTCP->Socket->SendText(msg.c_str());
                countEnbixas++;
                qSendBuffer.pop();
            } catch(...){
                countEnbixas--;
            }


        }
        
        sem.V();
}


void TForm1::threadReadTCP(){

        if (clienteTCP->Active){
              clienteTCP->Socket->Read(1);
        }
        
}

void TForm1::threadConectaTCP(){

        int portaTCP = -1;
        string hostTCP = "";

        portaTCP = atoi(tcpPorta->Text.c_str());
        hostTCP = host->Text.c_str();

        conectaTCP(portaTCP, hostTCP);
}

void TForm1::threadCheckServer(){

        if (controleWatchDog){

            sem1.P();
            controleWatchDog = false;
            sem1.V();

            list<OPCServer> servers;
            string pathCompleto = getPathApplication()+XML_FILENAME;
            XML* reader = new XML(pathCompleto,XMLDocument1);
            bool status = reader->readFile();
            if (!status) {
                return;
            }

            configServer(reader);

            sem1.P();
            controleWatchDog = true;
            sem1.V();

        }

}

/*
* Método para verificar e habilitar botão de conexão
*/
void __fastcall TForm1::ListBox1Click(TObject *Sender)
{
        if(ListBox1->ItemIndex >= 0){
                ConectarBt->Enabled = true;
        }
}
/*
* Verificação de habilitação de botões na interface
* de acordo com o objeto selecionado na árvore
*/
void __fastcall TForm1::tv1Change(TObject *Sender, TTreeNode *Node)
{
        if (tv1 == NULL){
                logger.addLinhaLog("tv1 is NULL");
                return;
        }

        if (tv1->SelectionCount > 0){
                if(tv1->Selected->Level == 1){
                        subscriptionButton->Enabled = true;
                        disconectButton->Enabled = true;
                        remSubBt->Enabled = false;
                        FiltroBt->Enabled = false;
                        attributosBT->Enabled = false;

                }else if(tv1->Selected->Level == 2){
                        subscriptionButton->Enabled = false;
                        disconectButton->Enabled = false;
                        remSubBt->Enabled = true;
                        FiltroBt->Enabled = true;
                        attributosBT->Enabled = true;
                }else{
                        subscriptionButton->Enabled = false;
                        disconectButton->Enabled = false;
                        remSubBt->Enabled = false;
                        FiltroBt->Enabled = false;
                        attributosBT->Enabled = false;
                }
        }
}
//---------------------------------------------------------------------------

/*
* Abre a caixa de dialogo para criação da subscription
*/
void __fastcall TForm1::subscriptionButtonClick(TObject *Sender)
{
        //OKBottomDlg1->clearAll(); /* Descomentar na versão final*/
        OKBottomDlg1->setHost(tv1->Selected->Parent->Text.c_str());
        OKBottomDlg1->setServer(tv1->Selected->Text.c_str());
        OKBottomDlg1->Show();

}
//---------------------------------------------------------------------------

/*
* Liga o Cliente TCP
*/
void __fastcall TForm1::btLigaServidorTCPClick(TObject *Sender){

        int portaTCP = -1;
        string hostTCP = "";

        portaTCP = atoi(tcpPorta->Text.c_str());
        hostTCP = host->Text.c_str();
        conectaTCP(portaTCP, hostTCP);

}

//---------------------------------------------------------------------------

void TForm1::conectaTCP(int portaTCP, string hostTCP){

        try{

            if (!clienteTCP->Active){

                //logger.addLinhaLog("Tentando se conectar ao servidor de banco. Host: "+hostTCP+" e Porta: "+portaTCP.);

                if (portaTCP > 0 && portaTCP <= 65535 && hostTCP != ""){
                    char *b = new char[6];
                    itoa(portaTCP,b,10);
                    logger.addLinhaLog("vai conectar ao Host: "+hostTCP+" e Porta: "+ b);
                    
                    clienteTCP->Port = portaTCP;
                    clienteTCP->Host = hostTCP.c_str();
                    clienteTCP->Open();
                    logger.addLinhaLog("Conectado com sucesso!");

                }else{
                  logger.addLinhaLog("Porta ou host inválidos");
                }

            }else{
                //addMsgLog("Cliente Já conectado a um servidor");
            }

        }catch(...){
            logger.addLinhaLog("Falha ao tentar conectar ao servidor");
        }
}

/*
* Limpa o array que guarda os progIds dos servidores
*/
void TForm1::clearProgId(string *clString){

        for(int i=0;i<sizeof(clString);i++){
                if (clString[i] != ""){
                       clString[i] = "";
                }else{
                        break;
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::clienteTCPConnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        Image2->Visible = false;
        addMsgLog("Conectado!");
        btLigaServidorTCP->Enabled = false;
        disconnectSocketBt->Enabled = true;
        
}
//---------------------------------------------------------------------------


void __fastcall TForm1::clienteTCPDisconnect(TObject *Sender,
      TCustomWinSocket *Socket)
{
        Image2->Visible = true;
        addMsgLog("Cliente TCP Desconectado");
        btLigaServidorTCP->Enabled = true;
        disconnectSocketBt->Enabled = false;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::clienteTCPError(TObject *Sender,
      TCustomWinSocket *Socket, TErrorEvent ErrorEvent, int &ErrorCode)
{
        addMsgLog("Erro na conexão");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::clienteTCPConnecting(TObject *Sender,
      TCustomWinSocket *Socket)
{
        addMsgLog("Conectando ao servidor...");
        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::disconnectSocketBtClick(TObject *Sender)
{
        if (clienteTCP->Active){
            clienteTCP->Close();
        }
        
        btLigaServidorTCP->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::remSubBtClick(TObject *Sender)
{
        OPCEventSubscription *ESub;
        OPCEventServer *ES;
        string subStr;
        string host;
        string server;

        server = tv1->Selected->Parent->Text.c_str();
        host = tv1->Selected->Parent->Parent->Text.c_str();
        subStr = tv1->Selected->Text.c_str();

        map<string, OPCEventServer *>::iterator iterDc = mapES.find(host+server);

        if(iterDc != mapES.end()){
                ES = iterDc->second;
                if(ES->disconnectEventSubscription(subStr+server+host)){
                        tv1->Items->Delete(tv1->Selected);
                }else{
                        //MessageBox(HWND_DESKTOP,"Erro ao remover subscription!","ERRO",MB_OK);
                        addMsgLog("Erro ao remover subscription!");
                }
        }else{
                //MessageBox(HWND_DESKTOP,"Erro ao remover subscription!","ERRO",MB_OK);
                addMsgLog("Erro ao remover subscription!");
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ClearBtClick(TObject *Sender)
{
        if(ListView1->Items->Count > 0){
                ClearBt->Enabled = true;
                ListView1->Clear();
        }else{
                ClearBt->Enabled = false;
        }
}
//---------------------------------------------------------------------------

bool TForm1::deleteServerInterface(string host, string server){

        TTreeNode *itemServer = NULL;
        TTreeNode *itemHost = NULL;

        if (tv1 == NULL){
                return false;
        }

        TTreeNode *filho,*pai;

        for(int i=0; i<tv1->Items->Count; i++){

                filho = tv1->Items->Item[i];

                if (!filho->IsFirstNode()){
                        pai = filho->Parent;

                        if(filho->Text == server.c_str() && pai->Text == host.c_str()){
                                itemServer = tv1->Items->Item[i];
                                break;
                        }
                }
        }

        if (itemServer != NULL && itemServer->IsFirstNode()){
                return false;
        }

        itemHost = itemServer->Parent;

        if (itemHost == NULL || itemServer == NULL){
                return false;
        }

        tv1->Items->Delete(itemServer);

        if(!itemHost->HasChildren){
                tv1->Items->Delete(itemHost);
        }

        return true;
}

bool TForm1::disconnectServidor(OPCEventServer *ES){

        if(ES != NULL){

                string host = ES->getHostServer();
                string server = ES->getNameServer();
                return disconect(host,server);

        }

        return false;
}

 bool TForm1::disconect(string host, string server){

                map<string, OPCEventServer *>::iterator iterMpSrv = mapES.find(host+server);

                if (iterMpSrv == mapES.end()){
                        addMsgLog("OPCEventServer não encontrado");
                        //MessageBox(HWND_DESKTOP,"OPCEventServer não encontrado","ERRO",MB_OK);
                        return false;
                }

                OPCEventServer *ES = iterMpSrv->second;

                if(ES->disconnectAllEventSubscriptions()){
                                ES->release();
                                delete ES;
                                mapES.erase(host+server);
                                deleteServerInterface(host, server);

                }else{
                        //MessageBox(HWND_DESKTOP,"Erro ao remover servidor!","ERRO",MB_OK);
                        addMsgLog("Erro ao remover servidor!");
                        return false;
                }

                return true;
}

bool TForm1::forceDisconect(OPCEventServer *myEs){

                if (myEs == NULL){
                    return false;
                }

                string host = myEs->getHostServer();
                string server = myEs->getNameServer();

                map<string, OPCEventServer *>::iterator iterMpSrv = mapES.find(host+server);

                if (iterMpSrv == mapES.end()){
                        return false;
                }

                OPCEventServer *ES = iterMpSrv->second;

                if (ES != NULL){

                    ES->disconnectAllEventSubscriptions();
                    ES->release();
                    delete ES;
                    mapES.erase(host+server);
                    deleteServerInterface(host, server);

                }

                return true;
}

void __fastcall TForm1::disconectButtonClick(TObject *Sender)
{
        string host;
        string server;

        server = tv1->Selected->Text.c_str();
        host = tv1->Selected->Parent->Text.c_str();

        OPCEventServer *ES = NULL;

        map<string, OPCEventServer *>::iterator iterMpSrv = mapES.find(host+server);

        if(iterMpSrv != mapES.end()){
                ES = iterMpSrv->second;
                disconnectServidor(ES);
        }else{
                //MessageBox(HWND_DESKTOP,"OPCEventServer não encontrado","ERRO",MB_OK);
                addMsgLog("OPCEventServer não encontrado");
        }

}

/*
* Disconecta aos servidores e finaçiza o COM. Quando fechar a janela
*/

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        Timer1->Enabled = false;
        InitSystem->Enabled = false;

        OPCEventServer *ES = NULL;

        map<string, OPCEventServer *>::iterator iter;

            for(iter = mapES.begin(); iter != mapES.end(); iter++){
                    ES = iter->second;
                    if(ES != NULL){
                            try{
                                disconnectServidor(ES);
                            }catch (...){
                            }
                    }
            }
        
        if (myConection->getStatusCom()){
            myConection->stopCom();
        }

        delete myConection;

        if (threadViewPtr != NULL){
            threadViewPtr->Terminate();
            threadViewPtr->WaitFor();
            delete threadViewPtr;
        }

        if (threadConectaTCPPtr != NULL){
            threadConectaTCPPtr->Terminate();
            threadConectaTCPPtr->WaitFor();
            delete threadConectaTCPPtr;
        }

        if (threadSendPtr != NULL){
            threadSendPtr->Terminate();
            threadSendPtr->WaitFor();
            delete threadSendPtr;
        }

        if (clienteTCP->Active){
            clienteTCP->Close();
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FiltroBtClick(TObject *Sender)
{
        string server = tv1->Selected->Parent->Text.c_str();
        string host = tv1->Selected->Parent->Parent->Text.c_str();
        string subscription = tv1->Selected->Text.c_str();
        string chaveSub = subscription+server+host;

        OKBottomDlg->setServerAndHost(server,host);
        OKBottomDlg->setSub(subscription);

        OPCEventServer *servidor = getPtOPCEventServer(server,host);
        OPCEventSubscription *sub;
        Filtro myFilter;

        if (servidor != NULL){

                sub = servidor->getEvSub(chaveSub);

                if (sub != NULL){
                     bool retorno = sub->getFiltro(&myFilter);

                     if (!retorno){
                             addMsgLog("Falha ao tentar capturar o filtro atual.");
                     }

                }else{
                        logger.addLinhaLog("Falha ao tentar encontrar a subscription para utilizar o getFiltro");
                }

        }else{

              logger.addLinhaLog("Falha ao tentar criar Filtro --> server is NULL");
              addMsgLog("Falha ao tentar criar Filtro");

        }


        OKBottomDlg->setAtualFiltro(myFilter);
        OKBottomDlg->Show();
}
//---------------------------------------------------------------------------

bool TForm1::browseAreas(string server, string host, string *lista){

        OPCEventAreaBrowser *opcABrowser = NULL;
        OPCEventServer *servidor = getPtOPCEventServer(server,host);

        if (servidor != NULL && servidor->isAllowedBrowseArea()){
                opcABrowser = servidor->getAreaBrowser();
                if(opcABrowser != NULL){
                        return opcABrowser->browseOPCAreas(lista);
                }
        }
        return false;
}

bool TForm1::browseSource(string server, string host, string *lista){

        OPCEventAreaBrowser *opcABrowser = NULL;
        OPCEventServer *servidor = getPtOPCEventServer(server,host);

        if (servidor != NULL){
                opcABrowser = servidor->getAreaBrowser();
                if(opcABrowser != NULL){
                        return opcABrowser->browseOPCSource(lista);
                }
        }
        return false;
}

bool TForm1::changeAreaDown(string server, string host, string passou){
        OPCEventAreaBrowser *opcABrowser = NULL;
        OPCEventServer *servidor = getPtOPCEventServer(server,host);
        if (servidor != NULL && servidor->isAllowedBrowseArea()){
                opcABrowser = servidor->getAreaBrowser();
                if(opcABrowser != NULL){
                        return opcABrowser->changeBrowseDown(passou);
                }
        }
        return false;
}

bool TForm1::changeAreaTo(string server, string host, string passou){
        OPCEventAreaBrowser *opcABrowser = NULL;
        OPCEventServer *servidor = getPtOPCEventServer(server,host);
        if (servidor != NULL && servidor->isAllowedBrowseArea()){
                opcABrowser = servidor->getAreaBrowser();
                if(opcABrowser != NULL){
                        return opcABrowser->changeBrowseTo(passou);
                }
        }
        return false;
}

bool TForm1::changeAreaUp(string server, string host){
        OPCEventAreaBrowser *opcABrowser = NULL;
        OPCEventServer *servidor = getPtOPCEventServer(server,host);
        if (servidor != NULL && servidor->isAllowedBrowseArea()){
                opcABrowser = servidor->getAreaBrowser();
                if(opcABrowser != NULL){
                        return opcABrowser->changeBrowseUp();
                }
        }
        return false;
}

OPCEventServer * TForm1::getPtOPCEventServer(string server, string host){

        OPCEventServer *servidor = NULL;
        map<string, OPCEventServer *>::iterator buscaES = mapES.find(host+server);

        if (buscaES != mapES.end()){
            servidor = buscaES->second;
        }

        return servidor;

}

bool TForm1::callFilter(ESTRUTURA *ptr){

        string host = ptr->host;
        string server = ptr->server;
        string subName = ptr->subscription;
        string chaveSub = subName+server+host;

        OPCEventServer *servidor = getPtOPCEventServer(server,host);
        OPCEventSubscription *sub = NULL;

        if(servidor != NULL){

                sub = servidor->getEvSub(chaveSub);
                if(sub == NULL){
                        logger.addLinhaLog("Falha ao tentar criar Filtro --> Subscription is NULL");
                        addMsgLog("Falha ao tentar criar Filtro");
                        //MessageBox(HWND_DESKTOP,"Falha ao tentar criar Filtro","ERRO",MB_OK);
                        return false;

                }else{
                        return sub->setarFiltro(ptr);
                }
        }
        return false;
}

void __fastcall TForm1::SalvarConfiguraes1Click(TObject *Sender)
{

      bool status = false;
      string pathCompleto = getPathApplication()+XML_FILENAME;
      XML* writer = new XML(pathCompleto,XMLDocument1);
      status = writer->writeFile(mapES, host->Text.c_str(), tcpPorta->Text.c_str());

      if (status) {
            addMsgLog("Configurações Salvas com Sucesso!!");
            //MessageBox(HWND_DESKTOP,"Configurações Salvas com Sucesso!!","Sucesso",MB_OK);

      }else{
            addMsgLog("Falha ao tentar criar arquivo!");
            //MessageBox(HWND_DESKTOP,"Falha ao tentar criar arquivo!","ERRO",MB_OK);
      }


}
//---------------------------------------------------------------------------

void TForm1::addAreaFilter(Filter& filter, ESTRUTURA& ptr, LPWSTR* listaArea)
{
        list<Area> areas;
        Area area;
        int arsize = 0;
        int icount = 0;

        areas = filter.getAreas();
        arsize = areas.size();;
        ptr.numArea = arsize;
        while (!areas.empty()) {
                area = areas.front();
                areas.pop_front();
                listaArea[icount]= WideString(area.getName().c_str()).Detach();
                icount++;
        }
        ptr.pszAreaList = listaArea;
}
//---------------------------------------------------------------------------
void TForm1::addSourceFilter(Filter& filter, ESTRUTURA& ptr, LPWSTR* listaSrc)
{
        list<Source> sources;
        Source source;
        int srcsize = 0;
        int icount = 0;

        sources = filter.getSources();
        srcsize = sources.size();
        ptr.numSources = srcsize;
        while (!sources.empty()) {
                source = sources.front();
                sources.pop_front();
                listaSrc[icount]= WideString(source.getName().c_str()).Detach();
                icount++;
        }
        ptr.pszSourceList = listaSrc;

}
//---------------------------------------------------------------------------
void TForm1::addEventFilter(Filter& filter, ESTRUTURA& ptr, string* listaEvCat, DWORD *listaDwd)
{
        OPCEventServer* ptrserver;
        list<EventCategory> events;
        EventCategory event;
        int evsize = 0;
        int icount = 0;

        events = filter.getEventCategories();
        evsize = events.size();
        ptr.countEventCategory = evsize;
        while (!events.empty()) {
                event = events.front();
                events.pop_front();
                listaEvCat[icount] = event.getName().c_str();
                icount++;
        }

        ptrserver = getPtOPCEventServer(ptr.server,ptr.host);
        ptrserver->getPtEvCat(listaEvCat,evsize, listaDwd);
        ptr.ptEventCategories = listaDwd;

}
//---------------------------------------------------------------------------
void TForm1::configFilter(Subscription& opcsub, string server, string hostcompleto)
{

        LPWSTR listaArea[MAX_LEN];
        LPWSTR listaSrc[MAX_LEN];
        string listaEvCat[MAX_LEN];
        DWORD  listaDwd[MAX_LEN];

        Filter filter;
        ESTRUTURA ptr;
        DWORD  evType;

        filter = opcsub.getFilter();

        ptr.sevLow = filter.getLowPriorityValue();
        ptr.sevHigh = filter.getHighPriorityValue();
        ptr.server = server;
        ptr.host = hostcompleto;
        ptr.subscription = opcsub.getName();

        addAreaFilter(filter, ptr, listaArea);
        addSourceFilter(filter, ptr, listaSrc);
        addEventFilter(filter, ptr, listaEvCat, listaDwd);

        evType = filter.getEvTypeValue();
        ptr.btCEvent = evType & OPC_CONDITION_EVENT;
        ptr.btSEvent =  evType & OPC_SIMPLE_EVENT;
        ptr.btTEvent = evType & OPC_TRACKING_EVENT;

        callFilter(&ptr);

}
//---------------------------------------------------------------------------
void TForm1::configSubscription(OPCServer& opcserver, string hostcompleto, string server)
{
        list<Subscription> subs;
        list<EventCategory> evtCat;
        
        Subscription opcsub;
        int buffer, maxSize;
        string sub;
        int icount = 0;

        subs = opcserver.getSubscriptions();

        while (!subs.empty()) {

                opcsub = subs.front();
                subs.pop_front();
                buffer = opcsub.getBufferValue();
                maxSize = opcsub.getMaxSizeValue();
                sub = opcsub.getName();
                callSubscription(hostcompleto, server, sub, buffer, maxSize);
                configFilter(opcsub,server,hostcompleto);
                evtCat = opcsub.getEventCategories();
                configAttributes(evtCat,hostcompleto,server,sub);
                icount++;

        }

}

void TForm1::configAttributes(list<EventCategory> evtCat, string hostcompleto, string server, string sub){

        OPCEventServer *servidor = getPtOPCEventServer(server,hostcompleto);
        OPCEventSubscription *opcSub = NULL;

        string chaveSub = sub+server+hostcompleto;

        DWORD listEvtCat[MAX_LEN_EVTCAT];
        DWORD listQntAttr[MAX_LEN_ATTRIBUTES];
        DWORD listAttr[MAX_LEN_EVTCAT][MAX_LEN_ATTRIBUTES];
        DWORD countEvt = 0;
        DWORD countAttr = 0;

        list<Attributes> attributes;
        list<Attributes>::iterator j;
        Attributes attr;

        list<EventCategory>::iterator i;
        EventCategory evt;

        while (!evtCat.empty()){
        
            evt = evtCat.front();
            evtCat.pop_front();
            listEvtCat[countEvt] = (DWORD) evt.getId();

            attributes = evt.getAtributos();

            countAttr = 0;

            while (!attributes.empty()){
            
                attr = attributes.front();
                attributes.pop_front();

                listAttr[countEvt][countAttr] = (DWORD) attr.getIdAtributo();

                countAttr++;

            }

            listQntAttr[countEvt] = countAttr;

            countEvt++;
        }

        if(servidor != NULL){

                opcSub = servidor->getEvSub(chaveSub);

                if(opcSub == NULL){

                        logger.addLinhaLog("Falha ao tentar criar Filtro --> Subscription is NULL");
                        addMsgLog("Falha ao tentar criar Atributos");

                }else{

                    opcSub->selectReturnedAttr(listEvtCat,countEvt,listQntAttr,listAttr);

                }
        }


}

//---------------------------------------------------------------------------

void TForm1::configServer(XML* reader)
{
        Form1->host->Text = reader->getHost().c_str();
        Form1->tcpPorta->Text = reader->getPorta().c_str();

        list<OPCServer> servers;
        OPCServer opcserver;
        string hostcompleto;
        string server;
        string host;
        bool flagLocal;
        bool rede = false;
        bool status = false;
        bool static desligouUmaVez = false;
//      bool status = false;

        servers = reader->getServers();
        while (!servers.empty()) {

                opcserver = servers.front();
                servers.pop_front();
                server = opcserver.getName();
                hostcompleto = opcserver.getHost();

                int posi = hostcompleto.find("[",0);
                int posf = hostcompleto.rfind("]", hostcompleto.size());
                host = hostcompleto.substr(posi+1,(posf-posi-1));

                if (host == "127.0.0.1") {
                        flagLocal = true;
                } else {
                        flagLocal = false;
                }

                OPCEventServer *ES;
                ES = getPtOPCEventServer(server,hostcompleto);

                if (ES != NULL){
                    //verifica o status do servidor
                    status = ES->getStatus();

                }
                    rede = checkRede(host,server, flagLocal);

                if ((ES == NULL || !status) || desligouUmaVez){
                    if (ES != NULL && (status || rede)){

                        string hostCompleto = "";
                        hostCompleto = ES->getHostServer();

                        try {
                            forceDisconect(ES);
                        }catch (...){
                                  logger.addLinhaLog("nao foi possivel desconectar servidor opc");
                        }
                    }

                    if (status || ES == NULL || rede){

                        clearProgId(progIds);
                        bool result2 = myConection->listaOpc(flagLocal,progIds, host);
                        bool result = conectarServidor(flagLocal,server,host);

                        if (result){
                            adicionarServerListTree(server,hostcompleto);
                            ListBox1->Items->Clear();
                            ConectarBt->Enabled = false;
                            configSubscription(opcserver, hostcompleto, server);
                        }

                    }

                  if((status == false && !rede) && ES != NULL){
                        desligouUmaVez = true;
                  }else{
                        desligouUmaVez = false;
                  }
                  
                }
        }
}

//---------------------------------------------------------------------------

/* Adiciona uma mensagem de log na INTERFACE */
void TForm1::addMsgLog(string msg){

    if (MemoLog->Lines->Count > 30){
        MemoLog->Clear();
    }

    MemoLog->Lines->Add(msg.c_str());

}

//---------------------------------------------------------------------------

void __fastcall TForm1::btVisualizarClick(TObject *Sender)
{
    visualizaDados = !visualizaDados;

    if (visualizaDados){
        btVisualizar->Caption = "Esconder Dados";
        ClearBt->Enabled = true;
    }else{
        btVisualizar->Caption = "Visualizar Dados";
    }

}
//---------------------------------------------------------------------------

bool TForm1::getflagLocal(){
        return this->flagLocal;
}

//---------------------------------------------------------------------------

bool TForm1::checkRede(string host, string server, bool flagLocal){

        clearProgId(progIds);
        bool result = myConection->listaOpc(flagLocal,progIds, host);

        if (!result){

            addMsgLog("Host não encontrado!");
            return false;

        }

        CLSID clsid = myConection->getCLSID(server);
        return myConection->testeConnection(flagLocal,host,clsid);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender){
    threadCheckServer();
}
//---------------------------------------------------------------------------

void TForm1::init(){

        addMsgLog("Inicializando o Sistema...");
        logger.addLinhaLog("Inicializando o Sistema...");
        
        bool status = false;
        string pathCompleto = getPathApplication()+XML_FILENAME;
        XML* reader = new XML(pathCompleto,XMLDocument1);
        status = reader->readFile();

        threadViewPtr = new ThreadView(false,this);
        threadSendPtr = new ThreadSendTCP(false,this);
        threadConectaTCPPtr = new ThreadConectaTCP(false,this);

        if (!status) {
             return;
        }
        configServer(reader);
        delete reader;

        logger.addLinhaLog("Inicialização Concluída!");
}

void __fastcall TForm1::InitSystemTimer(TObject *Sender)
{
    InitSystem->Enabled = false;
    init();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
    InitSystem->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::attributosBTClick(TObject *Sender)
{

    string server = tv1->Selected->Parent->Text.c_str();
    string host = tv1->Selected->Parent->Parent->Text.c_str();
    string subscription = tv1->Selected->Text.c_str();
    
    dialogAttributes->setServerAndHostAndSubscription(server,host,subscription);
    dialogAttributes->Show();
}
//---------------------------------------------------------------------------













