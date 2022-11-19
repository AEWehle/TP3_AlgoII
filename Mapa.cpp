#include <string>
#include <iostream>
#include <time.h>
#include "Mapa.h"
#include "Animal.h"
using namespace std;


Mapa::Mapa(){

    iniciar_matrices();

    usar_terreno_por_defecto();
    generar_animales();

}


Mapa::Mapa(string ruta){

    iniciar_matrices();

    buscar_mapa(ruta);
    generar_animales();

}


Mapa::~Mapa(){

    for(int i = 0; i < 8; i++){
        delete terreno[i];
        delete ocupantes[i];
        delete visitados[i];
    }
    delete terreno;
    delete ocupantes;
    delete visitados;

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

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            terreno[i][j] = ' ';
            ocupantes[i][j] = ' ';
            visitados[i][j] = false;
        }
    }

}


void Mapa::usar_terreno_por_defecto(){ //Se puede cargar de alguna forma más bonita?

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

}


void Mapa::generar_animales(){

    int creados = 0;
    int i;
    int j;

    ocupantes[0][0] = 'A'; //Cargo el auto primero

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


void Mapa::buscar_mapa(string ruta){

    //fstream archivo_terreno(RUTA, ios::in);

    //if(!archivo_terreno.is_open()){
        cout << "No se encontro un archivo con nombre \"" << /*ruta <<*/ "\", se usará el terreno por defecto" << endl << endl;
        usar_terreno_por_defecto();
    //}
/*
    else{

        char lectura;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 7; j++){
                getline(archivo_terreno, lectura, ',');
                terreno[i][j] = lectura;
            }
            getline(archivo_terreno, lectura);  //Después del 8vo no hay ',' sino un '\n'
            terreno[i][7] = lectura;
        }

        archivo_terreno.close();

    }
*/
}


void Mapa::mostrar(){

    //visitados[0][0] = true;
    visitados[1][0] = true;
    visitados[2][0] = true;
    visitados[2][1] = true;
    visitados[2][2] = true;
    visitados[3][2] = true;
    

    cout << BORDE << "    a  b  c  d  e  f  g  h    " << RESET << endl;
    
    for(int i = 0; i < 8; i++){
        cout << BORDE << " " << i << " " << RESET;
        for (int j = 0; j < 8; j++){
            imprimir_casilla(i, j);
        }
        cout << BORDE << " " << i << " " << RESET << endl;
    }

    cout << BORDE << "    a  b  c  d  e  f  g  h    " << RESET << endl << endl;

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