#ifndef _MENU_CUIDAR_H
#define _MENU_CUIDAR_H

#include "Menu.h"
#include "../Opciones/Opcion.h"
#include "../Archivos_auxiliares/Vector.h"
#include <string>

using namespace std; 

class MenuCuidar: public Menu{
    //Atributos
    private:
        Vector<Opcion*> opciones;

    public:
        MenuCuidar();

        void ejecutar() override;

        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
        void mostrar() override;

        ~MenuCuidar() = default;
        
};


#endif