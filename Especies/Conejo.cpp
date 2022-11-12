#include <string>
#include <iostream>
#include "../Animal.h"
#include "Conejo.h"
using namespace std; 


Conejo::Conejo(){

    comida = "lechuga";
    es_domestico = true;

}


Conejo::Conejo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "lechuga";
    es_domestico = true;

}


Conejo::~Conejo(){
}


void Conejo::mostrar(){
    
    cout << "____________________CONEJO_______________________________" << endl;
    Animal::mostrar();

}


Especie Conejo::resolver_especie(){

    return O;

}