#ifndef _GATO_H_
#define _GATO_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Gato: public Animal{
    
public:

    /*________constructor Gato default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Gato, establece comida = "queso", es_domestico = true
    _______________________________________________________________________________*/
    Gato();

    /*________constructor Gato con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Gato con parámetros, establece comida = "atun", 
           es_domestico = true
    _______________________________________________________________________________*/
    Gato( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un GATO y muestra sus datos
    _______________________________________________________________________________*/
    void mostrar() override;

    /*________duchar()______________________________________________________________
     PRE: - 
     POST: Imprime en pantalla mensaje que esta clase no requiere ducharse
    _______________________________________________________________________________*/
    void duchar() override;

    /*________ensuciar()_____________________________________________________________
     PRE: - 
     POST: Reestablece la higiene a 100 sin decrementarla
    _______________________________________________________________________________*/
    bool ensuciar() override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie G
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye gato
    _______________________________________________________________________________*/
    ~Gato();
};


#endif