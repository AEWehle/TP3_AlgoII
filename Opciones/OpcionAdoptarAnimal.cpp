#include "OpcionAdoptarAnimal.h"

void OpcionAdoptarAnimal::ejecutar( Guarderia* mi_guarderia ){

    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();

    if(mi_guarderia->obtener_cantidad()==0){
        cout << "No hay animales disponibles para adoptar." << endl;
    }else{
        cout << endl << "Para adoptar un animal es necesario saber de cuánto espacio dispondrán, según eso se le mostrará una lista de los disponibles" << endl;
        cout << "Ingrese cuántos metros cuadrados tiene disponibles:" << endl;

        string espacio_string;
        float espacio;

        cin >> espacio_string;

        if(es_numero(espacio_string)){
            espacio = stof(espacio_string);
        }

        while( !es_numero(espacio_string) || espacio <= 0){
            cout << "Ingresá un espacio válido:" << endl << " >> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> espacio_string;
            if(es_numero(espacio_string))
                espacio = stof(espacio_string);
        }


        Guarderia* lista_adoptables = crear_lista_adoptables( mi_guarderia, espacio);

        if(lista_adoptables->obtener_cantidad() != 0){

            cout << endl << "Estos son los animales que podés adoptar:" << endl;

            lista_adoptables->ver_lista_de_animales();

            cout << endl << "Si desea adoptar alguno, ingrese el nombre como se muestra." << endl;
            cout << "Nuestros Erizos y Lagartijas NO SON ADOPTABLES ya que son salvajes, por lo que no aparecerán en la lista" << endl;

            int elegido = pedir_el_adoptado( mi_guarderia, lista_adoptables );

            if ( elegido != ( lista_adoptables -> obtener_cantidad()+1)  ){
                string nombre = lista_adoptables -> obtener_animal( elegido ) -> obtener_nombre();
                cout << endl << "Adoptaste a " << nombre << endl;
                int posicion_en_guarderia = mi_guarderia -> obtener_posicion( nombre );
                mi_guarderia -> obtener_animal( posicion_en_guarderia ) -> mostrar();
                mi_guarderia -> eliminar_animal( posicion_en_guarderia );
            }
        }

        else
            cout << endl << "No hay animales para adoptar para el espacio ingresado. Volviendo a menú principal..." << endl;
        
        delete lista_adoptables;
    }

}

Guarderia* OpcionAdoptarAnimal::crear_lista_adoptables(Guarderia* mi_guarderia, float espacio){

    Animal* animal_actual;
    Animal* animal_nuevo;
    Guarderia* lista_adoptables = new Guarderia;
    
    for( int numero_de_animal = 1;  numero_de_animal<= mi_guarderia->obtener_cantidad() ;  numero_de_animal++){

        animal_actual =  mi_guarderia -> obtener_animal( numero_de_animal );
        
        if ( (animal_actual -> es_adoptable()) && (tamano_ok(animal_actual, espacio))){
            animal_nuevo = crear_nuevo_animal(ESPECIE_CHAR[animal_actual->resolver_especie() - 1],
                                            animal_actual->obtener_nombre(),
                                            animal_actual->obtener_edad(),
                                            animal_actual->obtener_tamano(),
                                            animal_actual->obtener_personalidad() );
            lista_adoptables -> agregar_animal( animal_nuevo );
        }
    }

    return lista_adoptables;

}

/*  PEDIR EL ADOPTADO:
    Pide al usuario el nombre del animal que desea aoptar, o si desea cancelar.
    Devuelve la posicion del animal que desea adoptar, o la cantidad+1 si quiere cancelar*/
int OpcionAdoptarAnimal::pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* lista_adoptables ){

    string entrada = "";
    int cant_adoptables = lista_adoptables -> obtener_cantidad();
    int elegido = cant_adoptables+1;

    while ( ( elegido == (cant_adoptables +1) ) && ( string_a_mayuscula(entrada) != CANCELAR)){ 

        cout << "En caso de no querer adoptar ingrese CANCELAR, y volvera al menú inicial" << endl;
        entrada = ingresar_nombre();

        if( es_cancelar(entrada)){
            cout << "Se ha cancelado la adopción" << endl;
            elegido = cant_adoptables+1;
        }

        else{
            elegido = lista_adoptables -> obtener_posicion( entrada );
            if ( elegido == (cant_adoptables +1) ){
                cout << "El nombre ingresado no es de un animal disponble para adoptar." << endl;
            }
        }
    }

    return elegido;

}