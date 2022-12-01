#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include "../Guarderia.h"

// Interface
class Menu{

    public:

        //Constructor
        //PRE: -
        //POS: Crea menu
        Menu() {};
        
        //ejecutar()
        //PRE: La guarderia fue creada correctamente
        //POS: Muestra menu, pide opcion y ejecuta mientras no se cumpla condicion de salida (override obligatorio)
        virtual void ejecutar(Guarderia *mi_guarderia) = 0;

        //ejecutar_opcion()
        //PRE: La opcion ingresada es valida, la guarderia fue creada correctamente
        //POS: Ejecuta la opcion elegida, afectando a mi_guarderia (override obligatorio)
        virtual void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) = 0;
        
        //mostrar()
        //PRE: -
        //POS: Muestra en pantalla el menu (override obligatorio)
        virtual void mostrar() = 0;
        
        //Destructor
        //PRE: -
        //POS: Borra menu
        virtual ~Menu() {};
        
};


#endif