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
        
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de rescatar animal
        void ejecutar(Guarderia * mi_guarderia) override;


    private:

        //PRE: Guarderia creada correctamente, especie es char valido
        //POS: Genera un animal de la especie elegida, con caracteristicas aleatorias
        Animal* generar_animal( Guarderia * mi_guarderia , char especie);

        //introduccion()
        //PRE: -
        //POS: Da una introducción al rescate y pregunta al usuario qué mapa usará. Crea el mapa en consecuencia y lo devuelve
        Mapa* introduccion();

        //PRE: Guarderia creada correctamente, nombre es string sin numeros
        //POS: Devuelve true si el nombre ya se encuentra en uso en la guarderia
        bool otro_nombre( Guarderia* mi_guarderia, string & nombre );

        //PRE: -
        //POS: Pide y devuelve valor de personalidad en int
        int pedir_personalidad();

        //PRE: -
        //POS: Pide y devuelve valor de especie en int
        int pedir_especie();

        //PRE: -
        //POS: Pide y devuelve valor de edad en string
        string pedir_tamano();

        //PRE: -
        //POS: Pide y devuelve valor de edad en int
        int pedir_edad();

};

#endif