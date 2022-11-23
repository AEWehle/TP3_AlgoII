#include <string>
#include <iostream> 
#include "Guarderia.h"
#include "Auto.h"
#include "Archivos_auxiliares/funciones_auxiliares.h"
using namespace std; 


// NO HACE DELETE DE LOS ANIMALES, POR SI SE DESEAN SEGUIR USANDO

Guarderia::Guarderia(){
    //se crea una lista vacía
}


Guarderia::~Guarderia(){
}


void Guarderia::agregar_animal( Animal* nuevo_animal ){
    
    diccionario_de_animales.agregar_dato( nuevo_animal, nuevo_animal->obtener_nombre() );

}


void Guarderia::afectar_animales(){
    Lista<string>* claves = diccionario_de_animales.obtener_lista_de_claves();
    for(int i = 1; i <= this -> obtener_cantidad(); i++) {
       this -> obtener_animal( *claves -> consulta(i) ) -> ensuciar();
       this -> obtener_animal( *claves -> consulta(i) ) -> dar_hambre();
    }
}


void Guarderia::eliminar_animal( string nombre ){

    diccionario_de_animales.baja( nombre );

}


int Guarderia::obtener_cantidad(){

    return diccionario_de_animales.obtener_cantidad();

}


Animal* Guarderia::obtener_animal ( string nombre ){

    return diccionario_de_animales.consulta( nombre );

}


Auto* Guarderia::obtener_auto(){
    return &automovil;
}


void Guarderia::ver_diccionario_de_animales(  ){

    if( this -> diccionario_de_animales.obtener_cantidad()){

        cout << "Hay " << diccionario_de_animales.obtener_cantidad() << " animales en la reserva." << endl;
        Lista <Animal>*  ordenados = diccionario_de_animales.ordenar_mayor_menor();

        for( int numero_animal = 1 ; numero_animal <= ordenados -> obtener_cantidad(); numero_animal++){
           ordenados -> consulta( numero_animal ) -> mostrar();
        }
    } 

    else
        cout << "No hay animales en la lista" << endl;

}


void Guarderia::ver_los_animales( Lista <string>* nombres ){

    if( this -> diccionario_de_animales.obtener_cantidad()){

        cout << "Se muestran " << nombres -> obtener_cantidad() << " animales." << endl;
        for( int nombre = 1 ; nombre <= nombres -> obtener_cantidad(); nombre++){
           diccionario_de_animales.consulta( *(nombres -> consulta( nombre ) ) ) -> mostrar();
        }
    } 

    else
        cout << "No hay animales en la lista" << endl;

}
