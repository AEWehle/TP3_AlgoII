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
#include "Archivos_auxiliares/lista.h"
#include "Archivo.h"
using namespace std; 

const int NO_SE_ENCUENTRA = -1;


//  EL ORDEN DE LOS ELEMENTOS SE EMPIEZA A CONTAR DESDE 1, NO DESDE 0

class Guarderia{
    //Atributos

    private:
        ArbolB3<Animal, string>* diccionario_de_animales;
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
            PPOST: Agrega un animal a al diccionario de animales */
            void agregar_animal(Animal* nuevo_animal);


        /*Obtener cantidad
            PRE: -
            POST: Devuelve la cantidad de animales en la Guarderia*/
            int obtener_cantidad();

        /*Eliminar animal
            PRE:  El nombre del animal a borrar es válido.
            POST: Da de baja del diccionario de animales al animal.
            NO HACE DELETE*/
            void eliminar_animal( string nombre );

        /* Obtener animal
        PRE:  el nombre ingresado debe ser existente.
        POST: Develve un puntero al Animal con ese nombre*/
            Animal* obtener_animal( string nombre );

        /* Obtener auto
        PRE:  -
        POST: Develve un puntero al Auto*/  
            Auto* obtener_auto();

        /* Afectar animales
        PRE:  Guardería cargada con animales
        POST: Disminuye higiene y aumenta hambre a todos los animales 
              según sus caracteristicas*/  
            void afectar_animales();
        
        /*Devuelve una lista con los nombres de los animales no adoptados
         del diccionario*/
            Lista<string>* obtener_lista_nombres();

};

#endif
