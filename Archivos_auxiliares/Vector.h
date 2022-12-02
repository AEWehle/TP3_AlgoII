#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>

template<typename Dato>
class Vector {

    //atributos
private:

    int longitud;
    Dato* elementos;


    //metodos
public:

    //Constructor sin parametros
    //PRE: -
    //POS: crea un objeto Vector vacío con longitud 0
    Vector();

    //Constructor con parametros
    //PRE: cantidad > 0
    //POS: crea un objeto Vector de longitud = cantidad
    Vector(int cantidad);

    //Constructor de copia
    //PRE: -
    //POS:
    Vector(const Vector& v);

    //Destructor
    //POS: libera la memoria pedida
    ~Vector();

    //PRE: 0 <= pos < longitud
    //POS: carga elem en la posicion pos
    void cargar(Dato elem, int pos);

    //PRE: 0 <= pos < longitud
    //POS: devuelve el elemento que esta en la posicion pos
    Dato obtener(int pos);

    // Muestra el vector entero
    void mostrar();

    //devuelve la longitud del vector
    int obtener_longitud();

};


//Constructor sin parametro
template<typename Dato>
Vector<Dato>::Vector() {

    longitud = 0;
    elementos = 0;

}


//Constructor con parametro
template<typename Dato>
Vector<Dato>::Vector(int cantidad) {

    longitud = cantidad;
    elementos = new Dato[longitud];

}


//Constructor de copia
template<typename Dato>
Vector<Dato>::Vector(const Vector& v) {

    longitud = v.longitud;
    elementos = 0;

    if (longitud > 0) {
        elementos = new Dato[longitud];
        for (int i = 0; i < longitud; i++)
            elementos[i] = v.elementos[i];
    }

}


//Destructor
template<typename Dato>
Vector<Dato>::~Vector() {

    if (longitud > 0)
        delete[] elementos;

}


//cargar
template<typename Dato>
void Vector<Dato>::cargar(Dato elem, int pos) {

    elementos[pos] = elem;

}


//obtener
template<typename Dato>
Dato Vector<Dato>::Vector::obtener(int pos) {

    return elementos[pos];

}


//mostrar
template<typename Dato>
void Vector<Dato>::mostrar() {

    for(int i = 0; i < longitud; i++)
        std::cout << elementos[i] << " - ";
    std::cout << std::endl;

}


//obtener longitud
template<typename Dato>
int Vector<Dato>::Vector::obtener_longitud() {

    return longitud;

}


#endif // VECTOR_H_INCLUDED