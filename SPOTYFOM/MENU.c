#include "INTERFACES.h"


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

char *escolhas[] = {
    "EXECUTAR", "ADICIONAR PLAYLIST", "BUSCAR MUSICA", "IMPRIMIR", "RELATORIO", "BACKUP", "SAIR", (char*)NULL,
};

char interface(Playlist *playlist, char escolha){
    ITEM **opcoes;
    MENU *menu;
    TelaPrincipal *tela = (TelaPrincipal*)malloc(sizeof(TelaPrincipal));
    int n_escolhas, i, c;
    float altura, largura;

    //CRIA OS ITENS DO MENU:
        n_escolhas = ARRAY_SIZE(escolhas);
        opcoes = (ITEM **)calloc(n_escolhas, sizeof(ITEM*));
        for(i = 0; i < n_escolhas; i++){
            opcoes[i] = new_item(escolhas[i], escolhas[i]);
        }

    //CRIA MENU:
        menu = new_menu((ITEM**)opcoes);

    //Set menu option not to show the description
        menu_opts_off(menu, O_SHOWDESC);

    //CRIA JANELA ASSOCIADA AO MENU:
        desenhaTelaInicial(&altura, &largura, tela);
        keypad(tela->menu, TRUE);

    clear();
    while(escolha == ' '){
        //INCIALIZA NCURSES:
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
            curs_set(0);

        //DESENHA A TELA:
            desenhaMenu(tela, altura, largura, playlist);
    }

    
    //PRINTA O MENU:
        post_menu(menu);
        wrefresh(tela->menu);

    //OPCOES:
        while((c = wgetch(tela->menu)) != KEY_F(1))
        {       switch(c)
                {	case KEY_DOWN:
                    menu_driver(menu, REQ_DOWN_ITEM);
                    break;
                case KEY_UP:
                    menu_driver(menu, REQ_UP_ITEM);
                    break;
                case KEY_NPAGE:
                    menu_driver(menu, REQ_SCR_DPAGE);
                    break;
                case KEY_PPAGE:
                    menu_driver(menu, REQ_SCR_UPAGE);
                    break;
            }
                    wrefresh(tela->menu);
        }

    unpost_menu(menu);
        free_menu(menu);
        for(i = 0; i < n_escolhas; ++i)
                free_item(opcoes[i]);	
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
        mvwprintw(tela->menu, 3, largura*1.3, "----MENU----");
        mvwprintw(tela->menu, 5, largura, "EXECUTAR");
        mvwprintw(tela->menu, 6, largura, "ADICIONAR PLAYLIST");
        mvwprintw(tela->header, 7, largura, "BUSCAR MUSICA");
        mvwprintw(tela->header, 8, largura, "IMPRIMIR");
        mvwprintw(tela->header, 9, largura, "RELATORIO");
        mvwprintw(tela->header, 10, largura, "BACKUP");
        mvwprintw(tela->header, 11, largura, "SAIR");
        if(playlist != NULL){

        }
        else{
            mvwprintw(tela->content, 1, largura/2, "--- PLAYLISTS ALEATORIAS ---");
            mvwprintw(tela->content, 2, largura/2, "----------------------------");

            mvwprintw(tela->content, 3, largura/2, "--- PLAYLISTS PESSOAIS ---");
            mvwprintw(tela->content, 4, 5, "--------------------------");
        }

    //FOOTER
        mvwprintw(tela->footer, 1, largura*2, "AUTOR");
        mvwprintw(tela->footer, 2, largura, "Henrique de Lima Bortolomiol");
        
    // Atualização das janelas
        wrefresh(tela->header);
        wrefresh(tela->menu);
        wrefresh(tela->content);
        wrefresh(tela->footer);
}