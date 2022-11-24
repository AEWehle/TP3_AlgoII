#include "Floyd.h"
#include <iostream>

const int INFINITO = 99999;

// Constructor
Floyd::Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia):AlgoritmoCaminoMinimo(lista_vertices,matriz_de_adyacencia){
    crear_matriz_de_caminos();
    crear_matriz_de_costos(matriz_de_adyacencia);
    aplicar_floyd();
}

// Destructor
Floyd::~Floyd(){
    liberar_matriz(matriz_de_costos);
    liberar_matriz(matriz_de_caminos);
}

void Floyd::mostrar_camino_minimo(int origen, int destino){


    // Me fijo si existe un camino
    if(matriz_de_caminos[origen][destino] == NO_SE_ENCUENTRA){
        cout << "No existe un camino entre " << origen << " y " << destino << endl;
    }else{
        cout << "El camino mínimo entre " << origen << " y " << destino << " es: " << endl;
        cout << "\t\t\t " << origen << endl;
        while(origen != destino){
            origen = matriz_de_caminos[origen][destino];
            cout << " -> " << lista_vertices->consulta(origen);
        }
    }

    cout << endl;


    //mostrarMatrices();


}

void Floyd::liberar_matriz(int** matriz){
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    if(matriz != nullptr){
        for(int i=0; i<cantidad_vertices; i++){
            delete[] matriz[i];
        }

        delete[] matriz;
        matriz = nullptr;
    }
}

void Floyd::crear_matriz_de_costos(int** matriz_de_adyacencia){
    int cantidad_vertices = lista_vertices->obtener_cantidad();
    
    int** matriz_de_costos_nueva = new int*[cantidad_vertices];
    for(int i=0; i<cantidad_vertices; i++){
        matriz_de_costos_nueva[i] = new int[cantidad_vertices];
    }

    // Copio lo que hay en la matriz de adyacencia
    for(int i=0; i<cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++){
            matriz_de_costos_nueva[i][j] = matriz_de_adyacencia[i][j];
        }
    }

    matriz_de_costos = matriz_de_costos_nueva;
}

void Floyd::crear_matriz_de_caminos(){
    int cantidad_vertices = lista_vertices->obtener_cantidad();

    int** matriz_de_caminos_nueva = new int*[cantidad_vertices];
    for(int i=0; i<cantidad_vertices; i++){
        matriz_de_caminos_nueva[i] = new int[cantidad_vertices];
    }

    for(int i = 0; i < cantidad_vertices; i++){
        for(int j = 0; j < cantidad_vertices; j++) {
            matriz_de_caminos_nueva[i][j] = j;
        }
    }

    matriz_de_caminos = matriz_de_caminos_nueva;
}

// void Floyd::mostrar_matriz_de_costos(){
//     cout << "Matriz de costos"<< endl;

//     int cantidad_vertices = lista_vertices->obtener_cantidad();

//     for(int i=0; i<cantidad_vertices; i++){

//     }
// }



void Floyd::aplicar_floyd(){
    // Creo las matrices de costos y de caminos
    crear_matriz_de_costos(matriz_de_adyacencia);
    crear_matriz_de_caminos();

    // Aplico algoritmo de Floyd
    int cantidad_vertices = lista_vertices->obtener_cantidad();

    for(int i=0; i<cantidad_vertices; i++){
        for(int j=0; j<cantidad_vertices; j++){
            for(int k=0; k<cantidad_vertices; k++){
                if( (matriz_de_adyacencia[j][i] + matriz_de_adyacencia[i][k]) < matriz_de_adyacencia[j][k] && matriz_de_adyacencia[i][k]!=INFINITO && matriz_de_adyacencia[j][i]!=INFINITO){
                    matriz_de_adyacencia[j][k] = matriz_de_adyacencia[j][i] + matriz_de_adyacencia[i][k];
                    matriz_de_caminos[j][k] = matriz_de_caminos[j][i];
                }
            }
        }
    }

}
