#ifndef NODOB3_TEMPLATE
#define NODOB3_TEMPLATE

#include <iostream>
using namespace std; 


template <typename Dato, typename Clave>
class NodoB3;

#include "lista.h"
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
            POS: Crea un NodoB3 con elemento tipo Elemento ya creado.
            */
        NodoB3( Elemento<Dato,Clave> * elemento_entrante );
        
        //Destructor
        ~NodoB3();


        /*Devuelve true si el padre es distinto de nullptr*/
       bool tiene_padre();

   
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
        
        void mostrar_hijos();


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
                          1 se es == a menor o <= a mayor
                          2 si es mayor a la clave mayor del nodo
            */
        int clave_menor_entra_mayor( Clave clave);



        void ordenar_mayor_menor( Lista<Dato>* datos );
};


// Constructor por dato y clave
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>                     :: NodoB3( Dato* dato, Clave clave){
    Elemento<Dato, Clave>* elemento = new Elemento<Dato, Clave>(dato, clave);
    this -> elementos = new Lista<Elemento<Dato, Clave>>();
    elementos -> alta( elemento, 1 );
    ultimo_hijo = nullptr;
    nodo_padre = nullptr;
}

// Constructor por elemento
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>                     :: NodoB3( Elemento<Dato, Clave>* elemento_entrante ){
    this -> elementos = new Lista<Elemento<Dato, Clave>>();
    this -> elementos -> alta( elemento_entrante , 1 );
    ultimo_hijo = nullptr;
    nodo_padre = nullptr;
}

//Destructor
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>                     :: ~NodoB3(){
    cout << "Chau nodo" << endl;
}


template <typename Dato, typename Clave>
bool NodoB3<Dato,Clave> :: tiene_padre(){
    return (this -> obtener_nodo_padre() != nullptr);
}


// obtener dato
template <typename Dato, typename Clave>
Dato* NodoB3<Dato, Clave>               :: obtener_dato( Clave clave ) {
    if (elementos -> consulta(1) -> obtener_clave() == clave){
        return elementos -> consulta(1) -> obtener_dato();
    }
    else if ( ( elementos -> obtener_cantidad() == 2 ) && (elementos -> consulta(2) -> obtener_clave() == clave) ){
        return elementos -> consulta(2) -> obtener_dato();
    }
    else{
        // no esta esa clave
        return nullptr;
    }
}


// Obtener clave segun posicion
template <typename Dato, typename Clave>
Clave NodoB3<Dato, Clave>               :: obtener_clave_de( int pos ){
    Clave clave_out;
    if ( pos > elementos -> obtener_cantidad()){
        clave_out = this -> elementos -> consulta( elementos -> obtener_cantidad() ) -> obtener_clave();
    }
    else {
        clave_out = this ->  elementos -> consulta(pos) -> obtener_clave();
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
    if ( pos > elementos -> obtener_cantidad()){
        nodo_aux = this ->  ultimo_hijo;
    }
    else {
        nodo_aux = this ->  elementos -> consulta(pos) -> obtener_hijo();
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
    else if ( ( this -> elementos -> obtener_cantidad() == 2 ) &&
              ((nodo_hijo_entrante -> obtener_clave_de(1) ) <= (this -> obtener_clave_de(2) ) ) ){
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
    NodoB3<Dato, Clave>* nodo_herm_mayor = this -> agregar_elemento_existente( elemento_nuevo );
    return nodo_herm_mayor;
}


// Agregar elemento dando el tipo Elemento armado
template <typename Dato, typename Clave>
NodoB3<Dato, Clave>* NodoB3<Dato, Clave>:: agregar_elemento_existente( Elemento<Dato, Clave>* elemento_entrante ){
    NodoB3<Dato,Clave>* nodo_hermano_mayor = nullptr;

    if ( elemento_entrante -> obtener_clave() < this -> obtener_clave_de(1) ){
        this -> elementos -> alta( elemento_entrante , 1);
    }
    else if( ( this -> elementos -> obtener_cantidad() == 1 )  ||
             (elemento_entrante -> obtener_clave() < this -> obtener_clave_de(2) )){
        elementos -> alta( elemento_entrante , 2); // puede que ahora tenga 3 claves
    }
    else{
        elementos -> alta( elemento_entrante , 3);
    }

    // SI AGREGUÉ UNA TERCERA CLAVE:
    if ( elementos->obtener_cantidad() == VIAS ){
        
        Elemento<Dato,Clave> * elemento_a_subir = new Elemento<Dato,Clave>( this -> elementos -> consulta(2) -> obtener_dato() , this -> elementos -> consulta(2) -> obtener_clave() );

        nodo_hermano_mayor = new NodoB3<Dato,Clave>( this -> elementos -> consulta(3) -> obtener_dato(),
                                                     this -> elementos -> consulta(3) -> obtener_clave() );

        NodoB3<Dato,Clave>* nodo_hijo_2;

        if( !(this -> es_hoja() )){
            // cout << "no es hoja" << endl;
            nodo_hermano_mayor -> ubicar_nodo_hijo( this -> obtener_hijo(3) );
            nodo_hermano_mayor -> ubicar_nodo_hijo( this -> obtener_hijo(4) );
            this -> obtener_hijo(3) -> cambiar_nodo_padre( nodo_hermano_mayor );
            this -> obtener_hijo(4) -> cambiar_nodo_padre( nodo_hermano_mayor );

            nodo_hijo_2 = this -> elementos -> consulta(2) -> obtener_hijo() ;
        }
        this -> elementos -> baja(3);
        this -> elementos -> baja(2);
        
        elemento_a_subir -> cambiar_hijo( this );

        if( !(this -> es_hoja() )){
            this -> cambiar_ultimo_hijo( nodo_hijo_2 );
            nodo_hijo_2 -> cambiar_nodo_padre( this );
        }


        if ( nodo_padre == nullptr ){ // SI NO TENGO PADRE
            NodoB3<Dato,Clave>* nuevo_nodo_padre = new NodoB3<Dato,Clave>( elemento_a_subir );
            nuevo_nodo_padre -> cambiar_nodo_padre( this -> nodo_padre );
            nodo_hermano_mayor -> cambiar_nodo_padre( nuevo_nodo_padre );
            if ( nodo_hermano_mayor -> obtener_clave_de(1) > elemento_a_subir -> obtener_clave() ){
                nuevo_nodo_padre  -> cambiar_ultimo_hijo( nodo_hermano_mayor ); 
            }
            else{
                nuevo_nodo_padre  -> ubicar_nodo_hijo( nodo_hermano_mayor );
            }    
            this -> nodo_padre = nuevo_nodo_padre;
        }
        else{ //SI YA TENGO PADRE
            nodo_hermano_mayor -> cambiar_nodo_padre( this -> nodo_padre );
            this -> nodo_padre -> agregar_elemento_existente( elemento_a_subir );// le dice a hermano mayor su nuevo padre
            
            if ( nodo_hermano_mayor -> obtener_clave_de(1) > this -> nodo_padre -> obtener_clave_de(2)  ){
                this -> nodo_padre -> cambiar_ultimo_hijo( nodo_hermano_mayor ); 
            }
            else{
                this -> nodo_padre -> ubicar_nodo_hijo( nodo_hermano_mayor );
            }
            nodo_hermano_mayor -> cambiar_nodo_padre( this -> nodo_padre ); // si, esta repetido
        }
        
    }
    return this -> nodo_padre;
}


// Eliminar elemento segun la clave
template <typename Dato, typename Clave>
Elemento<Dato, Clave>* NodoB3<Dato, Clave>           :: quitar_elemento( Clave clave_chau ){
    for ( int i = 1 ; i <= elementos -> obtener_cantidad() ; i++ ){
        if (clave_chau == elementos -> consulta( i ) -> obtener_clave() ) {
            elementos -> baja( i );
        }
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
    for( int i = 1 ; i <= this -> elementos -> obtener_cantidad() ; i++){
        cout << "Clave:" << this -> obtener_clave_de( i ) << endl;
        cout << "Dato:" << *(this -> obtener_dato( this -> obtener_clave_de( i ) )) << endl;
    }
    cout << "mi padre es: " << endl;
    if ( nodo_padre != nullptr){
        for( int i = 1 ; i <= this -> nodo_padre -> elementos -> obtener_cantidad() ; i++){
            cout << this -> nodo_padre -> obtener_clave_de( i ) << " " ;
            // cout << "Dato:" << *(this -> nodo_padre -> obtener_dato( this -> nodo_padre -> obtener_clave_de( i ) )) << endl;
        }
        cout << endl;
    }
}

// MImprimir en terminal clave y dato
template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                :: mostrar_hijos(){ 
    for( int i = 1 ; i <= ( this-> elementos -> obtener_cantidad() +1 ) ; i++){
        cout << "Hijo "<< i <<": puntero " << this -> obtener_hijo(i) << endl;
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
    bool es_hoja = true;
    es_hoja = es_hoja &&  ( this -> ultimo_hijo  == nullptr );
    for (  int i = 1 ; (i <= elementos -> obtener_cantidad()) && es_hoja ; i++ ){
        es_hoja = es_hoja && (elementos -> consulta( i ) -> obtener_hijo()  == nullptr);
    }
    return es_hoja;
}


template <typename Dato, typename Clave>
int NodoB3<Dato, Clave>                 :: clave_menor_entra_mayor( Clave clave ){
    int clave_es = 2;
    if (clave < this -> obtener_clave_de(1)){
        clave_es = 0;}
    else if (  ( clave == this -> obtener_clave_de(1) ) ||
               (( this -> elementos -> obtener_cantidad() == 2) && ( clave <= this -> obtener_clave_de(2) ))){
        clave_es = 1;  }
    
    return clave_es;
}



template <typename Dato, typename Clave>
void NodoB3<Dato, Clave>                 :: ordenar_mayor_menor( Lista<Dato>* datos ){
    for ( int i = this -> elementos -> obtener_cantidad() ; i >= 0 ; i-- ){
        if ( !this -> es_hoja() ){
            this -> obtener_hijo(i+1) -> ordenar_mayor_menor( datos );}
        
        if(i != 0){
            datos -> alta(  this -> obtener_dato( this -> obtener_clave_de(i) ) );}
    }
}



#endif // NODOB3_TEMPLATE
