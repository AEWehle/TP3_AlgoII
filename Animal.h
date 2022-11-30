#ifndef ANIMAL_H
#define ANIMAL_H
#include <string>
using namespace std; 

const int EDAD_MAX = 100;
const int HAMBRE_MAX = 100;
const int HIGIENE_MAX = 100;
const int CANTIDAD_ESPECIES = 7; 
const int CANTIDAD_PERSONALIDADES = 4;
const int CANTIDAD_TAMANOS = 5;
const int PUNTOS_HAMBRE = 10;
const int PUNTOS_HIGIENE = 10;

const char ESPECIE_CHAR[ CANTIDAD_ESPECIES ] = { 'P', 'G', 'C', 'R', 'O', 'E', 'L' }; 
const string ESPECIE_STRING[ CANTIDAD_ESPECIES ]= { "Perro", "Gato", "Caballo", "Roedor", "Conejo", "Erizo", "Lagartija" }; 
const string PERSONALIDADES[ CANTIDAD_PERSONALIDADES ] = { "dormilon", "jugueton", "sociable", "travieso" };
const string TAMANOS_STRING[ CANTIDAD_TAMANOS ] = { "diminuto", "pequeño", "mediano", "grande", "gigante" };

enum Especie { ESPECIE_INVALIDA = 0, P, G, C, R, O, E, L }; 

class Animal{

    protected:
        string nombre;
        int    edad;	        //  [0-100]
        string tamano;	        //	[ D<2, P<10, M>=10, Gr>=20, Gi>=50 ]    
        string personalidad;	// 	[D J S T]
        bool   es_domestico;	//  [lo define la especie, indica si es adoptable]
        int    hambre; 	        //	[0-100]
        int    higiene;	        //	[0-100]
        string comida;	        //	[lo define la especie, es lo que va a imprimir]
    
    
    public:

    /*________constructor Animal default___________________________________________
     PRE: - 
     POST: En el objeto Animal establece higiene = 100 y hambre = 0
    _______________________________________________________________________________*/
        Animal();


    /*________constructor Animal con parametros____________________________________
     PRE: Los datos recibidos son correctos (fueron validados previamente)
     POST: Se crea un Animal con los datos ingresados.
           Establece higiene = 100 y hambre = 0.
    _______________________________________________________________________________*/
        Animal( string nombre, int edad, string tamano, string personalidad );


       
    /*________destructor Animal_____________________________________________________
     PRE: -
     POST: Destruye animal
    _______________________________________________________________________________*/
        virtual ~Animal() = 0;


    /*________alimentar()_______________________________________________________
     PRE: -
     POST: Establece hambre = 0 y muestra al usuario su nombre y comida
    _______________________________________________________________________________*/
        virtual void alimentar();


    /*________duchar()_____________________________________________________________
     PRE: -
     POST: Establece higiene = 100
    _______________________________________________________________________________*/
        virtual void duchar();


    /*________dar_hambre()_____________________________________________________________
     PRE: -
     POST: Aumenta el hambre de acuerdo a PERSONALIDAD. Si hambre es 100,
     deja en 100 e informa que se llegó al límite.
     Devuelve true si el animal llega al límite
    _______________________________________________________________________________*/
        bool dar_hambre();


    /*________ensuciar()_____________________________________________________________
     PRE: -
     POST: Baja la higiene de acuerdo a ESPECIE y PERSONALIDAD. Si higiene es 0,
     deja en 0 e informa que se llegó al límite
     Devuelve true si el animal llega al límite
    _______________________________________________________________________________*/
        virtual bool ensuciar();



    /*________mostrar()_____________________________________________________
     PRE: -
     POST:  El Animal se muestra individualmente,
            nombre, edad, tamano, especie, personalidad, hambre e higiene.
    _______________________________________________________________________________*/
        virtual void mostrar();


    /*________obtener_nombre()_____________________________________________________
     PRE: -
     POST:  Devuelve el nombre del animal
    _______________________________________________________________________________*/
        string obtener_nombre();


    /*________obtener_edad()_____________________________________________________
     PRE: -
     POST:  Devuelve la edad del animal
    _______________________________________________________________________________*/
        int obtener_edad();

    
    /*________obtener_tamano()_____________________________________________________
     PRE: -
     POST:  Devuelve el tamano del animal
    _______________________________________________________________________________*/
        string obtener_tamano();

    
    /*________obtener_personalidad()_____________________________________________________
     PRE: -
     POST:  Devuelve la personalidad del animal
    _______________________________________________________________________________*/
        string obtener_personalidad();


        virtual Especie resolver_especie() = 0;


    /*________es_adoptable()_____________________________________________________
     PRE: -
     POST:  Devuelve un bool si es adoptable o no (definido por la especie).
    _______________________________________________________________________________*/
        bool es_adoptable();

    
    /*________obtener_hambre()_____________________________________________________
     PRE: -
     POST:  Devuelve (int) de hambre.
    _______________________________________________________________________________*/
        int obtener_hambre();


    /*________obtener_higiene()_____________________________________________________
     PRE: -
     POST:  Devuelve (int) de higiene.
    _______________________________________________________________________________*/
        int obtener_higiene();

    
    /*________setear_hambre(int hambre_int)__________________________________________
     PRE: int debe ser entre 0 y 100
     POST: Establece el hambre en el valor hambre_int
    _______________________________________________________________________________*/
        void setear_hambre(int hambre_int);

    /*________setear_higiene(int higiene_int)_________________________________________
     PRE: int debe ser entre 0 y 100
     POST: Establece la higiene en el valor higiene_int
    _______________________________________________________________________________*/
        void setear_higiene(int higiene_int);

};



        
/*________es_primer_animal_mayor()_____________________________________________
    PRE: -
    POST: DEvuelve true si el animal1 tiene mas edad que el animal 2
_______________________________________________________________________________*/        
    bool es_primer_animal_mayor( Animal* animal1, Animal* animal2 );

#endif