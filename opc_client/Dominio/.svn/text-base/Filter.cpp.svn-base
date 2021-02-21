#include "Filter.h"

Filter::Filter()
{
}

Filter::~Filter()
{
       areas.clear();
       sources.clear();
       events.clear();
}

Filter& Filter::operator=(const Filter &opcfilter)
{
        if (this == &opcfilter) {
                return *this;
        } else {
                this->lowpriority = opcfilter.lowpriority;
                this->highpriority = opcfilter.highpriority;
                this->evtype = opcfilter.evtype;
                this->areas = opcfilter.areas;
                this->sources = opcfilter.sources;
                this->events = opcfilter.events;
                return *this;
        }        
}

unsigned long Filter::getLowPriorityValue() const
{
        return atol(lowpriority.c_str());
}

unsigned long Filter::getHighPriorityValue() const
{
        return atol(highpriority.c_str());
}

long Filter::getEvTypeValue() const
{
        return atol(evtype.c_str());
}

void Filter::addArea(const Area &area)
{
       areas.push_back(area);
}

void Filter::addSource(const Source &source)
{
       sources.push_back(source);
}

void Filter::addEventCategory(const EventCategory &event) 
{
       events.push_back(event);
}
