#ifndef _ATRIBUTES_H_
#define _ATRIBUTES_H_

#include<stdlib.h>

class Attributes
{
       private:

              unsigned int idAtributo;

       public:

              Attributes();
              ~Attributes();

              inline const unsigned int getIdAtributo() const {return idAtributo;};
              inline void setIdAtributo(const unsigned int sid) {idAtributo = sid;};

};

#endif

 