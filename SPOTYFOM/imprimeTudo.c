#include "bibliotecas.h"


void imprime(DescLE *descritor){
    NodoLP *aux = descritor->primeiro;
    char titulo[256];
    int escolha, loop = 1;
    do{
        aux = descritor->primeiro;
        printf("Digite: [1] Imprimir pelo titulo || [2] para imprimir tudo\n");
        scanf("%d", &escolha);
        if(escolha == 1){
            printf("Digite o titulo a ser buscado: ");
            fgets(titulo, 256, stdin);
            titulo[256 - 1] = '\0';
            while(aux != NULL){
                if(strcmp(aux->info->titulo, titulo) == 0){
                    printf("\n==========================\n");
                    printf("Titulo: %s\n", aux->info->titulo);
                    printf("Letra: %s\n", aux->info->letra);
                    printf("Artista: %s\n", aux->info->artista);
                    printf("Execucoes: %d\n", aux->info->execucoes);
                    printf("Codigo: %d\n", aux->info->codigo);
                    printf("==========================\n");
                    loop = 0;
                    break;
                }
                aux = aux->prox;
            }
        }

        else if(escolha == 2){
            while (aux != NULL){
                printf("\n==========================\n");
                printf("Titulo: %s\n", aux->info->titulo);
                printf("Letra: %s\n", aux->info->letra);
                printf("Artista: %s\n", aux->info->artista);
                printf("Execucoes: %d\n", aux->info->execucoes);
                printf("Codigo: %d\n", aux->info->codigo);
                printf("==========================\n");
                aux = aux->prox;
            }
        }
        else {
            printf("Opcao inexistente.\n");
        }

    }while(loop == 1);
}