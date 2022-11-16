#ifndef NODOB3_TEMPLATE
#define NODOB3_TEMPLATE

#include <iostream>
using namespace std; 


template <typename Dato, typename Clave>
class NodoB3;

#include "Lista.h"
#include "Elemento.h"


/*  Esta clase es un nodo de arbol B 3 vias. 
    Está implementado con una lista de objetos tipo Elemento, el cual contiene
    una clave, un dato, y un puntero a NodoB3.
    Al ser un Arbol de 3 vias, la lista contiene a lo sumo dos nodos con un
    hijo cada uno, y como minimo 1.
    De esta forma cada clave tiene dos hijos NodoB3 ya que la clase NodoB3 ya
    tiene un ountero a NodoB3.
*/

const int VIAS = 3;

template <typename Dato, typename Clave>
class NodoB3{
        // Atributos
    private:
    NodoB3* ultimo_hijo;
    NodoB3* nodo_padre;
    Lista<Elemento<Dato, Clave>>* elementos; // Contiene por lo menos uno, y hasta dos

    public:
        // Constructor
        /*  PRE: -
            POS: Crea un NodoB3 con dato , clave y puntero de hijo a nullptr.
            */
        NodoB3( Dato* dato, Clave clave);

   
        /*  PRE: -
            POS: Devuelve un puntero al Dato de la clave.
            */
        Dato* obtener_dato( Clave clave );


        /*  PRE: -
            POS: Devuelve la clave del elemento pos ( 1 o 2 )
            Si igresa 2, pero solo hay una clave se duelvuelve la clave 1
            */
        Clave obtener_clave_de( int pos );


        /*  PRE: -
            POS: Devuelve el puntero a la lista de elementos del nodo.
            */
        Lista<Elemento<Dato,Clave>>* obtener_lista_elementos();


        /*  PRE: 
            POS: Devuelve el puntero del nodo hijo ( 1 2 o 3)
            Si se elije 3 y solo hay dos hijos devuelve el hijo 2
            */
        NodoB3<Dato,Clave>* obtener_hijo( int pos );


        /*  PRE: -
            POS: Devuelve el puntero al nodo_padre
            */
        NodoB3<Dato,Clave>* obtener_nodo_padre();


        /*  PRE: La clave no se debe repetir.
            Es necesario que la clave le correponda a este nodo y no a uno menor o mayor.
            POS: Agrega el dato y clave al nodo.
            Devuelve el puntero al nodo padre de este nodo, esto es por si el
            nodo estaba lleno, crea un nodo padre.
            */
        NodoB3<Dato, Clave>* agregar_elemento( Dato* dato_nuevo, Clave clave_nueva );


        /*  PRE: El elemento ya debe estar creado, sirve para cuando se cambian
            de nodo los elementos del arbol.
            Es necesario que la clave le correponda a este nodo y no a uno menor o mayor.
            POS: Agrega el elemento al nodo .
            Devuelve el puntero al nodo padre de este nodo, esto es por si el
            nodo estaba lleno, crea un nodo padre.
            */
        NodoB3<Dato, Clave>* agregar_elemento_existente( Elemento<Dato, Clave>* elemento_entrante );


        /*  PRE: -
            POS: Saca del nodo el elemento con esa clave.
            Devuelve el Elemento que se eliminó, pero su puntero hijo apuntando
            a nullptr.
            */
        Elemento<Dato, Clave>* quitar_elemento( Clave clave_chau );


        /*  PRE: -
            POS: Cambia el puntero al hijo de mas a la derecha del nodo.
            */
        void cambiar_ultimo_hijo( NodoB3<Dato, Clave>* nuevo_ultimo_hijo );


        /*  PRE: -
            POS: Cambia el puntero al nodo padre
            */
        void cambiar_nodo_padre( NodoB3<Dato, Clave>* nuevo_nodo_padre );


        /*  PRE: Se utiliza cuando se reubican elementos entre nodos.
            Es necesario que l clave le correponda a este nodo y no a uno menor o mayor.
            POS: Cambia el puntero al hijo que le correponde segun el orden de las claves.
            */
        void ubicar_nodo_hijo( NodoB3<Dato,Clave>* nodo_hijo_entrante );


        /* Muestra en terminal todas las claves con su dato asociado
        No es para mostrar los datos, es para mostrar el nodo */
        void mostrar_nodob3();


        /*  PRE: -
            POS: DEvuelve true si ya tiene 2 claves.
            */
        bool esta_completo();


        /*  PRE: -
            POS: DEvuelve true si sus hijos apuntan a nullptr.
            */
        bool es_hoja();


        /*  PRE: -
            POS: devuelve 0 si es menor a la clave menor del nodo
                          1 se esta entre la mayor y la menor clave
                          2 si es mayor a la clave mayor del nodo
            */
        int clave_menor_entra_mayor( Clave clave);
};


// Constructor
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>                     :: NodoB3( Dato* dato, Clave clave){
    Elemento<Dato, Clave>* elemento = new Elemento<Dato, Clave>(dato, clave);
    this -> elementos = new Lista<Elemento<Dato, Clave>>();
    elementos -> alta( elemento, 1 );
    ultimo_hijo = nullptr;
    nodo_padre = nullptr;
}


// obtener dato
template <typename Dato, typename Clave>
Dato* NodoB3<Dato, Clave>               :: obtener_dato( Clave clave ) {
    if (elementos -> consulta(1) -> obtener_clave() == clave){
        return elementos -> consulta(1) -> obtener_dato();
    }
    else{
        return elementos -> consulta(2) -> obtener_dato();
    }
}


// Obtener clave segun posicion
template <typename Dato, typename Clave>
Clave NodoB3<Dato, Clave>               :: obtener_clave_de( int pos ){
    Clave clave_out;
    if ( pos == 1){
        clave_out = elementos -> consulta(1) -> obtener_clave();
    }
    if ( pos == 2){
        if ( this -> elementos -> obtener_cantidad() == 1 ){
            cout << "ERROR solo tengo una clave en el nodo" << endl;
            clave_out = 0;
        }
        else{
            clave_out = elementos -> consulta(2) -> obtener_clave();
        }
    }
    return clave_out;
}



template <typename Dato, typename Clave>
Lista<Elemento<Dato,Clave>>* NodoB3<Dato, Clave> :: obtener_lista_elementos(){
    return elementos;
}


template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* NodoB3<Dato, Clave> :: obtener_hijo( int pos ){
    NodoB3<Dato,Clave>* nodo_aux;
    if ( pos == 1 ){
        nodo_aux = this ->  elementos -> consulta(1) -> obtener_hijo();
    }
    else if ( pos == 2 ){
        if( elementos -> obtener_cantidad() == 2 ){
            nodo_aux = this ->  elementos -> consulta(2) -> obtener_hijo();
        }
        else{
            nodo_aux = this -> ultimo_hijo;
        }
    }
    else{// ( pos == 3){
        nodo_aux = this -> ultimo_hijo;
    }
    return nodo_aux;
}


template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* NodoB3<Dato, Clave> :: obtener_nodo_padre( ){
    return this ->  nodo_padre;
}


// Ubicar nodo hijo segun las claves
template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                :: ubicar_nodo_hijo( NodoB3<Dato,Clave>* nodo_hijo_entrante ){
    
    if      ( ( nodo_hijo_entrante -> obtener_clave_de(1) ) < (this -> obtener_clave_de(1) ) ){
        this ->  elementos -> consulta(1) -> cambiar_hijo( nodo_hijo_entrante );
    }
    else if ( ( this -> elementos -> obtener_cantidad() == 2 )  &&
              ((nodo_hijo_entrante -> obtener_clave_de(1) ) < (this -> obtener_clave_de(2) ) ) ){
        this -> elementos -> consulta(2) -> cambiar_hijo( nodo_hijo_entrante );
    }
    else{
        this -> ultimo_hijo = nodo_hijo_entrante;
    }
}


//Agregar elemento dando Dato y Clave
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* NodoB3<Dato, Clave> :: agregar_elemento( Dato* dato_nuevo, Clave clave_nueva ){
    Elemento<Dato,Clave>* elemento_nuevo = new Elemento<Dato,Clave> ( dato_nuevo, clave_nueva );
    NodoB3<Dato, Clave>* nodo_hermano_mayor = this -> agregar_elemento_existente( elemento_nuevo );
    return nodo_hermano_mayor;
}


// Agregar elemento dando el tipo Elemento armado
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* NodoB3<Dato, Clave>:: agregar_elemento_existente( Elemento<Dato, Clave>* elemento_entrante ){
    NodoB3<Dato,Clave>* nodo_hermano_mayor = nullptr;
    if ( elemento_entrante -> obtener_clave() < this -> obtener_clave_de(1) ){
        elementos -> alta( elemento_entrante , 1);
        // cout << "tenia una clave..";
        // this -> mostrar_nodob3();
    }
    else if( ( elementos -> obtener_cantidad() == 1 )  ||  (elemento_entrante -> obtener_clave() < this -> obtener_clave_de(2) )){
        elementos -> alta( elemento_entrante , 2); // puede que ahora tenga 3 claves
        // cout << "tenia una clave y era mayor. O tenia dos y era menor a segunda..";
        // this -> mostrar_nodob3();
        // cout << "mostre";
    }
    else{
        elementos -> alta( elemento_entrante , 3);
        // cout << "tenia una o mayor a ambas..";
        // this -> mostrar_nodob3();
    }
    // cout << "Cantidad";
    // cout << elementos->obtener_cantidad();
    if ( elementos->obtener_cantidad() == VIAS ){
     //EL nodo tendria 3 claves y eso es inaceptable, soy un arbol 3 vias
        
        if ( nodo_padre == nullptr ){
            NodoB3<Dato,Clave>* nuevo_nodo_padre = new NodoB3<Dato,Clave>( this -> elementos -> consulta(2) -> obtener_dato(),
                                                         this -> elementos -> consulta(2) -> obtener_clave());
            nuevo_nodo_padre -> cambiar_nodo_padre( this -> nodo_padre );
            this -> nodo_padre = nuevo_nodo_padre;
            // cout << "no tenia padre, me creo uno y agrego. padre:";
            // this -> nodo_padre -> mostrar_nodob3();
        }
        else{ //ya tengo padre 
            // cout << "tenia padre, agrego en este. padre:";
            NodoB3<Dato,Clave>* nodo_aux = this -> nodo_padre -> agregar_elemento_existente( this -> elementos -> consulta(2) );
            if (nodo_aux != nullptr){
                this -> nodo_padre = nodo_aux -> obtener_nodo_padre();
            }
        }
        nodo_hermano_mayor = new NodoB3<Dato,Clave>( this -> elementos -> consulta(3) -> obtener_dato(),
                                                     this -> elementos -> consulta(3) -> obtener_clave() );
        if( !(this -> es_hoja()) ){
            nodo_hermano_mayor -> ubicar_nodo_hijo( this -> obtener_hijo(1) );
            // nodo_hermano_mayor -> ubicar_nodo_hijo( this -> obtener_hijo(2) );
            nodo_hermano_mayor -> ubicar_nodo_hijo( this -> obtener_hijo(3) );
        }
        nodo_hermano_mayor -> cambiar_nodo_padre( this -> nodo_padre );
        this -> nodo_padre -> ubicar_nodo_hijo( nodo_hermano_mayor );
        this -> nodo_padre -> ubicar_nodo_hijo( this );
        this -> elementos -> baja_sin_delete(3); // ahora es hermano mayor
        if( !(this -> es_hoja()) ){
            this -> ubicar_nodo_hijo( this -> obtener_hijo(2) );
        }
        this -> elementos -> baja_sin_delete(2); // ahora es padre
        // cout << "padre de hermnao mayor";
        // nodo_hermano_mayor -> obtener_nodo_padre() ->mostrar_nodob3();
    }
    // if (nodo_hermano_mayor != nullptr){
    //     cout << "voy a devolver un hermano";
    // }
    return nodo_hermano_mayor;
}



// Eliminar elemento segun la clave
template <typename Dato, typename Clave>
Elemento<Dato, Clave>* NodoB3<Dato, Clave>           :: quitar_elemento( Clave clave_chau ){
    if (clave_chau == elementos -> consulta( 1 ) -> obtener_clave() ) {
        elementos -> baja( 1 );
    }
    if (clave_chau == elementos -> consulta( 2 ) -> obtener_clave() ) {
        elementos -> baja( 2 );
    }
}


// Cambiar puntero hijo de la derecha
template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                :: cambiar_ultimo_hijo( NodoB3<Dato, Clave>* nuevo_ultimo_hijo ){
    this ->  ultimo_hijo = nuevo_ultimo_hijo;
}



// Cambiar el puntero del nodo padre
template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                :: cambiar_nodo_padre( NodoB3<Dato, Clave>* nuevo_nodo_padre ){
    this ->  nodo_padre = nuevo_nodo_padre;
}



// MImprimir en terminal clave y dato
template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                :: mostrar_nodob3(){ 
    for( int i = 1 ; i <=  this-> elementos -> obtener_cantidad() ; i++){
        cout << "Clave:" << this -> obtener_clave_de( i ) << endl;
        cout << "Dato:" << *(this -> obtener_dato( this -> obtener_clave_de( i ) )) << endl << endl;
    }
}



// True si completo
template <typename Dato, typename Clave>
bool NodoB3<Dato, Clave>                :: esta_completo( ){
    return elementos -> obtener_cantidad() == (VIAS-1);
}



// True si todo hijo = nullptr
template <typename Dato, typename Clave>
bool NodoB3<Dato, Clave>                :: es_hoja( ){
    if ( (elementos -> consulta( 1 ) -> obtener_hijo()  == nullptr ) &&
         (this ->  ultimo_hijo  == nullptr ) ){
        if(  (elementos -> obtener_cantidad() == 1) ||
             (elementos -> consulta( 2 ) -> obtener_hijo()  == nullptr ) ){
            return true;
        }
    } 
    return false;
}


template <typename Dato, typename Clave>
int NodoB3<Dato, Clave>                 :: clave_menor_entra_mayor( Clave clave){
    int clave_es = 2;
    if (clave < this -> obtener_clave_de(1)){
        clave_es = 0;}
    else if (( this -> elementos -> obtener_cantidad() == 2) && ( clave < this -> obtener_clave_de(2) )){
        clave_es = 1;  }
    return clave_es;
}

#endif // NODOB3_TEMPLATE
