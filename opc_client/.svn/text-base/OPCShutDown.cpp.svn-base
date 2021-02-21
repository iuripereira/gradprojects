//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)
#include "OPCShutDown.h"


OPCShutDown::OPCShutDown(){
        m_cRef = 0;
}

OPCShutDown::OPCShutDown(OPCEventServer *ptr){
        m_cRef = 0;
        ptrES = ptr;
}

OPCShutDown::~OPCShutDown(){

}

STDMETHODIMP OPCShutDown::QueryInterface(REFIID riid, void** ppv){

        *ppv=NULL;

        if (IID_IUnknown == riid || IID_IOPCShutdown == riid){
                *ppv=this;
        }

        if (NULL!=*ppv){
                ((LPUNKNOWN)*ppv)->AddRef();
                return NOERROR;
        }

        return ResultFromScode(E_NOINTERFACE);
}


STDMETHODIMP_(ULONG) OPCShutDown::AddRef(void){
        return ++m_cRef;
}


STDMETHODIMP_(ULONG) OPCShutDown::Release(void)
{
        if (0 != --m_cRef){
                return m_cRef;
        }

        delete this;
        return 0;
}

STDMETHODIMP OPCShutDown::ShutdownRequest(/* [string][in] */ LPCWSTR szReason){

        wchar_t teste[ 500 ];
        //wcscpy(teste,szReason);
        wcscpy(teste,szReason);
        string razao = WideCharToString(teste).c_str();

        if (ptrES->disconect()){
                logger.addLinhaLog("ShutDown foi chamado e o servidor desconectou! Razão: "+razao);
        }else{
                logger.addLinhaLog("ShutDown foi chamado porém o servidor NÃO desconectou! Razão do shutdown: "+razao);
        }
        return S_OK;
}



//---------------------------------------------------------------------------




