#ifndef FLOYD_H
#define FLOYD_H
#include "Algoritmo_camino_min.h"

using namespace std;

// Algoritmo de camino mínimo: Floyd Warshall

class Floyd : public AlgoritmoCaminoMinimo{
    // Atributos
    private:
        int** matriz_de_costos; // tiene los costos de ir de un vértice a otro
        int** matriz_de_caminos; // tiene los caminos para ir de un vértice a otro

    // Métodos
    public:
        // Constructor con parámetros
        // PRE: recibe una lista de vertices y una matriz de adyacencia
        // POS: modifica la matriz de costos y la matriz de caminos según el algoritmo de Floyd
        Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia);

        // Destructor
        ~Floyd();

        // PRE: recibe una posicion de origen y una de destino, y una lista de coordenadas vacia
        // POS: se obtienen las coordenadas del camino recorrido y se guardan en la lista recibida, y el costo del camino
        void obtener_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_camino) override;

    private:
        // PRE: -
        // POS: crea la matriz de costos según la matriz de adyacencia
        void crear_matriz_de_costos(int** matriz_de_adyacencia);

        // PRE: -
        // POS: crea la matriz de caminos según la matriz de adyacencia
        void crear_matriz_de_caminos();

        // PRE: -
        // POS: crea y modifica la matriz de costos y la matriz de caminos según el algoritmo de Floyd
        void aplicar_floyd();

        // PRE: -
        // POS: devuelve el vertice siguiente al vertice en el camino vertice -> origen
        int hallar_siguiente_vertice_en_el_camino(int origen, int destino);

        // PRE: -
        // POS: imprime por pantalla el siguiente vertice en el camino en formato coordenadas de dos dimensiones
        void mostrar_siguiente_vertice_en_coordenadas(int nuevo_origen);

        // PRE: -
        // POS: imprime en la terminal la matriz de costos
        void mostrar_matriz_de_costos();

        // PRE: -
        // POS: imprime en la termina la matriz de caminos
        void mostrar_matriz_de_caminos();

        // PRE: recibe una matriz
        // POS: libera la memoria de la matriz
        // void liberar_matriz(int** matriz);

        // PRE: recibe un número de celda en una matriz y la dimension de la matriz
        // POS: convierte una ubicacion de una matriz (celda) en una coordenada de dos dimensiones
        void convertir_celdas_a_coordenadas(int celda, int dimension, int& coord_fila, int& coord_columna);
};


#endif // FLOYD_H
