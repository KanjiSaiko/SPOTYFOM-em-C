#include "bibliotecas.h"

DescFila *inicializaFila(){
    DescFila *descFila = malloc(sizeof(DescFila));
    descFila->head = NULL;
    descFila->tail = NULL;
    descFila->tamanho = 0;
    return descFila;
}