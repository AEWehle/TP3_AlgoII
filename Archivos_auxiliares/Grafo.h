#ifndef GRAFO_H
#define GRAFO_H
#include "lista.h"
#include "Vertice.h"
#include "Algoritmo_camino_min.h"
#include "Floyd.h"
#include "Coordenada.h"

using namespace std;

const int INFINITO = 99999;

class Grafo{
    // Atributos
    private:
        int** matriz_de_adyacencia;
        Lista<Vertice>* lista_vertices;
        AlgoritmoCaminoMinimo* algoritmo_camino_minimo;

    // Métodos
    public:
        // Constructor sin parámetros
        // PRE: -
        // POS: construye un grafo vacío
        Grafo();

        // Constructor con parámetros
        // PRE: recibe las dimensiones del grafo a crear y una matriz con los costos a aplicar a los caminos
        // POS: crea un grafo regular de orden 2 dirigido con caminos ida y vuelta con pesos
        // Grafo(int dimensiones, int** matriz_de_costos);

        // Destructor
        ~Grafo();

        // PRE: -
        // POS: muestra lista de vertices y matriz de adyacencia
        void mostrar_grafo();

        // PRE: -
        // POS: agrega un vertice en el grafo
        void agregar_vertice(int nuevo);
        
        // PRE: -
        // POS: crea un camino en el sentido origen -> destino, con costo siendo el peso de la arista
        void agregar_camino(int origen, int destino, int costo);

        // PRE: recibe la dimension del grafo y una matriz de costos que contiene los pesos de los caminos a crear
        // POS: crea un grafo regular de orden 2 que contendrá (dimensiones*dimensiones) vertices con caminos de ida y vuelta con pesos
        void mapa_a_grafo(int dimension, int** matriz_de_costos);

        // PRE: recibe coordenadas verticales (fila) y horizontales (columna) del lugar de destino y origen (posiciones en una matriz).
        // Además recibe una lista de coordenadas vacía.
        // POS: busca el camino mínimo entre las dos coordenadas, previamente traducidas a posiciones de vértices
        void obtener_camino_minimo_por_coordenadas(int coord_vertical_origen, int coord_horizontal_origen, int coord_vertical_destino, int coord_horizontal_destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_camino, int dimension);

        // PRE: recibe una posición de origen y una de destino
        // POS: busca el camino mínimo entre las dos posiciones.
        // Carga en la lista de coordenadas las ubicaciones atravesadas en el camino. Actualiza el valor de costo_camino con el costo
        // del camino recorrido.
        void obtener_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_viaje);

        // PRE: -
        // POS: inicializa el algoritmo de camino minimo (Floyd)
        void aplicar_algoritmo_camino_minimo();

    private:
        // PRE: -
        // POS: muestra el listado de vertices
        void mostrar_vertices();

        // PRE: -
        // POS: crea una matriz de adyacencia de 1x1
        void crear_matriz_de_adyacencia();

        // PRE: la matriz de adyacencia ya debe existir
        // POS: incrementa el tamanio de la matriz de adyacencia para agregar un vértice
        void agrandar_matriz_de_adyacencia();

        // PRE: la matriz de adyacencia ya debe existir y fue incrementada
        // POS: completa la matriz de adyacencia con ceros e infinitos según el nuevo tamanio de la matriz
        void actualizar_vertices_en_matriz_adyacencia(int** nueva_matriz_adyacencia);

        // PRE: la matriz de adyacencia ya debe existir
        // POS: imprime en pantalla la matriz de adyacencia
        void mostrar_matriz_adyacencia();
        
        // PRE: recibe la cantidad de vertices de la matriz a borrar
        // POS: libera la memoria
        void liberar_matriz_adyacencia(int cantidad_vertices);

        // PRE: recibe un vertice a buscar
        // POS: devuelve la ubicacion del vertice en el grafo
        int obtener_vertice_en_grafo(int vertice);

        // PRE: -
        // POS: convierte una coordenada de dos dimensiones [coord_vertical,coord_horizontal] en un numero de
        // celda de una dimension y devuelve ese numero
        int convertir_coordenadas_a_celda(int coord_vertical, int coord_horizontal, int dimension);

};

#endif //GRAFO_H