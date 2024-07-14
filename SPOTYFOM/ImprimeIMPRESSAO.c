#include "imprimeIMPRESSAO.h"


int ImprimeMUSICAS(DescLE *descritor) {
    float altura, largura;
    struct TelaExec *TelaImpressao = (struct TelaExec *)malloc(sizeof(struct TelaExec));
    int ch;
    while ((ch = getch()) != KEY_F(1))
    {
        inicializa_ncurses();

        //função que esta em ImprimeExecucoes.c
            desenhaTelaMusicas(&altura, &largura, TelaImpressao);

        desenhaImpressaoMusicas(largura, altura, TelaImpressao, descritor);
        getch();

    }
    endwin();
    free(TelaImpressao);
    clear();
    return 0;
}


void desenhaImpressaoMusicas(float largura, float altura, struct TelaExec *TelaImpressao, DescLE *descritor){
    int max_lines = altura*0.85; // Máximo de linhas visíveis na janela de conteúdo
    int header_alt, header_larg, cont_alt, cont_larg, foot_alt, foot_larg;
    NodoLP *aux = descritor->primeiro;
    int start_line = 0; // Linha inicial para rolagem
    int i = 0, linhas;
    int total_musics = 0; // Total de músicas na lista
    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    getmaxyx(TelaImpressao->header, header_alt, header_larg);
    getmaxyx(TelaImpressao->content, cont_alt, cont_larg);
    getmaxyx(TelaImpressao->footer, foot_alt, foot_larg);

    
    
    //HEADER
        wattron(TelaImpressao->header, A_BLINK);
        mvwprintw(TelaImpressao->header, 1, (header_larg-strlen("Musicas do Acervo"))/2, "Musicas do Acervo");
        wattroff(TelaImpressao->header, A_BLINK);

    // Calcula o total de músicas
    while (aux != NULL) {
        total_musics++;
        aux = aux->prox;
    }
    aux = descritor->primeiro; // Reset aux to head

    //CONTENT
    if (total_musics == 0) {
        mvwprintw(TelaImpressao->content, cont_alt / 3, (cont_larg - strlen("Acervo Vazio")) / 2, "Acervo Vazio");
    } else {
        int i = 0;
        while (aux != NULL && i < start_line + cont_alt - 2) {
            if (i >= start_line) {
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg/4, "Artista: %s", aux->info->artista);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-110, "Letra: %s", aux->info->letra);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-45, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }
            aux = aux->prox;
            i++;
        }
    }


    //FOOTER
        mvwprintw(TelaImpressao->footer, 1, 1, "Press F1 to quit");
        mvwprintw(TelaImpressao->footer, 1, (foot_larg-strlen("Henrique de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(TelaImpressao->header);
    wrefresh(TelaImpressao->content);
    wrefresh(TelaImpressao->footer);

    MEVENT event;
    keypad(stdscr, TRUE);
    while (1) {
        int ch = getch();

        if (ch == KEY_F(1)) {
            break; // Sai do loop ao pressionar F1
        } else if (ch == KEY_UP && start_line > 0) {
            start_line--;
        } else if (ch == KEY_DOWN && start_line + max_lines < total_musics) {
            start_line++;
        }

        // Limpar a janela de conteúdo antes de redesenhar
        werase(TelaImpressao->content);
        box(TelaImpressao->content, 0, 0);
        // Reimprimir conteúdo atualizado
        int i = 0;
        aux = descritor->primeiro;
        while (aux != NULL && i < start_line + cont_alt - 2) {
            if (i >= start_line) {
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg/4, "Artista: %s", aux->info->artista);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-110, "Letra: %s", aux->info->letra);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-45, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }
            aux = aux->prox;
            i++;
        }

        // Atualizar a janela após modificar
        wrefresh(TelaImpressao->content);
    }
}

int ImprimePorTitulo(NodoLP *aux) {
    float altura, largura;
    struct TelaExec *TelaImpressao = (struct TelaExec *)malloc(sizeof(struct TelaExec));
    int ch;
    while ((ch = getch()) != KEY_F(1))
    {
        inicializa_ncurses();

        //função que esta em ImprimeExecucoes.c
            desenhaTelaMusicas(&altura, &largura, TelaImpressao);

        desenhaImpressaoTitulo(largura, altura, TelaImpressao, aux);
        getch();

    }
    endwin();
    free(TelaImpressao);
    clear();
    return 0;
}


void desenhaImpressaoTitulo(float largura, float altura, struct TelaExec *TelaImpressao, NodoLP *aux){
    int max_lines = altura*0.85; // Máximo de linhas visíveis na janela de conteúdo
    int header_alt, header_larg, cont_alt, cont_larg, foot_alt, foot_larg;
    int start_line = 0; // Linha inicial para rolagem
    int i = 0, linhas;
    int total_musics = 0; // Total de músicas na lista
    attron(COLOR_PAIR(1)); // Ativa o par de cores número 1

    getmaxyx(TelaImpressao->header, header_alt, header_larg);
    getmaxyx(TelaImpressao->content, cont_alt, cont_larg);
    getmaxyx(TelaImpressao->footer, foot_alt, foot_larg);

    
    
    //HEADER
        wattron(TelaImpressao->header, A_BLINK);
        mvwprintw(TelaImpressao->header, 1, (header_larg-strlen("Musica"))/2, "Musica");
        wattroff(TelaImpressao->header, A_BLINK);

    //CONTENT
    if (aux == NULL) {
        mvwprintw(TelaImpressao->content, cont_alt / 3, (cont_larg - strlen("Musica nao encontrada")) / 2, "Musica nao encontrada");
    } 

    else {
                mvwprintw(TelaImpressao->content, cont_alt / 3, 1, "Musica: %s", aux->info->titulo);
                mvwprintw(TelaImpressao->content, cont_alt / 3, cont_larg/4, "Artista: %s", aux->info->artista);
                mvwprintw(TelaImpressao->content, cont_alt / 3, cont_larg-110, "Letra: %s", aux->info->letra);
                mvwprintw(TelaImpressao->content, cont_alt / 3, cont_larg-45, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaImpressao->content, cont_alt / 3, cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }

    //FOOTER
        mvwprintw(TelaImpressao->footer, 1, 1, "Press F1 to quit");
        mvwprintw(TelaImpressao->footer, 1, (foot_larg-strlen("Henrique de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(TelaImpressao->header);
    wrefresh(TelaImpressao->content);
    wrefresh(TelaImpressao->footer);

    MEVENT event;
    keypad(stdscr, TRUE);
    while (1) {
        int ch = getch();

        if (ch == KEY_F(1)) {
            break; // Sai do loop ao pressionar F1
        }
    }
}