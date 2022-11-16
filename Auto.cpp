#include "Auto.h"
#include <iostream>

Auto::Auto(){
    combustible = MAX_COMBUSTIBLE;
}

Auto::~Auto(){
}

unsigned int Auto::obtener_combustible(){
    return combustible;
}

void Auto::cargar_combustible(){
    combustible = MAX_COMBUSTIBLE;
}

void Auto::cargar_combustible(unsigned int cantidad){
    combustible = combustible + cantidad;
    if (combustible > MAX_COMBUSTIBLE) {
        cout << "No derroches combustible. Se ha llenado el tanque hasta el maximo." << endl;
        combustible = MAX_COMBUSTIBLE;
    }
}

void Auto::decrementar_combustible(unsigned int cantidad){
    combustible = combustible - cantidad;
    if (combustible < 0) {
        cout << "No tenes mas combustible." << endl;
        combustible = 0;
    }
}
