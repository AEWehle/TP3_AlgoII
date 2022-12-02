#ifndef _OPCION_H
#define _OPCION_H

#include <string>
#include "../Guarderia.h"

using namespace std; 

//Interface
class Opcion {

    public:
        //Constructor
        //PRE: -
        //POS: Crea opcion vacia
        Opcion() {};

        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion creada
        virtual void ejecutar(Guarderia * mi_guarderia) = 0;

        //Destructor
        //PRE: -
        //POS: Destruye opcion
        virtual ~Opcion() {};

};

#endif