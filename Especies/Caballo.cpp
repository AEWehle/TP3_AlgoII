#include <string>
#include <iostream> 
#include "../Animal.h"
#include "Caballo.h"
using namespace std; 

Caballo::Caballo(  ): Animal(  ){

    comida = "manzanas";
    es_domestico = true;

}


Caballo::Caballo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "manzanas";
    es_domestico = true;

}


Caballo::~Caballo(){
}


void Caballo::mostrar(){
    
    cout << "____________________CABALLO______________________________" << endl;
    Animal::mostrar();

}

Especie Caballo::resolver_especie(){

    return C;
    
}