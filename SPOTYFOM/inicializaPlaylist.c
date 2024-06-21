#include "bibliotecas.h"


Playlist *inicializaPlaylist(){
    Playlist *playlist = malloc(sizeof(Playlist));
    playlist->PlaylistFila = NULL;
    playlist->PlaylistPilha = NULL;
    
    return playlist;
}