#ifndef _FUNCIONESAUXILIARES_H_
#define _FUNCIONESAUXILIARES_H_

#include <string>

using namespace std; 


/*__________________________FuncnionesAuxioliares.h____________________________
    En este.h estan declaradas funciones auxiliares necesarias para el funcion-
amiento general del programa, no son especificas para el TP, se pueden usar en
 cualquier otro respetando las especificaciones.
_______________________________________________________________________________*/


/*________char_a_mayuscula()___________________________________________________
 PRE: Char no tiene tildes
 POST: Devuelve la misma (char) pero en mayucula.
_______________________________________________________________________________*/
char char_a_mayuscula(char letra);


/*________string_a_mayuscula()_________________________________________________
 PRE: String no tiene caracteres con tildes
 POST: Devuelve el mismo (string) pero en mayucula.
_______________________________________________________________________________*/
string string_a_mayuscula(string texto);


/**________es_csv()___________________________________________________
 PRE: Recive un texto (string)
 POST: true si el nombre del archivo tiene un .csv al final
_______________________________________________________________________________*/
bool es_csv( string nombre_archivo );



/*________elimina_espacios()___________________________________________________
 PRE: Recive un texto (string)
 POST: Devuelve el mismo (string) pero sin los isspace().
_______________________________________________________________________________*/
string elimina_espacios(string texto);


/*________string_a_entero()____________________________________________________
 PRE: String no es nulo
 POST: Devuelve la conversión de string ingresado a entero. 
_______________________________________________________________________________*/
int string_a_entero(string texto);


/*________buscar_en_array_de_string()__________________________________________
PRE: largo coincide con longitud de array.
POST: Devuelve la posicion correspondiente en el array.
      Si no lo encuentra devuelve el largo del array.
_______________________________________________________________________________*/
int buscar_en_array_de_string( const string* array, string buscado, int largo );


/*________shiftear_a_derecha()_________________________________________________
PRE:  largo coincide con longitud del array
POST: Shifteo circular a derecha de elementos de string, el utimo queda primero
_______________________________________________________________________________*/
void shiftear_a_derecha( int * array, int largo);


/*________menor_alfabetico()___________________________________________________
PRE:  strings ingresados no tienen caracteres con tilde
POST: Devuelve el string que esta primeor alfabeticamente
_______________________________________________________________________________*/
string menor_alfabetico( string texto1, string texto2);


/*________liberar_matriz()_____________________________________________________
PRE:  Recibe matriz que tenga datos en heap y la cantidad de filas
POST: libera la memeoria
_______________________________________________________________________________*/
void liberar_matriz(int** matriz , int cantidad_filas);


/*________llenar_con_int()_____________________________________________________
PRE:  largo coincide con longitud de array_int
POST: Llena el array ingresado con el entero deseado
_______________________________________________________________________________*/
void llenar_con_int ( int* array_int, int entero, int largo );


/*________es_numero()___________________________________________________________
PRE: -
POST: Verifica si todos los caracteres de string son numericos, devuelve true
      Caso contrario devuelve false.
_______________________________________________________________________________*/
bool es_numero(string st);

#endif