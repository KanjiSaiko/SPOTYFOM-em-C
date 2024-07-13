/*#include "INTERFACES.h"


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char interface(Playlist *playlist){
    TelaPrincipal *tela = (TelaPrincipal*)malloc(sizeof(TelaPrincipal));
    int i, c, ch;
    char escolha = ' ';
    float altura, largura;

    clear();
    while (escolha == ' ') 
    {
        //INICIALIZA O NCURSES
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
            curs_set(0);
        desenhaTelaInicial(&altura, &largura, tela);
        desenhaMenu(tela, largura, altura, playlist);

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
    endwin();
    free(tela);
    puts(&escolha);
    return escolha;
}


void desenhaTelaInicial(float *altura, float *largura, TelaPrincipal *tela){
    getmaxyx(stdscr, *altura, *largura);

    // Inicializa o modo de cores
    start_color();

    // Define um par de cores (texto branco no fundo preto)
    init_pair(1, COLOR_BLACK, COLOR_WHITE);

    //parametros de newwin(linhas, colunas, começo no eixo y, começo no eixo x)
    // Criação dos contêineres
    tela->header = newwin(*altura*0.1, *largura*0.5 + *largura*0.5, 0, 0);
    tela->menu = newwin(*altura*0.8, *largura*0.5, *altura*0.1, 0);
    tela->content = newwin(*altura*0.8, *largura*0.5, *altura*0.1, *largura*0.5);
    tela->footer = newwin(*altura*0.1, *largura, *altura*0.9, 0);

    //desenho dos containeres
    box(tela->header, 0, 0);
    box(tela->menu, 0, 0);
    box(tela->content, 0, 0);
    box(tela->footer, 0, 0);

    //atualização de cada parte da janela
    wrefresh(tela->header);
    wrefresh(tela->menu);
    wrefresh(tela->content);
    wrefresh(tela->footer);
}


void desenhaMenu(TelaPrincipal *tela, float largura, float altura, Playlist *playlist){
    int i;
    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    //parametros mvwprintw (tela, coordenada y, coordenada x, string)
    //MENSAGEM DO HEADER:
        mvwprintw(tela->header, 1, largura*1.8, "BEM-VINDO AO SPOTYFOM");

    //MENU:
        mvwprintw(tela->menu, 8, largura*1.3, "----MENU----");
        mvwprintw(tela->menu, 10, largura, "EXECUTAR");
        mvwprintw(tela->menu, 11, largura, "ADICIONAR PLAYLIST");
        mvwprintw(tela->header, 12, largura, "BUSCAR MUSICA");
        mvwprintw(tela->header, 13, largura, "IMPRIMIR");
        mvwprintw(tela->header, 14, largura, "RELATORIO");
        mvwprintw(tela->header, 15, largura, "BACKUP");
        mvwprintw(tela->header, 16, largura, "SAIR");
        /*if(playlist != NULL){

        }
        else{
            mvwprintw(tela->content, 1, largura/2, "--- PLAYLISTS ALEATORIAS ---");
            mvwprintw(tela->content, 2, largura/2, "----------------------------");

            mvwprintw(tela->content, 3, largura/2, "--- PLAYLISTS PESSOAIS ---");
            mvwprintw(tela->content, 4, 5, "--------------------------");
        }

    //FOOTER
        mvwprintw(tela->footer, 1, largura*2, "AUTOR");
        mvwprintw(tela->footer, 2, largura/2-strlen("Henrique de Lima Bortolomiol"), "Henrique de Lima Bortolomiol");
        
    // Atualização das janelas
        wrefresh(tela->header);
        wrefresh(tela->menu);
        wrefresh(tela->content);
        wrefresh(tela->footer);
}*/