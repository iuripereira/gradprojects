//---------------------------------------------------------------------------

#pragma hdrstop
#pragma package(smart_init)

#include "Com.h"

Com::Com()
{
        status=false;
}

Com::~Com()
{}

HRESULT Com::startCom()
{
        HRESULT tmp;
        tmp = CoInitialize(NULL);
        (tmp==S_OK?status=true:status=false);
        return tmp;
}
bool Com::getStatus()
{
        return status;
}
void Com::stopCom()
{
        CoUninitialize();
        status = false;
}

//---------------------------------------------------------------------------


