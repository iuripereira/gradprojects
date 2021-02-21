#include "OPCServer.h"

OPCServer::OPCServer()
{
}

OPCServer::~OPCServer()
{
        subscriptions.clear();
}

void OPCServer::addSubscription(const Subscription &subscription)
{
        subscriptions.push_back(subscription);
}
