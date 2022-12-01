#include "OpcionBuscarAnimal.h"
#include "../funciones_main.h"


void OpcionBuscarAnimal::ejecutar(Guarderia * mi_guarderia){

    cout << "      Elegiste la opción 3, buscar un animal de la reserva." << endl << endl;
    if (mi_guarderia->obtener_cantidad() == 0) 
        cout << "      No hay animales para buscar." << endl;   
    
    else{

        string nombre;
        cout << "      Ingrese el nombre del animal que busca:" << endl << " >> ";
        nombre = ingresar_nombre( );

        if( ! mi_guarderia -> nombre_existente(nombre) ) 
            cout << nombre << " no se encuentra en la guardería." << endl << endl;
        
        else{
            cout << "      SI! " << nombre << " está en la guardería: " << endl ;
            mi_guarderia -> obtener_animal( nombre )->mostrar();
        }  

    }

    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();

}