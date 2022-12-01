#include "Grafo.h"
#include <iostream>
#include "Algoritmo_camino_min.h"

const int NO_SE_ENCUENTRA = -1;

Grafo::Grafo(){

    matriz_de_adyacencia = nullptr;
    algoritmo_camino_minimo = nullptr;
    lista_vertices = new Lista<Vertice>();

}

void Grafo::mostrar_grafo(){

    mostrar_vertices();
    mostrar_matriz_adyacencia();

}

void Grafo::mapa_a_grafo(int dimension, int** matriz_de_costos_por_destino){

    // Creo grafo de tamanio dimension*dimension
    for(int i=1; i<= dimension*dimension; i++){
        agregar_vertice(i);
    }

    int costo_camino_ida = 0;
    int costo_camino_vuelta = 0;
    
    // Creo caminos
    int celda = 1;
    while(celda != (dimension*dimension)+1){
        for(int fila=0; fila<dimension; fila++){
            for(int col=0; col<dimension; col++){

                if(col < dimension-1){

                    costo_camino_ida = matriz_de_costos_por_destino[fila][col+1];
                    costo_camino_vuelta = matriz_de_costos_por_destino[fila][col];
                    
                    agregar_camino(celda,celda+1,costo_camino_ida);
                    agregar_camino(celda+1,celda,costo_camino_vuelta);
                }
                
                if(fila < dimension-1){

                    costo_camino_ida = matriz_de_costos_por_destino[fila+1][col];
                    costo_camino_vuelta = matriz_de_costos_por_destino[fila][col];

                    agregar_camino(celda,celda+dimension,costo_camino_ida);
                    agregar_camino(celda+dimension,celda,costo_camino_vuelta);
                }

                celda++;

            }
        }

    }

}

void Grafo::mostrar_vertices(){

    cout << "      Vértices: ";

    int cantidad_vertices = lista_vertices->obtener_cantidad();

    int contador = 1;

    while(contador != cantidad_vertices+1){
        cout << lista_vertices->consulta(contador)->obtener_nombre();
        if(contador != cantidad_vertices){
            cout << "       - ";
        }
        contador++;
    };

    cout << endl << endl;
}

void Grafo::agregar_vertice(int nuevo){

    Vertice* nuevo_vertice = new Vertice(nuevo);

    lista_vertices->alta(nuevo_vertice,lista_vertices->obtener_cantidad()+1);

    if(lista_vertices->obtener_cantidad() == 1){
        crear_matriz_de_adyacencia();
    }
    
    else{
        agrandar_matriz_de_adyacencia();
    }

}

void Grafo::crear_matriz_de_adyacencia(){

    matriz_de_adyacencia = new int*[1];
    matriz_de_adyacencia[0] = new int[1];
    matriz_de_adyacencia[0][0] = 0;
    
}

void Grafo::agrandar_matriz_de_adyacencia(){

    int tamanio_original = lista_vertices->obtener_cantidad() - 1;
    int nuevo_tamanio = lista_vertices->obtener_cantidad();
    int ** matriz_aux = new int*[nuevo_tamanio];

    for(int i=0; i<nuevo_tamanio; i++){
        matriz_aux[i] = new int[nuevo_tamanio];
    }

    for(int i=0; i<tamanio_original; i++){
        for(int j=0; j<tamanio_original; j++){
            matriz_aux[i][j] = matriz_de_adyacencia[i][j];
        }
    }

    actualizar_vertices_en_matriz_adyacencia(matriz_aux);

    liberar_matriz_adyacencia(tamanio_original);

    matriz_de_adyacencia = matriz_aux;

}

void Grafo::mostrar_matriz_adyacencia(){

    cout << "      MATRIZ DE ADYACENCIA" << endl;

    int cantidad_vertices = lista_vertices->obtener_cantidad();

    for(int i=0; i<cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++){
            if(matriz_de_adyacencia[i][j] == INFINITO){
                cout << "      |" <<  "-" << "|";    
            }else{
                cout << "      |" <<  matriz_de_adyacencia[i][j] << "|";
            }
            
        }

        cout << endl;
    }

    cout << endl;

}

void Grafo::liberar_matriz_adyacencia(int cantidad_vertices){

    for(int i=0; i<cantidad_vertices; i++){
        delete[] matriz_de_adyacencia[i];
    }

    delete[] matriz_de_adyacencia;

}

void Grafo::actualizar_vertices_en_matriz_adyacencia(int** nueva_matriz_adyacencia){

    // tamanio_original porque empiezan en 0 las posiciones en las matrices
    int tamanio_original = lista_vertices->obtener_cantidad() - 1;

    // infinito donde aún no hay datos (en toda la fila y toda la columna nuevo_tamanio)
    for(int i=0; i<tamanio_original; i++){
        nueva_matriz_adyacencia[tamanio_original][i] = INFINITO;
        nueva_matriz_adyacencia[i][tamanio_original] = INFINITO;
    }

    // 0 en la posición en la tabla que refiere a la distancia del vértice a sí mismo
    nueva_matriz_adyacencia[tamanio_original][tamanio_original] = 0;

}

int Grafo::obtener_vertice_en_grafo(int vertice_a_buscar){

    int contador = 1;

    int posicion_vertice = NO_SE_ENCUENTRA;

    while(contador<=lista_vertices->obtener_cantidad() && posicion_vertice == NO_SE_ENCUENTRA){

        if(lista_vertices->consulta(contador)->obtener_nombre() == vertice_a_buscar){
            posicion_vertice = contador;
        }

        contador++;
    }

    if(posicion_vertice == NO_SE_ENCUENTRA){
        cout << "El vertice " << vertice_a_buscar << " no se encuentra en el grafo." << endl;
    }
    
    return posicion_vertice;

}

void Grafo::agregar_camino(int origen, int destino, int costo){

    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    if(pos_origen != NO_SE_ENCUENTRA && pos_destino != NO_SE_ENCUENTRA){
        matriz_de_adyacencia[pos_origen-1][pos_destino-1] = costo;
    }

    else{
        cout << "Ocurrió un error al intentar agregar un camino en el grafo." << endl;
    }

}

void Grafo::aplicar_algoritmo_camino_minimo(){

    algoritmo_camino_minimo = new Floyd(lista_vertices,matriz_de_adyacencia);

}

void Grafo::obtener_camino_minimo(int origen, int destino,Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_camino){
    
    aplicar_algoritmo_camino_minimo();

    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    if(pos_origen != NO_SE_ENCUENTRA && pos_destino != NO_SE_ENCUENTRA){
        algoritmo_camino_minimo->obtener_camino_minimo(pos_origen,pos_destino, lista_coordenadas_recorridas,costo_camino);
    }
    
    else{
        cout << "Ocurrió un error al intentar obtener el camino mínimo." << endl;
    }

}

void Grafo::obtener_camino_minimo_por_coordenadas(int coord_fila_origen, int coord_columna_origen, int coord_fila_destino, int coord_columna_destino,Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_camino, int dimension){
    
    int pos_origen = convertir_coordenadas_a_celda(coord_fila_origen,coord_columna_origen, dimension);
    int pos_destino = convertir_coordenadas_a_celda(coord_fila_destino,coord_columna_destino, dimension);
    
    obtener_camino_minimo(pos_origen,pos_destino,lista_coordenadas_recorridas,costo_camino);

}

int Grafo::convertir_coordenadas_a_celda(int coord_fila, int coord_columna, int dimension){

    return coord_fila*dimension + coord_columna + 1;

}


Grafo::~Grafo() {

    liberar_matriz_adyacencia(lista_vertices->obtener_cantidad());
    matriz_de_adyacencia = nullptr;

    lista_vertices->destruir_con_delete();
    delete lista_vertices;
    lista_vertices = nullptr;

    delete algoritmo_camino_minimo;
    algoritmo_camino_minimo = nullptr;

}