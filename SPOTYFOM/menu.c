#include "bibliotecas.h"


int main(void){
    DescLE *descritorLE = NULL;
    Playlist *playlist = NULL;
    char escolha, escolhaplaylist, escolhaExec;
    int escolhaaux = 1, tamlinhas;
    Musica *musicaBuscada = NULL;
    //primeiro le arquivo:
    descritorLE = parser(&tamlinhas); //abre e le o arquivo, adicionando cada musica em nodos e por fim no descritor
    playlist = inicializaPlaylist();
    //depois apresenta o menu de opcoes
    do{ 
        printf("\n======================\n");
        printf("Digite:\n[E]xecutar\n[P]laylist\n[B]uscar\n[I]mprimir\n[R]elatorio\n[K]Backup\n[S]air\n");
        getchar();
        setbuf(stdin, NULL);
        scanf(" %c", &escolha);
        switch(escolha){
            case 'e':
            case 'E':
                //ADICIONAR A QUESTAO DE QUANDO EXECUTAR E EXCLUIR A PLAYLIST, NAO IMPRIMI-LO NO RELATORIO.
                printf("Execute a playlist: [A]leatorio || [P]essoal: ");
                scanf(" %c", &escolhaExec);
                if(escolhaplaylist == 'A' || escolhaplaylist == 'a'){
                    descritorLE = ExecucaoRandom(playlist, descritorLE);
                }
                else if(escolhaplaylist == 'P' || escolhaplaylist == 'p'){
                    descritorLE = ExecucaoPessoal(playlist, descritorLE);
                }
                break;
            
            case 'p':
            case 'P':
                printf("Digite: [A]leatorio || [P]essoal: ");
                setbuf(stdin, NULL);
                scanf(" %c", &escolhaplaylist);
                if(escolhaplaylist == 'A' || escolhaplaylist == 'a'){
                    playlist = playlistRandom(descritorLE, tamlinhas, playlist);
                }
                else if(escolhaplaylist == 'P' || escolhaplaylist == 'p'){
                    playlist = playlistPessoal(descritorLE, playlist);
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
                Relatorio(playlist, descritorLE);
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