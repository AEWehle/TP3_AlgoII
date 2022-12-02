#ifndef MAPA_H
#define MAPA_H
#include "Archivos_auxiliares/Grafo.h"
#include "Archivos_auxiliares/Coordenada.h"
#include <string>
using namespace std; 

const string RESET = "\u001b[0m";
const string MONTANA = "\u001b[48;5;52m";
const string PRECIPICIO = "\u001b[48;5;237m";
const string CAMINO = "\u001b[48;5;250m";
const string TIERRA = "\u001b[48;5;179m";
const string BORDE = "\u001b[48;5;2m";
const string BOLD = "\u001b[1m";

class Mapa{

    private:

        //Matrices de 8x8
        char** terreno;
        char** ocupantes;
        bool** visitados;
        int** matriz_de_costos_por_destino;
        Lista<Coordenada>* lista_coordenadas_recorridas;
        int coord_auto_num;
        int coord_auto_letra;


    public:

        //PRE: -
        //POST: Construye el objeto. Usa el mapa por defecto.
        Mapa();

        //PRE: -
        //Construye el objeto, usa el terreno que hay en la ruta si existe el archivo.
        //Asume que el archivo está bien formado si existe.
        Mapa(string ruta);

        //PRE: -
        //POST: Destruye el objeto.
        ~Mapa();

        //PRE: -
        //POST: Muestra el mapa.
        void mostrar();

        //PRE: el combustible está entre 0 y 100
        //POST: Devuelve false si el usuario decide cancelar el rescate.
        //Pone combustible_suficiente en false si el combustible fue insuficiente para el rescate que el usuario pretendía
        //Escribe en especie_rescatada la especie que rescató el usuario, si lo hizo.
        //Escribe en combustible_gastado el combustible que se gastó en el rescate, si se hizo.
        //Obtiene el camino mínimo a través del Grafo y escribe en consecuencia la matriz de visitados si se realiza un rescate
        bool ejecutar(int combustible, int &combustible_gastado, char &especie_rescatada, bool &combustible_suficiente);


    private:

        //PRE: -
        //POST: Crea una matriz de 8x8 del dato Tipo en memoria dinámica.
        template <typename Tipo>
        Tipo** crear_matriz();

        //PRE: -
        //POST: Las matrices quedan inicializadas con ' ' o false respectivamente.
        void iniciar_matrices();

        //PRE: -
        //POST: Carga en la matriz de terreno el mapa por defecto.
        void usar_terreno_por_defecto();

        //PRE: Hay memoria pedida para la matriz. La matriz de terreno fue inicializada.
        //POST: Inicializa la matriz de costos según el costo de cada terreno.
        void inicializar_matriz_de_costos_por_destino();

        //PRE: Hay memoria pedida para la matriz.
        //POST: Genera 5 animales aleatorios (solo el char) y coordenadas aleatorias para c/u.
        //Carga en la matriz de ocupantes los chars correspondientes a los animales y al auto.
        void generar_animales();

        //PRE: -
        //POST: Carga en la matriz de terreno lo que haya en el archivo de la ruta. 
        //Usa el terreno por defecto si no encuantra el archivo.
        //Asume que los archivos están bien formados.
        void buscar_mapa(string ruta);

        //PRE: Las matrices de terrenos y visitados fueron inicializadas.
        //POST: Imprime una casilla del mapa del color correspondiente al terreno.
        //Imprime en esa casilla al ocupante e indica si fué visitada.
        void imprimir_casilla(int i, int j);

        //PRE: -
        //POST: Imprime una explicación del mapa.
        void explicacion();

        //PRE: -
        //POST: Pide una coordenada número y luego una coordenada letra al usuario.
        //Verifica que los datos ingresados sean coordenadas válidas.
        //Permite ingresar 0 para cancelar el rescate.
        void pedir_coordenadas(int &coord_num, int &coord_letra, bool &cancelar);

        //PRE: Las coordenadas ingresadas son válidas.
        //POST: Devuelve lo que hay en la matriz de ocupantes en las coordenadas dadas.
        //Imprime un mensaje al usuario avisando si en las coordenadas se encuentra el auto, un animal o nada.
        char verificar_coordenadas(int &coord_num, int &coord_letra, bool &coord_ok);

        //PRE: El char destino corresponde a un terreno válido
        //POST: Obtiene el costo de viajar a ese terreno desde una casilla vecina.
        int obtener_costo_de_viaje(char destino);

        //PRE: Hay memoria para la matriz de visitados.
        //POST: Pone todas las posiciones de la matriz en false.
        void limpiar_visitados();

};

#endif //MAPA_H