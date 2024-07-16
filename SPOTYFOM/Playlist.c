#include "./Arquivos-h/bibliotecas.h"

Playlist *playlistRandom(DescLE *descritor, int tamlinhas, Playlist *playlist){
    DescFila *playlistFila = inicializaFila();
    NodoLP *aux = descritor->primeiro;
    Musica *musica = NULL;
    srand(time(NULL));
    int auxiliar, auxiliar2, tamanho, tamanhoaux = 0;
    printf("Digite o tamanho da playlist: ");
    setbuf(stdin, NULL);
    scanf("%d", &tamanho);
    while(tamanhoaux != tamanho){
        //inicío os valores dos auxiliares como aleatorios
        auxiliar = rand() % tamlinhas; 
        auxiliar2 = rand() % tamlinhas;
        //enquanto busco a igualdade de 2 numeros jogados de forma aleatoria, vou passando o aux adiante
            while(auxiliar != auxiliar2){ 
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
    DescFila *auxplaylist = playlist->primeiroFila;

    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    scanf("%s", playlistFila->nome);

    //VERIFICAÇÃO PARA VER SE A PLAYLIST COM ESSE NOME JA EXISTE, CASO EXISTA, COLOCO AS MUSICAS DENTRO DELA
        while(auxplaylist != NULL){
                if(strcmp(auxplaylist->nome, playlistFila->nome) == 0){
                    //ENCONTROU UMA PLAYLIST EXISTENTE:
                        //adicionar os itens na playlist antiga ao inves de substituir:
                            while(playlistFila->head != NULL){
                                musica = playlistFila->head->info;
                                NodoFila *nodoFila = inicializaNodoF(musica);
                                auxplaylist = addNodoFila(auxplaylist, nodoFila);
                                playlistFila = Dequeue(playlistFila);
                            }
                    return playlist;
                }
                auxplaylist = auxplaylist->prox;
        }

    //adiciona a nova fila na playlist:
        if(playlist->primeiroFila == NULL){
            playlist->primeiroFila = playlistFila;
        }
        else{
            auxplaylist = playlist->primeiroFila;
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
    Musica *musica = NULL;
    int auxiliar = 1;
    char escolha1, escolha2;
    DescPilha *auxplaylist = playlist->primeiroPilha;

    printf("De um nome a playlist: ");
    setbuf(stdin, NULL);
    scanf("%s", playlistPilha->nome);

    

    do{
        printf("Digite [1] para adicionar um album || [Any] para uma musica\n");
        scanf(" %c", &escolha2);

        if(escolha2 == '1'){
            playlistPilha = BuscaAlbum(descritor, playlistPilha);
        }

        else{
            playlistPilha = BuscaMusica(descritor, playlistPilha);
        }
        
        printf("Digite [1] para adicionar mais Musicas || [Any] para criar a playlist\n");
        setbuf(stdin, NULL);
        scanf(" %c", &escolha1);

    }while(escolha1 == '1');

    //VERIFICAÇÃO PARA VER SE A PLAYLIST COM ESSE NOME JA EXISTE, CASO EXISTA, COLOCO AS MUSICAS DENTRO DELA
        while(auxplaylist != NULL){
                if(strcmp(auxplaylist->nome, playlistPilha->nome) == 0){
                    //ENCONTROU UMA PLAYLIST EXISTENTE:
                        //adicionar os itens na playlist antiga ao inves de substituir:
                            while(playlistPilha->Fundo != NULL){
                                musica = playlistPilha->Topo->info;
                                NodoLP *nodoPilha = inicializaNodoP(musica);
                                auxplaylist = addNodoPilha(auxplaylist, nodoPilha);
                                playlistPilha = POP(playlistPilha);
                            }
                    return playlist;
                }
                auxplaylist = auxplaylist->prox;
        }

    //adiciona a nova pilha na playlist:
        if(playlist->primeiroPilha == NULL){
            playlist->primeiroPilha = playlistPilha;
        }
        else{
            auxplaylist = playlist->primeiroPilha;
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