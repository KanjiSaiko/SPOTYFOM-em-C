#include "bibliotecas.h"

DescLE *inicializaLE(){
    DescLE *descritorLE = malloc(sizeof(DescLE));
    descritorLE->primeiro = NULL;
    descritorLE->tamanho = 0;
    return descritorLE;
}