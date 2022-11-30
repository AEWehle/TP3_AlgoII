#include <string>
#include <iostream>
#include "../Animal.h"
#include "Gato.h"
using namespace std; 


Gato::Gato(){

    comida = "atun";
    es_domestico = true;

}


Gato::Gato( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "atun";
    es_domestico = true;

}


Gato::~Gato(){
}


void Gato::mostrar(){

    cout << "____________________GATO_________________________________" << endl;
    Animal::mostrar();

}

bool Gato::ensuciar(){

    higiene = 100;
    return false;
}


void Gato::duchar(){

    cout << nombre << ": - Soy un gato, no necesito ducharme." << endl;

}


Especie Gato::resolver_especie(){

    return G;
    
}
