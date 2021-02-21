//----------------------------------------------------------------------------
#ifndef DialogSourceFiltroH
#define DialogSourceFiltroH
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
#include "DialogFilter.h"
#include <ComCtrls.hpp>
#include "bibliotecas/defOPCSiga.h"
#include "formAE.h"
#include <stdlib.h>
#include <sstream.h>

#define MAX_LEN_SOURCE 5000

//----------------------------------------------------------------------------
class TOKBottomDlg3 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TTreeView *tvSource;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall tvSourceChange(TObject *Sender, TTreeNode *Node);
        void __fastcall OKBtnClick(TObject *Sender);
private:
        string servidor;
        string hostname;
        string subscription;
        string listaSource[MAX_LEN_SOURCE];
        void clearLista(string *lista);
        void clearTV();
public:
	virtual __fastcall TOKBottomDlg3(TComponent* AOwner);
        void setSub(string su);
        void setHost(string h);
        void setServer(string s);
        void populaTVSources(TTreeNode *parent);
        string getItemSelected();
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg3 *OKBottomDlg3;
//----------------------------------------------------------------------------
#endif    
