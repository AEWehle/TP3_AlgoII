#include "OpcionCuidarAnimales.h"

OpcionCuidarAnimales::OpcionCuidarAnimales(){
 
}

void OpcionCuidarAnimales::ejecutar(Guarderia *mi_guarderia){
    mi_guarderia -> obtener_auto() -> cargar_combustible();

    menu_cuidar = new MenuCuidar(mi_guarderia);
    menu_cuidar -> ejecutar(mi_guarderia);
    
    delete menu_cuidar;
}