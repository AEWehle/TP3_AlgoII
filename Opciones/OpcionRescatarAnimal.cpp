#include "OpcionRescatarAnimal.h"

void OpcionRescatarAnimal::ejecutar(Guarderia * mi_guarderia){
    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();

    cout << endl << "Rescataste un animal?" << endl;
    cout << endl << "Cómo se llama?" << endl;
    cout << " >> ";
    string nombre = pedir_nombre();

    if ( !otro_nombre( mi_guarderia, nombre )){
        cout << "Rescate cancelado." << endl;
        return;
    }

    int edad = pedir_edad();
    string tamano = pedir_tamano(); 
    char especie = ESPECIE_CHAR[pedir_especie()];
    string personalidad = PERSONALIDADES[pedir_personalidad()];

    Animal* nuevo_animal = crear_nuevo_animal(especie, nombre, edad, tamano, personalidad);

    mi_guarderia -> agregar_animal(nuevo_animal);

    cout << endl << nombre << " fue rescatado!" << endl << endl;
    //mi_guarderia -> obtener_animal( mi_guarderia -> obtener_cantidad() ) -> mostrar();
}


int OpcionRescatarAnimal::pedir_edad(){ 

    cout << endl << "Cuántos años tiene?" << endl << " >> ";
    int edad;  
    string edad_st;
    bool edad_valida = true;

    cin >> edad_st;
    edad_valida = validar_edad(edad_st, edad);
    
    while( !edad_valida ){ 
        cout << "Tiene que ser entre 0 y "<< EDAD_MAX << ", volvé a ingresar la edad:" << endl << " >> "; 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> edad_st;
        edad_valida = validar_edad(edad_st, edad);
    } 

    return edad;

} 


string OpcionRescatarAnimal::pedir_tamano(){ 

    cout << endl << "Qué tamaño tiene?" << endl 
    << "Elegí de entre los siguientes según el espacio que necesite:" << endl << endl

    << "1 - Diminuto -> menos de 2 m^2" << endl
    << "2 - Pequeño  -> menos de 10 m^2" << endl
    << "3 - Mediano  -> 10 m^2 o más" << endl
    << "4 - Grande   -> 20 m^2 o más" << endl
    << "5 - Gigante  -> 50 m^2 o más" << endl << endl << " >> ";

    string tamano_string;
    int tamano;

    cin >> tamano_string;

    if(es_numero(tamano_string)){
        tamano = stoi(tamano_string);
    }

    while( !es_numero(tamano_string) || !(tamano >= 1 && tamano <= 5)){
        cout << "Ingresá el número correspondiente a una categoría:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> tamano_string;
        if(es_numero(tamano_string))
            tamano = stoi(tamano_string);
    }

    return TAMANOS_STRING[ tamano-1];

}


int OpcionRescatarAnimal::pedir_especie(){ 

    cout << endl << "De qué especie es?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Perro" << endl
    << "2 - Gato" << endl
    << "3 - Caballo" << endl
    << "4 - Roedor" << endl
    << "5 - Conejo" << endl
    << "6 - Erizo" << endl
    << "7 - Lagartija" << endl << endl << " >> ";
    
    string especie_string;
    int especie;

    cin >> especie_string;

    if(es_numero(especie_string)){
        especie = stoi(especie_string);
    }

    while( !es_numero(especie_string) || !(especie >= 1 && especie <= 7)){
        cout << "Ingresá el número correspondiente a una especie:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> especie_string;
        if(es_numero(especie_string))
            especie = stoi(especie_string);
    }
    
    return especie-1;

}



int OpcionRescatarAnimal::pedir_personalidad(){

    cout << endl << "Qué personalidad tiene?" << endl 
    << "Elegí de entre las siguientes:" << endl << endl

    << "1 - Dormilón" << endl
    << "2 - Juguetón" << endl
    << "3 - Sociable" << endl
    << "4 - Travieso" << endl << endl << " >> ";
    
    string personalidad_string;
    int personalidad;

    cin >> personalidad_string;

    if(es_numero(personalidad_string)){
        personalidad = stoi(personalidad_string);
    }

    while( !es_numero(personalidad_string) || !(personalidad >= 1 && personalidad <= 4)){
        cout << "Ingresá el número correspondiente a una personalidad:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> personalidad_string;
        if(es_numero(personalidad_string))
            personalidad = stoi(personalidad_string);
    }
    
    return personalidad-1;

}


bool OpcionRescatarAnimal::otro_nombre( Guarderia* mi_guarderia, string & nombre ){

    int opcion;
    bool otro_nombre = true;

    while (otro_nombre && (mi_guarderia->obtener_posicion(nombre) != (mi_guarderia -> obtener_cantidad() + 1))){  

        cout << "Este nombre ya lo tiene otro animal! Podés elegir otro nombre o volver al menú." << endl
             << "Para elegir otro nombre ingresá 1, para volver al menú ingresá 2:" << endl << " >> ";

        cin >> opcion;

        while( opcion != 1 && opcion != 2 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingresá 1 para elegir otro nombre o 2 para volver al menú:" << endl << " >> ";
            cin >> opcion;
        }

        if (opcion == 2)
            otro_nombre = false;

        nombre = pedir_nombre();

    } 

    return otro_nombre;

}