#include "Auto.h"
#include <iostream>

Auto::Auto(){
    combustible = 100;
}

Auto::~Auto(){
}

int Auto::obtener_combustible(){
    return combustible;
}

void Auto::cargar_combustible(){
    int aux = combustible + 5;

    if (aux < MAX_COMBUSTIBLE) {
        combustible = aux;
    }

}

void Auto::cargar_combustible(int cantidad){
    if ( cantidad == 0 ){
        cout << "No le cargas combustible al auto." << endl;
        cout << "El auto tiene: " << combustible << " de combustible." << endl;
        return;
    }
    int aux = combustible + cantidad;
    if (aux > MAX_COMBUSTIBLE) {
        cout << "No derroches combustible. No podes cargar mas combustible del necesario." << endl;
        cout << "El auto tiene: " << combustible << " de combustible." << endl;
    }else {
        this->combustible = aux;
        cout << "Cargamos combustible."  << endl;
        cout << "El auto ahora tiene: " << combustible << " de combustible." << endl;
    }
}

void Auto::decrementar_combustible(int cantidad){
    int aux = combustible - cantidad;
    if (aux < 0) {
        cout << "No tenes mas combustible." << endl;
        combustible = 0;
    }else {
       combustible = aux;
    }
}
