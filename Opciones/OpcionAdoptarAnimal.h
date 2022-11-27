#ifndef _OPCION_ADOPTAR_ANIMAL_H
#define _OPCION_ADOPTAR_ANIMAL_H

#include "Opcion.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"
#include "../funciones_main.h"

#include <string>
using namespace std; 

class OpcionAdoptarAnimal: public Opcion {
    //Atributos ---> No tiene

    public:
        
        void ejecutar(Guarderia * mi_guarderia) override;

    private:

        string pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* lista_adoptables );

        Guarderia* crear_lista_adoptables(Guarderia* mi_guarderia, float espacio);

        float pedir_espacio();

};


#endif