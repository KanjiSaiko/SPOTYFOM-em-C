#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct musica Musica;
typedef struct nodoLE NodoLP;
typedef struct dscLE DescLE;
typedef struct nodo_fila NodoFila;
typedef struct dscFila DescFila;
typedef struct desc_Pilha DescPilha;


struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes; //numero de execuções da musica em playlists
};


struct dscLE{
    int tamanho;
    NodoLP *primeiro;
};


struct nodoLE{
    Musica *info;
    NodoLP *prox;
};


struct nodo_fila{
    NodoFila *prox;
    Musica *info;
    NodoFila *ant;
};


struct dscFila{
    NodoFila *head, *tail;
    int tamanho;
};


struct desc_Pilha{
    NodoLP *Fundo, *Topo;
    int tamanho;
};


DescLE *inicializaLE();
DescPilha *inicializaPilha();
DescFila *inicializaFila();
DescLE *parser();
NodoLP *criaNodo();
DescLE *addMusica(DescLE *descritorLista, NodoLP *nodo);
void imprime(DescLE *descritor);