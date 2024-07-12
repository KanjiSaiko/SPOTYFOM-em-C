#ifndef bibliotecas_h
#define bibliotecas_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct musica Musica;
typedef struct nodoLE NodoLP;
typedef struct dscLE DescLE;
typedef struct nodo_fila NodoFila;
typedef struct FilaPlaylist DescFila;
typedef struct PilhaPlaylist DescPilha;
typedef struct Playlist Playlist;


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


struct FilaPlaylist{
    NodoFila *head, *tail;
    struct FilaPlaylist *prox;
    char nome[100];
    int tamanho;
};


struct PilhaPlaylist{
    NodoLP *Fundo, *Topo;
    struct PilhaPlaylist *prox;
    char nome[100];
    int tamanho;
};



struct Playlist{
    DescFila *primeiroFila;
    DescPilha *primeiroPilha;
};


DescLE *inicializaLE();
DescPilha *inicializaPilha();
DescFila *inicializaFila();
Playlist *inicializaPlaylist();
DescLE *parser(int *tamLinhas);
NodoLP *criaNodo();
DescLE *addMusica(DescLE *descritorLista, NodoLP *nodo);
void imprime(DescLE *descritor);
Musica *Busca(DescLE *descritor);
NodoFila *inicializaNodoF(Musica *musica);
DescFila *addNodoFila(DescFila *descritor, NodoFila *nodo);
NodoLP *inicializaNodoP(Musica *musica);
DescPilha *addNodoPilha(DescPilha *descritor, NodoLP *nodo);
Playlist *playlistRandom(DescLE *descritor, int tamlinhas, Playlist *playlist);
Playlist *playlistPessoal(DescLE *descritor, Playlist *playlist);
DescLE *ExecucaoRandom(Playlist *playlist, DescLE *descritor);
DescLE *ExecucaoPessoal(Playlist *playlist, DescLE *descritor);
void Relatorio(Playlist *playlist, DescLE *descritor);
void *Backup(DescLE *descritor);


#endif