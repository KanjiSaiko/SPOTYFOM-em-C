#include "bibliotecas.h"

Playlist *playlistRandom(DescLE *descritor, int tamlinhas, Playlist *playlist){
    DescFila *playlistFila = inicializaFila();
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
        playlistFila = addNodoFila(playlistFila, nodo);
        aux = descritor->primeiro;
        tamanhoaux++;
    }
    printf("Criacao da playlist randomica concluida!\n");
    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    fgets(playlistFila->nome, 100, stdin);
    playlistFila->nome[strlen(playlistFila->nome) - 1] = '\0';
    //adiciona a nova fila na playlist:
    if(playlist->primeiroFila == NULL){
        playlist->primeiroFila = playlistFila;
    }
    else{
        DescFila *auxplaylist = playlist->primeiroFila;
        while(auxplaylist->prox != NULL){
            auxplaylist = auxplaylist->prox;
        }
        auxplaylist->prox = playlistFila;
    }
    return playlist;
}


Playlist *playlistPessoal(DescLE *descritor, Playlist *playlist){
    DescPilha *playlistPilha = malloc(sizeof(DescPilha));
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
            playlistPilha = addNodoPilha(playlistPilha, nodo);
        }
        else if(escolha == 'c' || escolha == 'C'){
            auxiliar = 0;
        }
        else {
            printf("\nOpcao incorreta, tente novamente.\n");
        }
    }while(auxiliar == 1);

    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    fgets(playlistPilha->nome, 100, stdin);
    playlistPilha->nome[strlen(playlistPilha->nome) - 1] = '\0';
    //adiciona a nova pilha na playlist:
    if(playlist->primeiroPilha == NULL){
        playlist->primeiroPilha = playlistPilha;
    }
    else{
        DescPilha *auxplaylist = playlist->primeiroPilha;
        while(auxplaylist->prox != NULL){
            auxplaylist = auxplaylist->prox;
        }
        auxplaylist->prox = playlistPilha;
    }
    printf("Criacao da playlist pessoal concluida!\n");
    return playlist;
}