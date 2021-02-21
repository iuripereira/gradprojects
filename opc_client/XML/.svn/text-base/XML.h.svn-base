#ifndef _XML_H_
#define _XML_H_

#include<xmldom.hpp>
#include<XMLDoc.hpp>

#include <map>
#include <io.h>

#include "OPCServer.h"
#include "OPCEventServer.h"
#include "../Logger.h"

// Strings dos elementos do arquivo XML

 static DOMString XML_XPATH_ROOT="configuracoes";

 static DOMString XML_XPATH_SERVERS="servidores";
 static DOMString XML_XPATH_SERVER="servidor";
 static DOMString XML_SERVER_NAME="nome";
 static DOMString XML_SERVER_HOST="host";

 static DOMString XML_XPATH_SUBSCRIPTIONS="subscriptions";
 static DOMString XML_XPATH_SUB="sub";
 static DOMString XML_SUBSCRIPTION_NAME="nome";
 static DOMString XML_SUBSCRIPTION_BUFFER="maxBufferTime";
 static DOMString XML_SUBSCRIPTION_MAXSIZE="maxSize";

 static DOMString XML_XPATH_ATTRIBUTES="attributes";
 static DOMString XML_ATTRIBUTES="attribute";
 static DOMString XML_ATTRIBUTES_IDATTR="idAtributo";
 static DOMString XML_ATTRIBUTES_ID="id";
 static DOMString XML_ATTRIBUTES_CATEGORY="category";  

 static DOMString XML_XPATH_FILTER="filtro";
 static DOMString XML_FILTER_LOWPRIORITY="prioridadeBaixa";
 static DOMString XML_FILTER_HIGHPRIORITY="prioridadeAlta";
 static DOMString XML_FILTER_EVTYPE="evType";

 static DOMString XML_XPATH_AREAS="areas";
 static DOMString XML_XPATH_AREA="area";
 static DOMString XML_AREA_NAME="nome";

 static DOMString XML_XPATH_SOURCES="sources";
 static DOMString XML_XPATH_SOURCE="source";
 static DOMString XML_SOURCE_NAME="nome";

 static DOMString XML_XPATH_EVENTS="eventcategories";
 static DOMString XML_XPATH_EVENT="eventcat";
 static DOMString XML_EVENT_NAME="nome";

 static DOMString XML_TCP_NAME="tcp";
 static DOMString XML_IP_NAME="ip";
 static DOMString XML_PORTA_NAME="porta";

class XML {
        private:
                string filename; // path e nome do arquivo XML
                list<OPCServer> servers; // Lista contendo os servidores OPC A&E
                TXMLDocument* xmldoc; //
                Logger logger;
                string porta;
                string host;
                inline bool file_exists(const char *file) const {return (access(file, 0) == 0);};
        public:
                XML();
                XML(string file,TXMLDocument* xml);
                ~XML();
                inline const string getFilename() const {return filename;};

                inline const list<OPCServer>& getServers() const {return servers;};
                inline const string getPorta() const {return porta;};
                inline const string getHost() const {return host;};
                bool readFile();
                bool writeFile(map<string, OPCEventServer *> mapES, string host, string porta);

};

#endif
