#include "MenuCuidarIndividual.h"

using namespace std;

// const int CANTIDAD_OPCIONES_PPAL = 7;


MenuCuidarIndividual::MenuCuidarIndividual( Guarderia* mi_guarderia ){
    lista_nombres = mi_guarderia -> obtener_lista_nombres();
    numero_de_animal = 1;   
    nombre_animal = *lista_nombres -> consulta( numero_de_animal );
    volver_menu_ppal = false;

}

void MenuCuidarIndividual::mostrar()
{
   cout << endl << "¿Qué querés hacer con él?" << endl;
    cout << "      Ingresá el número de la opción deseada." << endl;
    cout << "         1. Alimentar Animal" << endl;
    cout << "         2. Duchar Animal" << endl;
    cout << "         3. Pasar a Animal siguiente" << endl;
    cout << "         4. Volver a Menu Principal" << endl;
}

void MenuCuidarIndividual::ejecutar_opcion(int eleccion, Guarderia* mi_guarderia)
{
    switch (eleccion) {
        case 1:
            mi_guarderia->obtener_animal(nombre_animal)->alimentar();
            break;
        case 2:
            mi_guarderia -> obtener_animal(nombre_animal)->duchar();
            break;
        case 3:
            numero_de_animal ++ ;
            if (!(numero_de_animal > lista_nombres->obtener_cantidad())) {
                nombre_animal = *lista_nombres -> consulta( numero_de_animal ) ;
            }else {
                std::cout << "      No hay más animales en la lista, volviendo a menú anterior..." << std::endl ;
                volver_menu_ppal = true;
                //return;    
            }
            break;
        case 4:
            std::cout << "      Volviendo a menú principal..." << std::endl ;
            volver_menu_ppal = true;
            //return;
            break;
        default:
            std::cout << "      Opcion Invalida, ingresa nuevamente." << std::endl ;
            eleccion = pedir_eleccion(4);
    }
}

void MenuCuidarIndividual::ejecutar(Guarderia* mi_guarderia) { 
    int eleccion;

    while((numero_de_animal <= lista_nombres->obtener_cantidad()) && !volver_menu_ppal){
        mi_guarderia -> obtener_animal(nombre_animal) -> mostrar(); 
        mostrar();
        eleccion = pedir_eleccion(4);
        ejecutar_opcion(eleccion, mi_guarderia);
    }

}

bool MenuCuidarIndividual::volver_menu_principal(){
    return volver_menu_ppal;
}

MenuCuidarIndividual::~MenuCuidarIndividual(){

    
}
