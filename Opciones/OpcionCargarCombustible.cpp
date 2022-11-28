#include "OpcionCargarCombustible.h"
#include "../Archivos_auxiliares/funciones_auxiliares.h"

 void OpcionCargarCombustible::ejecutar(Guarderia * mi_guarderia){
    cout << "Elegiste la opción 6, cargar combustible al auto." << endl << endl;
    //int aux =50;
    //mi_guarderia->obtener_auto()->decrementar_combustible(aux);
    cout << "El auto tiene: " << mi_guarderia->obtener_auto()->obtener_combustible() << " de combustible." << endl;
    cout << "¿Cuanto combustible querés agregar? Coloca un numero de 0 a " << MAX_COMBUSTIBLE << "."<< endl;

    int cant_a_cargar = pedir_cantidad_combustible();

    mi_guarderia->obtener_auto()->cargar_combustible(cant_a_cargar);

    //cout << "El auto tiene: " << mi_guarderia->obtener_auto()->obtener_combustible() << " de combustible." << endl;
    mi_guarderia->afectar_animales();
}

int OpcionCargarCombustible::pedir_cantidad_combustible(){
    cout << " >> ";
    string cant_combustible_string;
    int cant_combustible;

    cin >> cant_combustible_string;

    if(es_numero(cant_combustible_string)){
        cant_combustible = stoi(cant_combustible_string);
    }

    while( !es_numero(cant_combustible_string) || !(cant_combustible >= 0 && cant_combustible <= MAX_COMBUSTIBLE)){
        cout << "Ingresá un numero entre 0 y " << MAX_COMBUSTIBLE << ":" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> cant_combustible_string;
        if(es_numero(cant_combustible_string))
            cant_combustible = stoi(cant_combustible_string);
    }
    
    return cant_combustible;
}