#ifndef _LAGARTIJA_H_
#define _LAGARTIJA_H_

#include <string>
#include "../Animal.h"
using namespace std; 


class Lagartija: public Animal{

public:
    
    /*________constructor Lagartija default___________________________________________
     PRE: - 
     POST: Crea un animal tipo Lagartija, establece comida = "insectos", es_domestico = false
    _______________________________________________________________________________*/
    Lagartija();

    /*________constructor Lagartija con parámetros______________________________________
     PRE: Parametros se ingresaron correctamente 
     POST: Crea un animal tipo Lagartija con parámetros, establece comida = "insectos", 
           es_domestico = false
    _______________________________________________________________________________*/
    Lagartija( string nombre, int edad, string tamano, string personalidad );
    
    /*________mostrar()_____________________________________________________________
     PRE: - 
     POST: Imprime en pantalla que se trata de un LAGARTIJA y muestra sus datos
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
     POST: Devuelve Especie R
    _______________________________________________________________________________*/
    Especie resolver_especie() override;

    /*________Destructor_____________________________________________________________
     PRE: - 
     POST: Destruye lagartija
    _______________________________________________________________________________*/
    ~Lagartija();
};


#endif