//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("DialogCreateSubscription.cpp", OKBottomDlg1);
USEFORM("formAE.cpp", Form1);
USEFORM("DialogFilter.cpp", OKBottomDlg);
USEFORM("DialogAtributos.cpp", dialogAttributes);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
             Application->Initialize();
             Application->Title = "BR-AlarmExpert - Coletor OPC A&E";
         Application->CreateForm(__classid(TForm1), &Form1);
         Application->CreateForm(__classid(TOKBottomDlg1), &OKBottomDlg1);
         Application->CreateForm(__classid(TOKBottomDlg), &OKBottomDlg);
         Application->CreateForm(__classid(TdialogAttributes), &dialogAttributes);
         Application->Run();
         

            
        }
        catch (Exception &exception)
        {
                 //Application->ShowException(&exception);
        }
        catch (...)
        {
                 /*
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
                 */
        }
        return 0;
}
//---------------------------------------------------------------------------
