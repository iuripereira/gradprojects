#include <SysUtils.hpp>
#include <SvcMgr.hpp>
#pragma hdrstop
#define Application Svcmgr::Application
USEFORM("Unt_Principal.cpp", BRAlarm_OPCAE); /* TService: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{

		Application->Initialize();
		Application->Title = "Serviço OPC AE CS - BR-AlarmExpert";
                 Application->CreateForm(__classid(TBRAlarm_OPCAE), &BRAlarm_OPCAE);
                 Application->Run();

                 
	}
	catch (Exception &exception)
	{
		//Sysutils::ShowException(&exception, Sysutils::ExceptAddr());
        //exception.Message
	}
	return 0;
}
