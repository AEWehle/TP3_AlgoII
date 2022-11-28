#include "OpcionListarAnimales.h"


void OpcionListarAnimales::ejecutar(Guarderia * mi_guarderia){
    cout << "Elegiste la opción 1, lista los animales en la reserva" << endl << endl;
    mi_guarderia->ver_diccionario_de_animales();

    mi_guarderia->afectar_animales();
    
    mi_guarderia->obtener_auto()->cargar_combustible();
}