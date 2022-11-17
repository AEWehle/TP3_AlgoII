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


        int obtener_cantidad();

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


        NodoB3<Dato,Clave>* obtener_nodo_mas_derecha();
        NodoB3<Dato,Clave>* obtener_nodo_mas_izquierda();


        /* PRE: -
           POS: Devuelve una lista con los datos ordenado de mayor a menor
         segun su clave*/
        Lista<Dato>* datos_mayor_menor();
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
            NodoB3<Dato,Clave>* nodo_aux = nodo_actual -> agregar_elemento( dato, clave );
            if ( nodo_aux != nullptr ){ // Me fijo si tengo que cambiar el nodo raiz
            //  nodo_aux no será null cuando cree un nuevo hermano mayor, esto sucede cuando un nodo alcanzó 3 clvaes
                nodo_actual = nodo_aux;
                while ( nodo_actual -> obtener_nodo_padre() != nullptr ){
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
Lista<Dato>* ArbolB3<Dato, Clave>       :: datos_mayor_menor( ){
    Lista<Dato> *datos = new Lista<Dato>;
    NodoB3<Dato,Clave> * nodo_actual = obtener_nodo_mas_derecha( );
    int i = 1;
    while( !(datos -> obtener_cantidad() > this -> cantidad)){
        if ( nodo_actual -> esta_completo() ){
            datos -> alta( nodo_actual -> obtener_dato( nodo_actual->obtener_clave_de(2) ) , i++);
        }
        datos -> alta( nodo_actual -> obtener_dato( nodo_actual->obtener_clave_de(1) ) , i++);
        nodo_actual = nodo_actual -> obtener_nodo_padre();
    }
    return datos;
}
    


#endif // ARBOL_TEMPLATE