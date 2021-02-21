//----------------------------------------------------------------------------
#ifndef DialogFilterH
#define DialogFilterH
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

#include <stdlib.h>
#include <sstream.h>
#include "bibliotecas/defOPCSiga.h"
#include "formAE.h"
#include <ComCtrls.hpp>

#define MAX_LEN_SOURCE 10000
#define MAX_LEN_AREA_FILTRO 1000

//----------------------------------------------------------------------------
class TOKBottomDlg : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TGroupBox *GroupBox1;
        TCheckBox *chBoxSEvent;
        TCheckBox *chBoxCEvent;
        TCheckBox *chBoxTEvent;
        TEdit *sevHighField;
        TEdit *sevLowField;
        TLabel *Label1;
        TLabel *Label2;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TListView *listArea;
        TTreeView *tvArea;
        TTreeView *tvSource;
        TListView *listEventCat;
        TButton *btAddArea;
        TButton *btRemoveArea;
        TButton *btAddSource;
        TButton *btRemoveSource;
        TListView *listSources;
        TListView *listSelectedEventCat;
        TButton *btAddCat;
        TButton *btRemoveCat;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *Label5;
    TLabel *Label6;
    TLabel *txtImplementaAB;
    TLabel *txtFiltroArea;
    TLabel *txtFiltroSource;
    TLabel *txtFiltroCat;
    TLabel *Label7;
    TLabel *Label8;
    TLabel *txtFiltroEvt;
    TLabel *txtFiltroSev;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall tvAreaChange(TObject *Sender, TTreeNode *Node);
        void __fastcall listAreaChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
        void __fastcall btAddAreaClick(TObject *Sender);
        void __fastcall btRemoveAreaClick(TObject *Sender);
        void __fastcall tvSourceChange(TObject *Sender, TTreeNode *Node);
        void __fastcall listSourcesChange(TObject *Sender, TListItem *Item,
          TItemChange Change);
        void __fastcall btRemoveSourceClick(TObject *Sender);
        void __fastcall btAddSourceClick(TObject *Sender);
        void __fastcall listEventCatChange(TObject *Sender,
          TListItem *Item, TItemChange Change);
        void __fastcall listSelectedEventCatChange(TObject *Sender,
          TListItem *Item, TItemChange Change);
        void __fastcall btRemoveCatClick(TObject *Sender);
        void __fastcall btAddCatClick(TObject *Sender);
private:
        ESTRUTURA param;
        TTreeNode *root;
        OPCEventServer *servidor;
        string listaSource[MAX_LEN_SOURCE];

        void populaTvArea(TTreeNode *parent);
        void populaTvSource(TTreeNode *parent);
        void populaListEventCategories();
        void populaListView(TListView *listView, string *list, int tam);
        void populaInfos();
        AnsiString toString(bool valor);

        void clearLista(string *lista);



public:
	virtual __fastcall TOKBottomDlg(TComponent* AOwner);
        bool getParametros(ESTRUTURA *x);
        string getServer();
        string getHost();
        string getSub();
        void setServerAndHost(string s,string h);
        void setSub(string sub);
        void setAtualFiltro(Filtro ptrStruct);

};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg *OKBottomDlg;
//----------------------------------------------------------------------------
#endif    
