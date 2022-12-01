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
        
        //ejecutar(Guarderia * mi_guarderia)
        //PRE: Guarderia creada correctamente
        //POS: Ejecuta opcion de adoptar animal
        void ejecutar(Guarderia * mi_guarderia) override;

    private:
        
        //pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* lista_adoptables )
        //PRE: Guarderias creadas correctamente
        //POS: Pide el animal a adoptar, verifica que se encuentre en lista_adoptables, y lo saca de la guarderia
        string pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* lista_adoptables );

        //crear_lista_adoptables(Guarderia* mi_guarderia, float espacio)
        //PRE: Guarderias creadas correctamente, espacio es un valor válido
        //POS: Crea guarderia de animales adoptables de acuerdo al espacio ingresado
        Guarderia* crear_lista_adoptables(Guarderia* mi_guarderia, float espacio);

        //pedir_espacio()
        //PRE: -
        //POS: Pide el espacio que tiene disponible para adoptar, valida espacio
        float pedir_espacio();

};


#endif