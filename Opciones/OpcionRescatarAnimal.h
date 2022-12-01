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
        
        //ejecutar(Guarderia * mi_guarderia)
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de rescatar animal
        void ejecutar(Guarderia * mi_guarderia) override;

    private:

        //generar_animal( Guarderia * mi_guarderia , char especie)
        //PRE: Guarderia creada correctamente, especie es char valido
        //POS: Genera un animal de la especie elegida, con caracteristicas randomizadas
        Animal* generar_animal( Guarderia * mi_guarderia , char especie);

        //introduccion()
        //PRE: -
        //POS: Devuelve true si el nombre ya se encuentra en uso en la guarderia
        Mapa* introduccion();

        //otro_nombre( Guarderia* mi_guarderia, string & nombre );
        //PRE: Guarderia creada correctamente, nombre es string sin numeros
        //POS: Devuelve true si el nombre ya se encuentra en uso en la guarderia
        bool otro_nombre( Guarderia* mi_guarderia, string & nombre );

        //pedir_personalidad()
        //PRE: -
        //POS: Pide y devuelve valor de personalidad en int
        int pedir_personalidad();

        //pedir_especie()
        //PRE: -
        //POS: Pide y devuelve valor de especie en int
        int pedir_especie();

        //pedir_tamano()
        //PRE: -
        //POS: Pide y devuelve valor de edad en string
        string pedir_tamano();

        //pedir_edad()
        //PRE: -
        //POS: Pide y devuelve valor de edad en int
        int pedir_edad();

};


#endif