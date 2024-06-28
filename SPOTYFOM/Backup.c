#include "bibliotecas.h"



void *Backup(DescLE *descritor){
    NodoLP *aux = descritor->primeiro;
    FILE *arqA = fopen("./musicas/BACKUP.txt", "w");
            
    if(arqA){
        fprintf(arqA, "%d\n", descritor->tamanho);
        while(aux != NULL){
            fprintf(arqA, "%s;", aux->info->artista);
            fprintf(arqA, "%d;", aux->info->codigo);
            fprintf(arqA, "%s;", aux->info->titulo);
            fprintf(arqA, "%s;", aux->info->letra);
            fprintf(arqA, "%d\n", aux->info->execucoes);
            aux = aux->prox;
        }
        fclose(arqA);
        printf("BACKUP escrito com sucesso!\n");
    }
}