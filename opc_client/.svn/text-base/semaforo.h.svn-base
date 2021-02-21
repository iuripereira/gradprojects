/***************************************************************************
                          semaforo.h  -  Classe que cria um semáforo binário.
                             -------------------
    begin                : Qui Jan 27 2005
    copyright            : (C) 2005 by Wany Andrade
***************************************************************************/

#include <windows.h>

class Semaforo {
        private:
                HANDLE hSemaforo;
        public:
                Semaforo(int numUnidades=1, int maxUnidades=MAXLONG, char * nomeSem=NULL);
                Semaforo(char * nomeSem);
                ~Semaforo();
                void P();//pega token de acesso à regiao crítica
                void V();//libera token
                void FatalErrorSystem(char * msg);
};


