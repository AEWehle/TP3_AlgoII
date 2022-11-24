#ifndef FLOYD_H
#define FLOYD_H
#include "Algoritmo_camino_min.h"

using namespace std;

const int NO_SE_ENCUENTRA = -1;

// Algoritmo de camino mínimo: Floyd Warshall

class Floyd : public AlgoritmoCaminoMinimo{
    // Atributos
    private:
        int** matriz_de_costos; // tiene los costos de ir de un vértice a otro
        int** matriz_de_caminos; // tiene los caminos para ir de un vértice a otro

    // Métodos
    public:
        // Constructor
        Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia);

        // Destructor
        ~Floyd();

        void mostrar_camino_minimo(int origen, int destino) override;

    private:
        void crear_matriz_de_costos(int** matriz_de_adyacencia);

        void crear_matriz_de_caminos();

        void aplicar_floyd();

        // void mostrar_matriz_de_costos();

        // void mostrar_matriz_de_caminos();

        void liberar_matriz(int** matriz);
};



#endif // FLOYD_H
