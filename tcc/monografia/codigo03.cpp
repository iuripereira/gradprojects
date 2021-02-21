#include "firebirddaofactory.h"
#include "firebirdcasingdao.h"
#include "firebirdtubingdao.h"
#include "firebirdplungerdao.h"
#include "firebirdvalvedao.h"
#include "firebirdflowlinedao.h"
#include "firebirdsimulationsettingsdao.h"
#include "firebirdwelldao.h"

FirebirdDAOFactory::FirebirdDAOFactory() {
}

FirebirdDAOFactory::~FirebirdDAOFactory() {
    std::cout << "Destruindo FirebirdDAOFactory..." << std::endl;
}

CasingDAO* FirebirdDAOFactory::getCasingDAO() {
    return new FirebirdCasingDAO();
}

TubingDAO* FirebirdDAOFactory::getTubingDAO() {
    return new FirebirdTubingDAO();
}

PlungerDAO* FirebirdDAOFactory::getPlungerDAO() {
    return new FirebirdPlungerDAO();
}

ValveDAO* FirebirdDAOFactory::getValveDAO() {
    return new FirebirdValveDAO();
}

FlowLineDAO* FirebirdDAOFactory::getFlowLineDAO() {
    return new FirebirdFlowLineDAO();
}

WellDAO* FirebirdDAOFactory::getWellDAO() {
    return new FirebirdWellDAO();
}

SimulationSettingsDAO* FirebirdDAOFactory::getSimulationSettingsDAO() {
    return new FirebirdSimulationSettingsDAO();
}
