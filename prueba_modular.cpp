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
    //cargar_guarderia(mi_guarderia); //Cargo la guardería con la información del archivo
    OpcionCargarGuarderia().ejecutar(mi_guarderia);

    //OpcionListarAnimales* opcion_listar = new OpcionListarAnimales;
    //OpcionRescatarAnimal* opcion_rescatar = new OpcionRescatarAnimal;
    //OpcionBuscarAnimal* opcion_buscar = new OpcionBuscarAnimal;
    //OpcionCuidarAnimales* opcion_cuidar = new OpcionCuidarAnimales;
    //OpcionAdoptarAnimal* opcion_adoptar = new OpcionAdoptarAnimal;
    //OpcionCargarCombustible* opcion_cargar_combustible = new OpcionCargarCombustible;
    //OpcionGuardarSalir* opcion_guardar = new OpcionGuardarSalir;

    MenuPrincipal* menu_principal = new MenuPrincipal;//(opcion_listar, opcion_rescatar, opcion_buscar, opcion_cuidar, opcion_adoptar, opcion_cargar_combustible, opcion_guardar);
   
    menu_principal->ejecutar(mi_guarderia);
    
    delete menu_principal;
    delete mi_guarderia;
    return 0;
}