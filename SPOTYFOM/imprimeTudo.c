#include "./Arquivos-h/bibliotecas.h"
#include "./Arquivos-h/imprimeIMPRESSAO.h"


void imprime(DescLE *descritor){
    NodoLP *aux = descritor->primeiro;
    char titulo[256], escolha;
    int loop = 1;
    endwin();
    do{
        aux = descritor->primeiro;
        printf("Digite: [1] Imprimir pelo titulo || [2] para imprimir tudo || Qualquer outra tecla para voltar\n");
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
                ImprimePorTitulo(aux);
                break;

            case '2':
                ImprimeMUSICAS(descritor);
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
                break;

            default:
                loop = 0;
                break;
        }

    }while(loop == 1);

}