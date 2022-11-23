#include "MenuCuidarIndividual.h"

using namespace std;

// const int CANTIDAD_OPCIONES_PPAL = 7;


MenuCuidarIndividual::MenuCuidarIndividual(){
    animal = 1;   

}

void MenuCuidarIndividual::mostrar()
{
   cout << endl << "¿Qué querés hacer con él?" << endl;
    cout << "Ingresá el número de la opción deseada." << endl;
    cout << "   1. Alimentar Animal" << endl;
    cout << "   2. Duchar Animal" << endl;
    cout << "   3. Pasar a Animal siguiente" << endl;
    cout << "   4. Volver a Menu Anterior" << endl;
}

void MenuCuidarIndividual::ejecutar_opcion(int eleccion, Guarderia* mi_guarderia)
{
    switch (eleccion) {
        case 1:
            mi_guarderia->obtener_animal(animal)->alimentar();
            break;
        case 2:
            mi_guarderia->obtener_animal(animal)->duchar();
            break;
        case 3:
            ++animal;
            break;
        case 4:
            return;
            break;
        default:
            std::cout << "Opcion Invalida, ingresa nuevamente." << std::endl ;
            eleccion = pedir_eleccion(4);
    }
}

void MenuCuidarIndividual::ejecutar(Guarderia* mi_guarderia) { 
    int eleccion;
    do{
        mi_guarderia->obtener_animal(animal);
        mostrar(); 
        eleccion = pedir_eleccion(4);
        ejecutar_opcion(eleccion, mi_guarderia);
    }while((animal <= mi_guarderia->obtener_cantidad()) && (eleccion != 4));

    if (animal > mi_guarderia->obtener_cantidad()) {
        std::cout << "Opcion Invalida, ingresa nuevamente." << std::endl ;
    }

}

MenuCuidarIndividual::~MenuCuidarIndividual(){
    
}