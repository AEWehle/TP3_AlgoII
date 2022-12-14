#include "OpcionGuardarSalir.h"

void OpcionGuardarSalir::ejecutar( Guarderia* mi_guarderia ){ 

    cout << "      Guardando..." << endl<< endl; 

    fstream archivo_guarderia(RUTA_ARCHIVO, ios::out);
    Lista<string> * nombres = mi_guarderia -> obtener_lista_nombres();
    string nombre;
    int edad;
    string tamano;
    char especie;
    string personalidad;

    for ( int numero_de_animal = 1; numero_de_animal < (mi_guarderia->obtener_cantidad()+1) ; numero_de_animal++ ){ 
        
        nombre = *nombres -> consulta ( numero_de_animal );
        edad            = mi_guarderia -> obtener_animal( nombre ) -> obtener_edad();
        tamano       = mi_guarderia -> obtener_animal( nombre ) -> obtener_tamano();
        especie        = ESPECIE_CHAR[mi_guarderia -> obtener_animal( nombre ) -> resolver_especie()-1];
        personalidad = mi_guarderia -> obtener_animal( nombre ) -> obtener_personalidad();


        archivo_guarderia << nombre << "," << edad << "," << tamano << "," << especie << "," << personalidad << endl;

    } 
 
    archivo_guarderia.close(); 
    for ( int n_animal = 1; n_animal <= mi_guarderia -> obtener_cantidad() ; n_animal++){
        cout << "      Chau " << *mi_guarderia -> obtener_lista_nombres() -> consulta( n_animal ) << endl;
    }
    cout << endl << "      Listo, tu registro de animales esta terminado." << endl;
    cout << "      Hasta la proxima!" << endl << endl;
    cout << "****************************************************************************" << endl << endl; 

} 