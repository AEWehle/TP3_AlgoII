#ifndef _OPCION_BUSCAR_ANIMAL_H
#define _OPCION_BUSCAR_ANIMAL_H

#include "Opcion.h"

#include <string>
using namespace std; 

class OpcionBuscarAnimal: public Opcion {
    //Atributos ---> No tiene

    public:
        
        void ejecutar(Guarderia * mi_guarderia) override;
};


#endif