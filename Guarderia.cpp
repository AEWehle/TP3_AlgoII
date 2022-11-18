#include <string>
#include <iostream> 
#include "Guarderia.h"
#include "Auto.h"
#include "Archivos_auxiliares/funciones_auxiliares.h"
using namespace std; 


Guarderia::Guarderia(){
    //se crea una lista vacía
}


Guarderia::~Guarderia(){
}


void Guarderia::agregar_animal( Animal* nuevo_animal ){
    
    diccionario_de_animales.agregar_dato( nuevo_animal, nuevo_animal->obtener_nombre() );

}


int Guarderia::obtener_posicion( string nombre ){

//    int cantidad_de_animales = diccionario_de_animales.obtener_cantidad();
    int posicion = 1;

//    while( (posicion <= cantidad_de_animales) &&  ( string_a_mayuscula( diccionario_de_animales.consulta( posicion  )->obtener_nombre() ) != string_a_mayuscula( nombre ) )){
//        posicion++;
//    }
   
    return posicion;

}


int Guarderia::obtener_cantidad(){

    return diccionario_de_animales.obtener_cantidad();

}


void Guarderia::eliminar_animal(int posicion){

    // diccionario_de_animales.baja(posicion);

}


Animal* Guarderia::obtener_animal(int posicion){

//    return diccionario_de_animales.consulta(posicion);
    return nullptr;

}


void Guarderia::ver_diccionario_de_animales(){

    if( this -> diccionario_de_animales.obtener_cantidad()){

        cout << "Hay " << diccionario_de_animales.obtener_cantidad() << " animales en la reserva." << endl;
        for( int i = 1 ; i < (diccionario_de_animales.obtener_cantidad()+1) ; i++){
//            diccionario_de_animales.obtener_dato(i)->mostrar();
        }
        
    }
    
    else
        cout << "No hay animales en la lista" << endl;

}


Auto* Guarderia::obtener_auto(){
    return &automovil;
}