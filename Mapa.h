#ifndef MAPA_H
#define MAPA_H
#include <string>
using namespace std; 

const string RESET = "\u001b[0m";
const string MONTANA = "\u001b[48;5;52m";
const string PRECIPICIO = "\u001b[48;5;237m";
const string CAMINO = "\u001b[48;5;250m";
const string TIERRA = "\u001b[48;5;179m";
const string BORDE = "\u001b[48;5;2m";
const string BOLD = "\u001b[1m";

const string RUTA = "mapa.csv";

//const int CANT_COLORES = 6;

//const string COLORES[CANT_COLORES] = {RESET, BORDE, CAMINO, TIERRA, MONTANA, PRECIPICIO};

//enum Colores {RESET = 0, BORDE, CAMINO, TIERRA}; 

class Mapa{

    private:

        //Matrices de 8x8
        char** terreno;
        char** ocupantes;
        bool** visitados;

    public:

        //Constructor por defecto, usa el terreno default
        Mapa();

        //Constructor con parámetro, usa el terreno que hay en la ruta si existe el archivo.
        //Asume que el archivo está bien formado si existe.
        Mapa(string ruta);

        //Destructor
        ~Mapa();

        //Muestra el mapa
        void mostrar();

    private:

        //Crea una matriz de 8x8 del dato Tipo
        template <typename Tipo>
        Tipo** crear_matriz();

        //Crea las matrices de 8x8 y las inicializa en ' '(espacio) o false respectivamente
        void iniciar_matrices();

        //Carga en la matriz de terreno el mapa por defecto
        void usar_terreno_por_defecto();

        //Genera 5 animales aleatorios (solo el char) y coordenadas aleatorias para c/u.
        //Carga en la matriz de ocupantes los chars correspondientes a los animales y al auto
        void generar_animales();

        //Carga en la matriz de terreno lo que haya en el archivo de la ruta. 
        //Usa el terreno por defecto si no encuantra el archivo.
        //Asume que los archivos están bien formados
        void buscar_mapa(string ruta);

        //
        void imprimir_casilla(int i, int j);

};

#endif //MAPA_H