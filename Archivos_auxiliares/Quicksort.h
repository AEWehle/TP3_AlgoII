#ifndef QUICKSORT_TEMPLATE
#define QUICKSORT_TEMPLATE


using namespace std; 


template <typename Dato>
class Quicksort{
private:
    Dato* lista_datos;
    bool (*funcion_operador) ( Dato dato1, Dato dato2 );
    int cantidad;
public:
    Quicksort( Dato* lista_datos, int cantidad, bool (*funcion_operador) ( Dato dato1, Dato dato2 ) );
    void ordenar();
    void mostrar();

private:
    void ordenar( int inicio, int final );
    int obtener_pivote( int inicio, int final );
    void swap( int pos1, int pos2  );
    
};




template <typename Dato>
Quicksort<Dato> :: Quicksort( Dato* lista_datos, int cantidad, bool (*funcion_operador) ( Dato dato1, Dato dato2 ) ){
    this -> lista_datos = lista_datos;
    this -> cantidad = cantidad;
    this -> funcion_operador = funcion_operador;
}



template <typename Dato>
int Quicksort<Dato> :: obtener_pivote( int inicio, int final ){
	
	int pivote= final;
	int j = inicio;
	for( int i = inicio ; i < final ; i++ ){
		if( funcion_operador( lista_datos[i], lista_datos[ pivote ] ) ){
			swap( i , j );
			j++;
		}
	}
	swap( j , pivote );
	return j;
	
}


template <typename Dato>
void Quicksort<Dato> ::  ordenar(  ){
		ordenar( 0, cantidad-1 );	
}
template <typename Dato>
void Quicksort<Dato> ::  ordenar( int inicio, int final ){

	if( inicio < final ){
		int pivote = obtener_pivote( inicio , final );
		ordenar( inicio , pivote - 1 );
		ordenar( pivote + 1, final );
	}
	
}






template <typename Dato>
void Quicksort<Dato> ::  swap( int pos1, int pos2 ){
    Dato dato_pos1 = lista_datos[ pos1 ];
    lista_datos[ pos1 ] = lista_datos[ pos2 ];
    lista_datos[ pos2 ] = dato_pos1;
}

template <typename Dato>
void Quicksort<Dato> ::  mostrar(){
	for(int i = 0 ; i < cantidad ; i++ ){
		cout << lista_datos [i] << " ";
    }
	cout << endl ;
}




#endif // NODOB3_TEMPLATE
