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
        
        void ejecutar(Guarderia * mi_guarderia) override;
};


#endif