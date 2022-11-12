#include <string>
#include <iostream>
#include "../Animal.h"
#include "Erizo.h"
using namespace std; 


Erizo::Erizo(){

    comida = "insectos";
    es_domestico = false;

}


Erizo::Erizo( string nombre, int edad, string tamano, string personalidad ) : Animal( nombre, edad, tamano, personalidad ){

    comida = "insectos";
    es_domestico = false;

}


Erizo::~Erizo(){
}


void Erizo::mostrar(){
    
    cout << "____________________ERIZO________________________________" << endl;
    Animal::mostrar();

}


Especie Erizo::resolver_especie(){

    return E;
    
}