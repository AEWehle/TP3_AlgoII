#include <iostream> 
#include <string>
#include <fstream> 
#include "Archivos_auxiliares/ArbolB3.h"
using namespace std; 

// g++ prueba.cpp -o TP3 -Wall -Werror -Wconversion

/*
int main(){
    int* dato1 = new int( 1 );
    int clave1 = 1;
    int* dato2 = new int( 2 );
    int clave2 = 2;
    int* dato3 = new int( 3 ); 
    int clave3 = 3;
    int* dato4 = new int( 4 );
    int clave4 = 4;
    int* dato5 = new int( 5 );
    int clave5 = 5;
    int* dato6 = new int( 6 );
    int clave6 = 6;
    int* dato7 = new int( 7 );
    int clave7 = 7;
    // int* dato8 =  new int(-1 );
    // int clave8 = -1;

    // Lista<int>* enteros = new Lista <int>();
    // enteros -> alta(&clave1);
    // enteros -> alta(&clave2);
    // for ( int i = 1 ; i<= enteros -> obtener_cantidad() ; i++ ){
    // cout<< "Lista" << *(enteros -> consulta(i))<< endl;}

    // int* dato9 =  new int(0 );
    // int clave9 = 0;
    ArbolB3<int,int>* diccionario = new ArbolB3<int,int>();
    diccionario -> agregar_dato(dato1, clave1);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato2, clave2);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato3, clave3);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato4, clave4);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato5, clave5);
    diccionario -> mostrar_arbolb3();
    // diccionario -> baja( clave4 );
    diccionario -> agregar_dato(dato6, clave6);
    diccionario -> mostrar_arbolb3();
    // diccionario -> agregar_dato(dato7, clave7);
    // diccionario -> agregar_dato(dato9, clave9);
    // diccionario -> agregar_dato(dato8, clave8);
    cout << "todo agregado" << endl;

    // diccionario -> baja( clave5 );

    // string aux = "";

    //     cout << "ingrese clave a buscar"<< endl<< " >> ";
    //     cin >> aux;
    // while( !(aux == "s")){

    //     int * dato = ( diccionario -> consulta( stoi(aux) ) );
    //     if (dato!=nullptr){
    //         cout << *dato << endl;
    //     }
    //     cout << "ingrese dato a buscar, o 's' para salir"<< endl<< " >> ";
    //     cin >> aux;
    // }

    Lista<int>* datos = diccionario -> ordenar_mayor_menor();
    for ( int i = 1 ; i <= datos -> obtener_cantidad() ; i++){
        cout << *(datos -> consulta(i)) << ", ";
    }
    datos -> destruir_con_delete();
    delete datos;
    return 0;
}
*/