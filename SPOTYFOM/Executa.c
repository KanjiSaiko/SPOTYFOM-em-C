#include "bibliotecas.h"


DescLE *ExecucaoRandom(Playlist *playlist, DescLE *descritor){ //na playlist randomica
    if(playlist->PlaylistFila->head == NULL){
        printf("Playlist randomica vazia.\n");
        return NULL;
    }
    NodoFila *aux = playlist->PlaylistFila->head;
    NodoLP *aux2 = descritor->primeiro;
    
    while(aux != NULL){ // executando em fila as musicas:
        printf("\n==========================\n");
        printf("Titulo: %s\n", aux->info->titulo);
        printf("Letra: %s\n", aux->info->letra);
        printf("Artista: %s\n", aux->info->artista);
        printf("==========================\n");
        while(aux2 != NULL){
            if(aux2->info->codigo == aux->info->codigo){
                aux2->info->execucoes++;
                break;
            }
            aux2 = aux2->prox;
        }

        playlist->PlaylistFila->head = aux->prox; //retira musica da playlist random
        if(playlist->PlaylistFila->head != NULL){
            playlist->PlaylistFila->head->ant = NULL;
        }
        else {
            playlist->PlaylistFila->tail = NULL;
        }
        aux = aux->prox; //busca proxima musica;
        playlist->PlaylistFila->tamanho--;  //diminui tamanho da playlist randomica
    }
    return descritor;
}



DescLE *ExecucaoPessoal(Playlist *playlist, DescLE *descritor){
    if(playlist->PlaylistPilha->Topo == NULL){
        printf("Playlist Pessoal vazia.\n");
        return NULL;
    }
    NodoLP *aux = playlist->PlaylistPilha->Topo;
    NodoLP *aux2 = descritor->primeiro;

    while(aux != NULL){
        printf("\n==========================\n");
        printf("Titulo: %s\n", aux->info->titulo);
        printf("Letra: %s\n", aux->info->letra);
        printf("Artista: %s\n", aux->info->artista);
        printf("==========================\n");
        while(aux2 != NULL){
            if(aux2->info->codigo == aux->info->codigo){
                aux2->info->execucoes++;
                break;
            }
            aux2 = aux2->prox;
        }
    
        playlist->PlaylistPilha->Topo = aux->prox; //retira a musica
        playlist->PlaylistPilha->tamanho--;
        if(playlist->PlaylistPilha->tamanho == 0){
            playlist->PlaylistPilha->Fundo = NULL;
        }
        aux = aux->prox;
    }
    return descritor;
}