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
using namespace std;

/*_____________________________TP3: LA RESERVA SOÑADA____________________*/
int main(){
    cout << endl << "****************************************************************************" << endl << endl; 
    cout << "      Hola," << endl << "        En este programa te aseguramos una Reserva Soñada." << endl << "     DISFRUTALO!" << endl << endl;

    Guarderia* mi_guarderia  =  new Guarderia;
    //cargar_guarderia(mi_guarderia); //Cargo la guardería con la información del archivo
    OpcionCargarGuarderia().ejecutar(mi_guarderia);

    MenuPrincipal* menu_principal = new MenuPrincipal;//(opcion_listar, opcion_rescatar, opcion_buscar, opcion_cuidar, opcion_adoptar, opcion_cargar_combustible, opcion_guardar);
   
    menu_principal->ejecutar(mi_guarderia);
    
    delete menu_principal;
    delete mi_guarderia;
    return 0;
}