//---------------------------------------------------------------------------


#pragma hdrstop

#include "OPCFilter.h"


//---------------------------------------------------------------------------

#pragma package(smart_init)


OPCFilter::OPCFilter(IOPCEventSubscriptionMgt *ptsub){
        ptrEventSubMgt = ptsub;
}

OPCFilter::~OPCFilter(){
}

void OPCFilter::setPtEvCat(DWORD *pt){
        ptEvCat = pt;
}

void OPCFilter::setarFiltro(DWORD tipo){
        ptrEventSubMgt->SetFilter()
}

