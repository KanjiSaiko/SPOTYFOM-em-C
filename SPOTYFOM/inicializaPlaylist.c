#include "./Arquivos-h/bibliotecas.h"


Playlist *inicializaPlaylist(){
    Playlist *playlist = malloc(sizeof(Playlist));
    playlist->primeiroFila = NULL;
    playlist->primeiroPilha = NULL;
    
    return playlist;
}