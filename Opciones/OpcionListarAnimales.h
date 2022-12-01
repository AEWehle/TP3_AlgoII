#ifndef _OPCION_LISTAR_ANIMALES_H
#define _OPCION_LISTAR_ANIMALES_H

#include "Opcion.h"

#include <string>
using namespace std; 

class OpcionListarAnimales: public Opcion {
    //Atributos ---> No tiene atributos
  
    public:
        //ejecutar(Guarderia * mi_guarderia)
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de listar animales cargados en guarderia (muestra por terminal)
        void ejecutar(Guarderia * mi_guarderia) override;
};


#endif