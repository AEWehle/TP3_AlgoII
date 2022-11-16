#include <iostream> 
#include <string>
#include <fstream> 
#include "Archivos_auxiliares/ArbolB3.h" 
using namespace std; 

// g++ prueba.cpp -o TP3 -Wall -Werror -Wconversion


int main(){
    char dato1 = 'a';
    int clave1 = 78;
    char dato2 = 'b';
    int clave2 = 79;
    char dato3 = 'c';
    int clave3 = 85;
    char dato4 = 'd';
    int clave4 = 86;
    char dato5 = 'e';
    int clave5 = 76;
    ArbolB3<char,int> diccionario( &dato1, clave1)  ;
    diccionario.mostrar_arbolb3();
    cout << "Agrego b" <<endl;
    diccionario.agregar_dato(&dato2, clave2);
    diccionario.mostrar_arbolb3();
    cout << "Agrego c" <<endl;
    diccionario.agregar_dato(&dato3, clave3);
    diccionario.mostrar_arbolb3();
    cout << "Agrego d " <<endl;
    diccionario.agregar_dato(&dato4, clave4);
    diccionario.mostrar_arbolb3();
    cout << "Agrego e" <<endl;
    diccionario.agregar_dato(&dato5, clave5);
    diccionario.mostrar_arbolb3();

    char dato6 = 'f';
    int clave6 = 10;
    cout << "Agrego f" <<endl;
    diccionario.agregar_dato(&dato6, clave6);
    diccionario.mostrar_arbolb3();
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
