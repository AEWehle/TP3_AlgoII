#include <iostream>  
#include <string> 
#include <fstream>
#include <limits>
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "funciones_main.h" 
#include "Guarderia.h"
using namespace std;  


Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad ){ 
    Animal* nuevo_animal; 
    if(especie == 'P')
        nuevo_animal = new Perro( nombre, edad, tamano, personalidad );
    else if(especie == 'G')
        nuevo_animal = new Gato( nombre, edad, tamano, personalidad );
    else if(especie == 'C')
        nuevo_animal = new Caballo( nombre, edad, tamano, personalidad );
    else if(especie == 'R')
        nuevo_animal = new Roedor( nombre, edad, tamano, personalidad );
    else if(especie == 'O')
        nuevo_animal = new Conejo( nombre, edad, tamano, personalidad );
    else if(especie == 'E')
        nuevo_animal = new Erizo( nombre, edad, tamano, personalidad );
    else//(especie == 'L')
        nuevo_animal = new Lagartija( nombre, edad, tamano, personalidad );

    return nuevo_animal; 

} 
 



bool eleccion_valida(int eleccion, int cantidad_opciones){

    return ( (1 <= eleccion) && (eleccion <= cantidad_opciones)); 

}


int pedir_eleccion(int cantidad_opciones){ 

    cout << "      Ingrese el numero de la opcion elegida: " << endl << " >> ";
    string eleccion_string;
    int eleccion;

    cin >> eleccion_string;

    if(es_numero(eleccion_string)){
        eleccion = stoi(eleccion_string);
    }

    while( !es_numero(eleccion_string) || !(eleccion >= 1 && eleccion <= cantidad_opciones)){
        cout << "      Ingresá una opción válida:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> eleccion_string;
        if(es_numero(eleccion_string))
            eleccion = stoi(eleccion_string);
    }
    cout << endl;

    return eleccion;

}

string ingresar_nombre(){ 

    string nombre ; 

    while ( nombre.length() == 0 ){
        getline( cin, nombre, '\n' ); 
    } 

    return nombre; 
}

string pedir_nombre( Guarderia* mi_guarderia ){
    string nombre = ingresar_nombre();
    bool nombre_invalido = true;
    while( nombre_invalido ) {
        if( es_cancelar(nombre) ){
            cout << "      Este nombre no puede ser usado, deberías elegir otro:" << endl << " >> ";
            nombre = ingresar_nombre();
        }
        else if( mi_guarderia -> nombre_existente( nombre ) ){
            cout << "      Este nombre ya lo tiene otro animal en la reserva, elegí otro" << endl << " >> ";
            nombre = ingresar_nombre();
        }
        else{
            nombre_invalido = false;
        }
    }
    return nombre;
}

bool es_cancelar(string nombre){
    return (string_a_mayuscula(nombre) == CANCELAR);
}



bool validar_edad(string edad_st, int &edad){

    bool edad_valida = es_numero(edad_st);

    if(edad_valida){
        edad = stoi(edad_st);
        edad_valida = (edad >= 0 && edad <= EDAD_MAX);
    }

    return edad_valida;

}

bool tamano_ok(Animal* animal, float espacio){ //espacio es mayor a 0

    int tamano_animal = buscar_en_array_de_string( TAMANOS_STRING, animal->obtener_tamano(), CANTIDAD_TAMANOS );
    bool ok = false;

    int tamano_disponible = (int) (espacio >= 2)  + (int) (espacio >= 10) + (int) (espacio >= 20) + (int) (espacio >= 50);
    if( tamano_animal <= tamano_disponible ){
        ok = true;
    }
    return ok;
}