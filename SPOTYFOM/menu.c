#include "menu.h"

char terminal(Playlist *playlist) {
    float altura, largura;
    int ch, r, i, j, instLogic, instAri, instDesvio, instAcessoMem;
    char escolha = ' ';
    struct TELA *tela = (struct TELA *)malloc(sizeof(struct TELA));
   
    //puts("Debug");
    clear();
    while (escolha == ' ') 
    {
        inicializaTerminal();
        desenhaTelaInicial(tela, &altura, &largura);
        desenhaMenu(tela, largura, playlist);

        ch = getch();
        switch (ch) {
            case KEY_F(1):
                escolha = '0';
                break;
            case KEY_F(2):
                escolha = '1';
                break;
            case KEY_F(3):
                escolha = '2';
                break;
            case KEY_F(4):
                escolha = '3';
                break;
            case KEY_F(5):
                escolha = '4';
                break;
            case KEY_F(6):
                escolha = '5';
                break;
            case KEY_F(7):
                escolha = '6';
                break;
            case KEY_F(8):
                escolha = '7';
                break;
            case 'r':
            case 'R':
                escolha = '8';
                break;
            case 's':
            case 'S':
                escolha = '9';
                break;
            case 'b':
            case 'B':
                escolha = 'a';
                break;
        }
        //puts(&escolha);
    }

    clear();
    finalizaTerminal();
    free(tela);
    puts(&escolha);
    return escolha;
}

void inicializaTerminal() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void finalizaTerminal(){
    endwin();
}

void desenhaTelaInicial(struct TELA *tela, float *altura, float *largura){
    getmaxyx(stdscr, *altura, *largura);

    start_color(); // Inicializa o modo de cores

    // Define um par de cores (texto branco no fundo preto)
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    //puts("Debug");
    // Criação dos contêineres
    tela->header = newwin(*altura*0.10, *largura*0.5 + *largura*0.5, 0, 0);
    tela->menu = newwin(*altura*0.80, *largura*0.5, *altura*0.10, 0);
    tela->content = newwin(*altura*0.80, *largura*0.5, *altura*0.10, *largura*0.5);
    tela->footer = newwin(*altura*0.10, *largura, *altura*0.9, 0);

    // Desenho dos contêineres
    box(tela->header, 0, 0);
    box(tela->menu, 0, 0);
    box(tela->content, 0, 0);
    box(tela->footer, 0, 0);

    // Atualização das janelas
    wrefresh(tela->header);
    wrefresh(tela->menu);
    wrefresh(tela->content);
    wrefresh(tela->footer);
}

void desenhaMenu(struct TELA *tela, float largura, Playlist *playlist)
{
    int i;
    DescFila *auxFila = playlist->primeiroFila;
    DescPilha *auxPilha = playlist->primeiroPilha;

    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    //HEAR
    mvwprintw(tela->header, 1, (largura-strlen("BEM-VINDO AO SPOTYFOM"))/2, "BEM-VINDO AO SPOTYFOM");

    //MENU
    mvwprintw(tela->menu, 4,  ((largura/2)-strlen("----MENU----"))/2, "----MENU----");
    mvwprintw(tela->menu, 7,  ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F2     EXECUTAR");
    mvwprintw(tela->menu, 8,  ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F3     ADICIONAR PLAYLIST");
    mvwprintw(tela->menu, 9,  ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F4     BUSCAR MUSICA");
    mvwprintw(tela->menu, 10,  ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F5     IMPRIMIR");
    mvwprintw(tela->menu, 11,  ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F6     RELATORIO");
    mvwprintw(tela->menu, 12, ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F7     BACKUP");
    mvwprintw(tela->menu, 13, ((largura/2)-strlen("F3     ADICIONAR PLAYLIST"))/2, "F1     ENCERRAR");

        //CONTENT
        mvwprintw(tela->content, 2, 35, "=== PLAYLISTS ===");

        mvwprintw(tela->content, 4, 34, "--------------------");

        mvwprintw(tela->content, 5, 35, "PLAYLIST RANDOMICA");
        mvwprintw(tela->content, 7,  35/2, "|-----------------------------------------------------|");
        //se nao existir playlists aleatorias:
            if(playlist->primeiroFila == NULL){
                mvwprintw(tela->content, 8, 35/2, "Sem playlists adicionadas");
            }
        //caso exista:
            else{
                while(auxFila != NULL){
                    mvwprintw(tela->content, 8, 20+i, "%s", auxFila->nome);
                    i++;
                    auxFila = auxFila->prox;
                }
            }

        mvwprintw(tela->content, 10, 35/2, "|-----------------------------------------------------|");


        mvwprintw(tela->content, 12, 34, "--------------------");
        
        mvwprintw(tela->content, 13, 35, "PLAYLIST PESSOAL");
        mvwprintw(tela->content, 15, 35/2, "|-----------------------------------------------------|");
        //se nao existir playlists aleatorias:
            if(playlist->primeiroPilha== NULL){
                mvwprintw(tela->content, 16, 35/2, "Sem playlists adicionadas");
            }
        //caso exista:
            else{
                while(auxPilha != NULL){
                    mvwprintw(tela->content, 16, 21, "%s", auxPilha->nome);
                    i++;
                    auxPilha = auxPilha->prox;
                }
            }
        mvwprintw(tela->content, 18, 35/2, "|-----------------------------------------------------|");

    //FOOTER
    mvwprintw(tela->footer, 1, largura/2, "AUTOR");
    mvwprintw(tela->footer, 1, (largura-strlen("Henrqiue de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(tela->header);
    wrefresh(tela->menu);
    wrefresh(tela->content);
    wrefresh(tela->footer);
}

