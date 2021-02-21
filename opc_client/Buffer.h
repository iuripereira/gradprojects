//---------------------------------------------------------------------------

#ifndef BufferH
#define BufferH

#define MAX_ATTRIBUTES 100

#include "System.hpp"
#include <sstream.h>

class Buffer{
        private:
                string           lpszString;
                string           lpszActiveString;
                string           qldStr;
                unsigned short   qld;
                string           szMsg;
                string           szSrc;
                string           changeMaskSrt;
                unsigned short   changeMask;
                string           newStateStr;
                unsigned short   newState;
                string           evTypeStr;
                unsigned short   evType;
                string           evCategory;
                string           severity;
                string           conditionName;
                string           subConditionName;
                bool             ackRequired;
                string           ackRequiredStr;
                string           actorID;
                string           nomeSub;
                int              cookie;

                string           attributos[MAX_ATTRIBUTES];
                int              qntAtrr;

        public:
                Buffer();
                ~Buffer();
                string getTime();
                void setTime(string time);

                unsigned short getQuality();
                void setQuality(unsigned short qualidade);
                string getQualityStr();
                void setQualityStr(string qualidade);

                string getMessage();
                void setMessage(string msg);
                string getSource();
                void setSource(string src);

                string getCMaskStr();
                void setCMaskStr(string cm);
                unsigned short getCMask();
                void setCMask(unsigned short cm);

                string getNewStateStr();
                void setNewStateStr(string ns);
                unsigned short getNewState();
                void setNewState(unsigned short ns);

                string getEventTypeStr();
                void setEventTypeStr(string et);
                unsigned short getEventType();
                void setEventType(unsigned short et);

                string getEventCategory();
                void setEventCategory(string ec);
                string getSeverity();
                void setSeverity(string sev);
                string getCondName();
                void setCondName(string cn);
                string getSubCondName();
                void setSubCondName(string scn);
                bool getAckRequired();
                void setAckRequired(bool ar);
                string getAckRequiredString();
                void setAckRequiredString(string ars);
                string getactorID();
                void setactorID(string aID);
                string getNomeSub();
                void setNomeSub(string nome);
                void setCookie(int c);
                int getCookie();
                string getActiveTime();
                void setActiveTime(string time);

                void setAttr(string *attr, int qnt);
                void getAttr(string *listaAttr);
                int getQntAttr();

};

//---------------------------------------------------------------------------
#endif
