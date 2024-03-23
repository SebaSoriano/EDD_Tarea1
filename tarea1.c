/**
 * 
 * @author  Hugo Hernandez
 * @author  Sebastian Soriano
 * 
 */

#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

/* --------------------------------------------------------------//-------------------------------------------------------------- */

typedef struct s_personaje{
    char nombre[50];
    int popularidad;
    struct s_personaje *siguiente;
} *PERSONAJE;

typedef struct s_lista{
    PERSONAJE primero;
    int total;
} LISTA;

typedef struct s_pila{
    PERSONAJE tope;
    int total;
} PILA;

LISTA creaLista();
PERSONAJE crear(char *nombre, int popularidad);
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo);
void verPersonajes(LISTA lista);
LISTA elimina(LISTA lst, int x);
LISTA eliminaPorNombre(LISTA lst, char *victima);
LISTA intercambio(LISTA lista, int x, int y);
LISTA insertar(LISTA lst_a, LISTA lst_b, int x);
LISTA seleccion(LISTA lst, int minimo, int maximo);
PILA masPopulares(LISTA primera, LISTA segunda);


PILA creaPila();
PILA apilar(PILA pila, PERSONAJE nuevo);
void verPjPila(PILA pila);
int comparar(char *nombre1, char *nombre2);
LISTA copiarLista(LISTA lst);


/* --------------------------------------------------------------//-------------------------------------------------------------- */


int main() {
    int flag = 0;
    int op;
    int n;
    int m;
    int x;
    LISTA lista1 = creaLista();
    LISTA lista2 = creaLista();
    PILA pila = creaPila();

    do
    {
        system("clear");
        printf("\n-------------------------TAREA 1-------------------------\n");
        printf("1. Crear dos listas de personajes\n");
        printf("2. Ver cantidad de personajes por lista\n");
        printf("3. Ver informacion de los personajes de cada lista\n");
        printf("4. Eliminar personaje por ubicacion\n");
        printf("5. Eliminar personaje por nombre\n");
        printf("6. Intercambiar personajes de una lista ingresando dos ubicaciones\n");
        printf("7. Insertar personajes de una lista en otra\n");
        printf("8. Filtrar personajes por popularidad\n");
        printf("9. Apilar comparando mayores popularidades\n");
        printf("10. Mostrar pila de opcion [9]\n");
        printf("0. Salir\n");
        printf("---------------------------------------------------------\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &op);
        switch (op)
        {
            // 1.- Crear dos listas de personajes
            case 1:
                char nombre[50];
                int popularidad;
                flag = 1;
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("Ingrese cantidad de personajes para la lista 1: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++){
                    printf("\nIngrese nombre del personaje %d: ", i+1);
                    scanf("%s", nombre);
                    printf("Ingrese popularidad del personaje %d: ", i+1);
                    scanf("%d", &popularidad);
                    lista1 = agregaPersonaje(lista1, crear(nombre, popularidad));
                }
                printf("\nIngrese cantidad de personajes para la lista 2: ");
                scanf("%d", &n);
                for(int i=0; i<n; i++){
                    printf("\nIngrese nombre del personaje %d: ", i+1);
                    scanf("%s", nombre);
                    printf("Ingrese popularidad del personaje %d: ", i+1);
                    scanf("%d", &popularidad);
                    lista2 = agregaPersonaje(lista2, crear(nombre, popularidad));
                }
                system("clear");
                printf("\nListas creadas con exito\n");
                printf("\nLista 1: \n");
                verPersonajes(lista1);
                printf("\n---------------------------------------------------------\n");
                printf("\nLista 2: \n");
                verPersonajes(lista2);
                printf("--------------------------------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 2.- Ver cantidad de personajes por lista
            case 2:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nLa lista 1 contiene %d personaje(s)\n", lista1.total);
                printf("\n---------------------------------------------------------\n");
                printf("\nLa lista 2 contiene %d personaje(s)\n", lista2.total);
                printf("--------------------------------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 3.- Ver informacion de los personajes de cada lista
            case 3:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nLista 1: \n");
                verPersonajes(lista1);
                printf("\n---------------------------------------------------------\n");
                printf("\nLista 2: \n");
                verPersonajes(lista2);
                printf("\n---------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 4.- Eliminar personaje por ubicacion
            case 4:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nIngrese la lista de la que desea eliminar un personaje (1 o 2): ");
                scanf("%d", &n);
                printf("\nIngrese la ubicacion del personaje que desea eliminar: ");
                scanf("%d", &m);
                if(n == 1){
                    lista1 = elimina(lista1, m);
                }else if(n == 2){
                    lista2 = elimina(lista2, m);
                }else{
                    printf("\nValor de lista invalido\n");
                }
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 5.- Eliminar personaje por nombre
            case 5:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nIngrese la lista de la que desea eliminar un personaje (1 o 2): ");
                scanf("%d", &n);
                printf("\nIngrese el nombre del personaje que desea eliminar: ");
                scanf("%s", nombre);
                if(n == 1){
                    lista1 = eliminaPorNombre(lista1, nombre);
                }else if(n == 2){
                    lista2 = eliminaPorNombre(lista2, nombre);
                }else{
                    printf("\nValor de lista invalido\n");
                }
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 6.- Intercambiar personajes de una lista ingresando dos ubicaciones
            case 6:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                LISTA caso6;
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nIngrese la lista de la que desea intercambiar personajes (1 o 2): ");
                scanf("%d", &n);
                printf("\nIngrese la ubicacion del primer personaje: ");
                scanf("%d", &m);
                printf("\nIngrese la ubicacion del segundo personaje: ");
                scanf("%d", &x);
                if(n == 1){
                    caso6 = intercambio(lista1, m, x);
                    if(lista1.total < m || lista1.total < x){
                        printf("\nPresione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }else if(n == 2){
                    caso6 = intercambio(lista2, m, x);
                    if(lista2.total < m || lista2.total < x){
                        printf("\nPresione enter para continuar...");
                        getchar();
                        getchar();
                        break;
                    }
                }else{
                    printf("\nValor de lista invalido\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                printf("\n---------------------------------------------------------\n");
                printf("\nLista inicial: \n");
                if(n == 1){
                    verPersonajes(lista1);
                }else{
                    verPersonajes(lista2);
                }
                printf("\n---------------------------------------------------------\n");
                printf("\nLista intercambiando el objeto de posición [%d] con el de posicion [%d]: \n", m, x);
                verPersonajes(caso6);
                printf("\n---------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 7.- Insertar personajes de una lista en otra
            case 7:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nIngrese la lista a la que desea insertar personajes (1 o 2): ");
                scanf("%d", &n);
                printf("\nIngrese la ubicacion en la que desea insertar los personajes: ");
                scanf("%d", &x);
                if(n == 1){
                    lista1 = insertar(lista1, lista2, x);
                }else if(n == 2){
                    lista2 = insertar(lista2, lista1, x);
                }else{
                    printf("\nValor de lista invalido\n");
                }
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 8.- Filtrar personajes por popularidad
            case 8:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                LISTA caso8;
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nIngrese la lista que desea filtrar (1 o 2): ");
                scanf("%d", &n);
                printf("\nIngrese la popularidad minima: ");
                scanf("%d", &m);
                printf("\nIngrese la popularidad maxima: ");
                scanf("%d", &x);
                if(m > x){
                    printf("\nEl valor minimo no puede ser mayor al valor maximo\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                if(n == 1){
                    caso8 = seleccion(lista1, m, x);
                }else if(n == 2){
                    caso8 = seleccion(lista2, m, x);
                }else{
                    printf("\nValor de lista invalido\n");
                }
                printf("\n---------------------------------------------------------\n");
                printf("\nLista N°%d con las popularidades filtradas entre %d y %d: \n", n, m, x);
                verPersonajes(caso8);
                printf("\n---------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 9.- Apilar comparando mayores popularidades
            case 9:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nSeleccione la pila a la cual desea ingresar como la primera (1 o 2): \n");
                scanf("%d", &n);
                if(n == 1){
                    pila = masPopulares(lista1, lista2);
                }else if(n == 2){
                    pila = masPopulares(lista2, lista1);
                }else{
                    printf("\nValor de lista invalido\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                printf("\nListas apiladas con exito\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;
            // 10.- Mostrar pila de opcion [9]
            case 10:
                if(flag == 0){
                    printf("\nPrimero debe crear las listas\n");
                    printf("\nPresione enter para continuar...");
                    getchar();
                    getchar();
                    break;
                }
                system("clear");
                printf("\n-------------------------TAREA 1-------------------------\n");
                printf("\nPila: \n");
                verPjPila(pila);
                printf("\n---------------------------------------------------------\n");
                printf("\nPresione enter para continuar...");
                getchar();
                getchar();
                break;



        }    
    }while (op != 0);
    printf("\n---------------------FIN DE LA SESIÓN---------------------\n");
    return 1;
}

/* Crea y retorna una lista vacia */
LISTA creaLista(){
    LISTA lista;
    lista.primero = NULL;
    lista.total = 0;
    return lista;
}

/* Crea y retorna un personaje */
PERSONAJE crear(char *nombre, int popularidad){
    PERSONAJE nuevo = (PERSONAJE)malloc(sizeof(struct s_personaje));
    strcpy(nuevo->nombre, nombre);
    nuevo->popularidad = popularidad;
    nuevo->siguiente = NULL;
    return nuevo;
}

// Compara dos strings sin considerar mayusculas
int comparar(char *nombre1, char *nombre2){
    int i = 0;
    while(nombre1[i] != '\0' && nombre2[i] != '\0'){
        if(tolower(nombre1[i]) != tolower(nombre2[i])){
            return 0;
        }
        i++;
    }
    if(tolower(nombre1[i]) == '\0' && tolower(nombre2[i]) == '\0'){
        return 1;
    }
    return 0;
}

/* Agrega un personaje a la lista y retorna la lista */
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo){
    PERSONAJE aux = lista.primero;
    if(aux == NULL){
        lista.primero = nuevo;
    }else{
        while(aux->siguiente != NULL){
            if(comparar(aux->nombre, nuevo->nombre) == 1){
                printf("\nEl personaje ya existe\n");
                return lista;
                }
            aux = aux->siguiente;
        }
        if(comparar(aux->nombre, nuevo->nombre) == 1){
            printf("\nEl personaje ya existe\n");
            return lista;
        }
        aux->siguiente = nuevo;
        
    }
    lista.total++;
    return lista;
}

/* Muestra los personajes registrados */
void verPersonajes(LISTA lista){
    PERSONAJE aux = lista.primero;
    while(aux != NULL){
        printf("\nNombre: %s\nPopularidad: %d\n", aux->nombre, aux->popularidad);
        aux = aux->siguiente;
    }
}

/* Elimina un personaje de la lista, dada la ubicacion x (partiendo desde 1) */
LISTA elimina(LISTA lst, int x){
    PERSONAJE aux = lst.primero;
    PERSONAJE anterior;

    if(lst.total < x){
        printf("\nNo existe un personaje con la posicion %d\n", x);

    }
    else if(x == 1){
        lst.primero = aux->siguiente;
        lst.total--;
    }
    else if (x <= lst.total){
        
        for(int i=1; i<x; i++){
            anterior = aux;
            aux = aux->siguiente;
        }
        anterior->siguiente = aux->siguiente;
        lst.total--;
    }
    return lst;

}

/* Crea y retorna una nueva lista con los NUEVOS personajes copiados de la lista original */
LISTA copiarLista(LISTA lst){
    PERSONAJE aux = lst.primero;
    LISTA nueva = creaLista();
    for(int i=1; i<=lst.total; i++){
        nueva = agregaPersonaje(nueva, crear(aux->nombre, aux->popularidad));
        aux = aux->siguiente;
    }
    return nueva;
}

/* Crea y retorna una nueva lista intercambiando el orden de 2 personajes (ubicados en la posici´on x e y) */
LISTA intercambio(LISTA lista, int x, int y){
    LISTA nueva = copiarLista(lista);
    PERSONAJE aux = nueva.primero;

    PERSONAJE px = NULL;
    PERSONAJE py = NULL;
    PERSONAJE apx = NULL;
    PERSONAJE apy = NULL;
    ;
    int cont_x = 1, cont_y = 1;

    if(x > nueva.total || y > nueva.total || x < 1 || y < 1){
        printf("\nNo existe un personaje con la posicion %d o %d\n", x, y);
        return nueva;

    }else if(x == y){
        printf("No se puede intercambiar un personaje consigo mismo\n");
        return nueva;
    // Si x o y son el primer elemento
    }else if (x == 1 || y == 1){
        if(x == 1){
            px = nueva.primero;
            py = nueva.primero;
            for(int i=1; i<y;i++){
                apy = aux;
                py = aux->siguiente;
                aux = aux->siguiente;
            }
            apy->siguiente = px;
            nueva.primero = py;
            aux = px->siguiente;
            px->siguiente = py->siguiente;
            py->siguiente = aux;
        }else if(y == 1){
            px = nueva.primero;
            py = nueva.primero;
            for(int i=1; i<x;i++){
                apx = aux;
                px = aux->siguiente;
                aux = aux->siguiente;
            }
            apx->siguiente = py;
            nueva.primero = px;
            aux = py->siguiente;
            py->siguiente = px->siguiente;
            px->siguiente = aux;
        }
    }
    // Si x o y estan adyacentes uno del otro
    else if(x == y-1 || y == x-1){
        PERSONAJE amenor = NULL;
        PERSONAJE mayor = NULL;
        PERSONAJE menor = NULL;

            while(aux != NULL){
                if(cont_x == x-1){
                    apx = aux;
                    px = aux->siguiente;
                }
                if(cont_y == y-1){
                    apy = aux;
                    py = aux->siguiente;
                }
                aux = aux->siguiente;
                cont_x++;
                cont_y++;
            }
        if(x<y){
            mayor = py;
            menor = px;
            amenor = apx;
        }else{
            mayor = px;
            menor = py;
            amenor = apy;
        }
        aux = menor->siguiente;
        menor->siguiente = mayor->siguiente;
        mayor->siguiente = menor;
        amenor->siguiente = mayor;
    }
    // Si x o y estan separados por mas de un elemento Y ninguno de los dos es el primero
    else{
        while(aux != NULL){
            if(cont_x == x-1){
                apx = aux;
                px = aux->siguiente;
            }
            if(cont_y == y-1){
                apy = aux;
                py = aux->siguiente;
            }
            }
            aux = aux->siguiente;
            cont_x++;
            cont_y++;
            aux = px->siguiente;
            px->siguiente = py->siguiente;
            py->siguiente = aux;
            apy->siguiente = px;
            apx->siguiente = py;
    }
    return nueva;
}

/* Elimina un personaje, dado su nombre*/
LISTA eliminaPorNombre(LISTA lst, char *victima){
    PERSONAJE aux = lst.primero;
    PERSONAJE anterior = NULL;
    if(comparar(aux->nombre, victima) == 1){
        lst.primero = aux->siguiente;
        lst.total--;
        return lst;
    }
    anterior = aux;
    aux = aux->siguiente;
    while(aux != NULL){
        if(comparar(aux->nombre, victima) == 1){
            anterior->siguiente = aux->siguiente;
            lst.total--;
            return lst;
        }
        anterior = aux;
        aux = aux->siguiente;
    }
    printf("\nNo existe un personaje con el nombre %s\n", victima);
    return lst;
    }

/* Inserta los elementos de lst_b en la lst_a luego de la ubicacion x */
LISTA insertar(LISTA lst_a, LISTA lst_b, int x){
    LISTA copia_a = copiarLista(lst_a);
    LISTA copia_b = copiarLista(lst_b);

    PERSONAJE aux = NULL;
    PERSONAJE anterior = NULL;
    PERSONAJE ultimo = copia_b.primero;
    while(ultimo->siguiente != NULL){
        ultimo = ultimo->siguiente;
    }
    if(x == 1){
        anterior = copia_a.primero;
        aux = anterior->siguiente;
        anterior->siguiente = copia_b.primero;
        ultimo->siguiente = aux;
        copia_a.total += copia_b.total;
        return copia_a;
    }
    if(x > copia_a.total){
        printf("\nNo existe un personaje con la posicion %d\n", x);
        return copia_a;
    }
    aux = copia_a.primero;
    for(int i=1; i<=x;i++){
        anterior = aux;
        aux = aux->siguiente;
    }
    anterior->siguiente = copia_b.primero;
    ultimo->siguiente = aux;
    copia_a.total += copia_b.total;
    return copia_a;
}

/* Genera una lista considerando todos los personajes de lst cuya popularidad se encuentre entre los valores mınimo y maximo
 * Estos maximos y minimos son INCLUSIVOS! */
LISTA seleccion(LISTA lst, int minimo, int maximo){
    LISTA nueva = creaLista();
    PERSONAJE aux = lst.primero;
    for(int i=1; i<=lst.total; i++){
        if(aux->popularidad >= minimo && aux->popularidad <= maximo){
            nueva = agregaPersonaje(nueva, crear(aux->nombre, aux->popularidad));
        }
        aux = aux->siguiente;
    }
    return nueva;
}

/* Crea y retorna una pila vacia */
PILA creaPila(){
    PILA pila;
    pila.tope = NULL;
    pila.total = 0;
    return pila;
}

/* Apila un personaje y retorna la pila */
PILA apilar(PILA pila, PERSONAJE nuevo){
    PERSONAJE aux = pila.tope;
    if(aux == NULL){
        pila.tope = nuevo;
    }else{
        nuevo->siguiente = aux;
        pila.tope = nuevo;
    }
    pila.total++;
    return pila;
}

/* Procesa los elementos de acuerdo con lo indicado en el requerimiento */
PILA masPopulares(LISTA primera, LISTA segunda){
    PILA pila = creaPila();
    PERSONAJE aux1 = primera.primero;
    PERSONAJE aux2 = segunda.primero;
    if(aux1->popularidad > aux2->popularidad){
        pila = apilar(pila, crear(aux1->nombre, aux1->popularidad));
    }else if(aux1->popularidad < aux2->popularidad){
        pila = apilar(pila, crear(aux2->nombre, aux2->popularidad));
    }

    if(primera.total < segunda.total){
        while(aux1->siguiente != NULL){
            aux1 = aux1->siguiente;
            aux2 = aux2->siguiente;
            if(aux1->popularidad > aux2->popularidad){
                pila = apilar(pila, crear(aux1->nombre, aux1->popularidad));
            }else if (aux1->popularidad < aux2->popularidad){
                pila = apilar(pila, crear(aux2->nombre, aux2->popularidad));
            }

        }
            aux1 = aux2->siguiente;
        while(aux2->siguiente != NULL){
            aux2 = aux2->siguiente;
            if(aux1->popularidad > aux2->popularidad){
                aux1 = aux2;
            } 
        }
        pila = apilar(pila, crear(aux1->nombre, aux1->popularidad));
    }
    else if(primera.total > segunda.total){
        while(aux2->siguiente != NULL){
            aux1 = aux1->siguiente;
            aux2 = aux2->siguiente;
            if(aux1->popularidad > aux2->popularidad){
                pila = apilar(pila, crear(aux1->nombre, aux1->popularidad));
            }else if (aux1->popularidad < aux2->popularidad){
                pila = apilar(pila, crear(aux2->nombre, aux2->popularidad));
            }
        }
        aux2 = aux1->siguiente;
        while(aux1->siguiente != NULL){
            aux1 = aux1->siguiente;
            if(aux1->popularidad > aux2->popularidad){
                aux2 = aux1;
            } 
        }
        pila = apilar(pila, crear(aux2->nombre, aux2->popularidad));
    }
    return pila;
}

// Muestra en pantalla los personajes de la pila
void verPjPila(PILA pila){
    PERSONAJE aux = pila.tope;
    if(aux == NULL){
        printf("\nLa pila esta vacia\n");
    }
    while(aux != NULL){
        printf("\nNombre: %s\nPopularidad: %d\n", aux->nombre, aux->popularidad);
        aux = aux->siguiente;
    }
}