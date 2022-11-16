#ifndef _AUTO_H
#define _AUTO_H
#include <string>
#include <iostream>
using namespace std; 

const int MAX_COMBUSTIBLE = 100;

class Auto{
    //Atributos
    private:
        unsigned int combustible;
    
    public:

    Auto();

    ~Auto();

    unsigned int obtener_combustible();

    void cargar_combustible();

    void cargar_combustible(unsigned int cantidad);

    void decrementar_combustible(unsigned int cantidad);
};

#endif