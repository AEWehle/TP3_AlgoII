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
        MenuCuidarIndividual* menu_cuidar_individual;
        bool volver_menu_ppal;


    public:
        //Constructor
        //PRE: -
        //POS: Crea la opcion, pide memoria y crea menu_cuidar_individual y volver_menu_ppal = false
        OpcionElegirAnimal(Guarderia* mi_guarderia);

        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de elegir animal individualmente
        void ejecutar(Guarderia* mi_guarderia) override;

        //PRE: -
        //POS: Devuelve valor de volver_menu_ppal
        bool volver_menu_principal();

        //Destructor
        //PRE: -
        //POS: Libera memoria pedida por menu_cuidar_individual
        ~OpcionElegirAnimal(); 
        
};

#endif