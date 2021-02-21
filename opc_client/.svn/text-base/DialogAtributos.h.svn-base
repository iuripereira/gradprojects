//----------------------------------------------------------------------------
#ifndef DialogAtributosH
#define DialogAtributosH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>

#include "formAE.h"
#include "Logger.h"
#include "OPCEventSubscription.h"

#include <sstream.h>
#include <ComCtrls.hpp>


//----------------------------------------------------------------------------
class OPCEventSubscription;
class TdialogAttributes : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
	TBevel *Bevel1;
    TListBox *listEventCat;
    TListView *ListAttributes;
    TListView *ListAttributesEscolhidos;
    TButton *btAdd;
    TButton *btRemove;
    void __fastcall listEventCatClick(TObject *Sender);
    void __fastcall btAddClick(TObject *Sender);
    void __fastcall btRemoveClick(TObject *Sender);
    void __fastcall CancelBtnClick(TObject *Sender);
    void __fastcall OKBtnClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:

    Logger logger;
    string host;
    string server;
    string sub;
    OPCEventServer *servidor;
    OPCEventSubscription *subscription;
    void populaListSelectedAttributes(string attributes[][3], string eventCat);
    void populaListAttributes(string attributes[][3], string eventCat);

public:
	virtual __fastcall TdialogAttributes(TComponent* AOwner);
    void populaEventCategoryList(string *lista);
    void setServerAndHostAndSubscription(string s,string h, string sub);


};
//----------------------------------------------------------------------------
extern PACKAGE TdialogAttributes *dialogAttributes;
//----------------------------------------------------------------------------
#endif    
