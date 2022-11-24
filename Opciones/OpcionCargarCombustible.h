#ifndef _OPCION_CARGAR_COMBUSTIBLE_H
#define _OPCION_CARGAR_COMBUSTIBLE_H

#include "Opcion.h"
#include <limits>
#include <string>
using namespace std; 

class OpcionCargarCombustible: public Opcion {
    //Atributos ---> No tiene

    public:
        
        void ejecutar(Guarderia * mi_guarderia) override;

    private:

        int pedir_cantidad_combustible();
};


#endif