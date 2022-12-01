#ifndef _MENU_PRINCIPAL_H
#define _MENU_PRINCIPAL_H

#include "Menu.h"
#include "../Archivos_auxiliares/Lista.h"
#include "../Opciones/Opcion.h"
#include "../Opciones/OpcionListarAnimales.h"
#include "../Opciones/OpcionRescatarAnimal.h"
#include "../Opciones/OpcionBuscarAnimal.h"
#include "../Opciones/OpcionCuidarAnimales.h"
#include "../Opciones/OpcionAdoptarAnimal.h"
#include "../Opciones/OpcionCargarCombustible.h"
#include "../Opciones/OpcionGuardarSalir.h"
#include <string>

const int CANTIDAD_OPCIONES = 7;

class MenuPrincipal: public Menu{
    // Atributos
    private:

        Lista<Opcion> opciones; //Trabajo con puntero a clase base, que es un vector de opciones

    // Metodos
    public:
        
        MenuPrincipal();

        void ejecutar(Guarderia *mi_guarderia) override;

        ~MenuPrincipal() override;

        void mostrar() override;

        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
};


#endif