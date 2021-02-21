#include "XML.h"

/** Construtores */
XML::XML(){
}

XML::XML(string file, TXMLDocument* xml)
{
       filename = file;
       xmldoc = xml;
}

/** Destrutores */
XML::~XML()
{
       //servers.clear();
}

/** Metodos Publicos */


bool XML::readFile(){

        _di_IXMLNode node;
        OleVariant aux;

        if (!file_exists(filename.c_str())){
                return false;
        }

         xmldoc->DOMVendor = GetDOMVendor("Open XML");
        // Le o arquivo xml especificado em filename
        xmldoc->LoadFromFile(WideString(filename.c_str()));
        // Retorna o elemento raiz do arquivo xml
        _di_IXMLNode root = xmldoc->DocumentElement;
        // Atributos vinculados ao nó raiz
        _di_IXMLNodeList nodes = root->GetChildNodes();
         // Realiza a leitura dos servidores

         if (nodes == NULL){
            return false;
         }
        
        int qnt;
        qnt  = nodes->GetCount();


        _di_IXMLNodeList nodesServer = nodes->Get(0)->GetChildNodes();
        _di_IXMLNode nodesTcp = nodes->Get(1);

        if (nodesServer == NULL || nodesTcp == NULL){
            return false;
        }

        for(int icount1=0; icount1 < nodesServer->GetCount(); icount1++) {

                OPCServer server = *(new OPCServer());
                node = nodesServer->Get(icount1);
                aux = node->GetAttribute(XML_SERVER_NAME);
                server.setName(WideCharToString(aux.VOleStr).c_str());
                aux = node->GetAttribute(XML_SERVER_HOST);
                server.setHost(WideCharToString(aux.VOleStr).c_str());

                /* Realiza a leitura da tag subscription */
                
                _di_IXMLNodeList subnodes = node->GetChildNodes();
                subnodes = subnodes->Get(0)->GetChildNodes();

                for(int icount2=0; icount2 < subnodes->GetCount(); icount2++) {

                        Subscription sub = *(new Subscription());
                        node = subnodes->Get(icount2);
                        aux = node->GetAttribute(XML_SUBSCRIPTION_NAME);
                        sub.setName(WideCharToString(aux.VOleStr).c_str());
                        aux = node->GetAttribute(XML_SUBSCRIPTION_BUFFER);
                        sub.setBuffer(WideCharToString(aux.VOleStr).c_str());
                        aux = node->GetAttribute(XML_SUBSCRIPTION_MAXSIZE);
                        sub.setMaxSize(WideCharToString(aux.VOleStr).c_str());

                        /* leitura do atributos */


                        _di_IXMLNode attributes = node->GetChildNodes()->FindNode(XML_XPATH_ATTRIBUTES);                        _di_IXMLNodeList attribute = attributes->GetChildNodes();

                        string strValor;

                         for(int icount3=0; icount3 < attribute->GetCount(); icount3++) {

                                EventCategory ev = *(new EventCategory());

                                _di_IXMLNode idAttributeList  = attribute->Get(icount3);

                                aux = idAttributeList->GetAttribute(XML_ATTRIBUTES_CATEGORY);
                                strValor = WideCharToString(aux.VOleStr).c_str();

                                try{
                                    ev.setId(StrToInt(strValor.c_str()));
                                }catch (...){
                                    ev.setId(-1);
                                }

                                _di_IXMLNodeList idAttribute = idAttributeList->GetChildNodes();

                                 for(int icount4=0; icount4 < idAttribute->GetCount(); icount4++) {

                                     Attributes atr = *(new Attributes());

                                     _di_IXMLNode idAttr = idAttribute->Get(icount4);
                                     aux = idAttr->GetAttribute(XML_ATTRIBUTES_ID);
                                     strValor = WideCharToString(aux.VOleStr).c_str();

                                     try{
                                     //string strTmp = strValor.c_str();
                                     //atr.setIdAtributo((unsigned int)StrToInt(strTmp.c_str()));
                                     }catch (...){
                                         atr.setIdAtributo(-1);
                                     }

                                     ev.addAtributos(atr);

                                 }

                                 sub.addEventCategory(ev);
                        }


                        /* Realiza a leitura do filtro */
                        
                        Filter fil = *(new Filter());
                        _di_IXMLNode filter = node->GetChildNodes()->FindNode(XML_XPATH_FILTER);
                        aux = filter->GetAttribute(XML_FILTER_HIGHPRIORITY);
                        fil.setHighPriority(WideCharToString(aux.VOleStr).c_str());
                        aux = filter->GetAttribute(XML_FILTER_LOWPRIORITY);
                        fil.setLowPriority(WideCharToString(aux.VOleStr).c_str());
                        aux = filter->GetAttribute(XML_FILTER_EVTYPE);
                        fil.setEvType(WideCharToString(aux.VOleStr).c_str());

                        /* Realiza a leitura das áreas filtro */

                        _di_IXMLNode area = filter->GetChildNodes()->FindNode(XML_XPATH_AREAS);
                        _di_IXMLNodeList areanodes = area->GetChildNodes();

                        for(int icount3=0; icount3 < areanodes->GetCount(); icount3++) {
                                Area ar = *(new Area());
                                area = areanodes->Get(icount3);
                                aux = area->GetAttribute(XML_AREA_NAME);
                                ar.setName(WideCharToString(aux.VOleStr).c_str());
                                fil.addArea(ar);
                        }

                        /* Realiza a leitura das sources filtro */

                        _di_IXMLNode source= filter->GetChildNodes()->FindNode(XML_XPATH_SOURCES);
                        _di_IXMLNodeList srcnodes = source->GetChildNodes();

                        for(int icount3=0; icount3 < srcnodes->GetCount(); icount3++) {
                                Source src = *(new Source());
                                source = srcnodes->Get(icount3);
                                aux = source->GetAttribute(XML_SOURCE_NAME);
                                src.setName(WideCharToString(aux.VOleStr).c_str());
                                fil.addSource(src);
                        }

                        //Retorna events do filtro

                        _di_IXMLNode event = filter->GetChildNodes()->FindNode(XML_XPATH_EVENTS);
                        _di_IXMLNodeList evtnodes = event->GetChildNodes();

                        for(int icount3=0; icount3 < evtnodes->GetCount(); icount3++) {
                                EventCategory evt = *(new EventCategory());
                                event = evtnodes->Get(icount3);
                                aux = event->GetAttribute(XML_EVENT_NAME);
                                evt.setName(WideCharToString(aux.VOleStr).c_str());
                                fil.addEventCategory(evt);
                        }
                        sub.addFilter(fil);
                        server.addSubscription(sub);
                }
                servers.push_back(server);
        }

        aux = nodesTcp->GetAttribute(XML_IP_NAME);
        this->host = WideCharToString(aux.VOleStr).c_str();
        aux = nodesTcp->GetAttribute(XML_PORTA_NAME);
        this->porta = WideCharToString(aux.VOleStr).c_str();

        return true;

}

bool XML::writeFile(map<string, OPCEventServer *> mapES, string host, string porta){

string path;
        string arquivo;

        short pos = filename.rfind("/",filename.size());
        if (pos < 0) {
                pos = filename.rfind("\\",filename.size());
                if (pos < 0) {
                        return  false;
                }
        }

        path = filename.substr(0,pos+1);
        arquivo = filename.substr(pos+1,filename.size());

        bool returnValue = true;

        if (!file_exists(path.c_str())){
            returnValue = CreateDirectory(path.c_str(), NULL);
        }

        if (returnValue){

            xmldoc->FileName = "";
            xmldoc->Active = true;

            xmldoc->Encoding = "UTF-8";
            xmldoc->Version = "1.0";
            xmldoc->StandAlone = "yes";

            _di_IXMLNode root = xmldoc->AddChild(XML_XPATH_ROOT);

            map<string, OPCEventServer *>::iterator iter;
            OPCEventServer *opcES;

            _di_IXMLNode servers = root->AddChild(XML_XPATH_SERVERS);

            for(iter = mapES.begin(); iter != mapES.end(); iter++){

                    opcES = iter->second;

                    if(opcES != NULL){

                        _di_IXMLNode server = servers->AddChild(XML_XPATH_SERVER);

                        server->Attributes[XML_SERVER_NAME] = WideString(opcES->getNameServer().c_str());                        server->Attributes[XML_SERVER_HOST] = WideString(opcES->getHostServer().c_str());
                        map<string, OPCEventSubscription*> *mapaSub;
                        map<string, OPCEventSubscription *>::iterator iterSub;

                        mapaSub = opcES->getSubscritions();

                        OPCEventSubscription *opcESub;
                        _di_IXMLNode subscriptions = server->AddChild(XML_XPATH_SUBSCRIPTIONS);

                        for(iterSub = mapaSub->begin(); iterSub != mapaSub->end(); iterSub++){

                            opcESub = iterSub->second;

                            if (opcESub == NULL){
                                break;
                            }

                            _di_IXMLNode sub = subscriptions->AddChild(XML_XPATH_SUB);
                            sub->Attributes[XML_SUBSCRIPTION_NAME] = WideString(opcESub->getNomeSub().c_str());                            sub->Attributes[XML_SUBSCRIPTION_BUFFER] = WideString(opcESub->getMaxBufferTime());                            sub->Attributes[XML_SUBSCRIPTION_MAXSIZE] = WideString(opcESub->getMaxSize());
                            /* inclui atributos */

                            _di_IXMLNode attributos = sub->AddChild(XML_XPATH_ATTRIBUTES);

                            DWORD listEvtCat[MAX_LEN];
                            string listAttr[MAX_LEN];

                            int qntEvtCat,qntAttr;

                            qntEvtCat = opcESub->getEventCategoriesAttr(listEvtCat);

                            stringstream out;
                            long temp;
                            string tempStr;

                            for (int i=0;i<qntEvtCat;i++){

                                _di_IXMLNode attr = attributos->AddChild(XML_ATTRIBUTES);
                                temp = (long)listEvtCat[i];
                                out << temp;
                                tempStr = out.str();

                                attr->Attributes[XML_ATTRIBUTES_CATEGORY] = WideString(tempStr.c_str());
                                qntAttr = opcESub->getAttributes(listEvtCat[i],listAttr);

                                for (int j=0;j<qntAttr;j++){
                                    _di_IXMLNode attrId = attr->AddChild(XML_ATTRIBUTES_IDATTR);
                                    attrId->Attributes[XML_ATTRIBUTES_ID] = WideString(listAttr[j].c_str());                                }

                            }

                            /* inclui filtros */

                            Filtro myFiltro;
                            opcESub->getFiltro(&myFiltro);

                            string *listaArea;
                            int countArea;
                            string *listaSources;
                            int countSources;
                            string *evtCat;
                            int countEvtCat;

                            listaArea = myFiltro.pszAreaList;
                            countArea = myFiltro.numArea;
                            listaSources = myFiltro.pszSourceList;
                            countSources = myFiltro.numSources;
                            evtCat = myFiltro.ptEventCategories;
                            countEvtCat = myFiltro.countEventCategory;

                            _di_IXMLNode filtro = sub->AddChild(XML_XPATH_FILTER);
                            filtro->Attributes[XML_FILTER_HIGHPRIORITY] = WideString(myFiltro.sevHigh);                            filtro->Attributes[XML_FILTER_LOWPRIORITY] = WideString(myFiltro.sevLow);
                            filtro->Attributes[XML_FILTER_EVTYPE] = WideString(myFiltro.evtType);

                            _di_IXMLNode areas = filtro->AddChild(XML_XPATH_AREAS);

                            for (int i=0;i<countArea;i++){
                                _di_IXMLNode area = areas->AddChild(XML_XPATH_AREA);
                                area->Attributes[XML_AREA_NAME] = WideString(listaArea[i].c_str());
                            }

                            _di_IXMLNode sources = filtro->AddChild(XML_XPATH_SOURCES);

                            for (int i=0;i<countSources;i++){
                                _di_IXMLNode source = sources->AddChild(XML_XPATH_SOURCE);
                                source->Attributes[XML_SOURCE_NAME] = WideString(listaSources[i].c_str());                            }

                            _di_IXMLNode evCats = filtro->AddChild(XML_XPATH_EVENTS);

                            for (int i=0;i<countEvtCat;i++){
                                _di_IXMLNode evCat = evCats->AddChild(XML_XPATH_EVENT);
                                evCat->Attributes[XML_EVENT_NAME] = WideString(evtCat[i].c_str());
                            }

                        }
                    }
            }

             _di_IXMLNode tcp = root->AddChild(XML_TCP_NAME);
             tcp->Attributes[XML_IP_NAME] = WideString(host.c_str());
             tcp->Attributes[XML_PORTA_NAME] = WideString(porta.c_str());

            xmldoc->SaveToFile(WideString((path+arquivo).c_str()));

            xmldoc->Active = false;

            return true;

        }else{

            logger.addLinhaLog("Falha ao tentar criar diretório para salvar configurações");
            return false;
        }
}



