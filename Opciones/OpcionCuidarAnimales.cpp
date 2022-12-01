#include "OpcionCuidarAnimales.h"

OpcionCuidarAnimales::OpcionCuidarAnimales(){

}

void OpcionCuidarAnimales::ejecutar(Guarderia *mi_guarderia){
    cout << "      Elegiste la opcion 4, Cuidar animales, podés alimentarlos y bañarlos!."<< endl<< endl;
    mi_guarderia -> obtener_auto() -> cargar_combustible();

    menu_cuidar = new MenuCuidar(mi_guarderia);
    menu_cuidar -> ejecutar(mi_guarderia);
    
    delete menu_cuidar;
}