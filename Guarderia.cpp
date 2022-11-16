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
    
    lista_de_animales.alta( nuevo_animal, lista_de_animales.obtener_cantidad() + 1 );

}


int Guarderia::obtener_posicion( string nombre ){

    int cantidad_de_animales = lista_de_animales.obtener_cantidad();
    int posicion = 1;

    while( (posicion <= cantidad_de_animales) &&  ( string_a_mayuscula( lista_de_animales.consulta( posicion  )->obtener_nombre() ) != string_a_mayuscula( nombre ) )){
        posicion++;
    }
   
    return posicion;

}


int Guarderia::obtener_cantidad(){

    return lista_de_animales.obtener_cantidad();

}


void Guarderia::eliminar_animal(int posicion){

    lista_de_animales.baja(posicion);

}


Animal* Guarderia::obtener_animal(int posicion){

    return lista_de_animales.consulta(posicion);

}


void Guarderia::ver_lista_de_animales(){

    if(lista_de_animales.obtener_cantidad()){

        cout << "Hay " << lista_de_animales.obtener_cantidad() << " animales en la reserva." << endl;
        for( int i = 1 ; i < (lista_de_animales.obtener_cantidad()+1) ; i++){
            lista_de_animales.consulta(i)->mostrar();
        }
        
    }
    
    else
        cout << "No hay animales en la lista" << endl;

}


Auto Guarderia::obtener_auto(){
    return automovil;
}