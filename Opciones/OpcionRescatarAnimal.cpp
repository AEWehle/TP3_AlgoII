#include "OpcionRescatarAnimal.h"
#include <time.h>
#include <limits>
#include <dirent.h>

void OpcionRescatarAnimal::ejecutar(Guarderia * mi_guarderia){

    cout << "      Elegiste la opcion 2, rescatar un animal."<< endl<< endl;

    int combustible_disponible = mi_guarderia->obtener_auto()->obtener_combustible();

    if(combustible_disponible == 0){
        cout << "      No hay nada de combustible! Se cancela el rescate." << endl;
    }

    Mapa* mapa = introduccion();

    int combustible_gastado = 0, rescatados = 0;
    char especie_rescatada = ' ';
    bool rescatando = true, combustible_suficiente;

    while(rescatando && rescatados < 5){

        combustible_suficiente = true;

        bool salida_ok = mapa->ejecutar(combustible_disponible, combustible_gastado, especie_rescatada, combustible_suficiente);

        if(!salida_ok){
            cout << "      Rescate cancelado!" << endl << endl;
            rescatando = false;
        }

        else if(combustible_suficiente){        

            mi_guarderia->obtener_auto()->decrementar_combustible(combustible_gastado);

            combustible_disponible = mi_guarderia->obtener_auto()->obtener_combustible();

            Animal* nuevo_animal = generar_animal( mi_guarderia, especie_rescatada);

            mi_guarderia -> agregar_animal(nuevo_animal);
            cout << "      Agregaste al animal: " << endl;
            nuevo_animal -> mostrar();
            rescatados++;

            cout << "      En este rescate se gastaron " << combustible_gastado << " de combustible, quedan " << mi_guarderia->obtener_auto()->obtener_combustible() << "." << endl;

        }

        if(rescatados == 5){
            mapa->mostrar();
            cout << "      Felicidades! Rescataste a todos los animales de la zona, volvamos al refugio." << endl << endl;
        }

    }

    mi_guarderia->afectar_animales();
    mi_guarderia->obtener_auto()->cargar_combustible();
    delete mapa;

}


Animal* OpcionRescatarAnimal::generar_animal(Guarderia * mi_guarderia, char especie){

    int especie_int;

    for(int i = 0; i < CANTIDAD_ESPECIES; i++){
        if(ESPECIE_CHAR[i] == especie)
            especie_int = i;
    }
    
    cout << "      Que bien! Rescataste un " << ESPECIE_STRING[especie_int] << endl;

    srand((unsigned int)time(nullptr));
    int edad = rand() % 101; //De 0 a 100
    string tamano = TAMANOS_STRING[rand() % 5];
    string personalidad = PERSONALIDADES[rand() % 4];
    string nombre;

    cout << "      Parece tener unos " << edad << " a??os, su tama??o es " << tamano << " y parece " << personalidad << "." << endl;
    cout << "      Qu?? nombre le quer??s poner?" << endl << " >> ";

    nombre = pedir_nombre( mi_guarderia );

    Animal* nuevo_animal = crear_nuevo_animal(especie, nombre, edad, tamano, personalidad);

    return nuevo_animal;

}


void  mostrar_lista_mapas(){

    cout << "      Para cargar nuevos mapas solo tenes que cargar el archivo con el nombre deseado en formato 'csv' a la carpeta 'mis_mapas'." << endl;
    cout << "      Los mapas disponibles son:" << endl;

    DIR* carpeta_mapas = opendir( "mis_mapas" );

    if( ( carpeta_mapas != nullptr ) ){

        string nombre_mapa;
        struct dirent *diread;
        diread = readdir( carpeta_mapas );

        while( ( diread != nullptr) ){
            nombre_mapa = diread -> d_name;
            if ( es_csv( nombre_mapa ) ){
                cout << "          -  " << nombre_mapa.substr(0, nombre_mapa.length()-4) << endl;
                }
            diread = readdir( carpeta_mapas );
        }
        
        closedir( carpeta_mapas );

    }

    else 
        cout << "No se encuentra el directorio de mapas" << endl;

}


Mapa* OpcionRescatarAnimal::introduccion(){

    cout << "      Ahora la reserva cuenta con un veh??culo para rescatar animales!" << endl
        << "      Pero el camino hasta el animal a rescatar puede ser peligroso y gastar mucho combustible, cuidado!" << endl
        << "      Solo se podr??n rescatar animales cuando el combustible sea suficiente" << endl << endl;

    string respuesta = "";
    bool respuesta_ok = false;

    cout << "      Desea rescatar animales en un terreno personalizado? [si/no]" << endl;

    while(!respuesta_ok){

        cout << " >> " ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> respuesta;

        if(respuesta != "si" && respuesta != "no")
            cout << "      Ingrese \"si\" o \"no\":" << endl;
        else
            respuesta_ok = true;

    }

    Mapa* mapa;

    if( string_a_mayuscula( respuesta ) == "NO")
        mapa = new Mapa();
    
    else{

        mostrar_lista_mapas();
        cout << endl << "      Ingrese el nombre del terreno:" << endl << " >> ";
        cin >> respuesta;
        mapa = new Mapa(respuesta);

    }

    return mapa;

}


int OpcionRescatarAnimal::pedir_edad(){ 

    cout << endl << "      Cu??ntos a??os tiene?" << endl << " >> ";
    int edad;  
    string edad_st;
    bool edad_valida = true;

    cin >> edad_st;
    edad_valida = validar_edad(edad_st, edad);
    
    while( !edad_valida ){ 

        cout << "      Tiene que ser entre 0 y "<< EDAD_MAX << ", volv?? a ingresar la edad:" << endl << " >> "; 
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> edad_st;
        edad_valida = validar_edad(edad_st, edad);

    } 

    return edad;

} 


string OpcionRescatarAnimal::pedir_tamano(){ 

    cout << endl << "      Qu?? tama??o tiene?" << endl 
    << "      Eleg?? de entre los siguientes seg??n el espacio que necesite:" << endl << endl

    << "      1 - Diminuto -> menos de 2 m^2" << endl
    << "      2 - Peque??o  -> menos de 10 m^2" << endl
    << "      3 - Mediano  -> 10 m^2 o m??s" << endl
    << "      4 - Grande   -> 20 m^2 o m??s" << endl
    << "      5 - Gigante  -> 50 m^2 o m??s" << endl << endl << " >> ";

    string tamano_string;
    int tamano;

    cin >> tamano_string;

    if(es_numero(tamano_string)){
        tamano = stoi(tamano_string);
    }

    while( !es_numero(tamano_string) || !(tamano >= 1 && tamano <= 5)){

        cout << "      Ingres?? el n??mero correspondiente a una categor??a:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> tamano_string;
        if(es_numero(tamano_string))
            tamano = stoi(tamano_string);

    }

    return TAMANOS_STRING[ tamano-1];

}


int OpcionRescatarAnimal::pedir_especie(){ 

    cout << endl << "De qu?? especie es?" << endl 
    << "      Eleg?? de entre las siguientes:" << endl << endl

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

    if(es_numero(especie_string))
        especie = stoi(especie_string);


    while( !es_numero(especie_string) || !(especie >= 1 && especie <= 7)){
        cout << "      Ingres?? el n??mero correspondiente a una especie:" << endl << " >> ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> especie_string;
        if(es_numero(especie_string))
            especie = stoi(especie_string);
    }
    
    return especie-1;

}


int OpcionRescatarAnimal::pedir_personalidad(){

    cout << endl << "      Qu?? personalidad tiene?" << endl 
    << "      Eleg?? de entre las siguientes:" << endl << endl

    << "1 - Dormil??n" << endl
    << "2 - Juguet??n" << endl
    << "3 - Sociable" << endl
    << "4 - Travieso" << endl << endl << " >> ";
    
    string personalidad_string;
    int personalidad;

    cin >> personalidad_string;

    if(es_numero(personalidad_string))
        personalidad = stoi(personalidad_string);


    while( !es_numero(personalidad_string) || !(personalidad >= 1 && personalidad <= 4)){

        cout << "      Ingres?? el n??mero correspondiente a una personalidad:" << endl << " >> ";
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
    
    while (otro_nombre && (mi_guarderia -> nombre_existente( nombre ))){  

        cout << "      Este nombre ya lo tiene otro animal! Pod??s elegir otro nombre o volver al men??." << endl
             << "      Para elegir otro nombre ingres?? 1, para volver al men?? ingres?? 2:" << endl << " >> ";

        cin >> opcion;

        while( opcion != 1 && opcion != 2 ){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "      Ingres?? 1 para elegir otro nombre o 2 para volver al men??:" << endl << " >> ";
            cin >> opcion;
        }

        if (opcion == 2)
            otro_nombre = false;

        nombre = pedir_nombre( mi_guarderia );

    } 

    return otro_nombre;

}