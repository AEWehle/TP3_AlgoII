#ifndef _GUARDERIA_H
#define _GUARDERIA_H
#include <string>
#include "Animal.h"
#include "Auto.h"
#include "Especies/Perro.h"
#include "Especies/Gato.h"
#include "Especies/Caballo.h"
#include "Especies/Roedor.h"
#include "Especies/Conejo.h"
#include "Especies/Erizo.h"
#include "Especies/Lagartija.h"
#include "Archivos_auxiliares/ArbolB3.h"
using namespace std; 

const int NO_SE_ENCUENTRA = -1;


//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0

class Guarderia{
    //Atributos

    private:
        ArbolB3<Animal, string> diccionario_de_animales;
        Auto automovil;

    //Metodos

    public:
        //Constructores
            //Sin Parametros
            //PRE: -
            //POS: Crea guarderia vacia (cantidad_de_animales = 0)
            Guarderia();

        //Destructor
            ~Guarderia();

        //Constructor de copia
            Guarderia(const Guarderia &guarderia_aux);

        /*Ver lista de animales en la guarderia
            PRE: 
            POST: Imprime en terminal todos los animales de la guarderia*/
            void ver_diccionario_de_animales(  );

            
        /*ver los animales en la lista
            PRE:  Necesita una lista con los nombres
            POST: Imprime en terminal todos los animales de la lista ingresada*/
            void ver_los_animales( Lista<string>* nombres );

        /*Agregar
            PRE: Puntero a Animal está creado correctamente
            PPOST: Agrega un animal a la lista de animales */
            void agregar_animal(Animal* nuevo_animal);

        /*Obtener Posicion
            PRE:  -
            POST: Devuelve la posicion en la lista del Animal con el nombre dado
            Si no lo encuentra devuelve la cantidad de animales + 1  */
            // int obtener_posicion(string nombre);

        /*Obtener cantidad
            PRE: -
            POST: Devuelve la cantidad de animales en la Guarderia*/
            int obtener_cantidad();

        /*Eliminar animal
            PRE:  La posición recibida del animal a borrar es válida.
            POST: Elimina del la lista de animales al animal en la posicion dada.*/
            void eliminar_animal(int posicion);

        /* Obtener animal
        PRE:  el nopmbre ingresado debe ser existente.
        POST: Develve un puntero al Animal en la posicion dada*/
            Animal* obtener_animal( string nombre );

        /* Obtener auto
        PRE:  -
        POST: Develve un puntero al Auto*/  
            Auto* obtener_auto();


};

#endif
