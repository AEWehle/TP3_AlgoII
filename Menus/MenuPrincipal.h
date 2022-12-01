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
        
        //Constructor
        //PRE: -
        //POS: Crea menu principal con sus opciones
        MenuPrincipal();

        //PRE: La guarderia fue creada correctamente
        //POS: Muestra menu, pide opcion y ejecuta mientras no se cumpla condicion de salida: quiero guardar y salir, o tengo 3 escapados
        void ejecutar(Guarderia *mi_guarderia) override;

        //Destructor
        //PRE: -
        //POS: Libera memoria pedida por las opciones, destruye Menu creado
        ~MenuPrincipal() override;

        //PRE: -
        //POS: Muestra en pantalla el menu principal
        void mostrar() override;

        //PRE: La opcion ingresada es valida, la guarderia fue creada correctamente
        //POS: Ejecuta la opcion elegida, afectando a mi_guarderia 
        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
};

#endif