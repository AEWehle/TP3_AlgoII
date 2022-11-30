#ifndef _ROEDOR_H_
#define _ROEDOR_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Roedor: public Animal{
    
public:

    /*________constructor Roedor default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Roedor, establece comida = "queso", es_domestico = true
    _______________________________________________________________________________*/
    Roedor();

    /*________constructor Roedor con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Roedor con parámetros, establece comida = "queso", 
           es_domestico = true
    _______________________________________________________________________________*/
    Roedor( string nombre, int edad, string tamano, string personalidad );

    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un ROEDOR y muestra sus datos
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
    bool ensuciar()    override;

    /*________resolver_especie()_____________________________________________________
     PRE: - 
     POST: Devuelve Especie R
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye roedor
    _______________________________________________________________________________*/
    ~Roedor();
};


#endif