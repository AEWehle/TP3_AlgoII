#ifndef COORDENADA_H
#define COORDENADA_H

#include <iostream>

using namespace std;

class Coordenada {
    // Atributos
    private:
        int coordenada_vertical;
        int coordenada_horizontal;

    // Métodos
    public:
        Coordenada(int coordenada_vertical, int coordenada_horizontal);

        ~Coordenada();
};


#endif //COORDENADA_H