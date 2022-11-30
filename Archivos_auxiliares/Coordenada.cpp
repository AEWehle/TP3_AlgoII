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