//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DialogAtributos.h"
//--------------------------------------------------------------------- 
#pragma resource "*.dfm"
TdialogAttributes *dialogAttributes;
//---------------------------------------------------------------------
__fastcall TdialogAttributes::TdialogAttributes(TComponent* AOwner)
	: TForm(AOwner)
{
}

void TdialogAttributes::setServerAndHostAndSubscription(string s, string h, string subStr){

    server = s;
    host = h;
    sub = subStr;

    string lista[1000];
    servidor = Form1->getPtOPCEventServer(server,host);

    if (servidor != NULL){
        subscription = servidor->getEvSub(sub+server+host);
        servidor->getEventCategoryList(lista);
        populaEventCategoryList(lista);
    }

}

void TdialogAttributes::populaEventCategoryList(string *lista){
        int i=0;
        logger.addLinhaLog("Inínio Lista Categorias");

        while(lista[i] != ""){

                string eventCat = lista[i].c_str();
                listEventCat->AddItem(lista[i].c_str(),NULL);


                logger.addLinhaLog(lista[i].c_str());



                string attributes[1000][3];
                servidor->getAttributes(eventCat, attributes);

                string selectedAtributes[1000][3];
                subscription->getAtributosSelecionados(eventCat, attributes, selectedAtributes);

                populaListSelectedAttributes(selectedAtributes,eventCat);
                i++;
        }

        logger.addLinhaLog("FIM Lista Categorias");
}

//---------------------------------------------------------------------

void __fastcall TdialogAttributes::listEventCatClick(TObject *Sender)
{
        string eventCat = listEventCat->Items->Strings[listEventCat->ItemIndex].c_str();

        string attributes[1000][3];
        servidor->getAttributes(eventCat, attributes);

        populaListAttributes(attributes,eventCat);
}

void TdialogAttributes::populaListSelectedAttributes(string attributes[][3], string eventCat){

        TListItem  *ListItem = NULL;

        ListAttributesEscolhidos->ViewStyle = vsReport;

        if (ListAttributesEscolhidos == NULL){
                logger.addLinhaLog("Falha ao tentar adicionar um elemento do buffer na interface --> ListAttributesEscolhidos is NULL");
                return;
        }

        //ListAttributesEscolhidos->Clear();

        int i=0;

        while(StrComp(attributes[i][0].c_str(),"") != 0){
            ListItem = ListAttributesEscolhidos->Items->Add();
            ListItem->Caption = attributes[i][0].c_str();
            ListItem->SubItems->Add(attributes[i][1].c_str());
            ListItem->SubItems->Add(attributes[i][2].c_str());
            ListItem->SubItems->Add(eventCat.c_str());
            i++;
        }
}


void TdialogAttributes::populaListAttributes(string attributes[][3], string eventCat){

        TListItem  *ListItem = NULL;

        ListAttributes->ViewStyle = vsReport;

        if (ListAttributes == NULL){
                logger.addLinhaLog("Falha ao tentar adicionar um elemento do buffer na interface --> ListAttributes is NULL");
                return;
        }

        ListAttributes->Clear();

        int i=0;

        while(StrComp(attributes[i][0].c_str(),"") != 0){
            ListItem = ListAttributes->Items->Add();
            ListItem->Caption = attributes[i][0].c_str();
            ListItem->SubItems->Add(attributes[i][1].c_str());
            ListItem->SubItems->Add(attributes[i][2].c_str());
            ListItem->SubItems->Add(eventCat.c_str());
            i++;
        }
}


//---------------------------------------------------------------------------


void __fastcall TdialogAttributes::btAddClick(TObject *Sender)
{
    ListAttributesEscolhidos->ViewStyle = vsReport;

    TListItem  *ListItemNovo = ListAttributes->Selected;
    TListItem  *ListItem = NULL;

    if (ListItemNovo != NULL){

        for (int i=0;i<ListAttributesEscolhidos->Items->Count;i++){

            if (ListAttributesEscolhidos->Items->Item[i]->Caption == ListItemNovo->Caption){

                if (ListAttributesEscolhidos->Items->Item[i]->SubItems->Text  == ListItemNovo->SubItems->Text){
                    return;
                }


            }
        }

        ListItem = ListAttributesEscolhidos->Items->Add();
        ListItem->Caption = ListItemNovo->Caption;

        ListItem->SubItems->Add("");
        ListItem->SubItems->Add("");
        ListItem->SubItems->Add("");

        ListItem->SubItems = ListItemNovo->SubItems;

    }

}
//---------------------------------------------------------------------------


void __fastcall TdialogAttributes::btRemoveClick(TObject *Sender)
{
    TListItem  *ListItemEscolhido = ListAttributesEscolhidos->Selected;

    if (ListItemEscolhido != NULL){

        ListItemEscolhido->Delete();

    }
}
//---------------------------------------------------------------------------


void __fastcall TdialogAttributes::CancelBtnClick(TObject *Sender){

    listEventCat->Clear();
    ListAttributes->Clear();
    ListAttributesEscolhidos->Clear();
    dialogAttributes->Close();

}
//---------------------------------------------------------------------------


void __fastcall TdialogAttributes::OKBtnClick(TObject *Sender)
{

    if (subscription != NULL){

        map<string, DWORD> mapEvtCatTmp;

        DWORD countAtt = (DWORD) ListAttributesEscolhidos->Items->Count;
        DWORD countEventCat = (DWORD)listEventCat->Items->Count;

        string evento;

        DWORD evtCategoryDword[MAX_LEN_ATTRIBUTES];
        DWORD listAttr[MAX_LEN_EVTCAT][MAX_LEN_ATTRIBUTES];

        string ids;
        string subs;

        DWORD countId[MAX_LEN_ATTRIBUTES];

        string idsStr;

        for (int i=0;i<countEventCat;i++) {

            evento = listEventCat->Items->Strings[i].c_str();
            evtCategoryDword[i] = servidor->getEventCategory(evento);

            countId[i] = 0;

            idsStr = "";

            for (int j=0;j<countAtt;j++){

                ids = ListAttributesEscolhidos->Items->Item[j]->Caption.c_str();
                subs = ListAttributesEscolhidos->Items->Item[j]->SubItems[0].Text.c_str();

                if (subs.find(evento) != -1){

                    listAttr[i][countId[i]] =  StrToInt(ids.c_str());
                    idsStr = idsStr + ids.c_str();
                    idsStr = idsStr + ",";

                    countId[i] = countId[i] + 1;

                }

            }

        }

        bool retorno = subscription->selectReturnedAttr(evtCategoryDword,countEventCat,countId,listAttr);

        if (!retorno){
            Form1->addMsgLog("Falha ao executar o selectReturnedAttr");

        }else {
            logger.addLinhaLog("Sucesso ao executar SelectReturnedAttributes com os parametros: eventoCategory: "+evento+" count: "+IntToStr(countId).c_str()+ " lista Atributos: "+idsStr);

        }

    }

    listEventCat->Clear();
    ListAttributes->Clear();
    ListAttributesEscolhidos->Clear();
    dialogAttributes->Close();

}
//---------------------------------------------------------------------------


void __fastcall TdialogAttributes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    listEventCat->Clear();
    ListAttributes->Clear();
    ListAttributesEscolhidos->Clear();

}
//---------------------------------------------------------------------------




