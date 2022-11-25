#ifndef LISTA_TEMPLATE
#define LISTA_TEMPLATE

#include "nodo.h"
#include <iostream>

//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0


template <typename Dato>
class Lista {

//atributos
    private:
        
        Nodo<Dato>* primero;
        
        int cantidad;
        
        Nodo<Dato>* actual;


//metodos
    public:
        // Constructor
        // PRE: -
        // POS: construye una Lista vacia
        Lista();

        // Devuelve un puntero al primer nodo ( el nodo que se agregó primero )
        Nodo<Dato>* obtener_primero();

        // PRE: 0 < POS <= cantidad + 1
        // POS: Agrega d en la posicion POS (la primera es la 1)
        void alta(Dato* dato, int POS);


        // PRE: Se usa si se desea agregar al final
        // POS: Agrega dato al final
        void alta(Dato* dato);


        // PRE: 0 < POS <= cantidad
        // POS: devuelve el dato que esta en la posicion POS (empieza en 1)
        Dato* consulta(int POS);

        // PRE: 
        // POS: devuelve el dato que se agregó recien
        Dato* consulta();

        // PRE: 0 < POS <= cantidad
        // POS: da de baja el nodo que esta en la posicion POS (empieza en 1)
        void baja(int POS);

        /* elimina el nodo de la lista pero LO DEVUELVE SIN DELETE!!!
        */
        Nodo<Dato>* extraer(int POS);


        // PRE: 0 < POS <= cantidad
        //      Guardarse el puntero del dato previamente.
        // POS: da de baja el dato que esta en la posicion POS,
        //haciendo delete de los datos (empieza en 1).
        void baja_con_delete(int POS);


        // PRE:
        // POS: da de baja todos los datos de la lista, haciendo delete de ellos.
        void destruir_con_delete();


        // PRE: -
        // POS: True si la Lista esta vacia, False si no
        bool vacia();

        // Devuelve la cantidad elementos
        int obtener_cantidad();

        // Destructor
        ~Lista();

        // Agregado Lista con cursores
        // POS: True si hay algún dato más en la lista, False si
        //      la lista es vacía o si llegué al final de la lista
        bool hay_siguiente();

        // PRE: hay_siguiente() es True
        // POS: devuelve el dato y mueve el cursor al siguiente
        Dato* siguiente();

        // POS: pone el cursor al principio
        void iniciar();


        /* Pre: La lista entrante debe tener el mismo Tipo de Dato
           Post: Appendea al final de la lista this la lista ingresante
                la lista this queda ->> this lista  +   lista_entrante*/
        void agregar_lista( Lista<Dato>* lista_entrante );


        /*Devuelve true si el datoe stá dentro de la lista*/
        bool dato_existente( Dato* dato_buscado );


        //PRE: -
        //POST: Devuelve la posición en la lista del dato, o -1 si no se encuentra
        int obtener_posicion(Dato* dato);


    private:
        // PRE: 0 < POS <= cantidad
        // POS: devuelve un ptr al nodo que esta en POS
        Nodo<Dato>* obtener_nodo(int POS);
};

// Constructor sin parametros
template <typename Dato>
Lista<Dato>::Lista() {

    this -> primero = nullptr;
    this -> cantidad = 0;
    this -> actual = primero;

}

//Destructor
template <typename Dato>
Lista<Dato>::~Lista() {

    while (! vacia()){
        baja(1);
    }
}


template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_primero(){
    return this -> primero;
}



template <typename Dato>
void Lista<Dato>::alta(Dato* dato, int POS) {
    
    Nodo<Dato>* nuevo = new Nodo<Dato>(dato);
   
    Nodo<Dato>* siguiente = primero;

    if (POS == 1){
        this -> primero = nuevo;
    }else {
        Nodo<Dato>* anterior = obtener_nodo(POS - 1);
        siguiente = anterior -> obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    this -> cantidad++;

}


template <typename Dato>
void Lista<Dato>::alta(Dato* dato) {

    this -> alta( dato, cantidad); //+1
}



template <typename Dato>
Dato* Lista<Dato>::consulta(int POS) {

    Nodo<Dato>* nodo = obtener_nodo(POS);
    return (nodo->obtener_dato());
}


template <typename Dato>
Dato* Lista<Dato>::consulta() {

    Nodo<Dato>* nodo = obtener_nodo( this -> cantidad );
    return (nodo->obtener_dato());
}


template <typename Dato>
bool Lista<Dato>::dato_existente(Dato* dato_buscado) {
    if( vacia() ){
        return false;
    }
    Nodo<Dato>* nodo_actual = this->primero;
    while (( *nodo_actual -> obtener_dato() != *dato_buscado ) ){
        nodo_actual = nodo_actual -> obtener_siguiente();
        if ( nodo_actual == nullptr ){
            return false;
        }
    } 
    return true;
}



template <typename Dato>
void Lista<Dato>::baja(int POS) {

    Nodo<Dato>* a_borrar = this->primero;
    if (POS == 1) {
        this->primero = a_borrar->obtener_siguiente();
    } else {
        Nodo<Dato>* anterior = obtener_nodo(POS - 1);
        a_borrar             = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(a_borrar->obtener_siguiente());
    }

    delete a_borrar;
    this -> cantidad--;
}




template <typename Dato>
void Lista<Dato>::baja_con_delete(int POS) {

    Nodo<Dato>* a_borrar = this -> primero;
    if (POS == 1)
        this -> primero = a_borrar->obtener_siguiente();
    else {
        Nodo<Dato>* anterior = obtener_nodo(POS - 1);
        a_borrar = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(a_borrar->obtener_siguiente());
    }

    delete a_borrar->obtener_dato();
    delete a_borrar;
    this -> cantidad--;

}


template <typename Dato>
void Lista<Dato>:: destruir_con_delete() {
    while (! vacia()){
        baja_con_delete(1);
    }
}





template <typename Dato>
bool Lista<Dato>::vacia() {

    return (this -> cantidad == 0);

}

template <typename Dato>
int Lista<Dato>::obtener_cantidad() {

    return this -> cantidad;

}

template <typename Dato>
Nodo<Dato>* Lista<Dato>::obtener_nodo(int POS) {

    Nodo<Dato>* auxiliar = this -> primero;
    for(int i = 1; i < POS; i++)
        auxiliar = auxiliar->obtener_siguiente();
    return auxiliar;

}

template <typename Dato>
bool Lista<Dato>::hay_siguiente() {

    return (this -> actual != nullptr);

}

template <typename Dato>
Dato* Lista<Dato>::siguiente() {

    Dato* dato = this -> actual->obtener_dato();
    this -> actual = this -> actual->obtener_siguiente();
    return dato;

}

template <typename Dato>
void Lista<Dato>::iniciar() {

    this -> actual = this -> primero;

}


template <typename Dato>
void Lista<Dato> :: agregar_lista( Lista<Dato>* lista_entrante ) {
    Nodo<Dato>* mas_reciente = this -> primero;
    for(int i = 1; i <= cantidad ; i++){
        mas_reciente = mas_reciente -> obtener_siguiente();}
    mas_reciente -> cambiar_siguiente( lista_entrante -> obtener_primero());
}


template <typename Dato>
int Lista<Dato> :: obtener_posicion(Dato* dato){

    int posicion = 1;
    Nodo<Dato>* auxiliar = this -> primero;

    while( auxiliar -> obtener_dato() != dato && posicion <= obtener_cantidad()){

        auxiliar = auxiliar -> obtener_siguiente();
        posicion++;

        if( posicion == obtener_cantidad())
            posicion = 0;

    }

    return posicion;

}


#endif // LISTA_TEMPLATE