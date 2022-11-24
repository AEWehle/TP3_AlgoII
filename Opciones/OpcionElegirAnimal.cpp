#include "OpcionElegirAnimal.h"

OpcionElegirAnimal::OpcionElegirAnimal(Guarderia* mi_guarderia){
    MenuCuidarIndividual* menu_cuidar_individual = new MenuCuidarIndividual(mi_guarderia);
}

void OpcionElegirAnimal:: ejecutar(Guarderia * mi_guarderia){
    menu_cuidar_individual -> ejecutar(mi_guarderia);
}