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
        OpcionElegirAnimal* opcion_elegir; 

    public:

        //Constructor
        //PRE: -
        //POS: Crea menu cuidar con sus opciones
        MenuCuidar(Guarderia* mi_guarderia);

        //ejecutar()
        //PRE: La guarderia fue creada correctamente
        //POS: Muestra menu, pide opcion y ejecuta mientras no se cumpla condicion de salida: elijo volver a menu principal
        void ejecutar(Guarderia *mi_guarderia) override;

        //ejecutar_opcion()
        //PRE: La opcion ingresada es valida, la guarderia fue creada correctamente
        //POS: Ejecuta la opcion elegida, afectando a mi_guarderia 
        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
        //mostrar()
        //PRE: -
        //POS: Muestra en pantalla el menu cuidar
        void mostrar() override;

        //Destructor
        //PRE: -
        //POS: Libera memoria pedida por las opciones, destruye Menu creado
        ~MenuCuidar();
        
};


#endif