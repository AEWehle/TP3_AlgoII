#ifndef _MENU_CUIDAR_H
#define _MENU_CUIDAR_H

#include "Menu.h"
#include "../Opciones/Opcion.h"
#include "../Archivos_auxiliares/lista.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"
#include "../Opciones/OpcionElegirAnimal.h"
#include "../Opciones/OpcionVolverAMenu.h"
#include "../Archivos_auxiliares/Vector.h"
#include "../funciones_main.h"
#include <string>

using namespace std; 

const int CANTIDAD_OPCIONES_CUIDAR = 2;

class MenuCuidar: public Menu{
    //Atributos
    private:
        Lista<Opcion> opciones;

    public:
        MenuCuidar(Guarderia* mi_guarderia);

        void ejecutar(Guarderia *mi_guarderia) override;

        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
        void mostrar() override;

        void ejecutar_menu(Guarderia *mi_guarderia);

        ~MenuCuidar();
        
};


#endif