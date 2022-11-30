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

void Floyd::obtener_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo_camino){

    // En caso de querer imprimir el camino descomentar *1* *2* y *3*

    if(matriz_de_caminos[origen-1][destino-1] == 0){

        cout << "No existe un camino entre " << origen << " y " << destino << endl;
    
    }
    
    else if(origen == destino){

        cout << "El destino del camino coincide con su origen." << endl;
    
    }
    
    else{

        int coord_fila_origen = 0, coord_columna_origen = 0, coord_fila_destino = 0, coord_columna_destino = 0;

        convertir_celdas_a_coordenadas(origen,8,coord_fila_origen,coord_columna_origen);
        convertir_celdas_a_coordenadas(destino,8,coord_fila_destino,coord_columna_destino);

        costo_camino = matriz_de_costos[origen-1][destino-1];
        
        // *1*
        // cout << "El camino mínimo entre [" << coord_fila_origen << "," << coord_columna_origen << "] y [" << coord_fila_destino << "," << coord_columna_destino << "]";
        // cout << " tiene un costo de $" << costo_camino << " y es: ";

        Coordenada* coordenada_origen = new Coordenada(coord_fila_origen,coord_columna_origen);
        lista_coordenadas_recorridas->alta(coordenada_origen,lista_coordenadas_recorridas->obtener_cantidad()+1);
        
        // *2*
        // cout << "[" << coord_fila_origen << "," << coord_columna_origen << "]";
        
        while(origen != destino){

            origen = hallar_siguiente_vertice_en_el_camino(origen,destino);

            convertir_celdas_a_coordenadas(origen,8,coord_fila_origen,coord_columna_origen);

            Coordenada* coordenada_origen = new Coordenada(coord_fila_origen,coord_columna_origen);
            lista_coordenadas_recorridas->alta(coordenada_origen,lista_coordenadas_recorridas->obtener_cantidad()+1);

            // *3* 
            // mostrar_siguiente_vertice_en_coordenadas(origen);
        }

    }

    cout << endl;
}

int Floyd::hallar_siguiente_vertice_en_el_camino(int origen, int destino){

    return matriz_de_caminos[origen-1][destino-1];

}

void Floyd::convertir_celdas_a_coordenadas(int celda, int dimension, int& coord_vertical, int& coord_horizontal){
    // Fila
    coord_vertical = (celda-1)/dimension;
    
    // Columna
    coord_horizontal = (celda-1)%dimension;
}

void Floyd::mostrar_siguiente_vertice_en_coordenadas(int nuevo_origen){

    int coord_vertical_siguiente = 0, coord_horizontal_siguiente = 0;
    convertir_celdas_a_coordenadas(nuevo_origen,8,coord_vertical_siguiente,coord_horizontal_siguiente);
    cout << " -> [" << coord_vertical_siguiente << "," << coord_horizontal_siguiente << "]";

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
    
    crear_matriz_de_costos(matriz_de_adyacencia);

    crear_matriz_de_caminos();

    // Algoritmo de Floyd

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
}
