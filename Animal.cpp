#include <string>
#include <iostream> 
#include "Animal.h"
using namespace std; 


Animal::Animal(){
    higiene = 100;
    hambre = 0;
}


Animal::Animal( string nombre, int edad, string tamano, string personalidad ){
    this -> nombre = nombre;
    this -> edad =  edad;
    this -> tamano = tamano;
    this -> personalidad = personalidad;
    higiene = 100;
    hambre = 0;
}




Animal::~Animal(){
}


void Animal::alimentar(){

    hambre = 0;
    cout << "      Soy " << nombre << ", como " << comida << "." << endl;

}


void Animal::mostrar(){
    
    // cout << "      ____________________"<< especie << "______________________________" << endl;
    cout << "             - " << "Nombre: " << nombre << "." << endl;
    cout << "             - " << edad << " años." << endl;
    cout << "             - " << "Es " << tamano << endl;
    cout << "             - " << "Es muy " << personalidad << "." << endl;
    cout << "             - " << "Tiene " << hambre << "\% de hambre y está " << higiene << "\% limpio." << endl << endl;

}


string Animal::obtener_nombre(){

    return nombre;

}


int Animal::obtener_edad(){

    return edad;

}


string Animal::obtener_tamano(){

    return tamano;

}


string Animal::obtener_personalidad(){

    return personalidad;

}


bool Animal::es_adoptable(){

    return es_domestico;
}


bool es_primer_animal_mayor( Animal* animal1, Animal* animal2 ){
    return animal1 -> obtener_edad() > animal2 -> obtener_edad();
}


int Animal::obtener_hambre(){

    return hambre;

}


int Animal::obtener_higiene(){

    return higiene;

}


void Animal::setear_hambre(int hambre_int){

    hambre = hambre_int;

}


void Animal::setear_higiene(int higiene_int){

    higiene = higiene_int;

}


bool Animal::dar_hambre(){

    bool se_escapa = false;
    if(hambre >= 100){
        se_escapa = true;
        cout << "      NOOOOO, " << nombre << " SE ESTÁ ESCAPANDO!!! NO LE DISTE COMIDA A TIEMPO" << endl;
        return se_escapa;
    }
    
    if (personalidad == PERSONALIDADES[0]) {
        //Caso mitad del hambre
        hambre = hambre + PUNTOS_HAMBRE/2;
    }
    else if (personalidad == PERSONALIDADES[1]) {
        //Caso doble del hambre
        hambre = hambre + 2*PUNTOS_HAMBRE;
    }
    else{
        hambre = hambre + PUNTOS_HAMBRE;
    }
        
    //Eliminar a discreción
    if(hambre >= 70){
        cout << "      Parece que " << nombre << " tiene mucha hambre. Quizás es hora de alimentarl@." << endl;
    }
    return se_escapa;
}

bool Animal::ensuciar(){
bool se_escapa = false;
    if( higiene <= 0  ){
        se_escapa = true;
        cout << "      NOOOOO, " << nombre << " SE ESTÁ ESCAPANDO!!! NO L@ DUCHASTE A TIEMPO" << endl;
        return se_escapa;
    }

    if (personalidad == PERSONALIDADES[2]) {
        //Caso se ensucia la mitad
        higiene = higiene - PUNTOS_HIGIENE/2;
    }
    else if (personalidad == PERSONALIDADES[3]) {
        //Caso se ensucia el doble
        higiene = higiene - 2*PUNTOS_HIGIENE;
    }
    else{
        higiene = higiene - PUNTOS_HIGIENE;
    }

    if(higiene <= 30){
        cout << "      Parece que " << nombre << " está muy suci@. Quizás es hora de ducharl@." << endl;
    }

    return se_escapa;
}


void Animal::duchar(){

    higiene = 100;
    
}