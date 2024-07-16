#include "./Arquivos-h/bibliotecas.h"
#include "./Arquivos-h/ImprimeExecucoes.h"

DescLE *ExecucaoRandom(Playlist *playlist, DescLE *descritor){ //na playlist randomica
    char nome[100];
    DescFila *FilaCorreta = playlist->primeiroFila;
    DescFila *ant;
        if(playlist->primeiroFila == NULL){
            printf("Crie uma playlist anteriormente\n");
            return descritor;
        }
        printf("Digite o nome da playlist a ser executada: ");
        setbuf(stdin, NULL);
        scanf("%s", nome);
        while(FilaCorreta != NULL){
            ant = FilaCorreta;
            if(strcmp(nome, FilaCorreta->nome) == 0){
                break;
            }
            FilaCorreta = FilaCorreta->prox;
        }

        if(FilaCorreta == NULL){
            printf("Playlist nao encontrada.\n");
            return descritor;
            //strcpy(nome, "\0");
        }


    if(FilaCorreta->head == NULL){
        printf("Playlist %s vazia.\n", nome);
    }
    
    NodoFila *aux = FilaCorreta->head;
    NodoLP *aux2 = descritor->primeiro;
    //INICIALIZA INTERFACE GRÁFICA
            inicializa_ncurses();
            ImprimePlaylistRandom(FilaCorreta);
            endwin();

    while(aux != NULL){ // executando em fila as musicas:
        printaExec(aux->info->titulo, aux->info->letra, aux->info->artista);
        
        aux2 = descritor->primeiro;
        while(aux2 != NULL){
            //procuro a musica no acervo atraves do codigo e adiciono uma execução
                if(aux2->info->codigo == aux->info->codigo){
                    aux2->info->execucoes++;
                    break;
                }
            aux2 = aux2->prox;
        }
        FilaCorreta = Dequeue(FilaCorreta);
        aux = aux->prox; //busca proxima musica;
    }

    ant->prox = FilaCorreta->prox;
    return descritor;
}



DescLE *ExecucaoPessoal(Playlist *playlist, DescLE *descritor){
    char nome[100];
    DescPilha *PilhaCorreta = playlist->primeiroPilha;
    DescPilha *ant;
        printf("Digite o nome da playlist a ser executada: ");
        getchar();
        setbuf(stdin, NULL);
        fgets(nome, 100, stdin);
        nome[strlen(nome) - 1] = '\0';
        while(PilhaCorreta != NULL){
            ant = PilhaCorreta;
            if(strcmp(nome, PilhaCorreta->nome) == 0){
                break;
            }
            PilhaCorreta = PilhaCorreta->prox;
        }
        
        if(PilhaCorreta == NULL){
            printf("Playlist nao encontrada. Tente novamente.\n");
            return descritor;
        }

    if(PilhaCorreta->Topo == NULL){
        printf("Playlist Pessoal: %s vazia.\n", nome);
        return descritor;
    }
    NodoLP *aux = PilhaCorreta->Topo;
    NodoLP *aux2 = descritor->primeiro;
    //INICIALIZA INTERFACE GRÁFICA
            inicializa_ncurses();
            ImprimePlaylistPessoal(PilhaCorreta);
            endwin();
            
    while(aux != NULL){
        printaExec(aux->info->titulo, aux->info->letra, aux->info->artista);
        
        //percorro o acervo para incrementar o numero de execucoes
            while(aux2 != NULL){
                if(aux2->info->codigo == aux->info->codigo){
                    aux2->info->execucoes++;
                    break;
                }
                aux2 = aux2->prox;
            }

        PilhaCorreta = POP(PilhaCorreta);
        aux = aux->prox;
    }

    ant->prox = PilhaCorreta->prox;
    return descritor;
}


void printaExec(char *titulo, char *letra, char *artista){
        printf("\n==========================\n");
        printf("Titulo: %s\n", titulo);
        printf("Letra: %s\n", letra);
        printf("Artista: %s\n", artista);
        printf("==========================\n");
}