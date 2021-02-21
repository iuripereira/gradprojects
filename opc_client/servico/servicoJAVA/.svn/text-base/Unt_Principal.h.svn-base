//---------------------------------------------------------------------------
#ifndef Unt_PrincipalH
#define Unt_PrincipalH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <SvcMgr.hpp>
#include <vcl.h>

#include <stdio.h>
//---------------------------------------------------------------------------
class TOPCAE : public TService
{
__published:    // IDE-managed Components
        void __fastcall ServiceExecute(TService *Sender);
        void __fastcall ServiceStop(TService *Sender, bool &Stopped);
private:        // User declarations
public:         // User declarations
	__fastcall TOPCAE(TComponent* Owner);
	TServiceController __fastcall GetServiceController(void);

	friend void __stdcall ServiceController(unsigned CtrlCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TOPCAE *OPCAE;
//---------------------------------------------------------------------------
#endif
