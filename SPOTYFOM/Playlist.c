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
    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    scanf("%s", playlistFila->nome);
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
    printf("Criacao da playlist randomica concluida!\n");
    return playlist;
}


Playlist *playlistPessoal(DescLE *descritor, Playlist *playlist){
    DescPilha *playlistPilha = inicializaPilha();
    //NodoLP *aux = descritor->primeiro;
    Musica *musica;
    int auxiliar = 1;
    char escolha;

    do{
        musica = Busca(descritor);
        NodoLP *nodo = inicializaNodoP(musica);
        playlistPilha = addNodoPilha(playlistPilha, nodo);
        printf("Digite [1] para adicionar mais Musicas || [0] para criar a playlist\n");
        scanf(" %c", &escolha);
        if(escolha != '1' && escolha != '0'){
            printf("Opcao inexistente\n");
        }
    }while(escolha != '0');
    

    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    scanf("%s", playlistPilha->nome);
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
    getchar();
    setbuf(stdin, NULL);
   
    printf("Criacao da playlist pessoal concluida!\n");
    return playlist;
}