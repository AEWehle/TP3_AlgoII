#ifndef VERTICE_H
#define VERTICE_H

using namespace std;

class Vertice {
    // Atributos
    private:
        int vertice;

    // Métodos
    public:
        Vertice(int vertice);

        //post: obtiene el nombre del vertice
        int obtener_nombre();

        ~Vertice();
};


#endif //VERTICE_H
