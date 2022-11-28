#include "OpcionElegirAnimal.h"

OpcionElegirAnimal::OpcionElegirAnimal(Guarderia* mi_guarderia){
    menu_cuidar_individual = new MenuCuidarIndividual(mi_guarderia);
    volver_menu_ppal = false;
}

void OpcionElegirAnimal:: ejecutar(Guarderia * mi_guarderia){
    menu_cuidar_individual->ejecutar(mi_guarderia);
}

bool OpcionElegirAnimal::volver_menu_principal(){
    return menu_cuidar_individual->volver_menu_principal();
}

OpcionElegirAnimal::~OpcionElegirAnimal(){
    delete menu_cuidar_individual;
}