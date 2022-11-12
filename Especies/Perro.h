#ifndef _PERRO_H_
#define _PERRO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Perro: public Animal{

public:

    /*________constructor Perro default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Perro, establece comida = "huesos", es_domestico = true
    _______________________________________________________________________________*/
    Perro();

    /*________constructor Perro con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Perro con parámetros, establece comida = "huesos", 
           es_domestico = true
    _______________________________________________________________________________*/
    Perro( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un PERRO y muestra sus datos
    _______________________________________________________________________________*/
    void mostrar() override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie P
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye perro
    _______________________________________________________________________________*/
    ~Perro();
};


#endif