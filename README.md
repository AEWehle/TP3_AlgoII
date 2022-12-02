# TP3_AlgoII

COMANDO: g++ *.cpp Especies/*.cpp Menus/*.cpp Opciones/*.cpp Archivos_auxiliares/*.cpp -o TP3 -Wall -Werror -Wconversion -std=c++11 -v -fsanitize=address -g

# Para compilar version meli: 

$g++ Animal.cpp Auto.cpp funciones_main.cpp Guarderia.cpp main.cpp Mapa.cpp Especies/*.cpp Archivos_auxiliares/*.cpp Menus/*.cpp Opciones/*.cpp  -o TP3 -Wall -Werror -Wconversion -std=c++11 -v -fsanitize=address -g$

Para ejecutar ./TP3

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s ./TP3

gdb ./Prueba

git status                                   Para ver lo que esta para subirse

git add .                                    Para agregar a las cosas a subirse

git commit -m "mensaje para nuestro grupo"   Para guardarlo y en un futuro subirlo con git push

git log --oneline                            Para ver el historial de Commits

git push                                     Lo sube a la nube 

ponen su nombre de usuario

git pull                                     Ponerlo para verificar si alguine del grupo pusheó algún cambio
                                                te asegurás tenes la úlrima versión

git checkout nombre_branch                   Primero hacerlo con la main y despues con la brunch en la que estás trabajando

git chechout -b nombre_nueva_brunch          Crear brunch

git push origin nombrE_nueva_brunch          Luego de haber hecho add y commit

