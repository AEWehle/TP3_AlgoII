#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include "Mapa.h"
#include "Animal.h"
#include <limits>
#include "Archivos_auxiliares/funciones_auxiliares.h"
using namespace std;


Mapa::Mapa(){

    iniciar_matrices();
    usar_terreno_por_defecto();
    generar_animales();

    explicacion();

}


Mapa::Mapa(string ruta){

    iniciar_matrices();
    buscar_mapa(ruta);
    generar_animales();

    explicacion();

}


Mapa::~Mapa(){

    for(int i = 0; i < 8; i++){
        delete [] terreno[i];
        delete [] ocupantes[i];
        delete [] visitados[i];
    }
    delete [] terreno;
    delete [] ocupantes;
    delete [] visitados;
}


template <typename Tipo>
Tipo** Mapa::crear_matriz(){

    Tipo** mapa = new Tipo*[8];
    for(int i = 0; i < 8; i++)
        mapa[i] = new Tipo[8];

    return mapa;

}


void Mapa::iniciar_matrices(){

    terreno = crear_matriz<char>();
    ocupantes = crear_matriz<char>();
    visitados = crear_matriz<bool>();
    matriz_de_costos_por_destino = crear_matriz<int>();

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            terreno[i][j] = ' ';
            ocupantes[i][j] = ' ';
            visitados[i][j] = false;
        }
    }
}

int Mapa::obtener_costo_de_viaje(char destino){
    int costo = 0;
    
    switch (destino){
    case 'C':
        costo = 1;
        break;
    case 'T':
        costo = 2;
        break;
    case 'M':
        costo = 5;
        break;
    case 'P':
        costo = 40;
        break;
    }

    return costo;
}


void Mapa::usar_terreno_por_defecto(){ //Se puede cargar de alguna forma más bonita?

    cout << "Generando terreno..." << endl;
    //Cargo los precipicios
    terreno[0][1] = 'P';
    terreno[1][4] = 'P';
    terreno[1][5] = 'P';
    terreno[1][6] = 'P';
    terreno[1][7] = 'P';
    terreno[6][1] = 'P';
    terreno[6][2] = 'P';
    terreno[6][3] = 'P';

    //Cargo las montañas
    terreno[4][0] = 'M';
    terreno[4][1] = 'M';
    terreno[4][2] = 'M';
    terreno[2][6] = 'M';
    terreno[3][6] = 'M';
    terreno[4][6] = 'M';
    terreno[5][6] = 'M';
    terreno[6][6] = 'M';
    terreno[2][7] = 'M';
    terreno[3][7] = 'M';
    terreno[4][7] = 'M';
    terreno[5][7] = 'M';
    terreno[6][7] = 'M';

    //Cargo los caminos
    terreno[0][0] = 'C';
    terreno[1][0] = 'C';
    terreno[2][0] = 'C';
    terreno[2][1] = 'C';
    terreno[2][2] = 'C';
    terreno[2][3] = 'C';
    terreno[2][4] = 'C';
    terreno[3][4] = 'C';
    terreno[4][4] = 'C';
    terreno[5][4] = 'C';
    terreno[6][4] = 'C';
    terreno[7][4] = 'C';
    terreno[7][5] = 'C';
    terreno[7][6] = 'C';
    terreno[7][7] = 'C';

    //Cargo las tierras
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(terreno[i][j] == ' ')
                terreno[i][j] = 'T';
        }
    }
    /*
    terreno[0][2] = 'T';
    terreno[0][3] = 'T';
    terreno[0][4] = 'T';
    terreno[0][5] = 'T';
    terreno[0][6] = 'T';
    terreno[0][7] = 'T';
    terreno[1][1] = 'T';
    terreno[1][2] = 'T';
    terreno[1][3] = 'T';
    terreno[2][5] = 'T';
    terreno[3][5] = 'T';
    terreno[4][5] = 'T';
    terreno[5][5] = 'T';
    terreno[6][5] = 'T';
    terreno[3][0] = 'T';
    terreno[3][1] = 'T';
    terreno[3][2] = 'T';
    terreno[3][3] = 'T';
    terreno[4][3] = 'T';
    terreno[5][3] = 'T';
    terreno[5][2] = 'T';
    terreno[5][1] = 'T';
    terreno[5][0] = 'T';
    terreno[6][0] = 'T';
    terreno[7][0] = 'T';
    terreno[7][1] = 'T';
    terreno[7][2] = 'T';
    terreno[7][3] = 'T';
    */

   for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            matriz_de_costos_por_destino[i][j] = obtener_costo_de_viaje(terreno[i][j]);
        }
    }

}


void Mapa::generar_animales(){

    int creados = 0;
    int i;
    int j;

    coord_auto_num = 0;
    coord_auto_letra = 0;
    ocupantes[coord_auto_num][coord_auto_letra] = 'A'; //Cargo el auto primero

    while(creados < 5){

        srand((unsigned int)time(nullptr)); //Probar dejando solo un srand
        i = rand() % 8;
        srand((unsigned int)time(nullptr));
        j = rand() % 8;
        if(ocupantes[i][j] == ' '){
            srand((unsigned int)time(nullptr));
            ocupantes[i][j] = ESPECIE_CHAR[rand() % 7];  //Especie random de las programadas
            creados++;
        }

    }

}


void Mapa::buscar_mapa(string ruta_terreno){

    fstream archivo_terreno(ruta_terreno, ios::in);

    if(!archivo_terreno.is_open()){
        cout << "No se encontro un archivo con nombre \"" << ruta_terreno << "\", se usará el terreno por defecto." << endl << endl;
        usar_terreno_por_defecto();
    }

    else{

        cout << "Generando terreno..." << endl;

        string lectura;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 7; j++){
                getline(archivo_terreno, lectura, ',');
                terreno[i][j] = lectura[0];
            }
            getline(archivo_terreno, lectura);  //Después del 8vo no hay ',' sino un '\n'
            terreno[i][7] = lectura[0];
        }

        archivo_terreno.close();

    }

}


void Mapa::mostrar(){    

    cout << BORDE << "    a  b  c  d  e  f  g  h    " << RESET << endl;
    
    for(int i = 0; i < 8; i++){
        cout << BORDE << " " << i+1 << " " << RESET;
        for (int j = 0; j < 8; j++){
            imprimir_casilla(i, j);
        }
        cout << BORDE << " " << i+1 << " " << RESET << endl;
    }

    cout << BORDE << "    a  b  c  d  e  f  g  h    " << RESET << endl << endl;

    cout << "*Si no puede visualizar el mapa pruebe en otra terminal*" << endl;

}


void Mapa::imprimir_casilla(int i, int j){

    char ocupante = ocupantes[i][j];

    switch (terreno[i][j]){

            case 'C':
                cout << CAMINO;
                break;
            case 'T':
                cout << TIERRA;
                break;
            case 'M':
                cout << MONTANA;
                break;
            case 'P':
                cout << PRECIPICIO;
                break;

        }
    
    if(visitados[i][j]){ //Ya pasé por acá
        if(ocupante == ' ')
            cout << "***" << RESET;
        else
            cout << "*" << ocupante << "*" << RESET;
    }

    else{ //Si no visité la casilla
        cout << " " << BOLD << ocupante << " " << RESET;
    }

}


void Mapa::explicacion(){

    cout << endl << "Cada tipo de terreno consume distinta cantidad de combustible:" << endl
        << CAMINO << "   " << RESET << " - El CAMINO consume 1 de combustible" << endl
        << TIERRA << "   " << RESET << " - La TIERRA consume 2 de combustible" << endl
        << MONTANA << "   " << RESET << " - La MONTANA consume 5 de combustible" << endl
        << PRECIPICIO << "   " << RESET << " - El PRECIPICIO consume 40 de combustible" << endl << endl;

    cout << "En este mapa la \"A\" representa la ubicación de auto, tu ubicación. El resto de casillas marcadas están ocupadas por animales. Las especies son:" << endl
        << "P: Perro" << endl
        << "G: Gato" << endl
        << "C: Caballo" << endl
        << "R: Roedor" << endl
        << "O: Conejo" << endl
        << "E: Erizo" << endl
        << "L: Lagartija" << endl << endl;

    cout << "Para rescatar un animal ingresá sus coordenadas, pero recordá que si el combustible no es suficiente no podrá ser rescatado!" << endl;

}


bool Mapa::ejecutar(int combustible, int &combustible_gastado, char &especie_rescatada){

    mostrar();

    int coord_num, coord_letra;
    bool coord_ok = false, cancelar = false;

    while(!coord_ok){

        pedir_coordenadas(coord_num, coord_letra, cancelar);

        if(cancelar){
            cout << "Rescate finalizado!" << endl;
            return false;  //Cancelar rescate
        }

        especie_rescatada = verificar_coordenadas(coord_num, coord_letra, coord_ok);

    }

    //Chequear con camino mínimo
    int coord_x_origen = 0;
    int coord_y_origen = 0;
    int coord_x_destino = coord_num;
    int coord_y_destino = coord_letra;

    Grafo* grafo = new Grafo();

    grafo->mapa_a_grafo(8,matriz_de_costos_por_destino);

    grafo->aplicar_algoritmo_camino_minimo();

    grafo->obtener_camino_minimo_por_coordenadas(coord_x_origen,coord_y_origen,coord_x_destino,coord_y_destino);

    ocupantes[coord_auto_num][coord_auto_letra] = ' ';
    coord_auto_num = coord_num;
    coord_auto_letra = coord_letra;
    ocupantes[coord_auto_num][coord_auto_letra] = 'A';

    //Marcar el camino recorrido

    combustible_gastado = 0; //Editar combustible

    return true;

}


void Mapa::pedir_coordenadas(int &coord_num, int &coord_letra, bool &cancelar){

    cout << "Ingrese el número de la coordenada, o 0 para cancelar el rescate:" << endl << " >> " ;
    string coord_num_string;
    cin >> coord_num_string;

    if(es_numero(coord_num_string)){
        coord_num = stoi(coord_num_string);
    }

    while( !es_numero(coord_num_string) || !(coord_num >= 0 && coord_num <= 8)){
        cout << "La coordenada no es válida! Puebe de nuevo:" << endl << " >> " ;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> coord_num_string;
        if(es_numero(coord_num_string))
            coord_num = stoi(coord_num_string);
    }
/*
    while(coord_num < 0 || coord_num > 8){
        cout << "La coordenada no es válida! Puebe de nuevo:" << endl << " >> " ;
        cout << " >> " ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> coord_num;
    }*/

    if(coord_num == 0){
        cancelar = true;
        return;
    }

    coord_num--;

    char coord_letra_char;

    cout << "Ingrese la letra de la coordenada:" << endl << " >> ";
    cin >> coord_letra_char;

    while((int)coord_letra_char < 97 || (int)coord_letra_char > 104){     //Entre 'a' y 'h'
        cout << "La coordenada no es válida! Puebe de nuevo:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> coord_letra_char;
    }

    coord_letra = (int)coord_letra_char - (int)'a';


    return;

}


char Mapa::verificar_coordenadas(int &coord_num, int &coord_letra, bool &coord_ok){

    char ocupante = ocupantes[coord_num][coord_letra];

    if(ocupante == 'A')
        cout << "Esta es tu ubicación!" << endl;

    else if(ocupante == ' ')
        cout << "No hay ningún animal ahí!" << endl;

    else{
        coord_ok = true;
    }

    return ocupante;

}
