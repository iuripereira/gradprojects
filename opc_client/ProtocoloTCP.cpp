//---------------------------------------------------------------------------
#pragma hdrstop
#pragma package(smart_init)

#include "ProtocoloTCP.h"

ProtocoloTCP::ProtocoloTCP(){
}

ProtocoloTCP::~ProtocoloTCP(){
}

string ProtocoloTCP::intToString(int value){

    char tmp[10];
    itoa((int)value, tmp, 10);
    string tmpR = tmp;
    return tmpR;

}

string ProtocoloTCP::boolToString(bool value){

    if (value){
        return "1";
    }else{
        return "0";
    }

}

AnsiString ProtocoloTCP::geraProtocol(Buffer *buffer){

        string protocol = "";
        int qntAttr = 0;
        string listAttr[MAX_ATTRIBUTES];

        protocol.append(buffer->getSource());
        protocol.append("&?&"+buffer->getTime());
        protocol.append("&?&"+buffer->getActiveTime());
        protocol.append("&?&"+buffer->getMessage());
        protocol.append("&?&"+intToString(buffer->getQuality()));
        protocol.append("&?&"+intToString(buffer->getCMask()));
        protocol.append("&?&"+intToString(buffer->getNewState()));
        protocol.append("&?&"+intToString(buffer->getEventType()));
        protocol.append("&?&"+buffer->getEventCategory());
        protocol.append("&?&"+buffer->getSeverity());
        protocol.append("&?&"+buffer->getCondName());
        protocol.append("&?&"+buffer->getSubCondName());
        protocol.append("&?&"+buffer->getNomeSub());
        protocol.append("&?&"+boolToString(buffer->getAckRequired()));
        protocol.append("&?&"+buffer->getactorID());

        buffer->getAttr(listAttr);
        qntAttr = buffer->getQntAttr();

        if (qntAttr > MAX_ATTRIBUTES){
            qntAttr = MAX_ATTRIBUTES;
        }

        for (int i=0;i<qntAttr;i++){
            protocol.append("&?&"+listAttr[i]);
        }

        protocol.append("&?&");
        protocol.append("#?#");

        return protocol.c_str();
}

//---------------------------------------------------------------------------


