#ifndef ImprimeExec_h
#define ImprimeExec_h


#include "bibliotecas.h"
#include "menu.h"


struct TelaExec{
    WINDOW *header;
    WINDOW *content;
    WINDOW *footer;
};

int ImprimePlaylistRandom(DescFila *playlistRandom);
int ImprimePlaylistPessoal(DescPilha *playlistPessoal);
void desenhaTelaMusicas(float *altura, float *largura, struct TelaExec *TelaMusicas);
void desenhaplaylistRandom(float *altura, float *largura, struct TelaExec *playlistRandom);
void desenhaMusicasRandom(float largura, float altura, struct TelaExec *playlistRandom, DescFila *FilaCorreta);
void desenhaMusicasPessoal(float largura, float altura, struct TelaExec *TelaMusicas, DescPilha *PilhaCorreta);
void inicializa_ncurses();




#endif