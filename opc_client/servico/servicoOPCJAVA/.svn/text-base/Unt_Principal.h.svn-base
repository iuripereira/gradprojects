//---------------------------------------------------------------------------
#ifndef Unt_PrincipalH
#define Unt_PrincipalH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <SvcMgr.hpp>
#include <vcl.h>

#include <time.h>
#include <string>
#include <stdio.h>

using std::string;

#include <stdio.h>
//---------------------------------------------------------------------------
class TBRAlarm_OPCAE : public TService
{
__published:    // IDE-managed Components
        void __fastcall ServiceExecute(TService *Sender);
        void __fastcall ServiceStop(TService *Sender, bool &Stopped);
private:        // User declarations

        AnsiString pathLog;
        AnsiString fileNameLOG;
  
public:         // User declarations
	__fastcall TBRAlarm_OPCAE(TComponent* Owner);
	TServiceController __fastcall GetServiceController(void);

	friend void __stdcall ServiceController(unsigned CtrlCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TBRAlarm_OPCAE *BRAlarm_OPCAE;
//---------------------------------------------------------------------------
#endif
