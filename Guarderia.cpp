#include <ostream>
#include <string>
#include <iostream> 
#include "Guarderia.h"
#include "Auto.h"
#include "Archivos_auxiliares/funciones_auxiliares.h"
#include "Archivos_auxiliares/Quicksort.h"
using namespace std; 


// NO HACE DELETE DE LOS ANIMALES, POR SI SE DESEAN SEGUIR USANDO

Guarderia::Guarderia(){
    this -> diccionario_de_animales = new ArbolB3<Animal,string>();
    this->escapados = 0;
}


Guarderia::~Guarderia(){
    delete diccionario_de_animales;
}


void Guarderia::agregar_animal( Animal* nuevo_animal ){
    
    diccionario_de_animales -> agregar_dato( nuevo_animal, nuevo_animal->obtener_nombre() );

}


void Guarderia::afectar_animales(){
    Lista<string>* claves = diccionario_de_animales -> obtener_lista_de_claves();
    
    for(int i = 1; i <= claves -> obtener_cantidad(); i++) {
        cout << *claves -> consulta(i) << endl;
    this -> obtener_animal( *claves -> consulta(i) ) -> ensuciar();
    this -> obtener_animal( *claves -> consulta(i) ) -> dar_hambre();

        if((this -> obtener_animal(*claves -> consulta(i))->obtener_hambre()==100) || (this -> obtener_animal(*claves -> consulta(i))->obtener_higiene()==0)){
            
            //this->eliminar_animal(*claves->consulta(i));
            ++this->escapados;
        }

        if (escapados == 3) {
            cout << "Se escaparon 3 animales... Tenemos que clausurar la guarderia." << endl;
            return;
        }

    }
    
}


void Guarderia::eliminar_animal( string nombre ){

    diccionario_de_animales -> baja( nombre );

}


int Guarderia::obtener_cantidad(){

    return diccionario_de_animales -> obtener_cantidad();

}


Animal* Guarderia::obtener_animal ( string nombre ){

    return diccionario_de_animales -> consulta( nombre );

}


Auto* Guarderia::obtener_auto(){
    return &automovil;
}


void Guarderia::ver_diccionario_de_animales(  ){

    if( this -> diccionario_de_animales -> obtener_cantidad()){

        cout << "Hay " << diccionario_de_animales -> obtener_cantidad() << " animales en la reserva." << endl;
        Lista <string>*  nombres = diccionario_de_animales -> obtener_lista_de_claves();

        for( int numero_animal = 1 ; numero_animal <= nombres -> obtener_cantidad(); numero_animal++){
           
           diccionario_de_animales -> consulta( *nombres -> consulta( numero_animal ) ) -> mostrar();
        }
    } 
    else
        cout << "No hay animales en la lista" << endl;
}


void Guarderia::ver_los_animales( Lista <string>* nombres ){

    if( this -> diccionario_de_animales -> obtener_cantidad()){

        cout << "Se muestran " << nombres -> obtener_cantidad() << " animales." << endl;
        for( int numero_animal = 1 ; numero_animal <= nombres -> obtener_cantidad(); numero_animal++){
           diccionario_de_animales -> consulta( *(nombres -> consulta( numero_animal ) ) ) -> mostrar();
        }
    } 

    else
        cout << "No hay animales en la lista" << endl;

}



Lista<string>* Guarderia :: obtener_lista_viejo_a_joven(){
    // crear array de animales
    // ordenar el array con quicksort
    // crear la lista con los nombres
    
    Lista<string>* nombres = obtener_lista_nombres();
    Animal** lista_animales = new Animal*[ obtener_cantidad() ];
    for (  int numero_animal = 1 ; numero_animal <= obtener_cantidad() ; numero_animal++ ){
        lista_animales[ numero_animal-1 ] = diccionario_de_animales -> consulta( *nombres -> consulta ( numero_animal ) ) ;
    }
    Quicksort<Animal*> quicksort( lista_animales , obtener_cantidad(), es_primer_animal_mayor);
    quicksort.ordenar();
    // nombres = new Lista<string>();
    
    nombres -> destruir_con_delete();
    for ( int numero_animal = 0 ; numero_animal < obtener_cantidad() ; numero_animal++ ) {
        string* nombre = new string (lista_animales[ numero_animal ] -> obtener_nombre() );
        nombres -> alta( nombre );
    }
    delete [] lista_animales;
    return nombres;
}



Lista<string>* Guarderia:: obtener_lista_nombres(){
    return diccionario_de_animales -> obtener_lista_de_claves();
}

int Guarderia::obtener_escapados(){
    return escapados;
}