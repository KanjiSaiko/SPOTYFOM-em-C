#include "bibliotecas.h"


DescLE *addMusica(DescLE *descritorLista, NodoLP *nodo){
    if(descritorLista->primeiro == NULL){
        descritorLista->primeiro = nodo;
    }
    else {
        NodoLP *aux = descritorLista->primeiro;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = nodo;
    }

    descritorLista->tamanho++;
    return descritorLista;
}