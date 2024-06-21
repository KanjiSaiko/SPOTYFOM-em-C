#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct musica Musica;
typedef struct nodoLE NodoLP;
typedef struct dscLE DescLE;
typedef struct nodo_fila NodoFila;
typedef struct dscFila DescFila;
typedef struct desc_Pilha DescPilha;
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


struct dscFila{
    NodoFila *head, *tail;
    int tamanho;
};


struct desc_Pilha{
    NodoLP *Fundo, *Topo;
    int tamanho;
};

struct Playlist{
    DescFila *PlaylistFila;
    DescPilha *PlaylistPilha;
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
DescFila *playlistRandom(DescLE *descritor, int tamlinhas);
DescPilha *playlistPessoal(DescLE *descritor);
DescLE *ExecucaoRandom(Playlist *playlist, DescLE *descritor);
DescLE *ExecucaoPessoal(Playlist *playlist, DescLE *descritor);
void Relatorio(Playlist *playlist, DescLE *descritor);