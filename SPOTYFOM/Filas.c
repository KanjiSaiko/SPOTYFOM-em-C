#include "bibliotecas.h"


DescFila *addNodoFila(DescFila *descritor, NodoFila *nodo){
    if(descritor->head == NULL){
        descritor->head = nodo;
        descritor->tail = nodo;
    }
    else{
        descritor->tail->prox = nodo;
        nodo->ant = descritor->tail;
        descritor->tail = nodo;
    }
    descritor->tamanho++;
    return descritor;
}

DescFila *inicializaFila(){
    DescFila *descFila = malloc(sizeof(DescFila));
    descFila->head = NULL;
    descFila->tail = NULL;
    descFila->tamanho = 0;
    return descFila;
}

NodoFila *inicializaNodoF(Musica *musica){
    NodoFila *nodo = malloc(sizeof(NodoFila));
    nodo->ant = NULL;
    nodo->prox = NULL;
    nodo->info = musica;
    return nodo;
}