#ifndef _AUTO_H
#define _AUTO_H
#include <string>
#include <iostream>
using namespace std; 

const int MAX_COMBUSTIBLE = 100;

class Auto{
    //Atributos
    protected: //No debería ser privado? -AVH
        int combustible;
    
    public:

        Auto();

        ~Auto();

        int obtener_combustible();

        void cargar_combustible();

        void cargar_combustible(int cantidad);

        void decrementar_combustible(int cantidad);
};

#endif