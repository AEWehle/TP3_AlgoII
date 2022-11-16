#ifndef Elemento_TEMPLATE
#define Elemento_TEMPLATE
#include "NodoB3.h"
using namespace std; 


/*  Esta clase es un elemento de la lista que hay en un Nodo de un arbol
    Contiene un puntero a dato, una clave y un puntero a nodoB3 (3 vias) por
    ahora por simplisidad
    Pero si se desea tener arboles con mas vias se podria crear una clase
    nodo_arbol donde sus hijas sean nodoB3, NodoB4 etc. En ese caso apuntaria
    a la clase nodo_arbol
*/

template <typename Dato, typename Clave>
class Elemento{
        // Atributos
    private:
    Clave clave;
    Dato* dato;
    NodoB3<Dato, Clave>* hijo;

    public:
        // Constructor
        /*  PRE: -
            POS: Crea un Elemento con dato y clave, apuntando a Null
            */
        Elemento( Dato* dato, Clave clave);


        /*  PRE: -
            POS: Devuelve un puntero que apunta a lo mismo que el atributo Dato
            */
        Dato* obtener_dato( );

        /*  PRE: -
            POS: Devuelve la clave
            */
        Clave obtener_clave( );

        /*  PRE: -
            POS: Devuelve un puntero al Nodo hijo izquierdo del arbol
            */
        NodoB3<Dato, Clave>* obtener_hijo( );

        /*  PRE: -
            POS: carga en el puntero a hijo el puntero dado
            */
        void cambiar_hijo( NodoB3<Dato, Clave>* nodo_hijo );

};


// Constructor
template <typename Dato, typename Clave>
Elemento<Dato, Clave> :: Elemento( Dato* dato, Clave clave ){
    this -> dato = dato;
    this -> clave = clave;
    this -> hijo = nullptr;
}

// obtener dato
template <typename Dato, typename Clave>
Dato* Elemento<Dato, Clave> :: obtener_dato( ) {
    return dato;
}

// obtener clave
template <typename Dato, typename Clave>
Clave Elemento<Dato, Clave> :: obtener_clave( ) {
    return clave;
}

template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* Elemento<Dato, Clave> :: obtener_hijo( ) {
    return this-> hijo;
}


template <typename Dato, typename Clave>
void Elemento<Dato, Clave> :: cambiar_hijo( NodoB3<Dato, Clave>* nodo_hijo ) {
    this-> hijo = nodo_hijo;
}

#endif // Elemento_TEMPLATE
