#include <iostream> 
#include <string>
#include <fstream> 
#include "Archivos_auxiliares/ArbolB3.h" 
using namespace std; 

// g++ prueba.cpp -o TP3 -Wall -Werror -Wconversion


int main(){
    int dato1 = 1;
    int clave1 = 1;
    int dato2 = 2;
    int clave2 = 2;
    int dato3 = 3; 
    int clave3 = 3;
    int dato4 = 4;
    int clave4 = 4;
    int dato5 = 5;
    int clave5 = 5;
    ArbolB3<int,int> diccionario( &dato1, clave1)  ;
    //diccionario.mostrar_arbolb3();
    //cout << "Agrego 2" <<endl;
    diccionario.agregar_dato(&dato2, clave2);
    //diccionario.mostrar_arbolb3();
    //cout << "Agrego 3" <<endl;
    diccionario.agregar_dato(&dato3, clave3);
    //diccionario.mostrar_arbolb3();
    //cout << "Agrego 4 " <<endl;
    diccionario.agregar_dato(&dato4, clave4);
    // cout  << "Sali de agregar dato" << endl;
    //diccionario.mostrar_arbolb3();
    //cout << "Agrego 5" <<endl;
    diccionario.agregar_dato(&dato5, clave5);
    //diccionario.mostrar_arbolb3();

    int dato6 = 6;
    int clave6 = 6;
    //cout << "Agrego 6" <<endl;
    diccionario.agregar_dato(&dato6, clave6);
    //diccionario.mostrar_arbolb3();

    int dato7 = 7;
    int clave7 = 7;
    //cout << "Agrego 7" <<endl;
    diccionario.agregar_dato(&dato7, clave7);
    //diccionario.mostrar_arbolb3();
    int dato8 = -1;
    int clave8 = -1;
    //cout << "Agrego -1" <<endl;
    diccionario.agregar_dato(&dato8, clave8);
    //diccionario.mostrar_arbolb3();
    int dato9 = 0;
    int clave9 = 0;
    //cout << "Agrego 0" <<endl;
    diccionario.agregar_dato(&dato9, clave9);
    diccionario.mostrar_arbolb3();


    Lista<int>* datos = diccionario.ordenar_mayor_menor();
    for ( int i = 1 ; i <= diccionario.obtener_cantidad() ; i++){
        cout << *datos -> consulta(i) << ", " ;
    }
    delete datos;
    return 0;
}
