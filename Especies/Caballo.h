#ifndef _CABALLO_H_
#define _CABALLO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Caballo: public Animal{

public:

    /*________constructor Caballo default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Caballo, establece comida = "manzanas", es_domestico = true
    _______________________________________________________________________________*/
    Caballo();

    /*________constructor Caballo con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Caballo con parámetros, establece comida = "manzanas", 
           es_domestico = true
    _______________________________________________________________________________*/
    Caballo( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un CABALLO y muestra sus datos
    _______________________________________________________________________________*/
    void mostrar() override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie C
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye caballo
    _______________________________________________________________________________*/
    ~Caballo();
};


#endif