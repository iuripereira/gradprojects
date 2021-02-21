#ifndef FIREBIRDDAOFACTORY_H
#define FIREBIRDDAOFACTORY_H

#include "daofactory.h"

//!
class FirebirdDAOFactory : public DAOFactory {
public:
    //!
    FirebirdDAOFactory();

    //!
    ~FirebirdDAOFactory();

    //!
    CasingDAO* getCasingDAO();

    //!
    TubingDAO* getTubingDAO();

    //!
    PlungerDAO* getPlungerDAO();

    //!
    ValveDAO* getValveDAO();

    //!
    FlowLineDAO* getFlowLineDAO();

    //!
    WellDAO* getWellDAO();

    //!
    SimulationSettingsDAO* getSimulationSettingsDAO();
};

#endif // FIREBIRDDAOFACTORY_H
