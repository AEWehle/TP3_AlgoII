#ifndef _OPCION_VOLVER_MENU_H
#define _OPCION_VOLVER_MENU_H

#include "Opcion.h"
#include "../funciones_main.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"

#include <string>
using namespace std; 

class OpcionVolverAMenu: public Opcion {
    //Atributos ---> No tiene atributos
  
    public:
        
        void ejecutar(Guarderia * mi_guarderia) override;



};


#endif