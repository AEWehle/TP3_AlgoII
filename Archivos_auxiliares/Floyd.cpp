#include "Floyd.h"
#include <iostream>

const int INFINITO = 99999;

// Constructor
Floyd::Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia):AlgoritmoCaminoMinimo(lista_vertices,matriz_de_adyacencia){
    matriz_de_caminos = nullptr;
    matriz_de_costos = nullptr;
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
    if(matriz_de_caminos[origen-1][destino-1] == 0){
        cout << "No existe un camino entre " << origen << " y " << destino << endl;
    }else if(origen == destino){
        cout << "El destino del camino coincide con su origen." << endl;
    }else{
        cout << "El camino mínimo entre " << origen << " y " << destino;
        cout << " tiene un costo de $" << matriz_de_costos[origen-1][destino-1] << " y es: ";
        
        // Imprimo el origen
        cout << origen;
        // Sigo recorriendo el camino hasta llegar al destino
        while(origen != destino){
            origen = hallar_siguiente_vertice_en_el_camino(origen,destino);
            
            mostrar_siguiente_paso_en_camino(origen);
        }
    }

    cout << endl;
}

int Floyd::hallar_siguiente_vertice_en_el_camino(int origen, int destino){
    return matriz_de_caminos[origen-1][destino-1];
}

void Floyd::mostrar_siguiente_paso_en_camino(int nuevo_origen){
    Vertice* vertice = new Vertice(nuevo_origen);
    cout << " -> " << lista_vertices->obtener_posicion_en_lista(vertice);
    delete vertice;
}

void Floyd::liberar_matriz(int** matriz){

    if(matriz != nullptr){
        for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
            delete[] matriz[i];
        }

        delete[] matriz;
        matriz = nullptr;
    }
}

void Floyd::crear_matriz_de_costos(int** matriz_de_adyacencia){

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

    matriz_de_caminos = new int*[cantidad_vertices_en_algoritmo];
    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        matriz_de_caminos[i] = new int[cantidad_vertices_en_algoritmo];
    }

    for(int i = 0; i < cantidad_vertices_en_algoritmo; i++){
        for(int j = 0; j < cantidad_vertices_en_algoritmo; j++) {
            if(i == j){
                matriz_de_caminos[i][j] = INFINITO;    
            }else{
                // Inicializo todas las columnas con los nombres de los vertices
                matriz_de_caminos[i][j] = j+1;
            }
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

    cout << "\t\t ALGORITMO FLOYD" << endl << endl;

    // Creo las matrices de costos y de caminos
    crear_matriz_de_costos(matriz_de_adyacencia);
    crear_matriz_de_caminos();

    // Aplico algoritmo de Floyd

    for(int i=0; i<cantidad_vertices_en_algoritmo; i++){
        for(int j=0; j<cantidad_vertices_en_algoritmo; j++){
            for(int k=0; k<cantidad_vertices_en_algoritmo; k++){
                if( ((matriz_de_costos[j][i] + matriz_de_costos[i][k]) < matriz_de_costos[j][k]) && matriz_de_costos[i][k]!=INFINITO && matriz_de_costos[j][i]!=INFINITO){

                    matriz_de_costos[j][k] = matriz_de_costos[j][i] + matriz_de_costos[i][k];
                    matriz_de_caminos[j][k] = matriz_de_caminos[j][i];

                }
            }
        }
    }

    cout << endl;

    mostrar_matriz_de_caminos();

    mostrar_matriz_de_costos();

    cout << endl;
}
