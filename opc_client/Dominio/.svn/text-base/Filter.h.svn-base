#ifndef _FILTER_H_
#define _FILTER_H_

#include<stdlib.h>
#include<list.h>

#include "Area.h"
#include "Source.h"
#include "EventCategory.h"

class Filter
{
       private:
              string lowpriority;
              string highpriority;
              string evtype;
              list<Area> areas;
              list<Source> sources;
              list<EventCategory> events;
        public:
              Filter();
              ~Filter();
              inline const string getLowPriority() const {return lowpriority;};
              inline const string getHighPriority() const {return highpriority;};
              inline const string getEvType() const {return evtype;};
              inline void setLowPriority(const string priority) {lowpriority = priority;};
              inline void setHighPriority(const string priority) {highpriority = priority;};
              inline void setEvType(const string sevtype) {evtype = sevtype;};
              Filter& operator=(const Filter & opcfilter);
              unsigned long getLowPriorityValue() const;
              unsigned long getHighPriorityValue() const;
              long getEvTypeValue() const;
              inline const list<Area>& getAreas() const {return areas;};
              inline const list<Source>& getSources() const {return sources;};
              inline const list<EventCategory>& getEventCategories() const {return events;};
              void addArea(const Area &area);
              void addSource(const Source &source);
              void addEventCategory(const EventCategory &event);
};

#endif
