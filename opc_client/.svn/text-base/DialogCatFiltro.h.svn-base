//----------------------------------------------------------------------------
#ifndef DialogCatFiltroH
#define DialogCatFiltroH
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
#include <ComCtrls.hpp>
#include "DialogFilter.h"
#include "bibliotecas/defOPCSiga.h"
#include "formAE.h"
#include <stdlib.h>
#include <sstream.h>
//----------------------------------------------------------------------------
class TOKBottomDlg4 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TTreeView *tvEC;
        void __fastcall tvECChange(TObject *Sender, TTreeNode *Node);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
private:
        void clearTV();
        string servidor;
        string hostname;
        string subscription;
public:
	virtual __fastcall TOKBottomDlg4(TComponent* AOwner);
        void populaTVEC();
        void setServer(string s);
        void setHost(string h);
        void setSub(string su);
        string getItemSelected();
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg4 *OKBottomDlg4;
//----------------------------------------------------------------------------
#endif    
