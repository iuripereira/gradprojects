//---------------------------------------------------------------------------


#pragma hdrstop

#include "OPCBridge.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

OPCBridge::OPCBridge(TForm1 *f){
        form = f;
}

OPCBridge::~OPCBridge(){
}

bool OPCBridge::disconectAndDeleteInterface(string host, string server){

        form->disconect(host,server);
        return true;
}
