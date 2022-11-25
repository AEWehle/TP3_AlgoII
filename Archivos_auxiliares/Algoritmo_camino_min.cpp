#include "Algoritmo_camino_min.h"

AlgoritmoCaminoMinimo::AlgoritmoCaminoMinimo(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia){
    this->lista_vertices = lista_vertices;
    this->matriz_de_adyacencia = matriz_de_adyacencia;
    this->cantidad_vertices_en_algoritmo = lista_vertices->obtener_cantidad();
}
