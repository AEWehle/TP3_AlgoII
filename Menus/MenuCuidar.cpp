#include "MenuCuidar.h"
#include <algorithm>

MenuCuidar::MenuCuidar(){
    Vector<Opcion*> opciones(2);

    //opciones.cargar(Opcion * elegir_individualmente, 1);
    //opciones.cargar(Opcion * volver_menu_ppal, 2);

}

void MenuCuidar::mostrar() {
    
    cout << endl << "*****   CUIDAR ANIMALES: MENU   *****" << endl << endl;
    cout << "   1. Elegir Individualmente." << endl; 
    cout << "   2. Regresar al Menu Principal." << endl << endl;
    
}

void MenuCuidar::ejecutar(){
    mostrar();
}

void MenuCuidar::ejecutar_opcion(int eleccion, Guarderia *mi_guarderia){
    std::cout << eleccion << std::endl; 
}