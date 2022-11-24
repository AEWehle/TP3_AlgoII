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
    bool funcional; // indica si este dato participa en el arbol

    public:
        // Constructor
        /*  PRE: -
            POS: Crea un Elemento con dato, clave y funcionalidad, con hijo apuntando a Null
            */
        Elemento( Dato* dato, Clave clave, bool funcional);

        // Destructor
        ~Elemento();


        /*  PRE: -
            POS: Le indica al elemento que ya no es funcional en el arbol
            */
        void dar_de_baja( );


        /*  PRE: -
            POS: devuelve true si participa en el arbol
            */
        bool es_funcional( );

        /*  PRE: -
            POS: Devuelve un puntero que apunta a lo mismo que el atributo Dato
            */
        Dato* obtener_dato( );

        /*  PRE: -
            POS: cambia el puntero a dato
            */
        void cambiar_dato(  Dato* dato_nuevo );


        void cambiar_funcional ( bool funcional );

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
Elemento<Dato, Clave> :: Elemento( Dato* dato, Clave clave , bool funcional){
    this -> dato = dato;
    this -> clave = clave;
    this -> hijo = nullptr;
    this -> funcional = funcional;
}


template <typename Dato, typename Clave>
Elemento<Dato, Clave> :: ~Elemento(){
    if ( dato != nullptr){
        delete this -> dato;}
}


template <typename Dato, typename Clave>
void Elemento<Dato, Clave> :: dar_de_baja( ){
    funcional = false;
}


template <typename Dato, typename Clave>
bool Elemento<Dato, Clave> :: es_funcional( ){
    return funcional;
}



// obtener dato
template <typename Dato, typename Clave>
Dato* Elemento<Dato, Clave> :: obtener_dato( ) {
    return dato;
}



// obtener dato
template <typename Dato, typename Clave>
void Elemento<Dato, Clave> :: cambiar_dato( Dato* dato_nuevo) {
    dato = dato_nuevo;
}


template <typename Dato, typename Clave>
void Elemento<Dato, Clave> :: cambiar_funcional( bool funcional ) {
    this -> funcional = funcional;
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
