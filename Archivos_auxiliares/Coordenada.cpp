#include "Coordenada.h"

Coordenada::Coordenada(){

    coordenada_fila = 0;
    coordenada_columna = 0;

}


Coordenada::Coordenada(int coordenada_fila, int coordenada_columna){

    this->coordenada_fila = coordenada_fila;
    this->coordenada_columna = coordenada_columna;

}


Coordenada::~Coordenada() {

}


int Coordenada::obtener_fila(){

    return coordenada_fila;

}


int Coordenada::obtener_columna(){

    return coordenada_columna;

}


int Coordenada::convertir_coordenadas_a_celda(int dimension){

    return (this->coordenada_fila)*dimension + (this->coordenada_columna) + 1;

}


void Coordenada::convertir_celda_a_coordenadas(int celda, int dimension){

    this->coordenada_fila = (celda-1)/dimension;
    this->coordenada_columna = (celda-1)%dimension;

}