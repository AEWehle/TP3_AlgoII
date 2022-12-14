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

    inicializar_matriz_de_costos_por_destino();
    lista_coordenadas_recorridas = new Lista<Coordenada>();

    explicacion();

}


Mapa::Mapa(string ruta){

    iniciar_matrices();

    buscar_mapa(ruta);
    generar_animales();

    inicializar_matriz_de_costos_por_destino();
    lista_coordenadas_recorridas = new Lista<Coordenada>();

    explicacion();

}


Mapa::~Mapa(){

    for(int i = 0; i < 8; i++){

        delete[] terreno[i];
        delete[] ocupantes[i];
        delete[] visitados[i];
        delete[] matriz_de_costos_por_destino[i];
    }
    delete[] terreno;
    delete[] ocupantes;
    delete[] visitados;
    delete[] matriz_de_costos_por_destino;

    delete lista_coordenadas_recorridas;
    lista_coordenadas_recorridas=nullptr;
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


void Mapa::usar_terreno_por_defecto(){ //Mapa default hardcodeado

    cout << "      Generando terreno..." << endl;

    //Cargo los precipicios
    terreno[0][1] = 'P';
    terreno[1][4] = 'P';
    terreno[1][5] = 'P';
    terreno[1][6] = 'P';
    terreno[1][7] = 'P';
    terreno[6][1] = 'P';
    terreno[6][2] = 'P';
    terreno[6][3] = 'P';

    //Cargo las monta??as
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

    //Cargo las tierras (el resto de casillas)
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if(terreno[i][j] == ' ')
                terreno[i][j] = 'T';
        }
    }

}


void Mapa::inicializar_matriz_de_costos_por_destino(){

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            matriz_de_costos_por_destino[i][j] = obtener_costo_de_viaje(terreno[i][j]);
        }
    }

}


void Mapa::generar_animales(){

    int creados = 0;
    int i,j;

    coord_auto_letra = 0;
    coord_auto_num = 0;

    ocupantes[coord_auto_num][coord_auto_letra] = 'A'; //Cargo el auto primero

    while(creados < 5){

        srand((unsigned int)time(nullptr));
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

    fstream archivo_terreno("mis_mapas/"+ruta_terreno+".csv", ios::in);

    if(!archivo_terreno.is_open()){
        cout << "      No se encontro un mapa con nombre \"" << ruta_terreno << "\", se usar?? el terreno por defecto" << endl;
        cout << "      Para cargar nuevos mapas solo tenes que cargar el archivo con el nombre deseado en formato 'csv' a la carpeta 'mis_mapas'." << endl << endl;
        usar_terreno_por_defecto();
    }

    else{

        cout << "      Generando terreno..." << endl;

        string lectura;

        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 7; j++){
                getline(archivo_terreno, lectura, ',');
                terreno[i][j] = lectura[0];
            }
            getline(archivo_terreno, lectura);  //Despu??s del 8vo no hay ',' sino un '\n'
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

    cout << "     *Si no puede visualizar el mapa pruebe en otra terminal*" << endl;

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
    
    if(visitados[i][j]){ //Ya pas?? por ac??
        if(ocupante == ' ')
            cout << "***" << RESET;
        else
            cout << "*" << ocupante << "*" << RESET;
    }

    else{ //Si no visit?? la casilla
        cout << " " << BOLD << ocupante << " " << RESET;
    }

}


void Mapa::explicacion(){

    cout << endl << "      Cada tipo de terreno consume distinta cantidad de combustible:" << endl
        << CAMINO << "   " << RESET << "    - El CAMINO consume 1 de combustible" << endl
        << TIERRA << "   " << RESET << "    - La TIERRA consume 2 de combustible" << endl
        << MONTANA << "   " << RESET << "    - La MONTANA consume 5 de combustible" << endl
        << PRECIPICIO << "   " << RESET << "    - El PRECIPICIO consume 40 de combustible" << endl << endl;

    cout << "     En este mapa tu ubicaci??n es la \"A\", y el resto de casillas ocupadas tienen animales:" << endl
        << "     P - Perro" << endl
        << "     G - Gato" << endl
        << "     C - Caballo" << endl
        << "     R - Roedor" << endl
        << "     O - Conejo" << endl
        << "     E - Erizo" << endl
        << "     L - Lagartija" << endl << endl
        << "     El camino recorrido en los rescates se marcar?? con ***." << endl
        << "     Para rescatar un animal ingres?? sus coordenadas, pero record?? que si el combustible no es suficiente no podr?? ser rescatado!" << endl;

}


void Mapa::limpiar_visitados(){

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            visitados[i][j] = false;
        }
    }
    
}


bool Mapa::ejecutar(int combustible, int &combustible_gastado, char &especie_rescatada, bool &combustible_suficiente){

    mostrar();

    cout << endl << "     En este momento hay " << combustible << " de combustible" << endl << endl;

    int coord_num, coord_letra;
    bool coord_ok = false, cancelar = false;

    while(!coord_ok && !cancelar){

        pedir_coordenadas(coord_num, coord_letra, cancelar);

        if(!cancelar)
            especie_rescatada = verificar_coordenadas(coord_num, coord_letra, coord_ok);

    }

    if(!cancelar){

        limpiar_visitados();

        Grafo* grafo = new Grafo();
        grafo->mapa_a_grafo(8,matriz_de_costos_por_destino);

        Coordenada* coordenada_auto = new Coordenada(coord_auto_num,coord_auto_letra);
        Coordenada* coordenada_rescate = new Coordenada(coord_num,coord_letra);
        
        grafo->obtener_camino_minimo_por_coordenadas(coordenada_auto,coordenada_rescate,lista_coordenadas_recorridas,combustible_gastado,8);

        delete coordenada_auto;
        delete coordenada_rescate;

        if(combustible_gastado <= combustible){

            ocupantes[coord_auto_num][coord_auto_letra] = ' ';
            coord_auto_num = coord_num;
            coord_auto_letra = coord_letra;
            ocupantes[coord_auto_num][coord_auto_letra] = 'A';

            for(int i=1; i<=lista_coordenadas_recorridas->obtener_cantidad(); i++){
                Coordenada* coordenada = lista_coordenadas_recorridas->consulta(i);

                visitados[coordenada->obtener_fila()][coordenada->obtener_columna()] = true;
            }

        }

        else{

            cout << "      No hay suficiente combustible para el rescate!" << endl
                << "      Este rescate tiene un costo de " << combustible_gastado << ", pero solo hay " << combustible << " de combustible!" << endl << endl;
            combustible_suficiente = false;

        }

        lista_coordenadas_recorridas->destruir_con_delete();
        delete grafo;

        return true;

    }

    else
        return false;
    
}


void Mapa::pedir_coordenadas(int &coord_num, int &coord_letra, bool &cancelar){

    cout << "      Ingrese el n??mero de la coordenada, o 0 para cancelar el rescate:" << endl << " >> ";
    
    string coord_num_string;
    
    cin >> coord_num_string;

    if(es_numero(coord_num_string)){
        coord_num = stoi(coord_num_string);
    }

    while( !es_numero(coord_num_string) || !(coord_num >= 0 && coord_num <= 8)){
        cout << "      La coordenada no es v??lida! Puebe de nuevo:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> coord_num_string;
        if(es_numero(coord_num_string))
            coord_num = stoi(coord_num_string);
    }

    if(coord_num == 0){
        cancelar = true;
        return;
    }

    coord_num--;
    string coord_letra_string;
    char coord_letra_char;

    cout << "      Ingrese la letra de la coordenada:" << endl << " >> ";
    cin >> coord_letra_string;
    coord_letra_char = coord_letra_string[0];

    while((int)coord_letra_char < 97 || (int)coord_letra_char > 104){     //Entre 'a' y 'h'
        cout << "      La coordenada no es v??lida! Puebe de nuevo:" << endl << " >> ";
        cin >> coord_letra_string;
        coord_letra_char = coord_letra_string[0];
    }

    coord_letra = (int)coord_letra_char - (int)'a';

    return;

}


char Mapa::verificar_coordenadas(int &coord_num, int &coord_letra, bool &coord_ok){

    char ocupante = ocupantes[coord_num][coord_letra];

    if(ocupante == 'A')
        cout << "      Esta es tu ubicaci??n!" << endl;

    else if(ocupante == ' ')
        cout << "      No hay ning??n animal ah??!" << endl;

    else{
        cout << "      Se avist?? un animal en esas coordenadas!" << endl;
        coord_ok = true;
    }

    return ocupante;

}
