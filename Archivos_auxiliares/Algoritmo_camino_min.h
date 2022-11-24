#ifndef ALGORITMO_CAMINO_MIN_H
#define ALGORITMO_CAMINO_MIN_H
#include "Lista.h"
#include "Vertice.h"
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

        virtual void mostrar_camino_minimo(int origen, int destino) = 0;

        virtual ~AlgoritmoCaminoMinimo() = default;
};

#endif // ALGORITMO_CAMINO_MIN_H
