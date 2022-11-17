#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include <time.h>
#include "Archivos_auxiliares/funciones_auxiliares.h"
#include "Auto.h"
#include "Guarderia.h"
#include "opciones.h"
using namespace std;

/* afectar_animal()
Esta función disminuye la higiene y aumenta el hambre de todos los 
animales de la lista */

void afectar_animales(Guarderia* mi_guarderia){

    for(int i = 1; i <= mi_guarderia->obtener_cantidad(); i++) {
       mi_guarderia->obtener_animal(i)->ensuciar();
       mi_guarderia->obtener_animal(i)->dar_hambre();

       /*if(mi_guarderia->obtener_animal(i)->obtener_higiene()==0 || mi_guarderia->obtener_animal(i)->obtener_hambre()==100){
            mi_guarderia->eliminar_animal(i);
            //Acá hay que ver si ponemos algo en guarderia que guarde los escapados
            //pero seria un :
            //int escapados += 1;
       }*/ 
    }

}

void afectar_combustible(Guarderia* mi_guarderia){
    mi_guarderia->obtener_auto()->cargar_combustible();
}


/*************************************** FUNCIONES DE LA OPCION 1 ***************************************/ 
// Listar animales

void listar_animales( Guarderia* mi_guarderia ){

    afectar_animales(mi_guarderia);
    afectar_combustible(mi_guarderia);
    
    mi_guarderia->ver_lista_de_animales();

}
 
 
/*************************************** FUNCIONES DE LA OPCION 2 ***************************************/ 
//Rescatar animal


string ingresar_nombre(){ 

    string nombre; 

    while ( nombre.length() == 0 ){ 
        getline( cin, nombre, '\n' ); 
    } 

    return nombre; 
}


bool es_cancelar(string nombre){
    return (string_a_mayuscula(nombre) == CANCELAR);
}

string pedir_nombre(){
    string nombre = ingresar_nombre();

    while(es_cancelar(nombre)) {
        cout << "Este nombre no puede ser usado, deberías elegir otro:" << endl;
        cout << " >> ";
        nombre = ingresar_nombre();
    }

    return nombre;
}


int buscar_nombre (Guarderia* mi_guarderia, string animal_buscado){

    return mi_guarderia->obtener_posicion(animal_buscado);

}


bool validar_edad(string edad_st, int &edad){

    bool edad_valida = es_numero(edad_st);

    if(edad_valida){
        edad = stoi(edad_st);
        edad_valida = (edad >= 0 && edad <= EDAD_MAX);
    }

    return edad_valida;

}


int pedir_edad(){ 

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


string pedir_tamano(){ 

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


int pedir_especie(){ 

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


int pedir_personalidad(){

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
 

/* Le pregunta al usuario si desea reescrbir el nombre si este ya existe en la guarderia o volver.
En caso de reescibir se guarda cuando que sea un nombre nuevo y devuelve true
En caso de queres salir devuelve false*/
bool otro_nombre( Guarderia* mi_guarderia, string & nombre ){

    int opcion;
    bool otro_nombre = true;

    while (otro_nombre && (buscar_nombre( mi_guarderia, nombre ) != (mi_guarderia -> obtener_cantidad() + 1))){  

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


char** crear_mapa_vacio(){

    char** mapa = new char*[8];
    for(int i = 0; i < 8; i++)
        mapa[i] = new char[8];

    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            mapa[i][j] = ' ';
        }
    }

    return mapa;

}


void animales_aleatorios(char** &mapa){ //Reemplaza 5 de los espacios por chars correspondientes a especies

    int creados = 0;
    int i;
    int j;

    mapa[0][0] = 'A';

    while(creados < 5){

        srand((unsigned int)time(nullptr));
        i = rand() % 8;
        srand((unsigned int)time(nullptr));
        j = rand() % 8;
        if(mapa[i][j] == ' '){
            srand((unsigned int)time(nullptr));
            mapa[i][j] = ESPECIE_CHAR[rand() % 7];  //Especie random de las programadas
            creados++;
        }

    }

}


void mostrar_mapa(char** mapa){

    cout    
    //fila1
    << ESC << CAMINO << " " << mapa[0][0] << " " << RESET << ESC << PRECIPICIO << " " << mapa[0][1] << " " << RESET
    << ESC << TIERRA << " " << mapa[0][2] << " " << RESET << ESC << TIERRA << " " << mapa[0][3] << " " << RESET
    << ESC << TIERRA << " " << mapa[0][4] << " " << RESET << ESC << TIERRA << " " << mapa[0][5] << " " << RESET
    << ESC << TIERRA << " " << mapa[0][6] << " " << RESET << ESC << TIERRA << " " << mapa[0][7] << " " << RESET << endl;
    
    cout
    //fila2
    << ESC << CAMINO << " " << mapa[1][0] << " " << RESET << ESC << TIERRA << " " << mapa[1][1] << " " << RESET
    << ESC << TIERRA << " " << mapa[1][2] << " " << RESET << ESC << TIERRA << " " << mapa[1][3] << " " << RESET
    << ESC << PRECIPICIO << " " << mapa[1][4] << " " << RESET << ESC << PRECIPICIO << " " << mapa[1][5] << " " << RESET
    << ESC << PRECIPICIO << " " << mapa[1][6] << " " << RESET << ESC << PRECIPICIO << " " << mapa[1][7] << " " << RESET << endl;

    cout
    //fila3
    << ESC << CAMINO << " " << mapa[2][0] << " " << RESET << ESC << CAMINO << " " << mapa[2][1] << " " << RESET
    << ESC << CAMINO << " " << mapa[2][2] << " " << RESET << ESC << CAMINO << " " << mapa[2][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[2][4] << " " << RESET << ESC << TIERRA << " " << mapa[2][5] << " " << RESET
    << ESC << MONTANA << " " << mapa[2][6] << " " << RESET << ESC << MONTANA << " " << mapa[2][7] << " " << RESET << endl;

    cout
    //fila4
    << ESC << TIERRA << " " << mapa[3][0] << " " << RESET << ESC << TIERRA << " " << mapa[3][1] << " " << RESET
    << ESC << TIERRA << " " << mapa[3][2] << " " << RESET << ESC << TIERRA << " " << mapa[3][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[3][4] << " " << RESET << ESC << TIERRA << " " << mapa[3][5] << " " << RESET
    << ESC << MONTANA << " " << mapa[3][6] << " " << RESET << ESC << MONTANA << " " << mapa[3][7] << " " << RESET << endl;

    cout
    //fila5
    << ESC << MONTANA << " " << mapa[4][0] << " " << RESET << ESC << MONTANA << " " << mapa[4][1] << " " << RESET
    << ESC << MONTANA << " " << mapa[4][2] << " " << RESET << ESC << TIERRA << " " << mapa[4][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[4][4] << " " << RESET << ESC << TIERRA << " " << mapa[4][5] << " " << RESET
    << ESC << MONTANA << " " << mapa[4][6] << " " << RESET << ESC << MONTANA << " " << mapa[4][7] << " " << RESET << endl;

    cout
    //fila6
    << ESC << TIERRA << " " << mapa[5][0] << " " << RESET << ESC << TIERRA << " " << mapa[5][1] << " " << RESET
    << ESC << TIERRA << " " << mapa[5][2] << " " << RESET << ESC << TIERRA << " " << mapa[5][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[5][4] << " " << RESET << ESC << TIERRA << " " << mapa[5][5] << " " << RESET
    << ESC << MONTANA << " " << mapa[5][6] << " " << RESET << ESC << MONTANA << " " << mapa[5][7] << " " << RESET << endl;

    cout
    //fila7
    << ESC << TIERRA << " " << mapa[6][0] << " " << RESET << ESC << PRECIPICIO << " " << mapa[6][1] << " " << RESET
    << ESC << PRECIPICIO << " " << mapa[6][2] << " " << RESET << ESC << PRECIPICIO << " " << mapa[6][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[6][4] << " " << RESET << ESC << TIERRA << " " << mapa[6][5] << " " << RESET
    << ESC << MONTANA << " " << mapa[6][6] << " " << RESET << ESC << MONTANA << " " << mapa[6][7] << " " << RESET << endl;

    cout
    //fila8
    << ESC << TIERRA << " " << mapa[7][0] << " " << RESET << ESC << TIERRA << " " << mapa[7][1] << " " << RESET
    << ESC << TIERRA << " " << mapa[7][2] << " " << RESET << ESC << TIERRA << " " << mapa[7][3] << " " << RESET
    << ESC << CAMINO << " " << mapa[7][4] << " " << RESET << ESC << CAMINO << " " << mapa[7][5] << " " << RESET
    << ESC << CAMINO << " " << mapa[7][6] << " " << RESET << ESC << CAMINO << " " << mapa[7][7] << " " << RESET << endl;  

}


void rescatar_animal( Guarderia* mi_guarderia ){

    afectar_animales(mi_guarderia);
    afectar_combustible(mi_guarderia);

    //char* mapa[8];
    
    char** mapa = crear_mapa_vacio();

    animales_aleatorios(mapa);

    mostrar_mapa(mapa);


    cout << endl << "Rescataste un animal!" << endl;
    cout << endl << "Cómo se va a llamar?" << endl;
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


/*************************************** FUNCIONES DE LA OPCION 3 ***************************************/ 
// Buscar Animal


void buscar_animal( Guarderia* mi_guarderia ){

    afectar_animales(mi_guarderia);
    afectar_combustible(mi_guarderia);


    if (mi_guarderia->obtener_cantidad() == 0) {
        cout << "No hay animales para buscar." << endl;   
    }else{
        string nombre;
        cout << "Ingrese el nombre del animal que busca:" << endl << " >> ";
        nombre = pedir_nombre();


        if(buscar_nombre(mi_guarderia,nombre) == mi_guarderia->obtener_cantidad()+1)
            cout << nombre << " no se encuentra en la guardería." << endl << endl;
        
        else{
            cout << "SI! " << nombre << " está en la guardería: " << endl ;
            mi_guarderia -> obtener_animal(buscar_nombre(mi_guarderia,nombre))->mostrar();
        }   
    }
    
}

 
/*************************************** FUNCIONES DE LA OPCION 4 ***************************************/ 
// Cuidar Animales


void menu_elegir_individualmente(){

    cout << endl << "¿Qué querés hacer con él?" << endl;
    cout << "Ingresá el número de la opción deseada." << endl;
    cout << "   1. Alimentar Animal" << endl;
    cout << "   2. Duchar Animal" << endl;
    cout << "   3. Pasar a Animal siguiente" << endl;
    cout << "   4. Volver a Menu Principal" << endl;

}

void volver_menu_ppal(Guarderia* mi_guarderia){

    return;

}

void ejecutar_eleccion_op4(Guarderia* mi_guarderia, int eleccion);

void elegir_animal_a_cuidar(Guarderia* mi_guarderia){

    cout << endl << "Elegiste la opción: Elegir Individualmente." << endl << endl;
    cout << "Vamos a pasar por todos los animales en la Guardería." << endl;
    cout << "Ingresá la opción correspondiente según lo que quieras hacer con cada uno." << endl << ESPECIE_INVALIDA;

    int i = 1;
    int eleccion = -1;
    
    while ( ( i <= (mi_guarderia->obtener_cantidad()) ) && (eleccion != VOLVER_MENU_OP4) ){

        mi_guarderia->obtener_animal(i)->mostrar();
        menu_elegir_individualmente();
        eleccion = pedir_eleccion(CANTIDAD_OPCIONES_EA);

        switch (eleccion) {
            case ALIMENTAR:
                mi_guarderia->obtener_animal(i)->alimentar();
                break;
            case DUCHAR:
                mi_guarderia->obtener_animal(i)->duchar();
                break;
            case SIGUIENTE:
                ++i;
                break;
            case VOLVER_MENU_OP4:
                //volver_menu_ppal(mi_guarderia);
                ejecutar_eleccion_op4(mi_guarderia, 2);
                break;
            default:
                cout << "Opción Inválida!!!" << endl;
        }

    }

    if(i == (mi_guarderia->obtener_cantidad()+1))
        cout << "No hay más animales en la lista, volviendo atrás..." << endl;
    
}


void alimentar_a_todos(Guarderia* mi_guarderia){

    cout << "Vamos a alimentar a todos los animales" << endl;

    for(int i = 1; i <= (mi_guarderia->obtener_cantidad());i++){
        mi_guarderia->obtener_animal(i)->alimentar();
    }

    cout << "Alimentaste a todos los animales! Ellos te lo agradecen!!" << endl;

}


void duchar_a_todos(Guarderia* mi_guarderia){

    cout << "Vamos a duchar a todos los animales" << endl;

    for(int i = 1; i <= (mi_guarderia->obtener_cantidad()); i++){
        mi_guarderia->obtener_animal(i)->duchar();
    }

    cout << "Duchaste a todos los animales! Ellos te lo agradecen!!" << endl;

}



const Manejo_Guarderia opcion_4[ CANTIDAD_OPCIONES_OP4] = {

    elegir_animal_a_cuidar,
    volver_menu_ppal,

}; 

 
void ejecutar_eleccion_op4(Guarderia* mi_guarderia, int eleccion){

    opcion_4[ eleccion - 1 ]( mi_guarderia );

}


void cuidar_animales( Guarderia* mi_guarderia ){
    afectar_combustible(mi_guarderia);

    if(mi_guarderia->obtener_cantidad()==0)
        cout << "No tenés ningún animal agregado a la guardería para cuidar" << endl;
    
    else{

        int eleccion;
        do{
            imprimir_menu(CANTIDAD_OPCIONES_OP4);
            eleccion = pedir_eleccion(CANTIDAD_OPCIONES_OP4);
            ejecutar_eleccion_op4(mi_guarderia, eleccion);
        }
        while (eleccion != VOLVER_MENU_PPAL);  

    }  

}
 

/*************************************** FUNCIONES DE LA OPCION 5 ***************************************/ 
// Adoptar Animal


bool tamano_ok(Animal* animal, float espacio){ //espacio es mayor a 0

    string tamano = animal->obtener_tamano();
    bool ok = false;

    if(espacio < 2)
        ok = (tamano == TAMANOS_STRING[0]) || (tamano == TAMANOS_STRING[1]);
    else if(espacio < 10)   // 2 <= espacio < 10
        ok = (tamano == TAMANOS_STRING[1]);
    else if(espacio >= 50)
        ok = (tamano == TAMANOS_STRING[4]) || (tamano == TAMANOS_STRING[3]) || (tamano == TAMANOS_STRING[2]);
    else if(espacio >= 20)   // 20 <= espacio < 50
        ok = (tamano == TAMANOS_STRING[3]) || (tamano == TAMANOS_STRING[2]);
    else                    // 10 <= espacio < 20
        ok = (tamano == TAMANOS_STRING[2]);
    
    return ok;

}


Guarderia* crear_lista_adoptables(Guarderia* mi_guarderia, float espacio){

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
int pedir_el_adoptado( Guarderia* mi_guarderia , Guarderia* lista_adoptables ){

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


void adoptar_animal( Guarderia* mi_guarderia ){

    afectar_animales(mi_guarderia);
    afectar_combustible(mi_guarderia);

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


/*
        string espacio_string;
        float espacio;

        cin >> espacio_string;
        espacio = stof(espacio_string);

        while(espacio <= 0){

            cout << "Ingrese un espacio válido:" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    //Por si el usuario ingresa caracteres que no sean números, sean la cantidad que sean
            cin >> espacio_string;
            espacio = stof(espacio_string);

        }*/

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

/*************************************** FUNCIONES DE LA OPCION 6 ***************************************/
// Cargar Combustible 

int pedir_cant_combustible(){
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


void cargar_combustible(Guarderia* mi_guarderia){
    //int aux =50;
    //mi_guarderia->obtener_auto()->decrementar_combustible(aux);
    cout << "El auto tiene: " << mi_guarderia->obtener_auto()->obtener_combustible() << " de combustible." << endl;
    cout << "¿Cuanto combustible querés agregar? Coloca un numero de 0 a " << MAX_COMBUSTIBLE << "."<< endl;

    int cant_a_cargar = pedir_cant_combustible();

    mi_guarderia->obtener_auto()->cargar_combustible(cant_a_cargar);

    //cout << "El auto tiene: " << mi_guarderia->obtener_auto()->obtener_combustible() << " de combustible." << endl;
}

/*************************************** FUNCIONES DE LA OPCION 7 ***************************************/ 
// Guardar y Salir


void guardar_salir( Guarderia* mi_guarderia ){ 

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