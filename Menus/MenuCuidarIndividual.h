#ifndef _MENU_INDIVIDUAL_H
#define _MENU_INDIVIDUAL_H

#include "Menu.h"
#include "../Opciones/Opcion.h"
#include "../Archivos_auxiliares/Lista.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"
#include "../funciones_main.h"
#include "../Opciones/Opcion.h"
#include <string>

class MenuCuidarIndividual: public Menu{

    // Atributos

    private:

        string nombre_animal;
        int numero_de_animal;
        Lista<string>* lista_nombres;
        bool volver_menu_ppal;
        

    // Metodos
    public:

        //Constructor
        //PRE: -
        //POS: Crea menu con la lista de nombres, numero_de animal = 1, volver_menu_ppal = false, nombre_animal con nombre de primer animal en la lista
        MenuCuidarIndividual(Guarderia *mi_guarderia);

        //PRE: La guarderia fue creada correctamente
        //POS: Muestra menu, pide opcion y ejecuta mientras no se cumpla condicion de salida: elijo volver a menu principal
        void ejecutar(Guarderia *mi_guarderia) override;

        //Destructor
        //PRE: -
        //POS: Libera memoria pedida por los atributos, destruye menu creado
        ~MenuCuidarIndividual() override;

        //PRE: -
        //POS: Muestra en pantalla el menu cuidar individual
        void mostrar() override;

        //PRE: La opcion ingresada es valida, la guarderia fue creada correctamente
        //POS: Ejecuta la opcion elegida, afectando a mi_guarderia 
        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;

        //PRE: -
        //POS: Devuelve valor de atributo volver_menu_ppal
        bool volver_menu_principal();
        
};

#endif