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
        << PRECIPICIO << "   " << RESET << " - El PRECIPICIO consume 40 de combustible" << endl << endl
        << "Para rescatar un animal ingresá sus coordenadas, pero recordá que si el combustible no es suficiente no podrá ser rescatado!" << endl;

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

    ocupantes[coord_num][coord_letra] = 'A';

    //Marcar el camino recorrido

    return true;

}


void Mapa::pedir_coordenadas(int &coord_num, int &coord_letra, bool &cancelar){

    cout << "Ingrese el número de la coordenada, o 0 para cancelar el rescate:" << endl << " >> " ;
    cin >> coord_num;

    while(coord_num < 0 || coord_num > 9){
        cout << "La coordenada no es válida! Puebe de nuevo:" << endl << " >> " ;
        cin >> coord_num;
    }

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
        cin >> coord_letra;
    }

    coord_letra = (int)coord_letra_char - (int)'a';

    cout << coord_letra << endl; 

    return;

}


char Mapa::verificar_coordenadas(int &coord_num, int &coord_letra, bool &coord_ok){

    char ocupante = ocupantes[coord_num][coord_letra];

    if(ocupante == 'A')
        cout << "Esta es tu ubicación!" << endl;

    else if(ocupante == ' ')
        cout << "No hay ningún animal ahí!" << endl;

    else{
        cout << "Se avistó un animal en esas coordenadas!" << endl;
        coord_ok = true;
    }

    return ocupante;

}