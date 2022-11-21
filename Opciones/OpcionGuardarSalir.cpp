#include "OpcionGuardarSalir.h"

void OpcionGuardarSalir::ejecutar( Guarderia* mi_guarderia ){ 

    cout << "Guardando..." << endl; 

    fstream archivo_guarderia(RUTA_ARCHIVO, ios::out);
 
    for ( int numero_de_animal = 1; numero_de_animal < (mi_guarderia->obtener_cantidad()+1) ; numero_de_animal++ ){ 
        
        string nombre       = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_nombre();
        int edad            = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_edad();
        string tamano       = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_tamano();
        char especie      = ESPECIE_CHAR[mi_guarderia -> obtener_animal(numero_de_animal) -> resolver_especie()-1];
        string personalidad = mi_guarderia -> obtener_animal(numero_de_animal) -> obtener_personalidad();


        archivo_guarderia << nombre << "," << edad << "," << tamano << "," << especie << "," << personalidad << endl;

    } 
 
    archivo_guarderia.close(); 

    cout << "Listo, tu registro de animales esta terminado." << endl << "Hasta la proxima!" << endl; 

} 