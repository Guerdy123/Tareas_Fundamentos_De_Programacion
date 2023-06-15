#include <stdio.h>
#include <stdlib.h>


/* Structure nodo*/
typedef struct nodo {
    int dato;
    struct nodo *siguiente;
}Nodo;

Nodo  * crearNodo(int dato){
    Nodo * n = (Nodo*) malloc(sizeof (Nodo));
    n->dato=dato;
    n->siguiente=NULL;
    return n;
}

void imprimirNodo(Nodo * n){
    printf("%d\n",n->dato);
}

typedef struct lista{
    Nodo * raiz;
    int total;
    Nodo * ultimo;
}Lista;


Nodo * crearLista(){
    Lista * l = (Lista*) malloc(sizeof (Lista));
    l->raiz=NULL;
    l->total=0;
    l->ultimo=NULL;
    return l;

}
int estaVacia(Lista * l){
    if((l->raiz=NULL)){
       return 1;
    } else{
        return 0;
    }
}

void insertarInicio(Nodo * n, Lista * l){
    if (estaVacia(l)){
        l->raiz = n;
        l->ultimo=n;
    } else{
      n->siguiente=l->raiz;
      l->raiz=n;
    }
    l->total++;
}

void insertarFinal(Nodo * n, Lista * l){
    if (estaVacia(l)){
        l->raiz = n;
        l->ultimo=n;
    } else{
        l->ultimo->siguiente=n;
        l->ultimo=n;
    }
    l->total++;
}

int main (){


    return 0;
}