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

        // PRE: -
        // POS: convierte una coordenada de dos dimensiones [coord_vertical,coord_horizontal] en un numero de
        // celda de una dimension y devuelve ese numero
        int convertir_coordenadas_a_celda(int dimension);

        // PRE: recibe un número de celda en una matriz y la dimension de la matriz
        // POS: convierte una ubicacion de una matriz (celda) en una coordenada de dos dimensiones
        void convertir_celda_a_coordenadas(int celda, int dimension);

};


#endif //COORDENADA_H