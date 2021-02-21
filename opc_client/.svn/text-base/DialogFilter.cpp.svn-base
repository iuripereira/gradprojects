//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#define MAX_LEN 2048

#include "DialogFilter.h"
#include <vector.h>

//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOKBottomDlg *OKBottomDlg;
//---------------------------------------------------------------------
__fastcall TOKBottomDlg::TOKBottomDlg(TComponent* AOwner)
	: TForm(AOwner)
{
        servidor = NULL;
}
bool TOKBottomDlg::getParametros(ESTRUTURA *x){

        x->btCEvent = chBoxCEvent->Checked;
        x->btSEvent = chBoxSEvent->Checked;
        x->btTEvent = chBoxTEvent->Checked;

        if(sevLowField->Text == "" || sevLowField->Text == "0"){
                x->sevLow = 1;
        }else{
                x->sevLow = sevLowField->Text.ToInt();
        }
        if(sevHighField->Text == ""){
                x->sevHigh = 1000;
        }else{
                x->sevHigh = sevHighField->Text.ToInt();
        }

        DWORD contTvS = 0;
        DWORD contTvA = 0;
        DWORD contTvE = 0;

        x->server =  param.server;
        x->host =  param.host;
        x->subscription =  param.subscription;

        DWORD  listaDwd[MAX_LEN];
        string listaEvCat[MAX_LEN];
        LPWSTR listaArea[MAX_LEN];
        LPWSTR listaSrc[MAX_LEN];

        for(int k=0;k<listSelectedEventCat->Items->Count;k++){
                listaEvCat[k] = listSelectedEventCat->Items->Item[k]->Caption.c_str();
                contTvE++;
        }

        if(servidor != NULL){
                servidor->getPtEvCat(listaEvCat, contTvE, listaDwd);
                x->ptEventCategories = listaDwd;
        }

        for(int i=0;i<listArea->Items->Count;i++){
                listaArea[i] = WideString(listArea->Items->Item[i]->Caption.c_str()).Detach();
                contTvA++;
        }

        x->pszAreaList = listaArea;

        for(int j=0;j<listSources->Items->Count;j++){
                listaSrc[j] = WideString(listSources->Items->Item[j]->Caption.c_str()).Detach();
                contTvS++;
        }

        x->pszSourceList = listaSrc;
        x->numSources = contTvS;
        x->numArea = contTvA;
        x->countEventCategory = contTvE;

        return true;
}

void TOKBottomDlg::setAtualFiltro(Filtro ptrStruct){

        chBoxSEvent->Checked = ptrStruct.btSEvent;
        chBoxCEvent->Checked = ptrStruct.btCEvent;
        chBoxTEvent->Checked = ptrStruct.btTEvent;

        if (ptrStruct.sevLow <= 0){
                ptrStruct.sevLow = 1;
        }

        sevLowField->Text = ptrStruct.sevLow;
        sevHighField->Text = ptrStruct.sevHigh;

        populaListView(listArea,ptrStruct.pszAreaList,ptrStruct.numArea);
        populaListView(listSources,ptrStruct.pszSourceList,ptrStruct.numSources);
        populaListView(listSelectedEventCat,ptrStruct.ptEventCategories,ptrStruct.countEventCategory);

}

void TOKBottomDlg::populaListView(TListView *listView, string *list, int tam){

        if (listView != NULL){
                listView->Clear();
        }else {
                return;
        }

        if (list == NULL || tam <= 0){
                return;
        }

        for (int i=0;i<tam;i++){
                listView->AddItem(list[i].c_str(),NULL);
        }
}

void TOKBottomDlg::setServerAndHost(string s,string h){

        param.server = s;
        param.host = h;
        servidor = Form1->getPtOPCEventServer(s,h);

        populaTvArea(NULL);
        populaTvSource(NULL);
        populaListEventCategories();
        populaInfos();

}


void TOKBottomDlg::setSub(string sub){
        param.subscription = sub;
}

string TOKBottomDlg::getServer(){
        return this->param.server;
}

string TOKBottomDlg::getHost(){
        return this->param.host;
}

string TOKBottomDlg::getSub(){
        return this->param.subscription;
}

void __fastcall TOKBottomDlg::OKBtnClick(TObject *Sender)
{
        if(!chBoxCEvent->Checked && !chBoxSEvent->Checked && !chBoxTEvent->Checked){
                Form1->addMsgLog("Você precisa selecionar pelo menos um tipo de evento");
                //MessageBox(HWND_DESKTOP,"Você precisa selecionar pelo menos um tipo de evento","ERRO",MB_OK);
        }else{
                ESTRUTURA mystruct;
                getParametros(&mystruct);
                if(Form1->callFilter(&mystruct)){
                        this->Close();
                }else{
                        Form1->addMsgLog("Erro ao setar filtro!");
                        //MessageBox(HWND_DESKTOP,"Erro ao setar filtro!","ERRO",MB_OK);
                }
        }

}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::CancelBtnClick(TObject *Sender){

        this->Close();
}

//---------------------------------------------------------------------------

void TOKBottomDlg::populaInfos(){

    if (servidor == NULL){
        return;
    }

    txtImplementaAB->Caption = toString(servidor->isAllowedBrowseArea());
    txtFiltroArea->Caption = toString(servidor->isAvaibleFilterByArea());
    txtFiltroSource->Caption = toString(servidor->isAvaibleFilterBySorce());
    txtFiltroCat->Caption = toString(servidor->isAvaibleFilterByCategory());

    txtFiltroEvt->Caption = toString(servidor->isAvaibleFilterByEvent());
    txtFiltroSev->Caption = toString(servidor->isAvaibleFilterBySeverity());

}

AnsiString TOKBottomDlg::toString(bool valor){

    if (valor){
        return "SIM";
    }else{
        return "NÃO";
    }

}

void TOKBottomDlg::populaTvArea(TTreeNode *parent){

        string lista[MAX_LEN_AREA_FILTRO];
        string server = getServer();
        string host =  getHost();
        string parentString;
        bool retorno,retorno2;

        if (parent==NULL){
                tvArea->Items->Clear();
                TTreeNode *parent = tvArea->Items->GetFirstNode();
        }else{
                parentString = parent->Text.c_str();
                retorno = Form1->changeAreaTo(server, host,parentString);
        }

        retorno2 = Form1->browseAreas(server, host, &lista[0]);

        if (lista[0] == ""){
                return;
        }else{

                int i=0;
                while(lista[i] != ""){
                        TTreeNode *newParent = tvArea->Items->AddChild(parent, lista[i].c_str());
                        this->populaTvArea(newParent);
                        Form1->changeAreaUp(server,host);
                        i++;
                }
        }

}

void TOKBottomDlg::populaTvSource(TTreeNode *parent){

        string listaArea[MAX_LEN_AREA_FILTRO];

        string server = getServer();
        string host =  getHost();
        string parentString;
        bool retorno,retorno2,returnSource;

        clearLista(listaSource);

        if (parent==NULL){
                tvSource->Items->Clear();
                TTreeNode *parent = tvSource->Items->GetFirstNode();
        }else{
                parentString = parent->Text.c_str();
                retorno = Form1->changeAreaTo(server, host,parentString);
        }

        retorno2 = Form1->browseAreas(server, host, &listaArea[0]);
        returnSource = Form1->browseSource(server, host, &listaSource[0]);

        if (listaArea[0] == "" && listaSource[0] == ""){
                return;
        }else{

                int i=0;
                while(listaSource[i] != ""){
                        tvSource->Items->AddChild(parent, listaSource[i].c_str());
                        i++;
                }
                int j=0;
                while(listaArea[j] != ""){
                        TTreeNode *newParent = tvSource->Items->AddChild(parent, listaArea[j].c_str());
                        this->populaTvSource(newParent);
                        Form1->changeAreaUp(server,host);
                        j++;
                }
        }


}

void TOKBottomDlg::populaListEventCategories(){

        string lista[1000];
        string server = getServer();
        string host =  getHost();
        string parentString;
        bool retorno;

        OPCEventServer *servidor = NULL;
        servidor = Form1->getPtOPCEventServer(server, host);

        if(servidor != NULL){

            retorno = servidor->getEventCategoryList(lista);

            if (!retorno){
                //LOGAR
            }

        }

        listEventCat->Clear();

        if (lista[0] == ""){
                return;
        }else{
                int i=0;
                while(lista[i] != ""){
                        listEventCat->AddItem(lista[i].c_str(),NULL);
                        i++;
                }
        }

}

void TOKBottomDlg::clearLista(string *lista){

        int i = 0;
        while(lista[i] != ""){
                lista[i] = "";
                i++;
        }
}

void __fastcall TOKBottomDlg::tvAreaChange(TObject *Sender,
      TTreeNode *Node)
{
        btAddArea->Enabled = (tvArea->SelectionCount > 0);

}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::listAreaChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{

        btRemoveArea->Enabled = (listArea->SelCount > 0);

}
//---------------------------------------------------------------------------


void __fastcall TOKBottomDlg::btAddAreaClick(TObject *Sender)
{
        string add = tvArea->Selected->Text.c_str();
        TListItem *item = listArea->FindCaption(0,add.c_str(),false,true,false);

        if (item == NULL){
                listArea->AddItem(add.c_str(),NULL);
        }
        
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::btRemoveAreaClick(TObject *Sender)
{
        listArea->DeleteSelected();
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::tvSourceChange(TObject *Sender,
      TTreeNode *Node)
{
        btAddSource->Enabled = !tvSource->Selected->HasChildren;
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::listSourcesChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
        btRemoveSource->Enabled = (listSources->SelCount > 0);
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::btRemoveSourceClick(TObject *Sender)
{
        listSources->DeleteSelected();
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::btAddSourceClick(TObject *Sender)
{
        string add = tvSource->Selected->Text.c_str();
        TListItem *item = listSources->FindCaption(0,add.c_str(),false,true,false);

        if (item == NULL){
                listSources->AddItem(add.c_str(),NULL);
        }
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::listEventCatChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
        btAddCat->Enabled = (listEventCat->SelCount > 0);
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::listSelectedEventCatChange(TObject *Sender,
      TListItem *Item, TItemChange Change)
{
        btRemoveCat->Enabled = (listSelectedEventCat->SelCount > 0);
}
//---------------------------------------------------------------------------



void __fastcall TOKBottomDlg::btRemoveCatClick(TObject *Sender)
{
        listSelectedEventCat->DeleteSelected();
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg::btAddCatClick(TObject *Sender)
{
        string add = listEventCat->Selected->Caption.c_str();
        TListItem *item = listSelectedEventCat->FindCaption(0,add.c_str(),false,true,false);

        if (item == NULL){
                listSelectedEventCat->AddItem(add.c_str(),NULL);
        }

}
//---------------------------------------------------------------------------













