#include <string>
#include <iostream>
#include "../Animal.h"
#include "Roedor.h"
using namespace std; 


Roedor::Roedor(){

    comida = "queso";
    es_domestico = true;

}


Roedor::Roedor( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "queso";
    es_domestico = true;

}


Roedor::~Roedor(){
}


void Roedor::mostrar(){

    cout << "____________________ROEDOR_______________________________" << endl;
    Animal::mostrar();

}


bool Roedor::ensuciar(){

    higiene = 100;
    return false;
}


void Roedor::duchar(){

    cout << nombre << ": - Soy un roedor, no necesito ducharme." << endl;

}


Especie Roedor::resolver_especie(){

    return R;
    
}