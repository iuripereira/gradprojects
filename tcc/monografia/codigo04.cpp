#include "daofactory.h"
#include "firebirddaofactory.h"

DAOFactory::DAOFactory() {
}

DAOFactory::~DAOFactory() {
    std::cout << "Destruindo DAOFactory..." << std::endl;
}

DAOFactory* DAOFactory::getFactory(int factory) {
    switch(factory) {
    case FIREBIRD:
        return new FirebirdDAOFactory();
    case POSTGRES:
        return NULL;
    case MYSQL:
        return NULL;
    default:
        return NULL;
    }
}
