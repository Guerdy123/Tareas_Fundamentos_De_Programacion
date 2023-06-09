#include <stdio.h>
#include <stdlib.h>


/* Structure nodo*/
typedef struct nodo{
    int dato;
    struct nodo * siguiente;
}Nodo;


Nodo *crearNodo(int dato){
    Nodo *n=(Nodo*) malloc(sizeof (Nodo));
    n->dato=dato;
    n->siguiente=NULL;
    return n;
}

/*Structure Lista*/

typedef struct {
    Nodo *raiz;
    int total;
    Nodo *ultimo;
}Lista;

Lista  * crearLista(){
    Lista * l = (Lista*) malloc(sizeof(Lista));
    l->raiz=NULL;
    l->total=0;
    l->ultimo=NULL;
    return l;
}

int estaVacia(Lista * l){  /*Verificar si lista esta vacia*/
    if(l->raiz==NULL){
        return 1;
    } else{
        return 0;
    }
}

void insertarFinal( Lista * l,Nodo * n){
    if (estaVacia(l)){ /*Si lista esta vacia*/
        l->raiz=n;/*Primer elemento es igual a n*/
        l->ultimo=n;/*ultimo elemento es igual a n*/
    } else{
        l->ultimo->siguiente=n;
        l->ultimo=n;
    }
    l->total++;
}


void imprimirNodo(Nodo * n){
    printf("%d\n",n->dato);
}
int main (){


    return 0;
}