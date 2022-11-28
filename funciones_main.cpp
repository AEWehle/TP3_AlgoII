#include <iostream>  
#include <string> 
#include <fstream>
#include <limits>
#include "Archivos_auxiliares/funciones_auxiliares.h" 
#include "Archivos_auxiliares/nodo.h" 
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
 

void cargar_guarderia(Guarderia* mi_guarderia){

    fstream archivo_guarderia(RUTA_ARCHIVO, ios::in);

    if(!archivo_guarderia.is_open()){
        cout << "No se encontro un archivo con nombre \"" << RUTA_ARCHIVO << "\", se va a crear el archivo" << endl << endl;
        archivo_guarderia.open(RUTA_ARCHIVO, ios::out);     //Si no existe el archivo lo creo
        archivo_guarderia.close();
        archivo_guarderia.open(RUTA_ARCHIVO, ios::in);
    }

    string nombre, edad, tamano, especie, personalidad;

    while(getline(archivo_guarderia, nombre, ',')){    //Cuando ya no encuentra un nombre se terminó el archivo

        getline(archivo_guarderia, edad, ',');
        getline(archivo_guarderia, tamano, ',');
        getline(archivo_guarderia, especie, ',');
        getline(archivo_guarderia, personalidad);    //El último lo leo hasta encontrar un \n, no una coma.

        Animal* nuevo_animal = crear_nuevo_animal(especie[0], nombre, stoi(edad), tamano, personalidad);

        mi_guarderia -> agregar_animal(nuevo_animal);
    }

    archivo_guarderia.close();

}


/*________imprimir_menu()______________________________________________________ 
 PRE: 
 POST: Imprime en temrinal todas las opciones que pude elegir el usuario. 
_______________________________________________________________________________*/ 
void imprimir_menu(int cantidad_elecciones){ 

    if(cantidad_elecciones == 7){ //Menú principal
        cout << endl << "*****   MENU   *****" << endl << endl;
        cout << "   1. Listar animales." << endl; 
        cout << "   2. Rescatar un animal." << endl; 
        cout << "   3. Buscar un animal." << endl;
        cout << "   4. Cuidar animales." << endl;
        cout << "   5. Adoptar un animal." << endl;
        cout << "   6. Cargar Combustible." << endl;
        cout << "   7. Guardar y salir." << endl << endl;

    }else if (cantidad_elecciones == 2) { //Menú de cuidar animales
        cout << endl << "*****   CUIDAR ANIMALES: MENU   *****" << endl << endl;
        cout << "   1. Elegir Individualmente." << endl; 
        cout << "   2. Regresar al Menu Principal." << endl << endl;
    }

}


bool eleccion_valida(int eleccion, int cantidad_opciones){

    return ( (1 <= eleccion) && (eleccion <= cantidad_opciones)); 

}


int pedir_eleccion(int cantidad_opciones){ 

    cout << "Ingrese el numero de la opcion elegida: " << endl << " >> ";
    string eleccion_string;
    int eleccion;

    cin >> eleccion_string;

    if(es_numero(eleccion_string)){
        eleccion = stoi(eleccion_string);
    }

    while( !es_numero(eleccion_string) || !(eleccion >= 1 && eleccion <= cantidad_opciones)){
        cout << "Ingresá una opción válida:" << endl << " >> ";
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

    string nombre; 

    while ( nombre.length() == 0 ){ 
        cout << " >> " ;
        getline( cin, nombre, '\n' ); 
    } 

    return nombre; 
}

string pedir_nombre( Guarderia* mi_guarderia ){
    string nombre = ingresar_nombre();
    bool nombre_invalido = true;
    while( nombre_invalido ) {
        if( es_cancelar(nombre) ){
            cout << "Este nombre no puede ser usado, deberías elegir otro:" << endl;
            nombre = ingresar_nombre();
        }
        else if( mi_guarderia -> nombre_existente( nombre ) ){
            cout << "Este nombre ya lo tiene otro animal en la reserva, elegí otro" << endl;
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


//void ejecutar_eleccion(Guarderia* mi_guarderia, int eleccion){ 

//    funcion_elegida[ eleccion - 1 ]( mi_guarderia );

//}

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