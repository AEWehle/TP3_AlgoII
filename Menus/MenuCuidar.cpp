#include "MenuCuidar.h"

MenuCuidar::MenuCuidar(Guarderia* mi_guarderia) : opciones(Lista<Opcion>()){

    opcion_elegir = new OpcionElegirAnimal(mi_guarderia);
    Opcion* opcion_menu_ppal = new OpcionVolverAMenu();
  
    opciones.alta(opcion_elegir, 1);
    opciones.alta(opcion_menu_ppal, 2);

}


void MenuCuidar::mostrar() {
    
    cout << endl << "      *****   CUIDAR ANIMALES: MENU   *****" << endl << endl;
    cout << "         1. Elegir Individualmente." << endl; 
    cout << "         2. Regresar al Menu Principal." << endl << endl;
    
}


void MenuCuidar::ejecutar(Guarderia *mi_guarderia){

    int eleccion;

    do{
        mostrar();
        eleccion = pedir_eleccion(CANTIDAD_OPCIONES_CUIDAR);
        ejecutar_opcion(eleccion, mi_guarderia);
    }
    while ( (eleccion != (CANTIDAD_OPCIONES_CUIDAR)) && !(opcion_elegir->volver_menu_principal()));

}


void MenuCuidar::ejecutar_opcion(int eleccion, Guarderia *mi_guarderia){

    opciones.consulta(eleccion)->ejecutar(mi_guarderia);

}


MenuCuidar::~MenuCuidar(){

    for (int i = 1; i < opciones.obtener_cantidad() + 1; ++i) {
        Opcion* actual = opciones.consulta(i);
        delete actual;
    }
    
}