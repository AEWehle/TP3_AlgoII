#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>

using namespace std;

class Coordenada {
    // Atributos
    private:
        int coordenada_fila;
        int coordenada_columna;

    // Métodos
    public:
        // Constructor sin parámetros
        // PRE: -
        // POS: construye la Coordenada origen: [0,0]
        Coordenada();

        // Constructor con parámetros
        // PRE: -
        // POS: construye la Coordenada: [coordenada_fila,coordenada_columna]
        Coordenada(int coordenada_fila, int coordenada_columna);

        // Destructor
        ~Coordenada();

        // PRE: -
        // POS: devuelve la coordenada fila
        int obtener_fila();

        // PRE: -
        // POS: devuelve la coordenada columna
        int obtener_columna();

};


#endif //COORDENADA_H