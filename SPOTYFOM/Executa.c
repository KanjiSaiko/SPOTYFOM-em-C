#include "bibliotecas.h"


DescLE *ExecucaoRandom(Playlist *playlist, DescLE *descritor){ //na playlist randomica
    char nome[100];
    int loop = 1;
    DescFila *FilaCorreta = playlist->primeiroFila;
    DescFila *ant;
    do{
        printf("Digite o nome da playlist a ser executada: ");
        setbuf(stdin, NULL);
        scanf("%s", nome);
        while(FilaCorreta != NULL){
            ant = FilaCorreta;
            if(strcmp(nome, FilaCorreta->nome) == 0){
                loop = 0;
                break;
            }
            FilaCorreta = FilaCorreta->prox;
        }

        if(FilaCorreta == NULL){
            printf("Playlist nao encontrada. Tente novamente.\n");
            FilaCorreta = playlist->primeiroFila;
            //strcpy(nome, "\0");
        }
            
        
    }while(loop == 1);

    if(FilaCorreta->head == NULL){
        printf("Playlist %s vazia.\n", nome);
        return NULL;
    }

    NodoFila *aux = FilaCorreta->head;
    NodoLP *aux2 = descritor->primeiro;
    
    while(aux != NULL){ // executando em fila as musicas:
        printf("\n==========================\n");
        printf("Titulo: %s\n", aux->info->titulo);
        printf("Letra: %s\n", aux->info->letra);
        printf("Artista: %s\n", aux->info->artista);
        printf("==========================\n");
        aux2 = descritor->primeiro;
        while(aux2 != NULL){
            if(aux2->info->codigo == aux->info->codigo){
                aux2->info->execucoes++;
                break;
            }
            aux2 = aux2->prox;
        }

        FilaCorreta->head = aux->prox; //retira musica da playlist random
        if(FilaCorreta->head != NULL){
            FilaCorreta->head->ant = NULL;
        }
        else {
            FilaCorreta->tail = NULL;
        }
        aux = aux->prox; //busca proxima musica;
        FilaCorreta->tamanho--;  //diminui tamanho da playlist randomica
    }
    ant->prox = FilaCorreta->prox;
    return descritor;
}



DescLE *ExecucaoPessoal(Playlist *playlist, DescLE *descritor){
    char nome[100];
    int loop = 1;
    DescPilha *PilhaCorreta = playlist->primeiroPilha;
    DescPilha *ant;
    do{
        printf("Digite o nome da playlist a ser executada: ");
        fgets(nome, 100, stdin);
        nome[strlen(nome) - 1] = '\0';
        while(PilhaCorreta != NULL){
            ant = PilhaCorreta;
            if(strcmp(nome, PilhaCorreta->nome) == 0){
                loop = 0;
                break;
            }
            PilhaCorreta = PilhaCorreta->prox;
        }
        
        if(PilhaCorreta == NULL)
            printf("Playlist nao encontrada. Tente novamente.\n");
        
    }while(loop == 1);



    if(PilhaCorreta->Topo == NULL){
        printf("Playlist Pessoal: %s vazia.\n", nome);
        return NULL;
    }
    NodoLP *aux = PilhaCorreta->Topo;
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
    
        PilhaCorreta->Topo = aux->prox; //retira a musica
        PilhaCorreta->tamanho--;
        if(PilhaCorreta->tamanho == 0){
            PilhaCorreta->Fundo = NULL;
        }
        aux = aux->prox;
    }
    ant->prox = PilhaCorreta->prox;
    free(PilhaCorreta);
    PilhaCorreta = NULL;
    return descritor;
}