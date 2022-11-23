//Prueba de Meli para ver si la modularizacion anda

#include <iostream>
#include <fstream>
#include "funciones_main.h"
#include "Guarderia.h"
#include "./Menus/Menu.h"
#include "./Menus/MenuPrincipal.h"
#include "./Menus/MenuCuidar.h"
#include "./Menus/MenuCuidarIndividual.h"
#include "./Opciones/Opcion.h"
#include "./Opciones/OpcionCargarGuarderia.h"
//#include "opciones.h"
using namespace std;

/*_____________________________TP2: LA RESERVA SOÑADA____________________*/
int main(){

    cout << "Hola," << endl << "En este programa te aseguramos una Reserva Soñada." << endl << "     DISFRUTALO!" << endl << endl;

    Guarderia* mi_guarderia  =  new Guarderia;

    OpcionCargarGuarderia().ejecutar(mi_guarderia);

    MenuPrincipal* menu_principal = new MenuPrincipal;

    menu_principal->ejecutar(mi_guarderia);
    
    delete menu_principal;
    delete mi_guarderia;
    return 0;
}