#ifndef menu_h
#define menu_h

#include <ncurses.h>
#include <menu.h>
#include "bibliotecas.h"

struct TELA{
    WINDOW *header;
    WINDOW *menu;
    WINDOW *content;
    WINDOW *footer;
};

void desenhaTelaInicial(struct TELA *tela, float *altura, float *largura);
void desenhaMenu(struct TELA *tela, float largura, Playlist *playlist);
char terminal(Playlist *playlist);
void inicializaTerminal();
void finalizaTerminal();


#endif