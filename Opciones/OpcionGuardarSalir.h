#ifndef _OPCION_GUARDAR_SALIR_H
#define _OPCION_GUARDAR_SALIR_H

#include "Opcion.h"
#include "../Archivo.h"
#include <fstream>


#include <string>
using namespace std; 

class OpcionGuardarSalir: public Opcion {
    //Atributos ---> No tiene atributos
  
    public:
        
        //ejecutar(Guarderia * mi_guarderia)
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de guardar y salir, guarda animales en archivo .csv
        void ejecutar(Guarderia * mi_guarderia) override;
};


#endif