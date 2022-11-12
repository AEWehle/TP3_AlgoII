#ifndef _ERIZO_H_
#define _ERIZO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Erizo: public Animal{

public:

    /*________constructor Erizo default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Erizo, establece comida = "insectos", es_domestico = false
    _______________________________________________________________________________*/
    Erizo();

    /*________constructor Erizo con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Erizo con parámetros, establece comida = "insectos", 
           es_domestico = false
    _______________________________________________________________________________*/
    Erizo( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un ERIZO y muestra sus datos
    _______________________________________________________________________________*/
    void mostrar() override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie E
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye erizo
    _______________________________________________________________________________*/
    ~Erizo();
};


#endif