#include "MenuPrincipal.h"

using namespace std;

//const int CANTIDAD_OPCIONES_PPAL = 7;

//OpcionListarAnimales* opcion_listar, OpcionRescatarAnimal* opcion_rescatar, OpcionBuscarAnimal* opcion_buscar,OpcionCuidarAnimales* opcion_cuidar, OpcionAdoptarAnimal* opcion_adoptar, OpcionCargarCombustible* opcion_cargar_combustible, OpcionGuardarSalir* opcion_guardar


MenuPrincipal::MenuPrincipal(){

    OpcionListarAnimales* opcion_listar = new OpcionListarAnimales;
    OpcionRescatarAnimal* opcion_rescatar = new OpcionRescatarAnimal;
    OpcionBuscarAnimal* opcion_buscar = new OpcionBuscarAnimal;
    OpcionCuidarAnimales* opcion_cuidar = new OpcionCuidarAnimales;
    OpcionAdoptarAnimal* opcion_adoptar = new OpcionAdoptarAnimal;
    OpcionCargarCombustible* opcion_cargar_combustible = new OpcionCargarCombustible;
    OpcionGuardarSalir* opcion_guardar = new OpcionGuardarSalir;

    //OpcionListarAnimales opcion_listar = OpcionListarAnimales();
    //OpcionRescatarAnimal opcion_rescatar = OpcionRescatarAnimal();
    //OpcionBuscarAnimal opcion_buscar = OpcionBuscarAnimal();
    //OpcionCuidarAnimales opcion_cuidar = OpcionCuidarAnimales();
    //OpcionAdoptarAnimal opcion_adoptar = OpcionAdoptarAnimal();
    //OpcionCargarCombustible opcion_cargar_combustible = OpcionCargarCombustible();
    //OpcionGuardarSalir opcion_guardar = OpcionGuardarSalir();

    Lista<Opcion> opciones;
    opciones.alta(opcion_listar, 1);
    opciones.alta(opcion_rescatar, 2);
    opciones.alta(opcion_buscar, 3);
    opciones.alta(opcion_cuidar, 4);
    opciones.alta(opcion_adoptar, 5);
    opciones.alta(opcion_cargar_combustible, 6);
    opciones.alta(opcion_guardar, 7);
    
}

void MenuPrincipal::mostrar(){
    cout << endl << "*****   MENU   *****" << endl << endl;
    cout << "   1. Listar animales." << endl; 
    cout << "   2. Rescatar un animal." << endl; 
    cout << "   3. Buscar un animal." << endl;
    cout << "   4. Cuidar animales." << endl;
    cout << "   5. Adoptar un animal." << endl;
    cout << "   6. Cargar Combustible." << endl;
    cout << "   7. Guardar y salir." << endl << endl;

}

void MenuPrincipal::ejecutar_opcion(int eleccion, Guarderia *mi_guarderia){
    opciones.consulta(eleccion+1)->ejecutar(mi_guarderia);
    
}

void MenuPrincipal::ejecutar(){
    mostrar();
    
}

MenuPrincipal::~MenuPrincipal(){

}