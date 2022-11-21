#ifndef _OPCION_MENU_PRINCIPAL_H
#define _OPCION_MENU_PRINCIPAL_H

#include "Opcion.h"
#include "../Menus/MenuPrincipal.h"

#include <string>
using namespace std; 

class OpcionCuidarAnimales: Opcion {
    //Atributos
    private:
        //Menu
        MenuPrincipal menu_principal;

    public:
        // Constructor tiene que asegurar las invariantes
        //Opcion(Estrategia* e) { m_e = e; };
        void ejecutar() { menu_principal.ejecutar(); };
};


#endif