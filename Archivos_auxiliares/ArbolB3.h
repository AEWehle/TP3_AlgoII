#ifndef ARBOL_TEMPLATE
#define ARBOL_TEMPLATE

#include "NodoB3.h"

//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0


template <typename Dato, typename Clave>
class ArbolB3 {

//atributos
    private:
        
        NodoB3<Dato,Clave>* nodo_raiz;
        int cantidad;

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


        // Destructor
        ~ArbolB3(  );


        // PRE: la clave no se puede repetir
        // POS: Inresa el dato en su ubicacion segun la clave
        // Esta es la funcion que utilizará el usuario
        void agregar_dato( Dato* dato, Clave clave);


        // PRE: 
        // POS: devuelve el puntero al dato segun la clave
        Dato* consulta( Clave clave );


        // Elimina todos los nodos
        // void baja_a_partir_de( NodoB3<Dato,Clave>* nodo_actual , int numero_de_hijo );
        int obtener_cantidad();


        NodoB3<Dato,Clave>* obtener_nodo_mas_derecha();
        NodoB3<Dato,Clave>* obtener_nodo_mas_derecha_a_partir( NodoB3<Dato,Clave>* nodo_actual );
        NodoB3<Dato,Clave>* obtener_nodo_mas_izquierda();


        /* PRE: -
           POS: Devuelve una lista con los datos ordenado de mayor a menor
         segun su clave*/
        Lista<Dato>* ordenar_mayor_menor();


        /* Es para imprimir en terminal el arbol como arbol y no para mostrar
        los datos en sí*/
        void mostrar_arbolb3();


        private:
        
        // PRE: la clave no se puede repetir
        // POS: Inresa el dato en su ubicacion segun la clave
        // Esta otra forma de la funcion es para aplicar recursividad
        void agregar_dato( NodoB3<Dato,Clave>* nodo_actual, Dato* dato, Clave clave);


        // PRE: 
        // POS: devuelve el puntero al dato segun la clave, buscando desde nodo actual
        Dato* consulta( NodoB3<Dato,Clave> * nodo_actual , Clave clave );


        // Me llaman para imprimir en recursion todo el arbol
        // Imprimo el arbol, no los datos
        void mostrar_arbolb3( NodoB3<Dato,Clave>* nodo_actual, int generacion );

};




// Constructor sin parametros
template <typename Dato, typename Clave>
ArbolB3<Dato, Clave>                     :: ArbolB3( ){
    this -> nodo_raiz = nullptr;
    cantidad = 0;
}


// Constructor con parametros
template <typename Dato, typename Clave>
ArbolB3<Dato, Clave>                     :: ArbolB3( Dato* dato, Clave clave){
    this -> nodo_raiz = new NodoB3<Dato, Clave> ( dato , clave );
    cantidad = 1;
}


// Destructor
template <typename Dato, typename Clave>
ArbolB3<Dato, Clave>                     :: ~ArbolB3( ){
        delete nodo_raiz;
        nodo_raiz = nullptr;
        cantidad = 0;
}



template <typename Dato, typename Clave>
int ArbolB3<Dato, Clave>               :: obtener_cantidad(){
    return this -> cantidad;
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
    
    this -> cantidad++;
    if ( nodo_actual == nullptr) {
        nodo_actual = new NodoB3<Dato, Clave> ( dato , clave );
    }
    else{
        if( nodo_actual -> es_hoja() ){
            NodoB3<Dato,Clave>* nodo_padre = nodo_actual -> agregar_elemento( dato, clave );
            if ( nodo_padre != nullptr ){ // Me fijo si tengo que cambiar el nodo raiz
                nodo_actual = nodo_padre;
                while ( nodo_actual -> tiene_padre() ){
                    nodo_actual = nodo_actual -> obtener_nodo_padre();
                }
                this -> nodo_raiz = nodo_actual;
            }
            return;
        }
        else{// Si no es hoja tengo que buscar a que nodo hijo le correpsonde la clave
            return agregar_dato( nodo_actual -> obtener_hijo( nodo_actual -> clave_menor_entra_mayor( clave ) + 1 ), dato, clave );
        }
    }
}


// Obtener Dato segun clave
template <typename Dato, typename Clave>
Dato* ArbolB3<Dato, Clave>              :: consulta( Clave clave ){
    if ( cantidad == 0 ) {
        cout << "La base de datos esta vacía" << endl;
        return nullptr;
    }
    
    Dato * dato = consulta( this -> nodo_raiz , clave );
    
    if ( dato == nullptr ){ //el dato no se encuentra en el arbol
        cout << "Clave inexistente" << endl;
    }
    return dato;
}


// consulta desde un nodo con la clave
template <typename Dato, typename Clave>
Dato* ArbolB3<Dato, Clave>              :: consulta( NodoB3<Dato,Clave>* nodo_actual , Clave clave ){
    int clave_men_igu_o_may = nodo_actual -> clave_menor_entra_mayor( clave );
    // La clave entra en el nodo
    if( clave_men_igu_o_may == 1){
        // puede estar en este nodo
        Dato* dato = nodo_actual -> obtener_dato( clave );
        if( dato == nullptr && nodo_actual -> es_hoja()){
            return nullptr;
        }
        if( dato != nullptr){
            return dato;
        }
    }

    // la clave es menor al nodo
    else if( nodo_actual -> es_hoja() ){
        return nullptr;
    }
    return consulta( nodo_actual -> obtener_hijo( clave_men_igu_o_may +1 ) , clave );
}


template <typename Dato, typename Clave>
void ArbolB3<Dato, Clave>               :: mostrar_arbolb3(){
    cout << "Nodo raiz:" << endl;
    this-> nodo_raiz -> mostrar_nodob3() ;
    if ( nodo_raiz->es_hoja() ){
        cout << "Es hoja"<< endl << endl;
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
        cout << "Es hoja generacion " << generacion << endl << endl;
        return;
    }
    cout << "Hijo 1:" << endl;
    mostrar_arbolb3( nodo_actual -> obtener_hijo(1), generacion+1 ) ;
    cout << "Hijo 2:" << endl;
    mostrar_arbolb3( nodo_actual -> obtener_hijo(2), generacion+1 ) ;
    if ( nodo_actual-> esta_completo() ) {
        cout << "Hijo 3:"<< endl;
        mostrar_arbolb3(nodo_actual -> obtener_hijo(3), generacion+1);
    }
    return;
}


template <typename Dato, typename Clave>
NodoB3<Dato,Clave> * ArbolB3<Dato, Clave>:: obtener_nodo_mas_derecha( ){
    NodoB3<Dato,Clave> * nodo_actual = nodo_raiz;
    while( !( nodo_actual -> es_hoja() ) ){
        nodo_actual = nodo_actual -> obtener_hijo(3);
    }
    return nodo_actual;
}


template <typename Dato, typename Clave>
NodoB3<Dato,Clave> * ArbolB3<Dato, Clave>:: obtener_nodo_mas_izquierda( ){
    NodoB3<Dato,Clave> * nodo_actual = nodo_raiz;
    while( !( nodo_actual -> es_hoja() ) ){
        nodo_actual = nodo_actual -> obtener_hijo(1);
    }
    return nodo_actual;
}


template <typename Dato, typename Clave>
NodoB3<Dato,Clave> * ArbolB3<Dato, Clave>:: obtener_nodo_mas_derecha_a_partir( NodoB3<Dato,Clave>* nodo_actual ){
    while( !( nodo_actual -> es_hoja() ) ){
        nodo_actual = nodo_actual -> obtener_hijo(3);
    }
    return nodo_actual;
}


template <typename Dato, typename Clave>
Lista<Dato>* ArbolB3<Dato, Clave>       :: ordenar_mayor_menor( ){    
    Lista<Dato>* datos = new Lista<Dato>();
    this -> nodo_raiz -> ordenar_mayor_menor( datos );
    return datos;
}


#endif // ARBOL_TEMPLATE