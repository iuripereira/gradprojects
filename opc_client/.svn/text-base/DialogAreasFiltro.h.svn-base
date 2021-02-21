//----------------------------------------------------------------------------
#ifndef DialogAreasFiltroH
#define DialogAreasFiltroH
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

#define MAX_LEN_AREA_FILTRO 5000
//----------------------------------------------------------------------------
class TOKBottomDlg2 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TTreeView *tvArea;
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall tvAreaChange(TObject *Sender, TTreeNode *Node);
        void __fastcall OKBtnClick(TObject *Sender);
private:
        OPCEventServer *serverOPC;
        string servidor;
        string hostname;
        string subscription;
        void clearLista(string *lista);
        void clearTV();
public:
	virtual __fastcall TOKBottomDlg2(TComponent* AOwner);
        void populaTV(TTreeNode *parent);
        void setServer(string s);
        void setHost(string h);
        void setSub(string su);
        string getItemSelected();
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg2 *OKBottomDlg2;
//----------------------------------------------------------------------------
#endif    
