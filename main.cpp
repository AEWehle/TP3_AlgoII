#include <iostream>
#include <fstream>
#include "funciones_main.h"
#include "Guarderia.h"
#include "opciones.h"
using namespace std;

/*_____________________________TP2: LA RESERVA SOÑADA____________________*/
int main(){

    cout << "Hola," << endl << "En este programa te aseguramos una Reserva Soñada." << endl << "     DISFRUTALO!" << endl << endl;

    Guarderia* mi_guarderia  =  new Guarderia;
    cargar_guarderia(mi_guarderia); //Cargo la guardería con la información del archivo
    
    int eleccion;
    do{
        imprimir_menu(CANTIDAD_OPCIONES);
        eleccion = pedir_eleccion(CANTIDAD_OPCIONES);
        ejecutar_eleccion(mi_guarderia, eleccion);
    }
    while ( eleccion != GUARDAR_Y_SALIR );
    
    delete mi_guarderia;
    return 0;
}
