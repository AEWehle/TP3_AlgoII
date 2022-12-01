#ifndef FUNCIONES_MAIN_H_ 
#define FUNCIONES_MAIN_H_ 
#include <string> 
#include "Archivos_auxiliares/Nodo.h" 
#include "Guarderia.h"
using namespace std;  
 
/* ________________________funciones_main.h_____________________________________ 
_______________________________________________________________________________*/ 


//const string RUTA_ARCHIVO = "animales.csv"; 
const string CANCELAR = "CANCELAR";


/*________crear_nuevo_animal()__________________________________________________ 
 PRE:  Datos para crear el animal son correctos
 POST: Crea un animal y devuelve un puntero al animal creado. 
_______________________________________________________________________________*/ 
Animal* crear_nuevo_animal( char especie, string nombre, int edad, string tamano, string personalidad );


/*________pedir_eleccion()_____________________________________________________ 
 PRE:  Recibe cantidad_opciones que es 4 o 6 según el menú que se esté
      ejecutando.
 POST: Pide al usuario opcion a ejecutar y devuelve la elección. Si no se ingresó
       una opcion correcta, la pide nuevamente.
_______________________________________________________________________________*/ 
int  pedir_eleccion(int cantidad_opciones); 


string ingresar_nombre();


string pedir_nombre(  Guarderia* mi_Guarderia );


bool es_cancelar(string nombre);


bool validar_edad(string edad_st, int &edad);


bool tamano_ok(Animal* animal, float espacio);


#endif