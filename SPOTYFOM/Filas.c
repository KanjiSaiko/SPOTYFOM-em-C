#include "./Arquivos-h/bibliotecas.h"


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
    descFila->prox = NULL;
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

DescFila *Dequeue(DescFila *descritor){
    NodoFila *aux = descritor->head;
    descritor->head = aux->prox;
    if(descritor->head != NULL){
        descritor->head->ant = NULL;
    }
    else{
        descritor->tail = NULL;
    }
    descritor->tamanho--;
    return descritor;
}