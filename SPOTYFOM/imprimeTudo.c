#include "./Arquivos-h/bibliotecas.h"
#include "./Arquivos-h/imprimeIMPRESSAO.h"


void imprime(DescLE *descritor){
    NodoLP *aux = descritor->primeiro;
    char titulo[256], escolha;
    int loop = 1;
    endwin();
        aux = descritor->primeiro;
        printf("Digite: [1] Imprimir pelo titulo || [2] para imprimir tudo\n");
        setbuf(stdin, NULL);
        scanf(" %c", &escolha);
        switch(escolha){
            case '1':
                printf("Digite o titulo a ser buscado: ");
                setbuf(stdin, NULL);
                getchar();
                fgets(titulo, 256, stdin);
                titulo[strlen(titulo) - 1] = '\0';
                while(aux != NULL){
                    if(strcmp(aux->info->titulo, titulo) == 0){
                        imprimeTudo(aux->info->titulo, aux->info->letra, aux->info->artista, aux->info->execucoes, aux->info->codigo);
                        loop = 0;
                        break;
                    }
                    aux = aux->prox;
                }
                ImprimePorTitulo(aux);
                break;

            case '2':
                ImprimeMUSICAS(descritor);
                while (aux != NULL){
                    imprimeTudo(aux->info->titulo, aux->info->letra, aux->info->artista, aux->info->execucoes, aux->info->codigo);
                    aux = aux->prox;
                }
                break;
        }

}

void imprimeTudo(char *titulo, char *letra, char *artista, int execucoes, int codigo){
        printf("\n==========================\n");
        printf("Titulo: %s\n", titulo);
        printf("Letra: %s\n", letra);
        printf("Artista: %s\n", artista);
        printf("Execucoes: %d\n", execucoes);
        printf("Codigo: %d\n", codigo);
        printf("==========================\n");
}