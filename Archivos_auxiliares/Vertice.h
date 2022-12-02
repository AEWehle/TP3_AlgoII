#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>

using namespace std;

class Vertice {

    // Atributos
    private:

        int vertice;


    // Métodos
    public:

        //Constructor
        // PRE: -
        // POS: crea un Vertice con el entero recibido
        Vertice(int vertice);

        // PRE: -
        // POS: devuelve el nombre del vertice
        int obtener_nombre();

        ~Vertice();

};


#endif //VERTICE_H