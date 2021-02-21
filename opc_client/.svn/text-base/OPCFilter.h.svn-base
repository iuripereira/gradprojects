//---------------------------------------------------------------------------

#ifndef OPCFilterH
#define OPCFilterH

#include "OPCEventSubscription.h"

class OPCFilter{

        private:
                IOPCEventSubscriptionMgt *ptrEventSubMgt;
                DWORD tipoEvento;
                DWORD numCat;
                DWORD* ptEvCat;

        public:
                OPCFilter(IOPCEventSubscriptionMgt*);
                ~OPCFilter();
                void setarFiltro();
                void setPtEvCat(DWORD*);

};


//---------------------------------------------------------------------------
#endif
