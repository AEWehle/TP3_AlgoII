#ifndef ARBOL_TEMPLATE
#define ARBOL_TEMPLATE

#include "NodoB3.h"

//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0


template <typename Dato, typename Clave>
class ArbolB3 {

//atributos
    private:
        
        NodoB3<Dato,Clave>* nodo_raiz;


//metodos
    public:
        // Constructor sin parámetros
        // PRE: -
        // POS: crea un arbol 3 vias vacio y con nodo raiz apuntando a nullptr.
        ArbolB3(  );


        // Constructor con parámetros
        // PRE: -
        // POS: construye un nodo raiz de arbol B 3 vias
        ArbolB3( Dato* dato, Clave clave );


        // PRE: la clave no se puede repetir
        // POS: Inresa el dato en su ubicacion segun la clave
        // Esta es la funcion que utilizará el usuario
        void agregar_dato( Dato* dato, Clave clave);


        // PRE: la clave no se puede repetir
        // POS: Inresa el dato en su ubicacion segun la clave
        // Esta otra forma de la funcion es para aplicar recursividad
        void agregar_dato( NodoB3<Dato,Clave>* nodo_actual, Dato* dato, Clave clave);


        /* Es para imprimir en terminal el arbol como arbol y no para mostrar
        los datos en sí*/
        void mostrar_arbolb3();

        // Me llaman para imprimir en recursion todo el arbol
        // Imprimo el arbol, no los datos
        void mostrar_arbolb3( NodoB3<Dato,Clave>* nodo_actual, int generacion );
};


// Constructor sin parametros
template <typename Dato, typename Clave>
ArbolB3<Dato, Clave>                     :: ArbolB3( ){
    this -> nodo_raiz = nullptr;
}


// Constructor con parametros
template <typename Dato, typename Clave>
ArbolB3<Dato, Clave>                     :: ArbolB3( Dato* dato, Clave clave){
    this -> nodo_raiz = new NodoB3<Dato, Clave> ( dato , clave );
}


// Ingresar dato segun clave, llamo a recursion
template <typename Dato, typename Clave>
void ArbolB3<Dato, Clave>               :: agregar_dato( Dato* dato, Clave clave){
    agregar_dato( nodo_raiz , dato , clave );
    return;    
    }    


// Ingresar dato segun clave
template <typename Dato, typename Clave>
void ArbolB3<Dato, Clave>               :: agregar_dato( NodoB3<Dato,Clave>* nodo_actual, Dato* dato, Clave clave){
    
    if ( nodo_actual == nullptr) {
        nodo_actual = new NodoB3<Dato, Clave> ( dato , clave );
    }
    else{
        if( nodo_actual->es_hoja() ){
            NodoB3<Dato,Clave>* nodo_aux = nodo_actual->agregar_elemento( dato, clave );
            if (nodo_aux != nullptr){
                this -> nodo_raiz = nodo_aux;
            }
            return;
        }
        else{
            return agregar_dato( nodo_actual -> obtener_hijo( nodo_actual -> clave_menor_entra_mayor( clave ) + 1 ), dato, clave );
        }
    }    
}


template <typename Dato, typename Clave>
void ArbolB3<Dato, Clave>               :: mostrar_arbolb3(){
    cout << "nodo raiz" << endl;
    this-> nodo_raiz -> mostrar_nodob3() ;
    if ( nodo_raiz->es_hoja() ){
        cout << "es hoja"<< endl << endl;
        return;
    }
    cout << endl;
    // nodo_raiz -> obtener_hijo(2);
    mostrar_arbolb3( nodo_raiz -> obtener_hijo(1), 1 ) ;
    mostrar_arbolb3( nodo_raiz -> obtener_hijo(2), 1 ) ;
    if ( nodo_raiz-> esta_completo() ) {
        mostrar_arbolb3(nodo_raiz -> obtener_hijo(3), 1);
    }
    return;
}


template <typename Dato, typename Clave>
void ArbolB3<Dato, Clave>               :: mostrar_arbolb3( NodoB3<Dato,Clave> * nodo_actual, int generacion){
    cout << "Generacion " << generacion << endl;
    nodo_actual -> mostrar_nodob3() ;
    if ( nodo_actual->es_hoja() ){
        cout << "es hoja generacion " << generacion << endl << endl;
        return;
    }
    cout << endl;
    mostrar_arbolb3( nodo_raiz -> obtener_hijo(1), generacion+1 ) ;
    mostrar_arbolb3( nodo_raiz -> obtener_hijo(2), generacion+1 ) ;
    if ( nodo_raiz-> esta_completo() ) {
        mostrar_arbolb3(nodo_raiz -> obtener_hijo(3), generacion+1);
    }
    return;
}

#endif // ARBOL_TEMPLATE