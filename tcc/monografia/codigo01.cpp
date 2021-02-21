...
// Criando a f�brica firebird a partir da f�brica abstrata
DAOFactory* firebirdFactory = DAOFactory::getFactory(DAOFactory::FIREBIRD);

// Criando os DAOs
PlungerDAO* plungerDAO = firebirdFactory->getPlungerDAO();

// Criando o objeto de transfer�ncia
PlungerData* plunger = new PlungerData();

// Atribuindo alguns valores aos objetos de transfer�ncia
plunger->fenceEfficiency = 23.98;
plunger->length = 0.1;
plunger->mass = 0.04
plunger->unitTypeFallInLiquidVelocity = 1;
plunger->fallInLiquidVelocity = 12.0;
plunger->unitTypeFallInGasVelocity = 1;
plunger->fallInGasVelocity = 34.43;
plunger->diameter = 2.5;
plunger->diameter_txt = "2 1/2"

// Salvando o objeto de transfer�ncia
int c = plungerDAO->insertPlunger(plunger);

// Excluindo os ponteiros
delete plunger;
delete plungerDAO;
delete firebirdFactory;
...
