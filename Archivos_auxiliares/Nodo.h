#ifndef NODO_TEMPLATE
#define NODO_TEMPLATE

//Dato será el ANIMAL que se introduzca en la lista
template <typename Dato>
class Nodo{

    // Atributos
    private:
        Dato* dato;
        Nodo* siguiente;


    public:

        // Constructor
        /*  PRE: -
            POS: Crea un nodo con dato = d y siguiente = 0
            */
        Nodo(Dato* dato);

        /*  PRE: Nodo nuevo_siguiente existe
            POS: Atributo Siguiente apunta a nodo ingresado
            */
        void cambiar_siguiente(Nodo* nuevo_siguiente);

        /*  PRE: -
            POS: Devuelve un puntero que apunta a lo mismo que el atributo Dato
            */
        Dato* obtener_dato();

        /*  PRE: -
            POS: Devuelve un puntero que apunta a lo mismo que el atributo Siguiente
            */
        Nodo* obtener_siguiente();

};


// Constructor
template <typename Dato>
Nodo<Dato>::Nodo(Dato* dato){

    this->dato = dato;
    siguiente = nullptr;

}


// cambiar siguiente
template <typename Dato>
void Nodo<Dato>::cambiar_siguiente(Nodo<Dato>* nuevo_siguiente){

    siguiente = nuevo_siguiente;

}


// obtener siguiente
template <typename Dato>
Nodo<Dato>* Nodo<Dato>::obtener_siguiente(){

    return siguiente;

}


// obtener dato
template <typename Dato>
Dato* Nodo<Dato>::obtener_dato() {

    return dato;

}


#endif // NODO_TEMPLATE