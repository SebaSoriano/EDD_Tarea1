#include<stdio.h>
#include<stdlib.h> 
#include<stdbool.h>
#include<time.h>
#include<math.h>
#include<string.h>

typedef struct s_personaje{
    char nombre[20];
    int popularidad;
}PERSONAJE;

typedef struct s_nodo{
    PERSONAJE pj;
    struct s_nodo *sgte;
}*NODO;

typedef struct s_lista{
    NODO primero;
    int tam;
}LISTA;

LISTA crearLista(){
    LISTA lst;
    lst.primero = NULL;
    lst.tam = 0;
    return lst;
}

void insertarNodo(LISTA *lst, PERSONAJE p){
    NODO nuevo = (NODO)malloc(sizeof(struct s_nodo));
    nuevo->pj = p;
    nuevo->sgte = NULL;
    if(lst->primero == NULL){
        lst->primero = nuevo;
    }else{
        NODO aux = lst->primero;
        while(aux->sgte != NULL){
            if(aux->pj.nombre == p.nombre){
                printf("El personaje ya existe\n");
                return;
            }
            aux = aux->sgte;
        }
        if(aux->pj.nombre == p.nombre){
            printf("El personaje ya existe\n");
            return;
        }
        aux->sgte = nuevo;
    }
    lst->tam++;
}

void imprimirLista(LISTA lst){
    NODO aux = lst.primero;
    while(aux != NULL){
        printf("Nombre: %s\n", aux->pj.nombre);
        printf("Popularidad: %d\n\n", aux->pj.popularidad);
        aux = aux->sgte;
    }
}

PERSONAJE crearPersonaje(){
    PERSONAJE p;
    int pop;
    printf("Ingrese el nombre del personaje: ");
    scanf("%s", p.nombre);
    printf("Ingrese la popularidad del personaje: ");
    scanf("%d", &pop);
    p.popularidad = pop;
    return p;



}

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