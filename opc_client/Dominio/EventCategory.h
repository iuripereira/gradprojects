#ifndef _EVENTCATEGORY_H_
#define _EVENTCATEGORY_H_

#include "Attributes.h"

#include<iostream.h>
#include<list.h>

class EventCategory
{
       private:
               string name;
               int id;
               list<Attributes> attributes;
       public:
              EventCategory();
              ~EventCategory();
              inline const string getName() const {return name;};
              inline void setName(const string sname) {name = sname;};

              inline const int getId() const {return id;};
              inline void setId(const int sid) {id = sid;};

              inline const list<Attributes>& getAtributos() const {return attributes;};
              void addAtributos(const Attributes &attr);

};
       
#endif

 