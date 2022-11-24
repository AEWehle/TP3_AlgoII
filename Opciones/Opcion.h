#ifndef _OPCION_H
#define _OPCION_H


#include <string>
#include "../Guarderia.h"

using namespace std; 

class Opcion {

    public:
        //Constructor tiene que asegurar las invariantes
        Opcion() {};

        virtual void ejecutar(Guarderia * mi_guarderia) = 0;

        virtual ~Opcion() {};
};


#endif