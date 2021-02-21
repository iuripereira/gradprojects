#ifndef _SUBSCRIPTION_H_
#define _SUBSCRIPTION_H_

#include "Filter.h"
#include "EventCategory.h"

class Subscription {

       private:
               string name;
               string buffer;
               string maxsize;
               Filter filter;
               list<EventCategory> events;

       public:
              Subscription();
              ~Subscription();
              inline const string getName() const {return name;};
              inline const string getBuffer() const {return buffer;};
              inline const string getMaxSize() const {return maxsize;};
              inline void setName(const string sname) {name = sname;};
              inline void setBuffer(const string sbuffer) {buffer = sbuffer;};
              inline void setMaxSize(const string smaxsize) {maxsize = smaxsize;};
              inline const Filter& getFilter() const {return filter;};
              void addFilter(const Filter &opcfilter);
              int getBufferValue() const;
              int getMaxSizeValue() const;

              inline const list<EventCategory>& getEventCategories() const {return events;};
              void addEventCategory(const EventCategory &event);
};

#endif

 