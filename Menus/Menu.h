#ifndef _MENU_H
#define _MENU_H

#include <iostream>
#include "../Guarderia.h"


class Menu{

    public:
        Menu() {};
        
        virtual void ejecutar(Guarderia *mi_guarderia) = 0;

        virtual void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) = 0;
        
        virtual void mostrar() = 0;

        virtual ~Menu() {};
        
};


#endif