#ifndef _CONEJO_H_
#define _CONEJO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Conejo: public Animal{

public:

    /*________constructor Conejo default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Conejo, establece comida = "lechuga", es_domestico = true
    _______________________________________________________________________________*/
    Conejo();

    /*________constructor Conejo con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Conejo con parámetros, establece comida = "lechuga", 
           es_domestico = true
    _______________________________________________________________________________*/
    Conejo( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un CONEJO y muestra sus datos
    _______________________________________________________________________________*/
    void mostrar() override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie O
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye conejo
    _______________________________________________________________________________*/
    ~Conejo();
};


#endif