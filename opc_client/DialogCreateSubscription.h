//----------------------------------------------------------------------------
#ifndef DialogCreateSubscriptionH
#define DialogCreateSubscriptionH
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

#include "formAE.h"

//----------------------------------------------------------------------------
class TOKBottomDlg1 : public TForm
{
__published:        
	TButton *OKBtn;
	TButton *CancelBtn;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *nomeTxt;
        TEdit *bufferTxt;
        TEdit *maxSizeTxt;
        void __fastcall OKBtnClick(TObject *Sender);
        void __fastcall CancelBtnClick(TObject *Sender);
private:
        bool    btOk;
        string serverDlg;
        string hostDlg;

public:
	virtual __fastcall TOKBottomDlg1(TComponent* AOwner);
        string getNome();
        int getBuffer();
        int getMaxSize();
        bool getBtOk();
        void clearAll();
        string getHost();
        string getServer();
        void setServer(string s);
        void setHost(string h);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg1 *OKBottomDlg1;
//----------------------------------------------------------------------------
#endif    
