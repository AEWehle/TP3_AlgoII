#ifndef _OPCION_CUIDAR_ANIMALES_H
#define _OPCION_CUIDAR_ANIMALES_H

#include "Opcion.h"
#include "../Menus/MenuCuidar.h"

#include <string>
using namespace std; 

class OpcionCuidarAnimales:public Opcion {
    //Atributos
    private:
        //Menu
        MenuCuidar menu_cuidar;

    public:
        // Constructor tiene que asegurar las invariantes
        OpcionCuidarAnimales();

        void ejecutar(Guarderia * mi_guarderia) override;
};


#endif