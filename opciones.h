#ifndef OPCIONES_H
#define OPCIONES_H
#include "Guarderia.h"
#include "funciones_main.h"
using namespace std; 


/*________listar_animales()______________________________________________________
 PRE:  La guardería mi_guarderia fue creada.
 POST: Imprime por la terminal la lista de animales contenidos en mi_guarderia.
_______________________________________________________________________________*/
void listar_animales( Guarderia* mi_guarderia );


/*________rescatar_animal()______________________________________________________
 PRE:  La guardería mi_guarderia fue creada correctamente
 POST: Pide los datos del animal a cargary guarda el animal rescatado en la lista.
_______________________________________________________________________________*/
void rescatar_animal( Guarderia* mi_guarderia );


/*________buscar_animal()______________________________________________________
 PRE:  La guardería mi_guarderia fue creada correctamente
 POST: Si hay animales en la guarderia, le pregunta al usuario el nombre del 
      animal, si lo encunetra lo muestra, sino se lo notifica.
_______________________________________________________________________________*/
void buscar_animal( Guarderia* mi_guarderia );
 

 /*________cuidar_animal()______________________________________________________
 PRE: La guardería mi_guarderia fue creada correctamente
 POST: Muestra menú con opciones para cuidar al animal y le pide al usuario que
      elija uno.
_______________________________________________________________________________*/
void cuidar_animales( Guarderia* mi_guarderia );
 

 /*________adoptar_animal()______________________________________________________
 PRE:  La guardería mi_guarderia fue creada correctamente
 POST: Le pregunta al usuario qué tamaño dispone y le muestra un lista con los 
      animales disponibles. Puede cancelar o adoptar ingresando el nombre. Si no 
      hay animales en la guarderia, informa por terminal
_______________________________________________________________________________*/
void adoptar_animal( Guarderia* mi_guarderia );


 /*________cargar_combustible()______________________________________________________
 PRE:  -
 POST: 
_______________________________________________________________________________*/
void cargar_combustible(Guarderia* mi_guarderia);


/*________guardar_salir()______________________________________________________
 PRE:  La guardería mi_guarderia fue creada correctamente
 POST: Guarda en el archivo llamado RUTA_ARCHIVO la informacion en la base de
       datos y libera la memoria.
_______________________________________________________________________________*/
void guardar_salir( Guarderia* mi_guarderia );


typedef void (*Manejo_Guarderia) (Guarderia* mi_guarderia );

const Manejo_Guarderia funcion_elegida[ CANTIDAD_OPCIONES ] = {
    listar_animales, 
    rescatar_animal,
    buscar_animal,
    cuidar_animales,
    adoptar_animal,
    cargar_combustible,
    guardar_salir,
};


#endif