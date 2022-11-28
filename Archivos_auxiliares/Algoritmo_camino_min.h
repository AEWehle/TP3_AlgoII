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
        AlgoritmoCaminoMinimo(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia);

        virtual void mostrar_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas) = 0;

        virtual ~AlgoritmoCaminoMinimo() = default;
};

#endif // ALGORITMO_CAMINO_MIN_H
