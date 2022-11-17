#include <iostream> 
#include <string>
#include <fstream> 
#include "Archivos_auxiliares/ArbolB3.h" 
using namespace std; 

// g++ prueba.cpp -o TP3 -Wall -Werror -Wconversion


int main(){
    char dato1 = 'a';
    int clave1 = 1;
    char dato2 = 'b';
    int clave2 = 2;
    char dato3 = 'c'; 
    int clave3 = 3;
    char dato4 = 'd';
    int clave4 = 4;
    char dato5 = 'e';
    int clave5 = 5;
    ArbolB3<char,int> diccionario( &dato1, clave1)  ;
    // diccionario.mostrar_arbolb3();
    cout << "Agrego b" <<endl;
    diccionario.agregar_dato(&dato2, clave2);
    // diccionario.mostrar_arbolb3();
    cout << "Agrego c" <<endl;
    diccionario.agregar_dato(&dato3, clave3);
    // diccionario.mostrar_arbolb3();
    cout << "Agrego d " <<endl;
    diccionario.agregar_dato(&dato4, clave4);
    cout  << "Sali de agregar dato" << endl;
    // diccionario.mostrar_arbolb3();
    cout << "Agrego e" <<endl;
    diccionario.agregar_dato(&dato5, clave5);
    // diccionario.mostrar_arbolb3();

    char dato6 = 'f';
    int clave6 = 6;
    cout << "Agrego f" <<endl;
    diccionario.agregar_dato(&dato6, clave6);
    // diccionario.mostrar_arbolb3();

    char dato7 = 'g';
    int clave7 = 7;
    cout << "Agrego g" <<endl;
    diccionario.agregar_dato(&dato7, clave7);
    // diccionario.mostrar_arbolb3();
    char dato8 = 'h';
    int clave8 = -1;
    cout << "Agrego h" <<endl;
    diccionario.agregar_dato(&dato8, clave8);
    // diccionario.mostrar_arbolb3();
    char dato9 = 'i';
    int clave9 = 0;
    cout << "Agrego i" <<endl;
    diccionario.agregar_dato(&dato9, clave9);
    diccionario.mostrar_arbolb3();

    // Lista<char>* datos = diccionario.datos_mayor_menor();
    // for ( int i = 1 ; i <= diccionario.obtener_cantidad() ; i++){
    //     cout << *datos->consulta(i) << ", " ;
    // }
    // delete datos;
    // char dato = 'a';
    // NodoB3<char,int> * nodo_hijo = new NodoB3<char,int> ( &dato, 3 );
    // nodo_hijo -> mostrar_nodob3 ();

    // cout << "agrego b" << endl << endl ;
    // char dato2 = 'b';
    // nodo_hijo -> agregar_elemento ( &dato2, 0 );
    // nodo_hijo -> mostrar_nodob3 ();


    // char dato3 = 'c';
    // cout << "agrego c" << endl << endl ;
    // NodoB3<char,int> * nodo_padre = nodo_hijo -> agregar_elemento ( &dato3, 9 );

    // cout << "Nodo padre" << endl;
    // nodo_padre -> mostrar_nodob3 ();
    // cout << "Nodo hijo menor" << endl;
    // nodo_hijo -> mostrar_nodob3 ();
    // cout << "Nodo hijo mayor" << endl;
    // nodo_padre -> obtener_hijo(1) -> mostrar_nodob3();

    
    // char dato4 = 'c';
    // cout << "agrego c" << endl << endl ;
    // nodo_padre = nodo_padre -> agregar_elemento ( &dato4, 5 );
    
    // cout << "Nodo padre" << endl;
    // nodo_padre -> mostrar_nodob3 ();
    // cout << "Nodo hijo menor" << endl;
    // nodo_hijo -> mostrar_nodob3 ();
    // cout << "Nodo hijo medio" << endl;
    // nodo_padre -> obtener_hijo(2) -> mostrar_nodob3();
    // cout << "Nodo hijo mayor" << endl;
    // nodo_padre -> obtener_hijo(3) -> mostrar_nodob3();
    // delete nodo_padre;
    // delete nodo_hijo;
    return 0;
}
