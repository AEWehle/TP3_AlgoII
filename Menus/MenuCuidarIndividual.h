#ifndef _MENU_INDIVIDUAL_H
#define _MENU_INDIVIDUAL_H

#include "Menu.h"
#include "../Opciones/Opcion.h"
#include "../Archivos_auxiliares/lista.h"
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
        
    // Metodos
    public:
        
        MenuCuidarIndividual(Guarderia *mi_guarderia);

        void ejecutar(Guarderia *mi_guarderia) override;

        ~MenuCuidarIndividual() override;

        void mostrar() override;

        void ejecutar_opcion(int eleccion, Guarderia *mi_guarderia) override;
        
};


#endif