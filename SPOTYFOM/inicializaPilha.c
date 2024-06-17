#include "bibliotecas.h"

DescPilha *inicializaPilha(){
    DescPilha *descPilha = malloc(sizeof(DescPilha));
    descPilha->Fundo = NULL;
    descPilha->Topo = NULL;
    descPilha->tamanho = 0;
    return descPilha;
}