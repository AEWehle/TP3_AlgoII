#include "Floyd.h"
#include <iostream>

const int INFINITO = 99999;

// Constructor
Floyd::Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia):AlgoritmoCaminoMinimo(lista_vertices,matriz_de_adyacencia){
    matriz_de_caminos = nullptr;
    matriz_de_costos = nullptr;
    crear_matriz_de_caminos();
    crear_matriz_de_costos(matriz_de_adyacencia);
    aplicar_floyd();
}

// Destructor
Floyd::~Floyd(){
    liberar_matriz(matriz_de_costos);
    liberar_matriz(matriz_de_caminos);
    matriz_de_costos = nullptr;
    matriz_de_caminos = nullptr;
}

void Floyd::mostrar_camino_minimo(int origen, int destino){

    // Me fijo si existe un camino
    if(matriz_de_caminos[origen][destino] == NO_SE_ENCUENTRA){
        cout << "No existe un camino entre " << origen << " y " << destino << endl;
    }else{
        cout << "El camino mínimo entre " << origen << " y " << destino << " es: ";

        while(origen != destino){
            origen = matriz_de_caminos[origen][destino];
            Vertice* vertice = new Vertice(origen);
            cout << " -> " << lista_vertices->obtener_posicion_en_lista(vertice);
            delete vertice;
        }
    }

    cout << endl;

    mostrar_matriz_de_caminos();

    mostrar_matriz_de_costos();
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
    // int** matriz_de_costos_nueva = new int*[cantidad_vertices_en_algoritmo];
    // for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
    //     matriz_de_costos_nueva[i] = new int[cantidad_vertices_en_algoritmo];
    // }

    // // Copio lo que hay en la matriz de adyacencia
    // for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
    //     for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
    //         matriz_de_costos_nueva[i][j] = matriz_de_adyacencia[i][j];
    //     }
    // }

    // matriz_de_costos = matriz_de_costos_nueva;

    matriz_de_costos = new int*[cantidad_vertices_en_algoritmo];
    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        matriz_de_costos[i] = new int[cantidad_vertices_en_algoritmo];
    }

    // Copio lo que hay en la matriz de adyacencia
    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
            matriz_de_costos[i][j] = matriz_de_adyacencia[i][j];
        }
    }

}

void Floyd::crear_matriz_de_caminos(){
    // int** matriz_de_caminos_nueva = new int*[cantidad_vertices_en_algoritmo];
    // for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
    //     matriz_de_caminos_nueva[i] = new int[cantidad_vertices_en_algoritmo];
    // }

    // for(int i = 0; i < cantidad_vertices_en_algoritmo; i++){
    //     for(int j = 0; j < cantidad_vertices_en_algoritmo; j++) {
    //         matriz_de_caminos_nueva[i][j] = j;
    //     }
    // }

    // matriz_de_caminos = matriz_de_caminos_nueva;

    matriz_de_caminos = new int*[cantidad_vertices_en_algoritmo];
    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        matriz_de_caminos[i] = new int[cantidad_vertices_en_algoritmo];
    }

    for(int i = 0; i < cantidad_vertices_en_algoritmo; i++){
        for(int j = 0; j < cantidad_vertices_en_algoritmo; j++) {
            matriz_de_caminos[i][j] = j;
        }
    }
}

void Floyd::mostrar_matriz_de_costos(){
    cout << "Matriz de costos"<< endl;

    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
            if(matriz_de_costos[i][j] == INFINITO){
                cout << "|" <<  "-" << "|";    
            }else{
                cout << "|" <<  matriz_de_costos[i][j] << "|";
            }
            
        }
        cout << endl;
    }

    cout << endl;
}

void Floyd::mostrar_matriz_de_caminos(){
    cout << "Matriz de caminos"<< endl;

    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
            if(matriz_de_caminos[i][j] == INFINITO){
                cout << "|" <<  "-" << "|";    
            }else{
                cout << "|" <<  matriz_de_caminos[i][j] << "|";
            }
            
        }
        cout << endl;
    }

    cout << endl;
}

void Floyd::aplicar_floyd(){
    // Creo las matrices de costos y de caminos
    crear_matriz_de_costos(matriz_de_adyacencia);
    crear_matriz_de_caminos();

    // Aplico algoritmo de Floyd

    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
            for(int k=0; k<cantidad_vertices_en_algoritmo; k++){
                if( (matriz_de_adyacencia[j][i] + matriz_de_adyacencia[i][k]) < matriz_de_adyacencia[j][k] && matriz_de_adyacencia[i][k]!=INFINITO && matriz_de_adyacencia[j][i]!=INFINITO){
                    matriz_de_adyacencia[j][k] = matriz_de_adyacencia[j][i] + matriz_de_adyacencia[i][k];
                    matriz_de_caminos[j][k] = matriz_de_caminos[j][i];
                }
            }
        }
    }
}
