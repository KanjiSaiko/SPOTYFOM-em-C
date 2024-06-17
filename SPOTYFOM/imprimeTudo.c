#include "bibliotecas.h"


void imprime(DescLE *descritor){
    NodoLP *aux = descritor->primeiro;
    while (aux != NULL){
        printf("\n==========================\n");
        printf("Titulo: %s\n", aux->info->titulo);
        printf("Letra: %s\n", aux->info->letra);
        printf("Artista: %s\n", aux->info->artista);
        printf("==========================\n");
    }
}