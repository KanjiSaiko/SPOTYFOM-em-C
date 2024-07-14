#include "ImprimeExecucoes.h"


int ImprimePlaylistRandom(DescFila *playlistRandom) {
    float altura, largura;
    struct TelaExec *TelaMusicas = (struct TelaExec *)malloc(sizeof(struct TelaExec));
    int ch;
    while ((ch = getch()) != KEY_F(1))
    {
        inicializa_ncurses();

        desenhaTelaMusicas(&altura, &largura, TelaMusicas);
        desenhaMusicasRandom(largura, altura, TelaMusicas, playlistRandom);
        getch();

    }
    endwin();
    free(TelaMusicas);
    clear();
    return 0;
}


int ImprimePlaylistPessoal(DescPilha *playlistPessoal) {
    float altura, largura;
    struct TelaExec *TelaMusicas = (struct TelaExec *)malloc(sizeof(struct TelaExec));
    int ch;
    while ((ch = getch()) != KEY_F(1))
    {
        //INICIALIZAÇÃO
            initscr();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
            curs_set(0);

        desenhaTelaMusicas(&altura, &largura, TelaMusicas);
        
        desenhaMusicasPessoal(largura, altura, TelaMusicas, playlistPessoal);
        getch();

    }
    endwin();
    free(TelaMusicas);
    clear();
    return 0;
}


void desenhaTelaMusicas(float *altura, float *largura, struct TelaExec *TelaMusicas)
{
    getmaxyx(stdscr, *altura, *largura);

    start_color(); // Inicializa o modo de cores

    // Define um par de cores (texto branco no fundo preto)
    init_pair(1, COLOR_BLACK, COLOR_WHITE);


    // Criação dos contêineres
    TelaMusicas->header = newwin(*altura*0.10, *largura*0.5 + *largura*0.5, 0, 0);
    TelaMusicas->content = newwin(*altura*0.80, *largura, *altura*0.10, 0);
    TelaMusicas->footer = newwin(*altura*0.10, *largura, *altura*0.90, 0);

    // Desenho dos contêineres
    box(TelaMusicas->header, 0, 0);
    box(TelaMusicas->content, 0, 0);
    box(TelaMusicas->footer, 0, 0);

    // Atualização das janelas
    wrefresh(TelaMusicas->header);
    wrefresh(TelaMusicas->content);
    wrefresh(TelaMusicas->footer);
}

void desenhaMusicasRandom(float largura, float altura, struct TelaExec *TelaMusicas, DescFila *FilaCorreta){
    
    int header_alt, header_larg, cont_alt, cont_larg, foot_alt, foot_larg;
    NodoFila *aux = FilaCorreta->head;
    int start_line = 0; // Linha inicial para rolagem
    int i = 0, linhas;
    int total_musics = 0; // Total de músicas na lista
    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    getmaxyx(TelaMusicas->header, header_alt, header_larg);
    getmaxyx(TelaMusicas->content, cont_alt, cont_larg);
    getmaxyx(TelaMusicas->footer, foot_alt, foot_larg);

    int max_lines = cont_alt - 2; // Máximo de linhas visíveis na janela de conteúdo
    
    //HEADER
        wattron(TelaMusicas->header, A_BLINK);
        mvwprintw(TelaMusicas->header, 1, (header_larg-strlen("Playlist Executada"))/2, "Playlist Executada");
        wattroff(TelaMusicas->header, A_BLINK);

    // Calcula o total de músicas
    while (aux != NULL) {
        total_musics++;
        aux = aux->prox;
    }
    aux = FilaCorreta->head; // Reset aux to head

    //CONTENT
    if (total_musics == 0) {
        mvwprintw(TelaMusicas->content, cont_alt / 3, (cont_larg - strlen("Playlist Vazia")) / 2, "Playlist Vazia");
    } else {
        int i = 0;
        while (aux != NULL && i < start_line + 26) {
            if (i >= start_line) {
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
            }
            aux = aux->prox;
            i++;
        }
    }


    //FOOTER
        mvwprintw(TelaMusicas->footer, 1, 1, "Press F1 to quit");
        mvwprintw(TelaMusicas->footer, 1, (foot_larg-strlen("Henrique de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(TelaMusicas->header);
    wrefresh(TelaMusicas->content);
    wrefresh(TelaMusicas->footer);

    MEVENT event;
    keypad(stdscr, TRUE);
    while (1) {
        int ch = getch();
        if (ch == KEY_F(1)) {
            break; // Sai do loop ao pressionar F1
        } 
        else if (ch == KEY_UP) { // Tecla para cima
            if (start_line > 0) {
                start_line--;
                desenhaMusicasRandom(largura, altura, TelaMusicas, FilaCorreta);
            }    
        } 
        else if (ch == KEY_DOWN) { // Tecla para baixo
            if (start_line + max_lines < i) {
                start_line++;
                desenhaMusicasRandom(largura, altura, TelaMusicas, FilaCorreta);
            } 
        }
    }
}

void inicializa_ncurses() {
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void desenhaMusicasPessoal(float largura, float altura, struct TelaExec *TelaMusicas, DescPilha *PilhaCorreta){
    int max_lines = altura * 0.85 - 2; // Máximo de linhas visíveis na janela de conteúdo
    int header_alt, header_larg, cont_alt, cont_larg, foot_alt, foot_larg;
    NodoLP *aux = PilhaCorreta->Topo;
    int start_line = 0; // Linha inicial para rolagem
    int i = 0, linhas;
    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    getmaxyx(TelaMusicas->header, header_alt, header_larg);
    getmaxyx(TelaMusicas->content, cont_alt, cont_larg);
    getmaxyx(TelaMusicas->footer, foot_alt, foot_larg);
    //HEADER
        wattron(TelaMusicas->header, A_BLINK);
        mvwprintw(TelaMusicas->header, 1, (header_larg-strlen("Playlist Executada"))/2, "Playlist Executada");
        wattroff(TelaMusicas->header, A_BLINK);

    //CONTENT
    if(PilhaCorreta->Topo == NULL){
        mvwprintw(TelaMusicas->content, cont_alt/3, (cont_larg-strlen("Playlist Vazia"))/2, "Playlist Vazia");
    }
    while (aux != NULL) {
        if (i >= start_line && i < start_line + max_lines) {
            mvwprintw(TelaMusicas->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
        }
        aux = aux->prox;
        i++;
    }


    //FOOTER
        mvwprintw(TelaMusicas->footer, 1, 1, "Press F1 to quit");
        mvwprintw(TelaMusicas->footer, 1, (foot_larg-strlen("Henrique de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(TelaMusicas->header);
    wrefresh(TelaMusicas->content);
    wrefresh(TelaMusicas->footer);

    MEVENT event;
    while (1) {
        int ch = getch();
        if (ch == KEY_F(1)) {
            break; // Sai do loop ao pressionar F1
        } 
        else if (ch == KEY_UP) { // Tecla para cima
            if (start_line > 0) {
                start_line--;
            }
            desenhaMusicasPessoal(largura, altura, TelaMusicas, PilhaCorreta);
        } 
        else if (ch == KEY_DOWN) { // Tecla para baixo
            if (start_line + max_lines < i) {
                start_line++;
            }
            desenhaMusicasPessoal(largura, altura, TelaMusicas, PilhaCorreta);
        }
    }
}