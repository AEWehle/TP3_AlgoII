#include "OpcionCargarGuarderia.h"

void OpcionCargarGuarderia::ejecutar(Guarderia* mi_guarderia){

    std::fstream archivo_guarderia(RUTA_ARCHIVO, ios::in);

    if(!archivo_guarderia.is_open()){
        cout << "No se encontro un archivo con nombre \"" << RUTA_ARCHIVO << "\", se va a crear el archivo" << endl << endl;
        archivo_guarderia.open(RUTA_ARCHIVO, ios::out);     //Si no existe el archivo lo creo
        archivo_guarderia.close();
        archivo_guarderia.open(RUTA_ARCHIVO, ios::in);
    }

    string nombre, edad, tamano, especie, personalidad;

    while(getline(archivo_guarderia, nombre, ',')){    //Cuando ya no encuentra un nombre se terminó el archivo

        getline(archivo_guarderia, edad, ',');
        getline(archivo_guarderia, tamano, ',');
        getline(archivo_guarderia, especie, ',');
        getline(archivo_guarderia, personalidad);    //El último lo leo hasta encontrar un \n, no una coma.

        Animal* nuevo_animal = crear_nuevo_animal(especie[0], nombre, stoi(edad), tamano, personalidad);

        mi_guarderia->agregar_animal(nuevo_animal);
    }

    archivo_guarderia.close();

}