#include "Grafo.h"
#include <iostream>

Grafo::Grafo(){
    matriz_de_adyacencia = nullptr;
    lista_vertices = new Lista<Vertice>();
    algoritmo_camino_minimo = nullptr;
}

void Grafo::mostrar_grafo(){
    mostrar_vertices();
    mostrar_matriz_adyacencia();
}

void Grafo::mostrar_vertices(){
    cout << "Vértices: ";
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    for(int i=1; i<=cantidad_vertices; i++){
        cout << lista_vertices->consulta(i)->obtener_nombre();
        if( (i+1) != cantidad_vertices){
            cout << " - ";
        }
    }
}

void Grafo::agregar_vertice(int nuevo){
    Vertice* nuevo_vertice = new Vertice(nuevo);
    lista_vertices->alta(nuevo_vertice,lista_vertices->obtener_cantidad()+1);

    //algo con matriz de adyacencia
    if(lista_vertices->obtener_cantidad() == 1){
        // Creo matriz de adyacencia
        crear_matriz_de_adyacencia();
    }else{
        agrandar_matriz_de_adyacencia();
    }
}

void Grafo::crear_matriz_de_adyacencia(){
    matriz_de_adyacencia = new int*[1];
    matriz_de_adyacencia[0] = new int[1];

    matriz_de_adyacencia[0][0] = 0;
}

void Grafo::agrandar_matriz_de_adyacencia(){
    // Creo una matriz auxiliar
    int tamanio_original = lista_vertices->obtener_cantidad() - 1;
    int nuevo_tamanio = lista_vertices->obtener_cantidad();
    int ** matriz_aux = new int*[nuevo_tamanio];

    for(int i=0; i<nuevo_tamanio; i++){
        matriz_aux[i] = new int[nuevo_tamanio];
    }

    // Le copio lo que ya tenía la matriz de adyacencia
    for(int i=0; i<tamanio_original; i++){
        for(int j=0; j<tamanio_original; j++){
            matriz_aux[i][j] = matriz_de_adyacencia[i][j];
        }
    }

    // Agrego el nuevo vertice a la matriz de adyacencia
    actualizar_vertices_en_matriz_adyacencia(matriz_aux);

    // Libero la memoria pedida para la matriz original y la reemplazo por la nueva
    liberar_matriz_adyacencia();

    matriz_de_adyacencia = matriz_aux;
}

void Grafo::mostrar_matriz_adyacencia(){
    cout << "MATRIZ DE ADYACENCIA" << endl;
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    for(int i=0; i<cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++){
            cout << "|" <<  matriz_de_adyacencia[i][j] << "|";
        }
        cout << endl;
    }
}

void Grafo::liberar_matriz_adyacencia(){
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    for(int i=0; i<cantidad_vertices; i++){
        delete[] matriz_de_adyacencia[i];
    }

    delete[] matriz_de_adyacencia;
}

void Grafo::actualizar_vertices_en_matriz_adyacencia(int** nueva_matriz_adyacente){
    int nuevo_tamanio = lista_vertices->obtener_cantidad();
    // Pongo infinito donde aún no hay datos (en toda la fila y toda la col nuevo_tamanio)
    for(int i=0; i<nuevo_tamanio; i++){
        nueva_matriz_adyacente[nuevo_tamanio][i] = INFINITO;
        nueva_matriz_adyacente[i][nuevo_tamanio] = INFINITO;
    }
    // Pongo un 0 en la posición en la tabla que refiere a la distancia del vértice a sí mismo
    nueva_matriz_adyacente[nuevo_tamanio][nuevo_tamanio] = 0;
}

int Grafo::obtener_vertice_en_grafo(int vertice_a_buscar){
    Vertice* vertice = new Vertice(vertice_a_buscar);

    int posicion_vertice = lista_vertices->obtener_posicion_en_lista(vertice);

    if(posicion_vertice == NO_SE_ENCUENTRA){
        cout << "El vertice " << vertice << " no se encuentra en el grafo." << endl;
    }

    return posicion_vertice;
}

void Grafo::agregar_camino(int origen, int destino, int costo){
    // Vertice* vertice_origen = new Vertice(origen);
    // Vertice* vertice_destino = new Vertice(destino);

    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    if(pos_origen != NO_SE_ENCUENTRA && pos_destino != NO_SE_ENCUENTRA){
        matriz_de_adyacencia[pos_origen][pos_destino] = costo;
        matriz_de_adyacencia[pos_destino][pos_origen] = costo;
    }
}

void Grafo::obtener_camino_minimo(int origen, int destino){

    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    algoritmo_camino_minimo->mostrar_camino_minimo(pos_origen,pos_destino);
}

// void Grafo::aplicar_algoritmo_camino_minimo(int origen, int destino){

//     algoritmo_camino_minimo->mostrar_camino_minimo(origen,destino);


// }




Grafo::~Grafo() {
    //delete matrices probar
    matriz_de_adyacencia = nullptr;
    delete lista_vertices;
    delete algoritmo_camino_minimo;
}
