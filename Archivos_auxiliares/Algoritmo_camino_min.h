#ifndef ALGORITMO_CAMINO_MIN_H
#define ALGORITMO_CAMINO_MIN_H
#include "lista.h"
#include "Vertice.h"
#include "Coordenada.h"
#include <iostream>

class AlgoritmoCaminoMinimo{
    // Atributos
    protected:
        int ** matriz_de_adyacencia;
        Lista<Vertice>* lista_vertices;
        int cantidad_vertices_en_algoritmo;

    // Métodos
    public:
        // Constructor con parámetros
        // PRE: recibe una lista con vertices y una matriz de adyacencia
        // POS: inicializa el objeto AlgoritmoCaminoMinimo con la lista de vertices, la matriz de adyacencia y la cantidad de vertices
        AlgoritmoCaminoMinimo(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia);

        // PRE: recibe una posicion de origen y una de destino, y una lista de coordenadas vacia
        // POS: se obtienen las coordenadas del camino recorrido y se guardan en la lista recibida, y el costo del camino.
        // Variable segun la clase hija.
        virtual void obtener_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_viaje) = 0;

        // Destructor
        virtual ~AlgoritmoCaminoMinimo() = 0;
};

#endif // ALGORITMO_CAMINO_MIN_H
