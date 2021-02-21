//---------------------------------------------------------------------------


#pragma hdrstop
#pragma package(smart_init)

#include "Logger.h"
#include "formAE.h"

/*
* Adiciona uma linha no LOG
*/

Logger::Logger(){
    pathCompleto = TForm1::getPathApplication();

}

void Logger::addLinhaLog(string texto){

        int const TAMANHO = 300;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );

        string path = pathCompleto +"LOGS\\";

        if (!file_exists(path.c_str())){
            CreateDirectory(path.c_str(), NULL);
        }

        char fileName[TAMANHO];
        string fileMask = path+"LOG_%d.%m.%Y.log";
        strftime(fileName,TAMANHO,fileMask.c_str(),timeinfo);

        ofstream log(fileName, ios_base::app); //arquivo de log do sistema

        string txtConcat;
        texto = "%I:%M:%S%p - " + texto;
        char logTxt[TAMANHO];
        strftime(logTxt,TAMANHO,texto.c_str(),timeinfo);

        log << logTxt << endl;

        log.close();
}

string Logger::getError(unsigned short erro){

    string erroMsg;

    switch (erro){

        case E_FAIL:
            erroMsg = "Falha ao executar operação.";
        break;
        case E_INVALIDARG:
            erroMsg = "Argumento(s) inválido(s).";
        break;
        case E_OUTOFMEMORY:
            erroMsg = "Memória Insuficiente.";
        break;
        case E_NOTIMPL:
            erroMsg = "O servidor não suporta este método.";
        break;
        case E_NOINTERFACE:
            erroMsg = "A interface solicitada, não é suportada pelo servidor.";
        break;
        case S_FALSE:
            erroMsg = "Um ou mais erros foram retornados.";
        break;

        case OPC_S_INVALIDBUFFERTIME:
            erroMsg = "Parâmetro Buffer Time Inválido.";
        break;
        case OPC_S_INVALIDMAXSIZE:
            erroMsg = "Parâmetro Max Size Inválido.";
        break;
        case OPC_E_BUSY:
            erroMsg = "Servidor Ocupado. Provavalmente uma operação de Refresh está em curso nesta subscription.";
        break;
        case OPC_E_INVALIDBRANCHNAME:
            erroMsg = "String não reconhecida como uma área válida.";
        break;
        case OPC_E_INVALIDTIME:
            erroMsg = "A data especificada não coincide com o alarme que está sendo reconhecido.";
        break;
        case OPC_E_NOINFO:
            erroMsg = "Nenhuma informação disponpivel para a especificada condição.";
        break;
        case OPC_S_ALREADYACKED:
            erroMsg = "Alarme já se encontra reconhecido.";
        break;
        case REGDB_E_CLASSNOTREG:
             erroMsg = "A specified class is not registered in the registration database. Also can indicate that the type of server you requested in the CLSCTX enumeration is not registered or the values for the server types in the registry are corrupt.";
        break;
        case CLASS_E_NOAGGREGATION:
             erroMsg = "This class cannot be created as part of an aggregate.";
        case CO_S_NOTALLINTERFACES:
             erroMsg = "At least one, but not all of the interfaces requested in the pResults array were successfully retrieved. The hr field of each of the MULTI_QI structures in pResults indicates with S_OK or E_NOINTERFACE whether the specific interface was returned.";
             break;
        case REGDB_E_READREGDB:
                erroMsg = "There is no CLSID registred for the class object";
        break;
        default:
            erroMsg = "Falha desconhecida";

    }

    return erroMsg;
}

bool Logger::file_exists(const char *filename){
   return (access(filename, 0) == 0);
}

//---------------------------------------------------------------------------


