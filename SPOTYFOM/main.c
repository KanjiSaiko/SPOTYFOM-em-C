#include "bibliotecas.h"
#include "INTERFACES.h"

int main(void){
    DescLE *descritorLE = NULL;
    Playlist *playlist = NULL;
    char escolha, escolhaplaylist, escolhaExec;
    int tamlinhas;
    Musica *musicaBuscada = NULL;
    //primeiro le arquivo:
        descritorLE = parser(&tamlinhas); //abre e le o arquivo, adicionando cada musica em nodos e por fim no descritor
    playlist = inicializaPlaylist();

    //INICIALIZA O NCURSES
        initscr();
        cbreak();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
    //depois apresenta o menu de opcoes
    do{ 
        system("clear");
        escolha = interface(playlist, escolha);
        /*printf("\n======================\n");
        printf("Digite:\n[1]Executar\n[2]Playlist\n[3]Buscar\n[4]Imprimir\n[5]Relatorio\n[6]Backup\n[0]Sair\n");
        getchar();
        setbuf(stdin, NULL);
        scanf(" %c", &escolha);*/
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
                musicaBuscada = Busca(descritorLE);
                break;

            case '6':
                Backup(descritorLE);
                break;

            case '0':
                break;
        }
    }while(escolha != '0');
    
    //ENCERRA NCURSES
        endwin();
    return 0;
}