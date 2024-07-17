#include "./Arquivos-h/bibliotecas.h"
#include "./Arquivos-h/imprimeIMPRESSAO.h"

Musica *BuscaPorTudo(DescLE *descritor){
    DescPilha *album = inicializaPilha();
    NodoLP *nodop = NULL;
    NodoLP *aux = descritor->primeiro;
    char artista[256], titulo[256];
    int codigo, escolha;
    printf("Busque por [1] Artista | [2] Titulo | [3] Codigo\n");
    scanf("%d", &escolha);
    switch(escolha){
        case 1:
            printf("Digite o nome do artista: ");
            getchar();
            setbuf(stdin, NULL);
            fgets(artista, 256, stdin);
            artista[strlen(artista) - 1] = '\0'; //remove a quebra de linha e coloca terminador nulo
            //percorro meu acervo
                while(aux != NULL){
                    if(!strcmp(aux->info->artista, artista)){
                        printf("\n==========================\n");
                        printf("Titulo: %s\n", aux->info->titulo);
                        printf("Letra: %s\n", aux->info->letra);
                        printf("Artista: %s\n", aux->info->artista);
                        printf("==========================\n");
                        nodop = inicializaNodoP(aux->info);
                        album = addNodoPilha(album, nodop);
                    }
                    aux = aux->prox;
                }
                ImprimeAlbum(album);
                break;



        case 2:
            printf("Digite o titulo da musica: ");
            getchar();
            setbuf(stdin, NULL);
            fgets(titulo, 256, stdin);
            titulo[strlen(titulo) - 1] = '\0'; //remove a quebra de linha e coloca terminador nulo
            //percorro meu acervo
                while(aux != NULL){
                    if(!strcmp(aux->info->titulo, titulo)){
                        printf("\n==========================\n");
                        printf("Titulo: %s\n", aux->info->titulo);
                        printf("Letra: %s\n", aux->info->letra);
                        printf("Artista: %s\n", aux->info->artista);
                        printf("==========================\n");
                        ImprimePorBusca(aux);
                        return aux->info;
                    }
                    aux = aux->prox;
                }
            printf("Musica nao encontrada.\n");
            break;


        case 3:
            printf("Digite o codigo da musica: ");
            scanf("%d", &codigo);
            //percorro meu acervo
                while(aux != NULL){
                    if(codigo == aux->info->codigo){
                        printf("\n==========================\n");
                        printf("Titulo: %s\n", aux->info->titulo);
                        printf("Letra: %s\n", aux->info->letra);
                        printf("Artista: %s\n", aux->info->artista);
                        printf("==========================\n");
                        ImprimePorBusca(aux);
                        return aux->info;
                    }
                    aux = aux->prox;
                }
            printf("Musica nao encontrada.\n");
            break;

    }

}


DescPilha *BuscaAlbum(DescLE *descritor, DescPilha *album){
    NodoLP *aux = descritor->primeiro;
    NodoLP *nodo = NULL;
    char artista[256];
    printf("Digite o nome do artista: ");
    getchar();
    setbuf(stdin, NULL);
    fgets(artista, 256, stdin);
    artista[strlen(artista) - 1] = '\0'; //remove a quebra de linha e coloca terminador nulo
    //percorro meu acervo
        while(aux != NULL){
            if(!strcmp(aux->info->artista, artista)){
                nodo = inicializaNodoP(aux->info);
                album = addNodoPilha(album, nodo);
            }
            aux = aux->prox;
        }
    return album;
}

DescPilha *BuscaMusica(DescLE *descritor, DescPilha *album){
    NodoLP *aux = descritor->primeiro;
    NodoLP *nodo = NULL;
    char artista[256], titulo[256];
    printf("Digite o nome do artista: ");
    getchar();
    setbuf(stdin, NULL);
    fgets(artista, 256, stdin);
    printf("Digite o titulo da musica: ");
    setbuf(stdin, NULL);
    fgets(titulo, 256, stdin);
    setbuf(stdin, NULL);

    titulo[strlen(titulo) - 1] = '\0';
    artista[strlen(artista) - 1] = '\0'; //remove a quebra de linha e coloca terminador nulo
    //percorro meu acervo
        while(aux != NULL){
            if(!strcmp(aux->info->artista, artista) && !strcmp(aux->info->titulo, titulo)){
                nodo = inicializaNodoP(aux->info);
                album = addNodoPilha(album, nodo);
            }
            aux = aux->prox;
        }
    return album;
}
