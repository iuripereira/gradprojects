/***************************************************************************
                          semaforo.cpp  -  Implementa��o de uma classe que cria um sem�foro bin�rio.
                             -------------------
    begin                : Qui Jan 27 2005
    copyright            : (C) 2005 by Wany Andrade
***************************************************************************/

//---------------------------------------------------------------------------
#include "semaforo.h"

Semaforo::Semaforo(int numUnidades, int maxUnidades, char * nomeSem)
{
        if ( (hSemaforo = CreateSemaphore(NULL, numUnidades, maxUnidades, nomeSem)) == NULL )
                FatalErrorSystem("Erro ao criar o semaforo(1)");
}

Semaforo::Semaforo(char * nomeSem)
{
        if ( (hSemaforo = OpenSemaphore(SEMAPHORE_ALL_ACCESS, TRUE, nomeSem)) == NULL )
                FatalErrorSystem("Erro ao criar o semaforo(3)");
}

Semaforo::~Semaforo()
{
        if (CloseHandle(hSemaforo)==0)
                FatalErrorSystem("Erro ao fechar o semaforo");
}

void Semaforo::FatalErrorSystem(char * msg)
{
        //cout<<msg<<endl;//nao tem mais console
}

void Semaforo::P()
{
        if ( WaitForSingleObject(hSemaforo, INFINITE) == WAIT_FAILED ){
                FatalErrorSystem("Erro na opera��o de Wait do sem�foro");
        }
}

void Semaforo::V()
{
        if ( ReleaseSemaphore(hSemaforo, 1, NULL) == 0 )
                FatalErrorSystem("Erro na opera��o de Signal do sem�foro");
}
 
