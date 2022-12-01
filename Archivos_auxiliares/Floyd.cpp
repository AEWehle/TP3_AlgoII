#include "Floyd.h"
#include <iostream>
#include "funciones_auxiliares.h"
#include "Algoritmo_camino_min.h"
const int INFINITO = 99999;

// Constructor
Floyd::Floyd(Lista<Vertice>* lista_vertices, int** matriz_de_adyacencia):AlgoritmoCaminoMinimo(lista_vertices,matriz_de_adyacencia){

    matriz_de_caminos = nullptr;
    matriz_de_costos = nullptr;

    aplicar_floyd();
    
}

// Destructor
Floyd::~Floyd(){

    liberar_matriz(matriz_de_costos , cantidad_vertices_en_algoritmo);
    liberar_matriz(matriz_de_caminos, cantidad_vertices_en_algoritmo);

    matriz_de_costos = nullptr;
    matriz_de_caminos = nullptr;

}

void Floyd::obtener_camino_minimo(int origen, int destino, Lista<Coordenada>* lista_coordenadas_recorridas, int& costo, int dimension){

    // En caso de querer imprimir el camino descomentar *1* *2* y *3*

    if(matriz_de_caminos[origen-1][destino-1] == 0){

        cout << "No existe un camino entre " << origen << " y " << destino << endl;
    
    }
    
    else if(origen == destino){

        cout << "El destino del camino coincide con su origen." << endl;
    
    }
    
    else{

        costo = matriz_de_costos[origen-1][destino-1];
        
        // *1*
        // cout << "El camino mínimo entre los puntos elegidos";
        // cout << " tiene un costo de $" << costo << " y es: ";

        Coordenada* coordenada_origen = new Coordenada();
        coordenada_origen->convertir_celda_a_coordenadas(origen,dimension);
        lista_coordenadas_recorridas->alta(coordenada_origen,lista_coordenadas_recorridas->obtener_cantidad()+1);
        
        // *2*
        // cout << "[" << coordenada_origen->obtener_fila() << "," << coordenada_origen->obtener_columna() << "]";
        
        while(origen != destino){

            origen = hallar_siguiente_vertice_en_el_camino(origen,destino);

            Coordenada* nueva_coordenada_origen = new Coordenada();
            nueva_coordenada_origen->convertir_celda_a_coordenadas(origen,dimension);
            lista_coordenadas_recorridas->alta(nueva_coordenada_origen,lista_coordenadas_recorridas->obtener_cantidad()+1);

            // *3* 
            // cout << " -> [" << nueva_coordenada_origen->obtener_fila() << "," << nueva_coordenada_origen->obtener_columna() << "]";
        }

    }

    cout << endl;
}

int Floyd::hallar_siguiente_vertice_en_el_camino(int origen, int destino){

    return matriz_de_caminos[origen-1][destino-1];

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
