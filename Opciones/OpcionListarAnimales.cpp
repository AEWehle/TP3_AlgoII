#include "OpcionListarAnimales.h"


void OpcionListarAnimales::ejecutar(Guarderia * mi_guarderia){
    //mi_guarderia->afectar_animales();
    
    mi_guarderia->obtener_auto()->cargar_combustible();

    mi_guarderia->ver_diccionario_de_animales();
}