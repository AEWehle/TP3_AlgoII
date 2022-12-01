#ifndef _OPCION_CARGAR_COMBUSTIBLE_H
#define _OPCION_CARGAR_COMBUSTIBLE_H

#include "Opcion.h"
#include <limits>
#include <string>

using namespace std; 

class OpcionCargarCombustible: public Opcion {

    //Atributos ---> No tiene

    public:
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de cargar combustible
        void ejecutar(Guarderia * mi_guarderia) override;


    private:
        //PRE: -
        //POS: Pide cantidad de combustible a cargar y valida que se encuentre en el rango de 0 a MAX_COMBUSTIBLE
        int pedir_cantidad_combustible();

};

#endif