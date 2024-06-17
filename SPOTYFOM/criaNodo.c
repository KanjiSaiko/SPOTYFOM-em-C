#include "bibliotecas.h"


NodoLP *criaNodo(){
    NodoLP *nodo = malloc(sizeof(NodoLP));
    nodo->info = NULL;
    nodo->prox = NULL;
    return nodo;
}