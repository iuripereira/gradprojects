#ifndef DAOFACTORY_H
#define DAOFACTORY_H

#include "casingdao.h"
#include "tubingdao.h"
#include "plungerdao.h"
#include "valvedao.h"
#include "flowlinedao.h"
#include "simulationsettingsdao.h"
#include "welldao.h"

//!
class DAOFactory {
public:
    //!
    DAOFactory();

    //!
    virtual ~DAOFactory();

    //!
    static const int FIREBIRD = 1;

    //!
    static const int POSTGRES = 2;

    //!
    static const int MYSQL = 3;

    //!
    virtual CasingDAO* getCasingDAO() = 0;

    //!
    virtual TubingDAO* getTubingDAO() = 0;

    //!
    virtual PlungerDAO* getPlungerDAO() = 0;

    //!
    virtual ValveDAO* getValveDAO() = 0;

    //!
    virtual FlowLineDAO* getFlowLineDAO() = 0;

    //!
    virtual WellDAO* getWellDAO() = 0;

    //!
    virtual SimulationSettingsDAO* getSimulationSettingsDAO() = 0;

    //!
    static DAOFactory* getFactory(int factory);
};
#endif // DAOFACTORY_H
