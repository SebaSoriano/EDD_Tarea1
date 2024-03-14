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


/* Crea y retorna una lista vac´ıa */
LISTA crearLista(){
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
                return lista;}
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
        while(aux != NULL){
            printf("\nNombre: %s\nPopularidad: %d\n", aux->nombre, aux->popularidad);
            aux = aux->sgte;
        }
    }

/* Elimina un personaje de la lista, dada la ubicaci´on x (partiendo desde 1) */
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

/* Elimina un personaje, dado su nombre */
LISTA eliminaPorNombre(LISTA lst, char *victima){
    PERSONAJE aux = lst.primero;
    
    while(aux->sgte != NULL){
        
    }
}
/* Crea y retorna una nueva lista intercambiando el orden de 2 personajes (ubicados en la posici´on x e y) */
LISTA intercambio(LISTA lista, int x, int y);
/* Inserta los elementos de lst_b en la lst_a luego de la ubicaci´on x */
LISTA insertar(LISTA lst_a, LISTA lst_b, int x);

int main() {
    int op;
    do{
        printf("Menu:\n");
        printf("1. Crear listas\n");
        printf("2. Option 2\n");
        printf("3. Option 3\n");
        printf("Enter your choice: ");
        scanf("%d", &op);
    
        switch(op) {
            case 1:
                LISTA lst1 = crearLista();
                LISTA lst2 = crearLista();
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
    }while(op!=0);   
    return 1;
}