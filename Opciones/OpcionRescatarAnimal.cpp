#include "OpcionRescatarAnimal.h"
#include <time.h>

void OpcionRescatarAnimal::ejecutar(Guarderia * mi_guarderia){
    Mapa* mapa = introduccion();

    int combustible_gastado = 0;
    char especie_rescatada = ' ';
    bool rescatando = true;

    while(rescatando){
        bool salida_ok = mapa->ejecutar(mi_guarderia->obtener_auto()->obtener_combustible(), combustible_gastado, especie_rescatada);

        if(!salida_ok)
            rescatando = false;

        else{        

            mi_guarderia->obtener_auto()->decrementar_combustible(combustible_gastado);

            Animal* nuevo_animal = generar_animal( mi_guarderia, especie_rescatada);

            mi_guarderia -> agregar_animal(nuevo_animal);
            cout << "Agregaste al animal: " << endl;
            nuevo_animal -> mostrar();
        }

    }

    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();
}


Animal* OpcionRescatarAnimal::generar_animal(Guarderia * mi_guarderia, char especie){

    int especie_int;

    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(ESPECIE_CHAR[i] == especie)
            especie_int = i;
    }
    
    cout << "Que bien! Rescataste un " << ESPECIE_STRING[especie_int] << endl;

    srand((unsigned int)time(nullptr));
    int edad = rand() % 101; //De 0 a 100
    string tamano = TAMANOS_STRING[rand() % 5];
    string personalidad = PERSONALIDADES[rand() % 4];
    string nombre;

    cout << "Parece tener unos " << edad << " años, su tamaño es " << tamano << " y parece " << personalidad << "." << endl;
    cout << "Qué nombre le querés poner?" << endl;


    nombre = pedir_nombre( mi_guarderia );
    
    // cin >> nombre;

    Animal* nuevo_animal = crear_nuevo_animal(especie, nombre, edad, tamano, personalidad);

    return nuevo_animal;

}


Mapa* OpcionRescatarAnimal::introduccion(){

    cout << "Ahora la reserva cuenta con un vehículo para rescatar animales!" << endl
        << "Pero el camino hasta el animal a rescatar puede ser peligroso y gastar mucho combustible, cuidado!" << endl
        << "Solo se podrán rescatar animales cuando el combustible sea suficiente" << endl << endl;

    string respuesta = "";

    while(respuesta != "si" && respuesta != "no"){

        cout << "Desea rescatar animales en un terreno personalizado? [si/no]" << endl << " >> ";
        cin >> respuesta;

    }

    Mapa* mapa;

    if(respuesta == "no")
        mapa = new Mapa();
    else{

        cout << endl << "Ingrese el nombre del terreno en la forma \"mi_terreno.csv\"" << endl;
        cin >> respuesta;
        mapa = new Mapa(respuesta);

    }

    return mapa;

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
    // Lista<string>* nombres = mi_guarderia -> obtener_lista_nombres();
    while (otro_nombre && (mi_guarderia -> nombre_existente( nombre ))){  

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

        nombre = pedir_nombre( mi_guarderia );

    } 

    return otro_nombre;

}