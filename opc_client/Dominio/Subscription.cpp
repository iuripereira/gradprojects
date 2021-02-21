#pragma hdrstop

#include "Subscription.h"

#pragma package(smart_init)

Subscription::Subscription(){
}

Subscription::~Subscription(){
}

void Subscription::addFilter(const Filter &opcfilter)
{
       filter = opcfilter;
}

int Subscription::getBufferValue() const
{
      return atoi(buffer.c_str());
}

int Subscription::getMaxSizeValue() const
{
      return atoi(maxsize.c_str());
}


void Subscription::addEventCategory(const EventCategory &event)
{
       events.push_back(event);
}



