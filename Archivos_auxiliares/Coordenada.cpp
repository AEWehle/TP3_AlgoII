#include "Coordenada.h"

Coordenada::Coordenada(int coordenada_vertical, int coordenada_horizontal){
    this->coordenada_vertical = coordenada_vertical;
    this->coordenada_horizontal = coordenada_horizontal;
}


Coordenada::~Coordenada() {

}

int Coordenada::obtener_horizontal(){
    return coordenada_horizontal;
}

int Coordenada::obtener_vertical(){
    return coordenada_vertical;
}