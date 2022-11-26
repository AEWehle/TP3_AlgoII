#ifndef _OPCION_RESCATAR_ANIMAL_H
#define _OPCION_RESCATAR_ANIMAL_H

#include "Opcion.h"
#include "../funciones_main.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"
#include <limits>
#include <string>
#include "../Mapa.h"
using namespace std; 

class OpcionRescatarAnimal: public Opcion {
    //Atributos ---> No tiene atributos
  
    public:
        
        void ejecutar(Guarderia * mi_guarderia) override;

    private:

        Mapa* introduccion();

        bool otro_nombre( Guarderia* mi_guarderia, string & nombre );

        int pedir_personalidad();

        int pedir_especie();

        string pedir_tamano();

        int pedir_edad();

};


#endif