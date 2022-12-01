#ifndef _OPCION_CARGAR_GUARDERIA_H
#define _OPCION_CARGAR_GUARDERIA_H

#include "Opcion.h"
#include "../Animal.h"
#include "../Archivo.h"
#include "../funciones_main.h"
#include <fstream>
#include <string>
using namespace std; 

class OpcionCargarGuarderia: public Opcion {
    //Atributos ---> No tiene

    public:
        //ejecutar(Guarderia * mi_guarderia)
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de cargar animales de un archivo a la guarderia
        void ejecutar(Guarderia * mi_guarderia) override;

        
};


#endif