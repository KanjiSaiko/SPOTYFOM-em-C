#include "./Arquivos-h/bibliotecas.h"
#include "./Arquivos-h/menu.h"
#include "./Arquivos-h/ImprimeExecucoes.h"
#include "./Arquivos-h/imprimeIMPRESSAO.h"

int main(void){
    DescLE *descritorLE = NULL;
    Playlist *playlist = NULL;
    char escolha, escolhaplaylist, escolhaExec;
    int tamlinhas;
    Musica *musicaBuscada = NULL;
    system("clear");
    //primeiro le arquivo:
        descritorLE = parser(&tamlinhas); //abre e le o arquivo, adicionando cada musica em nodos e por fim no descritor
    playlist = inicializaPlaylist();
    inicializa_ncurses();
    
    do{ 
        system("clear");
        escolha = terminal(playlist);
        switch(escolha){
            case '1':
                //ADICIONAR A QUESTAO DE QUANDO EXECUTAR E EXCLUIR A PLAYLIST, NAO IMPRIMI-LO NO RELATORIO.
                printf("Execute a playlist: [A]leatorio || [P]essoal: ");
                scanf(" %c", &escolhaExec);
                if(escolhaExec == 'A' || escolhaExec == 'a'){
                    descritorLE = ExecucaoRandom(playlist, descritorLE);
                }
                else if(escolhaExec == 'P' || escolhaExec== 'p'){
                    descritorLE = ExecucaoPessoal(playlist, descritorLE);
                }
                break;
            
            case '2':
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

            case '3':
                imprime(descritorLE);
                break;

            case '4':
                Relatorio(playlist, descritorLE);
                break;
            
            case '5':
                musicaBuscada = BuscaPorTudo(descritorLE);
                break;

            case '6':
                Backup(descritorLE);
                break;

            case '0':
                break;
        }
    }while(escolha != '0');
    endwin();
    return 0;
}