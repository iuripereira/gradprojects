//----------------------------------------------------------------------------
#ifndef DialogTCPH
#define DialogTCPH
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
//----------------------------------------------------------------------------
class TOKBottomDlg3 : public TForm
{
__published:
    TGroupBox *GroupBox1;
    TLabel *Label1;
    TEdit *Edit1;
    TLabel *Label2;
    TEdit *Edit2;
    TButton *OKBtn;
    TButton *CancelBtn;
        void __fastcall CancelBtnClick(TObject *Sender);
        void __fastcall OKBtnClick(TObject *Sender);
private:
public:
	virtual __fastcall TOKBottomDlg3(TComponent* AOwner);
};
//----------------------------------------------------------------------------
extern PACKAGE TOKBottomDlg3 *OKBottomDlg3;
//----------------------------------------------------------------------------
#endif    
