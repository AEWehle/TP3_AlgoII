#include "OpcionAdoptarAnimal.h"


void OpcionAdoptarAnimal::ejecutar( Guarderia* mi_guarderia ){

    cout << "      Elegiste la opción 5, adoptar una animal de la reserva." << endl<< endl;
    if(mi_guarderia->obtener_cantidad()==0)
        cout << "      No hay animales disponibles para adoptar." << endl;

    else{

        float espacio = pedir_espacio();
        Guarderia* animales_adoptables = crear_lista_adoptables( mi_guarderia, espacio );

        if( animales_adoptables -> obtener_cantidad() != 0){

            cout << endl << "      Estos son los animales que podés adoptar:" << endl;

            Lista<string>* nombres_ordenados_edad = animales_adoptables -> obtener_lista_viejo_a_joven();
            animales_adoptables -> ver_los_animales( nombres_ordenados_edad );

            cout << endl << "      Si desea adoptar alguno, ingrese el nombre de animal como se muestra." << endl;
            cout << "      Nuestros Erizos y Lagartijas NO SON ADOPTABLES ya que son salvajes, por lo que no aparecerán en la lista" << endl;
            string elegido = pedir_el_adoptado( mi_guarderia, animales_adoptables );

            if ( !es_cancelar(elegido)  ){
                cout << endl << "      Adoptaste a " << elegido << endl;
                
                mi_guarderia -> obtener_animal( elegido ) -> mostrar();
                mi_guarderia -> eliminar_animal( elegido );
            }

        }

        else
            cout << endl << "      No hay animales para adoptar para el espacio ingresado. Volviendo a menú principal..." << endl;
        
        delete animales_adoptables;

    }

    cout << endl << endl ;

    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();

}


Guarderia* OpcionAdoptarAnimal::crear_lista_adoptables(Guarderia* mi_guarderia, float espacio){

    Animal* animal_actual;
    Animal* animal_nuevo;
    Guarderia* lista_adoptables = new Guarderia;
    Lista<string>* nombres = mi_guarderia -> obtener_lista_nombres();

    for( int numero_de_animal = 1;  numero_de_animal <= mi_guarderia -> obtener_cantidad() ;  numero_de_animal++){

        animal_actual =  mi_guarderia -> obtener_animal( *nombres -> consulta( numero_de_animal ) );
        
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


string OpcionAdoptarAnimal::pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* diccionario_adoptables ){
    
    string entrada = "";

    bool adopto = false;

    do{ 

        cout << "      En caso de no querer adoptar ingrese CANCELAR, y volvera al menú inicial" << endl<< " >> ";
        entrada = ingresar_nombre();

        if( es_cancelar(entrada))
            cout << "      Se ha cancelado la adopción" << endl;

        else{
            if ( !diccionario_adoptables -> nombre_existente( entrada )  )
                cout << "      El nombre ingresado no es de un animal disponble para adoptar." << endl;

            else
                adopto = true;
        }

    }

    while( !es_cancelar(entrada) && !adopto );

    return entrada;

}


float OpcionAdoptarAnimal:: pedir_espacio(){

    cout << endl << "      Para adoptar un animal es necesario saber de cuánto espacio dispondrán, según eso se le mostrará una lista de los disponibles" << endl;
    cout << "      Ingrese cuántos metros cuadrados tiene disponibles:" << endl << " >> ";

    string espacio_string;
    float espacio;

    cin >> espacio_string;

    if(es_numero(espacio_string))
        espacio = stof(espacio_string);


    while( !es_numero(espacio_string) || espacio <= 0){

        cout << "      Ingresá un espacio válido:" << endl << " >> ";
        cin.clear();
        cin.ignore();
        cin >> espacio_string;
        if(es_numero(espacio_string))
            espacio = stof(espacio_string);
    }

    return espacio;
    
}