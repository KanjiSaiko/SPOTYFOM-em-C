#include "./Arquivos-h/bibliotecas.h"

DescPilha *addNodoPilha(DescPilha *descritor, NodoLP *nodo){
    if(descritor->Topo == NULL){
        descritor->Topo = nodo;
        descritor->Fundo = nodo;
    }
    else {
        nodo->prox = descritor->Topo;
        descritor->Topo = nodo;
    }
    descritor->tamanho++;
    return descritor;

}


NodoLP *inicializaNodoP(Musica *musica){
    NodoLP *nodo = malloc(sizeof(nodo));
    nodo->prox = NULL;
    nodo->info = musica;
    return nodo;
}


DescPilha *inicializaPilha(){
    DescPilha *descPilha = malloc(sizeof(DescPilha));
    descPilha->Fundo = NULL;
    descPilha->Topo = NULL;
    descPilha->prox = NULL;
    descPilha->tamanho = 0;
    return descPilha;
}

DescPilha *POP(DescPilha *descritor){
    if(descritor->Topo == NULL)
        return NULL;
    NodoLP *aux = descritor->Topo;
    descritor->Topo = aux->prox;
    descritor->tamanho--;
    if(descritor->tamanho == 0)
        descritor->Fundo = NULL;
    return descritor;
}