#ifndef _OPCSERVER_H_
#define _OPCSERVER_H_

#include "Subscription.h"

class OPCServer {
       private:
               string name;
               string host;
               list<Subscription> subscriptions;
       public:
              OPCServer();
              ~OPCServer();
              inline const string getName() const {return name;};
              inline void setName(const string sname) {name = sname;};
              inline const string getHost() const {return host;};
              inline void setHost(const string shost) {host = shost;};
              void addSubscription(const Subscription &subscription);
              inline const list<Subscription>& getSubscriptions() const {return subscriptions;};
};

#endif

 