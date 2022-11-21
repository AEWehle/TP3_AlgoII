#include "OpcionCuidarAnimales.h"

OpcionCuidarAnimales::OpcionCuidarAnimales(){
    menu_cuidar = MenuCuidar();
}

void OpcionCuidarAnimales::ejecutar(Guarderia *mi_guarderia){
    menu_cuidar.ejecutar();

}