#include <iostream> 
#include <string>
#include <fstream> 
#include "Archivos_auxiliares/ArbolB3.h"
using namespace std; 

// g++ prueba.cpp -o TP3 -Wall -Werror -Wconversion


/*
int main(){
    string* dato1 = new string( "dato1" );
    string clave1 = "clave1";
    string* dato2 = new string( "dato2" );
    string clave2 = "clave2";
    string* dato3 = new string( "dato3" ); 
    string clave3 = "clave3";
    string* dato4 = new string( "dato4" );
    string clave4 = "clave4";
    string* dato5 = new string( "dato5" );
    string clave5 = "clave5";
    string* dato6 = new string( "dato6" );
    string clave6 = "clave6";
    // int* dato7 = new int( 7 );
    // int clave7 = 7;
    // int* dato8 =  new int(-1 );
    // int clave8 = -1;


//     // Lista<int>* enteros = new Lista <int>();
//     // enteros -> alta(&clave1);
//     // enteros -> alta(&clave2);
//     // for ( int i = 1 ; i<= enteros -> obtener_cantidad() ; i++ ){
//     // cout<< "Lista" << *(enteros -> consulta(i))<< endl;}

    // int* dato9 =  new int(0 );
    // int clave9 = 0;
    ArbolB3<string,string>* diccionario = new ArbolB3<string,string>();
    diccionario -> agregar_dato(dato1, clave1);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato2, clave2);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato3, clave3);
    diccionario -> mostrar_arbolb3();
    diccionario -> cambiar_dato( dato3, clave1 );
    diccionario -> agregar_dato(dato4, clave4);
    diccionario -> mostrar_arbolb3();
    diccionario -> agregar_dato(dato5, clave5);
    diccionario -> mostrar_arbolb3();
    diccionario -> baja( clave4 );
    diccionario -> agregar_dato(dato6, clave6);
    diccionario -> mostrar_arbolb3();
    // diccionario -> agregar_dato(dato7, clave7);
    // diccionario -> agregar_dato(dato9, clave9);
    // diccionario -> agregar_dato(dato8, clave8);
    // cout << "todo agregado" << endl;

//     diccionario -> baja( clave5 );

//     string aux = "";

//         cout << "ingrese clave a buscar"<< endl<< " >> ";
//         cin >> aux;
//     while( !(aux == "s")){

//         string * dato = ( diccionario -> consulta( aux ) );
//         if (dato!=nullptr){
//             cout << *dato << endl;
//         }
//         cout << "ingrese dato a buscar, o 's' para salir"<< endl<< " >> ";
//         cin >> aux;
//     }


    Lista<string>* datos = diccionario -> ordenar_mayor_menor();
    for ( int i = 1 ; i <= datos -> obtener_cantidad() ; i++){
        cout << *(datos -> consulta(i)) << ", ";
    }
    datos -> destruir_con_delete();
    delete datos;
    return 0;
}
*/
