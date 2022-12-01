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
        MenuCuidar* menu_cuidar;


    public:
        
        //Constructor
        //PRE: -
        //POS: Crea la opcion sin el menu cargado
        OpcionCuidarAnimales();

        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de cuidar animales
        void ejecutar(Guarderia * mi_guarderia) override;

};

#endif