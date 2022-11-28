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
        // Constructor
        Grafo();

        // Destructor
        ~Grafo();

        void mostrar_grafo();

        void agregar_vertice(int nuevo);
        
        void agregar_camino(int origen, int destino, int costo);

        void mapa_a_grafo(int dimensiones, int** matriz_de_costos_en_mapa);

        void obtener_camino_minimo(int origen, int destino,Lista<Coordenada>* lista_coordenadas_recorridas);

        void obtener_camino_minimo_por_coordenadas(int coord_x_origen, int coord_y_origen, int coord_x_destino, int coord_y_destino, Lista<Coordenada>* lista_coordenadas_recorridas);

        void aplicar_algoritmo_camino_minimo();

    private:
        void mostrar_vertices();

        void crear_matriz_de_adyacencia();

        void agrandar_matriz_de_adyacencia();

        void actualizar_vertices_en_matriz_adyacencia(int** nueva_matriz_adyacencia);

        void mostrar_matriz_adyacencia();
        
        void liberar_matriz_adyacencia(int cantidad_vertices);

        int obtener_vertice_en_grafo(int vertice);

        int convertir_coordenadas_a_celda(int coord_x, int coord_y);

};

#endif //GRAFO_H