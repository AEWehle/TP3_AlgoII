#ifndef _AUTO_H
#define _AUTO_H
#include <string>
#include <iostream>
using namespace std; 

const int MAX_COMBUSTIBLE = 100;

class Auto{


    //Atributos
    private: 
        int combustible;
    

    public:
        //Constructor
        //PRE: -
        //POS: Crea auto con combustible = 100
        Auto();

        //Destructor
        //PRE: -
        //POS: Destruye Auto crado
        ~Auto();

        //obtener_combustible()
        //PRE: -
        //POS: Devuelve valor de atributo combustible
        int obtener_combustible();

        //cargar_combustible()
        //PRE: -
        //POS: Suma 5 a combustible. Si se tiene maximo combustible no lo modifica
        void cargar_combustible();

        //cargar_combustible(int cantidad)
        //PRE: cantidad valor entre 0 y MAX_COMBUSTIBLE
        //POS: Suma cantidad a combustible. Si se tiene maximo combustible no lo modifica
        void cargar_combustible(int cantidad);

        //decrementar_combustible(int cantidad)
        //PRE: cantidad valor entre 0 y MAX_COMBUSTIBLE
        //POS: Resta cantidad a combustible. Si llega a combustible < 0 lo deja en 0
        void decrementar_combustible(int cantidad);
        
};

#endif