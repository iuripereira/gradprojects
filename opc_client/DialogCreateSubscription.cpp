//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "DialogCreateSubscription.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TOKBottomDlg1 *OKBottomDlg1;
//---------------------------------------------------------------------
__fastcall TOKBottomDlg1::TOKBottomDlg1(TComponent* AOwner)
	: TForm(AOwner)
{
        btOk=false;
        //clearAll();
}
//---------------------------------------------------------------------

string TOKBottomDlg1::getNome(){
        return nomeTxt->Text.c_str();
}
int TOKBottomDlg1::getBuffer(){
        return bufferTxt->Text.ToInt();
}
int TOKBottomDlg1::getMaxSize(){
        return maxSizeTxt->Text.ToInt();
}

bool TOKBottomDlg1::getBtOk(){
        return maxSizeTxt->Text.ToInt();
}
string TOKBottomDlg1::getHost(){
        return hostDlg;
}
string TOKBottomDlg1::getServer(){
        return serverDlg;
}
void TOKBottomDlg1::setServer(string s){
        serverDlg = s;
}
void TOKBottomDlg1::setHost(string h){
        hostDlg = h;
}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg1::OKBtnClick(TObject *Sender)
{
        btOk = true;
        //verificar campos antes de chamar callsub
        Form1->callSubscription(getHost(), getServer(), getNome(),getBuffer(),getMaxSize());
        this->Close();

}
//---------------------------------------------------------------------------

void __fastcall TOKBottomDlg1::CancelBtnClick(TObject *Sender)
{
        btOk = false;
        this->Close();
}
void TOKBottomDlg1::clearAll(){
        maxSizeTxt->Clear();
        bufferTxt->Clear();
        nomeTxt->Clear();
}
//---------------------------------------------------------------------------












