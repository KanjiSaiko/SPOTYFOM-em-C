#include "bibliotecas.h"


int main(void){
    DescLE *descritorLE = NULL;
    Playlist *playlist = NULL;
    NodoLP *nodoLista = NULL, *nodoPilha = NULL;
    NodoFila *nodoFila = NULL;
    char escolha, escolhaplaylist;
    int escolhaaux = 1, tamlinhas;
    Musica *musicaBuscada = NULL;
    //primeiro le arquivo:
    descritorLE = parser(&tamlinhas); //abre e le o arquivo, adicionando cada musica em nodos e por fim no descritor
    playlist = inicializaPlaylist();
    //depois apresenta o menu de opcoes
    do{ 
        printf("\n======================\n");
        printf("Digite:\n[E]xecutar\n[P]laylist\n[B]uscar\n[I]mprimir\n[R]elatorio\n[K]Backup\n[S]air\n");
        setbuf(stdin, NULL);
        scanf(" %c", &escolha);
        switch(escolha){
            case 'e':
            case 'E':

                break;
            
            case 'p':
            case 'P':
                printf("Digite: [A]leatorio || [P]essoal: ");
                setbuf(stdin, NULL);
                scanf(" %c", &escolhaplaylist);
                if(escolhaplaylist == 'A' || escolhaplaylist == 'a'){
                    playlist->PlaylistFila = playlistRandom(descritorLE, tamlinhas);
                }
                else if(escolhaplaylist == 'P' || escolhaplaylist == 'p'){
                    playlist->PlaylistPilha = playlistPessoal(descritorLE);
                }
                else {
                    printf("Opcao incorreta.");
                }
                break;

            case 'i':
            case 'I':
                imprime(descritorLE);
                break;

            case 'r':
            case 'R':

                break;
            
            case 'b':
            case 'B':
                musicaBuscada = Busca(descritorLE);
                break;

            case 'k':
            case 'K':
                
                break;

            case 's':
            case 'S':
                escolhaaux = 0;
                break;
        }
    }while(escolhaaux != 0);

    return 0;
}