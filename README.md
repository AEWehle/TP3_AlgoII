# TP2_AlgoII

COMANDO: g++ *.cpp Especies/*.cpp Archivos_auxiliares/*.cpp -o TP2 -Wall -Werror -Wconversion

Para ejecutar ./TP2

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TP2

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

1 * Revisar que no haya funciones que no se usen (por ejemplo que hayan quedado del TP1)

2 * Revisar que todo esté con clases y no estructuras, incluso descripciones de pos y pre condiciones

3 * Revisar métodos de guarderia, si se necesitan todos o si algunos sobran ya que ahora se usan listas. Por ejemplo: el método privado "swap" lo vamos a usar?

4 * Dejamos el constructor de copia? En caso de que sí, hay que adaptarlo a listas

5 * Revisar pos y pre condiciones de todo

6 * PROBAR Y VER QUE TODO FUNCIONE Y QUE SE CUMPLA LO QUE PIDE EL ENUNCIADO DEL TP

7 * LISTO - Hay que ver que se guarden bien las cosas. Sin mayúsculas y esas cosas. -> Minusculas en tamaño y personalidad?? Acentos en las palabras??

8 * UML -- (LN puse un .txt con el link, despu)

## COSAS HECHAS:

A.V. - Acomodé el main, creería que ya no va a haber que cambiarlo
A.V. - Hice la función que lee el archivo y va guardando los animales en la lista de guardería
A.V. - Acomodé un poco la funciones de pedir eleccion
A.V. - En algunos archivos puse una división con ///// para separar funciones que o bien no se usan o bien van en otra parte (creo). Así queda más ordenada la modularización
A.V. - Fui dejando algunos comentarios en algunas líneas que no entiendo o no se si son necesarias
A.V. - Fui sacando todos los \n que encontré y cambiandolos por endl, me parece que al usar C++ es lo más correcto. Habría que revisar todo el final.
A.V. - Hice la función de guardar y salir, que escribe el archivo. Hice las funciones de mostrar edad, tamaño y personalidad para hacer la de guardar.
A.V. - Arreglé errores para que compile.
A.V. - Arreglé la función de rescatar. Cuando se ingresa en la edad una letra lo toma como edad 0, habría que arreglarlo, lo dejé comentado.


AEW. - Cambié el nombre de un metodo de guarderia que devuelve un puntero al animal en la posicion de la lista
            Guarderia -> mostrar()  =====>  Guarderia -> obtener_animal()
AEW. - Eliminé la funcion verificar_almacenamiento ya que como usamos listas ese manejo se hace implicitamente
AEW. - La funcion obtener pocion por nombre de animal estaba mal, iteraba dos veses en cada posicion
AEW. - Puse algunos comentarios de pre y post, hay que seguir
AEW. - EL PROGRAMA CORREEEE
AEW. - HYA LEAK DE MEMORIAAAA, no sé de donde será pero hay que revisar la destruccion de la guarderia.

MGC. - Me queda revisar leaks de memoria que no pude encontrar por qué pasan. Modificaciones de varias funciones (principalmente mostrar_menu y pedir_opcion) para reciclarlas cuando se quiere funcionalidad parecida. Vi un tema que en una de las opciones al crear el animal se le puede ingresar una letra cuando deberia ser número y esto no es correcto, lo reviso mañana y lo subo a mi branch, pero salvo revisiones creo que podríamos hacer el merge\\
- Funciona bien cuidar_animales! Verificado correcto de los datos al rescatar un animal y manejo de memoria.

A.V.H. - Arreglé la función de adoptar, ahora si hace lo qeu dice el enunciado.
A.V.H. - Ahora "cancelar" no es un nombre válido.
A.V.H. - Emprolijé todos los archivo, cambios más bien estéticos, con los enter y ese tipo de cosas. No rompí nada.
A.V.H. - Probé a romper el programa de todas las formas que se me ocurrió, y cambie cosas para que no pase. Debería ser bastante robusto ahora.
A.V.H. - Terminé de emprolijar los archivos que me faltaban.
A.V.H. - Ahora la función de adoptar puede recibir números con coma (usando el punto .) para el espacio del usuario sin romperse.