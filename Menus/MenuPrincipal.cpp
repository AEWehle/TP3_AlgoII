#include "MenuPrincipal.h"

using namespace std;

MenuPrincipal::MenuPrincipal() : opciones(Lista<Opcion>()){

    Opcion* opcion_listar = new OpcionListarAnimales;
    Opcion* opcion_rescatar = new OpcionRescatarAnimal;
    Opcion* opcion_buscar = new OpcionBuscarAnimal;
    Opcion* opcion_cuidar = new OpcionCuidarAnimales;
    Opcion* opcion_adoptar = new OpcionAdoptarAnimal;
    Opcion* opcion_cargar_combustible = new OpcionCargarCombustible;
    Opcion* opcion_guardar = new OpcionGuardarSalir;

    opciones.alta(opcion_listar, 1);
    opciones.alta(opcion_rescatar, 2);
    opciones.alta(opcion_buscar, 3);
    opciones.alta(opcion_cuidar, 4);
    opciones.alta(opcion_adoptar, 5);
    opciones.alta(opcion_cargar_combustible, 6);
    opciones.alta(opcion_guardar, 7);
    
}


void MenuPrincipal::mostrar(){

    cout << endl << "        *****   MENU   *****" << endl << endl;
    cout << "         1. Listar animales." << endl; 
    cout << "         2. Rescatar un animal." << endl; 
    cout << "         3. Buscar un animal." << endl;
    cout << "         4. Cuidar animales." << endl;
    cout << "         5. Adoptar un animal." << endl;
    cout << "         6. Cargar Combustible." << endl;
    cout << "         7. Guardar y salir." << endl << endl;

}


void MenuPrincipal::ejecutar_opcion(int eleccion, Guarderia *mi_guarderia){

    opciones.consulta(eleccion)->ejecutar(mi_guarderia);
    
}


void MenuPrincipal::ejecutar(Guarderia *mi_guarderia){

    int eleccion;

    do{
        mostrar();
        eleccion = pedir_eleccion(CANTIDAD_OPCIONES);
        system( "clear" );
        ejecutar_opcion(eleccion, mi_guarderia);
    }
    while ( (eleccion != (CANTIDAD_OPCIONES)) && (mi_guarderia->obtener_escapados()<3));
    
}


MenuPrincipal::~MenuPrincipal(){

    int cant_opciones = opciones.obtener_cantidad();

    for (int i = 1; i < (cant_opciones + 1); ++i) {
        //cout << i << '\n'; // se tiene que ejecutar 7 veces
        Opcion* actual = opciones.consulta(i);
        delete actual;
    }
    
}