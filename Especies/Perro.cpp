#include <string>
#include <iostream>
#include "../Animal.h"
#include "Perro.h"
using namespace std; 


Perro::Perro(){

    comida = "huesos";
    es_domestico = true;

}


Perro::Perro( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "huesos";
    es_domestico = true;

}


Perro::~Perro(){
}


void Perro::mostrar(){

    cout << "____________________PERRO________________________________" << endl;
    Animal::mostrar();

}


Especie Perro::resolver_especie(){

    return P;
    
}