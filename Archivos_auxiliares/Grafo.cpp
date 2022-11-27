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

void Grafo::mapa_a_grafo(int dim, int** matriz_de_costos_por_destino){

    // Creo grafo de dim*dim
    for(int i=1; i<= dim*dim; i++){
        agregar_vertice(i);
    }

    int costo_camino_ida = 0;
    int costo_camino_vuelta = 0;
    
    // Creo caminos
    int celda = 1;
    while(celda != (dim*dim)+1){
        for(int fila=0; fila<dim; fila++){
            for(int col=0; col<dim; col++){

                if(col < dim-1){

                    costo_camino_ida = matriz_de_costos_por_destino[fila][col+1];
                    costo_camino_vuelta = matriz_de_costos_por_destino[fila][col];
                    
                    // cout << "\t\t$$$ costo para ir de " << celda << " a " << celda+1 << ": " << costo_camino_ida << endl<<endl;

                    agregar_camino(celda,celda+1,costo_camino_ida);
                    agregar_camino(celda+1,celda,costo_camino_vuelta);
                }
                
                if(fila < dim-1){

                    costo_camino_ida = matriz_de_costos_por_destino[fila+1][col];
                    costo_camino_vuelta = matriz_de_costos_por_destino[fila][col];

                    // cout << "\t\t$$$ costo para ir de " << celda << " a " << celda+dim << ": " << costo_camino_ida << endl<<endl;

                    agregar_camino(celda,celda+dim,costo_camino_ida);
                    agregar_camino(celda+dim,celda,costo_camino_vuelta);
                }
                celda++;
            }
        }

    }
    

}

void Grafo::mostrar_vertices(){
    cout << "Vértices: ";
    int cantidad_vertices = lista_vertices->obtener_cantidad();

    int contador = 1;
    while(contador != cantidad_vertices+1){
        cout << lista_vertices->consulta(contador)->obtener_nombre();
        if(contador != cantidad_vertices){
            cout << " - ";
        }
        contador++;
    };

    cout << endl << endl;
}

void Grafo::agregar_vertice(int nuevo){
    Vertice* nuevo_vertice = new Vertice(nuevo);

    lista_vertices->alta(nuevo_vertice,lista_vertices->obtener_cantidad()+1);

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
    liberar_matriz_adyacencia(tamanio_original);

    matriz_de_adyacencia = matriz_aux;
}

void Grafo::mostrar_matriz_adyacencia(){
    cout << "MATRIZ DE ADYACENCIA" << endl;
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    for(int i=0; i<cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++){
            if(matriz_de_adyacencia[i][j] == INFINITO){
                cout << "|" <<  "-" << "|";    
            }else{
                cout << "|" <<  matriz_de_adyacencia[i][j] << "|";
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
    // Pongo infinito donde aún no hay datos (en toda la fila y toda la col nuevo_tamanio)
    for(int i=0; i<tamanio_original; i++){
        nueva_matriz_adyacencia[tamanio_original][i] = INFINITO;
        nueva_matriz_adyacencia[i][tamanio_original] = INFINITO;
    }
    // Pongo un 0 en la posición en la tabla que refiere a la distancia del vértice a sí mismo
    nueva_matriz_adyacencia[tamanio_original][tamanio_original] = 0;
}

int Grafo::obtener_vertice_en_grafo(int vertice_a_buscar){
    Vertice* vertice = new Vertice(vertice_a_buscar);

    int posicion_vertice = lista_vertices->obtener_posicion_en_lista(vertice);

    if(posicion_vertice == NO_SE_ENCUENTRA){
        cout << "El vertice " << vertice << " no se encuentra en el grafo." << endl;
    }

    delete vertice;

    return posicion_vertice;
}

void Grafo::agregar_camino(int origen, int destino, int costo){
    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    if(pos_origen != NO_SE_ENCUENTRA && pos_destino != NO_SE_ENCUENTRA){
        matriz_de_adyacencia[pos_origen-1][pos_destino-1] = costo;
        // Si los costos de ida y vuelta fueran iguales:
        // matriz_de_adyacencia[pos_destino-1][pos_origen-1] = costo;
    }

}

void Grafo::aplicar_algoritmo_camino_minimo(){
    algoritmo_camino_minimo = new Floyd(lista_vertices,matriz_de_adyacencia);
}

void Grafo::obtener_camino_minimo(int origen, int destino){

    int pos_origen = obtener_vertice_en_grafo(origen);
    int pos_destino = obtener_vertice_en_grafo(destino);

    algoritmo_camino_minimo->mostrar_camino_minimo(pos_origen,pos_destino);
}

void Grafo::obtener_camino_minimo_por_coordenadas(int coord_x_origen, int coord_y_origen, int coord_x_destino, int coord_y_destino){
    // Transformo coordenadas en vertices
    int pos_origen = convertir_coordenadas_a_celda(coord_x_origen,coord_y_origen);
    int pos_destino = convertir_coordenadas_a_celda(coord_x_destino,coord_y_destino);

    obtener_camino_minimo(pos_origen,pos_destino);
}

int Grafo::convertir_coordenadas_a_celda(int coord_x, int coord_y){
    return (coord_x + 1)*(coord_y + 1);
}


Grafo::~Grafo() {
    liberar_matriz_adyacencia(lista_vertices->obtener_cantidad());
    matriz_de_adyacencia = nullptr;
    delete lista_vertices;
    delete algoritmo_camino_minimo;
}