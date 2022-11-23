#include "OpcionElegirAnimal.h"

OpcionElegirAnimal::OpcionElegirAnimal(){
    menu_cuidar_individual = MenuCuidarIndividual();
}

void OpcionElegirAnimal:: ejecutar(Guarderia * mi_guarderia){
    menu_cuidar_individual.ejecutar(mi_guarderia);
}