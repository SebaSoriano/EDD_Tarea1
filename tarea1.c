#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

typedef struct s_personaje{
char nombre[50];
int popularidad;
struct s_personaje *sgte;
} *PERSONAJE;


typedef struct s_lista{
PERSONAJE primero;
int total;
} LISTA;

LISTA creaLista();
PERSONAJE crear(char *nombre, int popularidad);
LISTA agregaPersonaje(LISTA lista, PERSONAJE nuevo);
LISTA intercambio(LISTA lista, int x, int y);
void verPersonajes(LISTA lista);
int comparar(char *nombre1, char *nombre2);
LISTA elimina(LISTA lst, int x);
LISTA eliminaPorNombre(LISTA lst, char *victima);
LISTA insertar(LISTA lst_a, LISTA lst_b, int x);
LISTA seleccion(LISTA lst, int minimo, int maximo);






int main() {
    PERSONAJE lukas = crear("1-Lukas", 10);
    PERSONAJE maxi = crear("2-Maxi", 10);
    PERSONAJE santi = crear("3-Santi", 10);
    PERSONAJE hugo = crear("4-Hugo", 10);
    PERSONAJE cristopher = crear("5-Cristopher", 10);

    LISTA lst = creaLista();

    lst = agregaPersonaje(lst, lukas);
    lst = agregaPersonaje(lst, maxi);
    lst = agregaPersonaje(lst, santi);
    lst = agregaPersonaje(lst, hugo);
    lst = agregaPersonaje(lst, cristopher);

    printf("\nLista 1:\n");
    verPersonajes(lst);

    lst = intercambio(lst, 5,1);
    printf("\nLista 3:\n");
    verPersonajes(lst);

    /*int op;
    do{
        printf("Menu:\n");
        printf("1. Crear listas\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
    
        switch(op) {
            case 1:
                LISTA lst1 = creaLista();
                LISTA lst2 = creaLista();
                PERSONAJE p = crearPersonaje();
                break;
            case 2:
             // Code for option 2
                break;
            case 3:
             // Code for option 3
              break;
            default:
             printf("Invalid choice\n");
             break;
    }
    }while(op!=0); */



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
    nuevo->sgte = NULL;
    return nuevo;
}

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
        while(aux->sgte != NULL){
            if(comparar(aux->nombre, nuevo->nombre) == 1){
                printf("\nEl personaje ya existe\n");
                return lista;
                }
            aux = aux->sgte;
        }
        if(comparar(aux->nombre, nuevo->nombre) == 1){
            printf("\nEl personaje ya existe\n");
            return lista;
        }
        aux->sgte = nuevo;
        
    }
    lista.total++;
    return lista;
}

/* Muestra los personajes registrados */
void verPersonajes(LISTA lista){
    PERSONAJE aux = lista.primero;
    PERSONAJE first = aux;
    while(aux != NULL){
        printf("\nNombre: %s\nPopularidad: %d\n", aux->nombre, aux->popularidad);
        aux = aux->sgte;
        if (aux == first) {
            printf("\nDetected a cycle in the list. Stopping to prevent infinite loop.\n");
            break;
        }
    }
}

/* Elimina un personaje de la lista, dada la ubicacion x (partiendo desde 1) */
LISTA elimina(LISTA lst, int x){
    PERSONAJE aux = lst.primero;
    PERSONAJE anterior;

    if(x == 1){
        lst.primero = aux->sgte;
        lst.total--;
        return lst;
    } else if (lst.total >= x) {
        
        for(int i=1; i<x;i++){
            anterior = aux;
            aux = aux->sgte;
        }
        anterior->sgte = aux;
        lst.total--;
        return lst;
    }else if(lst.total < x){
        printf("\nNo existe un personaje con la posicion %d\n", x);
    }

}


/* Crea y retorna una nueva lista intercambiando el orden de 2 personajes (ubicados en la posici´on x e y) */
LISTA intercambio(LISTA lista, int x, int y){
    PERSONAJE aux = lista.primero;
    PERSONAJE auxnuevo = NULL;
    LISTA nueva = creaLista();
    for(int i=1; i<=lista.total; i++){
        auxnuevo = crear(aux->nombre, aux->popularidad);
        nueva = agregaPersonaje(nueva, auxnuevo);
        aux = aux->sgte;
    }
    aux = nueva.primero;

    PERSONAJE px = NULL;
    PERSONAJE py = NULL;
    PERSONAJE apx = NULL;
    PERSONAJE apy = NULL;
    ;
    int cont_x = 1, cont_y = 1;

    if(x > lista.total || y > lista.total || x < 1 || y < 1){
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
                py = aux->sgte;
                aux = aux->sgte;
            }
            apy->sgte = px;
            nueva.primero = py;
            aux = px->sgte;
            px->sgte = py->sgte;
            py->sgte = aux;
        }else if(y == 1){
            px = nueva.primero;
            py = nueva.primero;
            for(int i=1; i<x;i++){
                apx = aux;
                px = aux->sgte;
                aux = aux->sgte;
            }
            apx->sgte = py;
            nueva.primero = px;
            aux = py->sgte;
            py->sgte = px->sgte;
            px->sgte = aux;
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
                    px = aux->sgte;
                }
                if(cont_y == y-1){
                    apy = aux;
                    py = aux->sgte;
                }
                aux = aux->sgte;
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
        aux = menor->sgte;
        menor->sgte = mayor->sgte;
        mayor->sgte = menor;
        amenor->sgte = mayor;
    }
    // Si x o y estan separados por mas de un elemento Y ninguno de los dos es el primero
    else{
        while(aux != NULL){
            if(cont_x == x-1){
                apx = aux;
                px = aux->sgte;
            }
            if(cont_y == y-1){
                apy = aux;
                py = aux->sgte;
            }
            }
            aux = aux->sgte;
            cont_x++;
            cont_y++;
            aux = px->sgte;
            px->sgte = py->sgte;
            py->sgte = aux;
            apy->sgte = px;
            apx->sgte = py;
    }
    return nueva;
}

/* Elimina un personaje, dado su nombre*/
LISTA eliminaPorNombre(LISTA lst, char *victima){
    PERSONAJE aux = lst.primero;
    // -----------------------TODO------------------
    while(aux->sgte != NULL){
        
    }
}

/* Inserta los elementos de lst_b en la lst_a luego de la ubicacion x */
LISTA insertar(LISTA lst_a, LISTA lst_b, int x){
 //------------------------------------TODO-----------------------------------
}

/* Genera una lista considerando todos los personajes de lst cuya popularidad se encuentre entre los valores mınimo y maximo */
LISTA seleccion(LISTA lst, int minimo, int maximo){
    //------------------------------------TODO-----------------------------------

}