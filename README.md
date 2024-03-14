# TAREA 1 - PARTE 1

## REQUERIMIENTOS

1. Presentar un men´u de opciones que se debe repetir hasta que el usuario indique salir del
programa.
2. Opciones de men´u para:
(a) Crear 2 listas de personajes, ingresando para cada personaje su nombre y su popularidad.
Luego de crearlas se debe mostrar el contenido de cada una de ellas. Los personajes deben
ser ´unicos en la lista.
(b) Mostrar la cantidad de elementos de cada lista creada.
(c) Mostrar los elementos de 2 listas creadas.
(d) Dada una ubicaci´on, eliminar de una de las listas (seleccionada por el usuario) el elemento
ubicado en el valor ingresado.
(e) Dado el nombre de un personaje, eliminar de una de las listas (seleccionada por el
usuario) el personaje con el nombre indicado.
(f) Dadas 2 ubicaciones, x e y, crear una tercera lista conteniendo los elementos de la lista
con los elementos de la ubicaci´on x e y intercambiados. Luego de ejecutar la opci´on
deber´a mostrar el contenido de las listas iniciales y de la lista resultado; esto es porque
las listas originales deben mantenerse intactas.
(g) Considerando las listas creadas en la opci´on (a), seleccionar el orden de tratamiento de
las listas y un valor ingresado (que representa una ubicaci´on dentro de la primera lista
seleccionada) se pide insertar la segunda lista despu´es de la ubicaci´on indicada.
(h) Dados 2 valores enteros que representan popularidad m´ınima y m´axima, crear una lista
de los personajes de una de las listas (seleccionada por el usuario) de la opci´on (a)
considerando todos los personajes cuya popularidad se encuentre dentro del rango de
popularidad, luego deber´a mostrar la lista resultado.
(i) Salir del programa
3. La opci´on de men´u (b) en adelante requiere de la ejecuci´on previa de la opci´on (a) , de lo
contrario debe advertir de la ausencia de datos a procesar.

## RESTRICCIONES

1. Se prohibe el uso de variables globales.
2. Se deben utilizar los tipos de datos definidos (ver secci´on DEFINICION DE ESTRUCTURAS ´
DE DATOS).
3. Se debe modularizar considerando, como m´ınimo, las funcionalidades que se indican en la
secci´on de PROTOTIPO DE FUNCIONES
4. Usted deber´a combinar las llamadas a las funciones de forma adecuada para permitir el
cumplimiento de todos los requerimientos.


### DEFINICION DE ESTRUCTURAS DE DATOS
```
typedef struct s_personaje{
char nombre[50];
int popularidad;
struct s_personaje *siguiente;
} *PERSONAJE;
typedef struct s_lista{
PERSONAJE primero;
int total;
} LISTA;
```

### PROTOTIPO DE FUNCIONES

```
/* Crea y retorna una lista vac´ıa */
LISTA creaLista();
/* Crea y retorna un personaje */
PERSONAJE crear(char *nombre, int popularidad);
/* Agrega un personaje a la lista y retorna la lista */
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo);
/* Muestra los personajes registrados */
void verPersonajes(LISTA lista);
/* Elimina un personaje de la lista, dada la ubicaci´on x (partiendo desde 1) */
LISTA elimina(LISTA lst, int x);
/* Elimina un personaje, dado su nombre */
LISTA eliminaPorNombre(LISTA lst, char *victima);
/* Crea y retorna una nueva lista intercambiando el orden de 2 personajes (ubicados en la posici´on xLISTA intercambio(LISTA lista, int x, int y);
/* Inserta los elementos de lst_b en la lst_a luego de la ubicaci´on x */
LISTA insertar(LISTA lst_a, LISTA lst_b, int x);
/*
Genera una lista considerando todos los personajes de lst cuya popularidad se encuentre entre los valores m´ınimo y m´aximo
*/
LISTA seleccion(LISTA lst, int minimo, int maximo);
```

## PLAZOS DE ENTREGA

En la plataforma MOODLE, VIERNES 22 DE MARZO hasta las 23:00. 

## CONDICIONES DE ENTREGA

1. Desarrollado en grupos de 2 personas.
2. Entrega de c´odigo fuente con la debida documentaci´on.
3. Las copias ser´an evaluadas con la nota m´ınima sin derecho a apelaci´on.
4. Se debe programar en C.
5. Se debe usar punteros y definici´on de tipos de datos.
6. Queda prohibido usar librer´ıas exclusivas de windows. La calificaci´on de la tarea QUEDARA´
DESCARTADA si se da el caso
