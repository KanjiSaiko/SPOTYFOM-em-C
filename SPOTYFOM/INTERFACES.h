/*#ifndef interface_h
#define interface_h

#include <ncurses.h>
#include <menu.h>
#include "bibliotecas.h"

typedef struct TelaPrincipal TelaPrincipal;

struct TelaPrincipal{
    WINDOW *header;
    WINDOW *menu;
    WINDOW *content;
    WINDOW *footer;
};
void desenhaTelaInicial(float *altura, float *largura, TelaPrincipal *tela);
char interface(Playlist *playlist);
void desenhaMenu(TelaPrincipal *tela, float largura, float altura, Playlist *playlist);

#endif