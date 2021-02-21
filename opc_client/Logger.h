//---------------------------------------------------------------------------


#ifndef LoggerH
#define LoggerH

#include <iostream.h>
#include <time.h>
#include <fstream>
#include <io.h>
#include <stdio.h>
#include <windows.h>

#include "bibliotecas/opcaedef.h"

class TForm1;
class Logger {

        private:
        time_t rawtime;
        struct tm * timeinfo;
        bool file_exists(const char *filename);
        string pathCompleto;

        public:
        Logger(/*string pathCompleto*/);
        void addLinhaLog(string texto);
        string getError(unsigned short erro);


};

//---------------------------------------------------------------------------
#endif
