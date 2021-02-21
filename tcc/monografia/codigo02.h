#ifndef FIREBIRDPLUNGERDAO_H
#define FIREBIRDPLUNGERDAO_H

#include "plungerdao.h"

class FirebirdPlungerDAO : public PlungerDAO {
public:
    //! Construtor padrão
    FirebirdPlungerDAO();

    //! Destrutor padrão
    ~FirebirdPlungerDAO();

    //! Salvar um plunger
    int insertPlunger(PlungerData* plunger);

    //! Excluir um plunger
    bool deletePlunger(PlungerData* plunger);

    //! Buscar um plunger pelo id
    PlungerData* findPlunger(int id);

    //! Atualizar um plunger
    bool updatePlunger(PlungerData* plunger);

    //! Buscar todos os plungers cadastrados
    std::vector<PlungerData*>* selectPlungerTO(PlungerData* plunger);
};

#endif // FIREBIRDPLUNGERDAO_H
