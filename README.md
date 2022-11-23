# TP3_AlgoII

COMANDO: g++ *.cpp Especies/*.cpp Archivos_auxiliares/*.cpp -o TP3 -Wall -Werror -Wconversion

# Para compilar version meli: g++ Guarderia.cpp Animal.cpp funciones_main.cpp prueba_modular.cpp Especies/*.cpp Archivos_auxiliares/*.cpp Menus/*.cpp Opciones/*.cpp Auto.cpp -o TP3_MOD -Wall -Werror -Wconversion -std=c++11 -v -fsanitize=address -g

Para ejecutar ./TP3

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TP3

gdb ./Prueba

git status                                   Para ver lo que esta para subirse

git add .                                    Para agregar a las cosas a subirse

git commit -m "mensaje para nuestro grupo"   Para guardarlo y en un futuro subirlo con git push

git log --oneline                            Para ver el historial de Commits

git push                                     Lo sube a la nube 

ponen su nombre de usuario

ponen la siguiente clave --->  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

git pull                                     Ponerlo para verificar si alguine del grupo pusheó algún cambio
                                                te asegurás tenes la úlrima versión

git checkout nombre_branch                   Primero hacerlo con la main y despues con la brunch en la que estás trabajando

git chechout -b nombre_nueva_brunch          Crear brunch

git push origin nombrE_nueva_brunch          Luego de haber hecho add y commit

## COSAS A MODIFICAR/CORREGIR:
1. Camino mínimo (LN)
2. Crear funcion que genere 5 animales random (LN)
3. Cambiar la implementacion de listar animales, buscar animal, ya que ahora no usamos lista sino diccionario de arbol 3 vias.
4. Agregar opcion del menú principal:
        5. Adoptar animal.
        
   ---> 6. Cargar combutible. (Muestra cuanto y regunta cuanto agregar)*LISTO(M)*
   
        7. Guardar y salir.
        
   El auto se autocarga 5 de combustible cada vez que se selecciona una opcion del menú (max_combustible = 100)*LISTO (M)*
   
5. - Mapa: matriz de 8x8
   - Mostramos al inicio el mapa y animales generados random ( propner otra forma si prefiere )
   - Terreno y Costo: montana: 5, camino: 1, precipicio: 40, tierra: 2
   - Animales: Se generan 5 random (en posicion y características), se muestran con su letra representativa
   - Auto: (A) inicia arriba a la izq. Camino mínimo (GRAFOS menor costo, se debe mostrar) y solo rescata si le alcanza el combustible.
          Si no le alcanza se pregunta al usuario otro destino u otra acción          
6. Diría de agregar un atributo a los animales que sea su ubicacion
   Si tiene 0 higiene o 100 hambre el animal se escapa. Si escapan 3 --> GAME OVER
7. En cuidar animales el menú ahora es otro. Pero para volver al menú inicial hay que apretar 4 (NO SÉ QUE ONDA jajaj) *EN ESO (M)*
8. En adoptar animal hay que mostrar los animales de mayor a menor según edad
10. Actualizar UML

## COSAS HECHAS:

CARGAR_COMBUSTIBLE, CLASE AUTO, AFECTAR_COMBUSTIBLE(+5)


## UPDATES:

MCH: Modificando menues, funcion de escaparse (No esta listo yet pero en eso). Consultar lo de apretar 4 para el menu anterior (Yo pregunto). UPDATE: Creo que entendi lo de la opcion 4, es que en el menu de elegir individualmente la opcion 4 te lleve al menu inicial y no al anterior (o sea, en la implementacion tipo TP2 teniamos que volvia al anterior, ahora queremos que vuelva al inicial). Ahora c/hambre 100 animal se "escapa" (todavia no elimino de la guarderia, solo agregue mensaje) 

MCH: COMPLETO LO DE CARGAR COMBUSTIBLE, FALTA IMPLEMENTARLO CON EL MAPA. Sigo revisando opcion 4.
