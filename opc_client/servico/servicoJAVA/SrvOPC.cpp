#include <SysUtils.hpp>
#include <SvcMgr.hpp>
#pragma hdrstop
#define Application Svcmgr::Application
USERES("SrvOPC.res");
USEFORM("Unt_Principal.cpp", OPCAE); /* TService: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{

		Application->Initialize();
		Application->Title = "Serviço OPC AE S - BR-AlarmExpert";
                 Application->CreateForm(__classid(TOPCAE), &OPCAE);
                 Application->Run();

                 
	}
	catch (Exception &exception)
	{
		//Sysutils::ShowException(&exception, Sysutils::ExceptAddr());
        //exception.Message
	}
	return 0;
}
