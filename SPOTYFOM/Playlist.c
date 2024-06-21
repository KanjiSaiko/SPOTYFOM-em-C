#include "bibliotecas.h"

DescFila *playlistRandom(DescLE *descritor, int tamlinhas){
    DescFila *playlist = inicializaFila();
    NodoLP *aux = descritor->primeiro;
    srand(time(NULL));
    int auxiliar, auxiliar2, tamanho, tamanhoaux = 0;
    printf("Digite o tamanho da playlist: ");
    scanf("%d", &tamanho);
    while(tamanhoaux != tamanho){ //100 musicas na playlist
        auxiliar = rand() % tamlinhas; //inicío o valor do auxiliar como aleatorio
        auxiliar2 = rand() % tamlinhas;
        while(auxiliar != auxiliar2){ //enquanto busco a igualdade de 2 numeros jogados de forma aleatoria, vou passando o aux adiante
            aux = aux->prox;
            if(auxiliar > auxiliar2){
                auxiliar--;
            }
            else{
                auxiliar++;
            }
        }
        NodoFila *nodo = inicializaNodoF(aux->info);
        playlist = addNodoFila(playlist, nodo);
        aux = descritor->primeiro;
        tamanhoaux++;
    }
    printf("Criacao da playlist randomica concluida!\n");
    return playlist;
}


DescPilha *playlistPessoal(DescLE *descritor){
    DescPilha *playlist = malloc(sizeof(DescPilha));
    NodoLP *aux = descritor->primeiro;
    Musica *musica;
    int auxiliar = 1;
    char escolha;
    do{
        printf("Digite: [I]nserir || [C]ancelar insercao\n");
        scanf(" %c", &escolha);
        if(escolha == 'i' || escolha == 'I'){
            musica = Busca(descritor);
            NodoLP *nodo = inicializaNodoP(musica);
            playlist = addNodoPilha(playlist, nodo);
        }
        else if(escolha == 'c' || escolha == 'C'){
            auxiliar = 0;
        }
        else {
            printf("\nOpcao incorreta, tente novamente.\n");
        }
    }while(auxiliar == 1);
    printf("Criacao da playlist pessoal concluida!\n");
    return playlist;
}