#ifndef _OPCION_ELEGIR_ANIMAL_H
#define _OPCION_ELEGIR_ANIMAL_H

#include "Opcion.h"
#include "../Menus/MenuCuidarIndividual.h"

#include <string>
using namespace std; 

class OpcionElegirAnimal:public Opcion {
    //Atributos
    private:
        //Menu
        MenuCuidarIndividual menu_cuidar_individual;

    public:
        // Constructor tiene que asegurar las invariantes
        OpcionElegirAnimal();

        void ejecutar(Guarderia * mi_guarderia) override;
};

#endif