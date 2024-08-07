#include "../Arquivos-h/imprimeIMPRESSAO.h"


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
        mvwprintw(TelaImpressao->header, 1, (header_larg-strlen("MUSICAS DO ACERVO"))/2, "MUSICAS DO ACERVO");
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
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-95, "Letra: %s", aux->info->letra);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-30, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }
            aux = aux->prox;
            i++;
        }
    }


    //FOOTER
        mvwprintw(TelaImpressao->footer, 1, 1, "Press KEY_DOWN/UP para passar conteudo ou F1 para sair");
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
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-95, "Letra: %s", aux->info->letra);
                mvwprintw(TelaImpressao->content, 1 + (i - start_line), cont_larg-30, "Codigo: %d", aux->info->codigo);
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
        mvwprintw(TelaImpressao->header, 1, (header_larg-strlen("Musica"))/2, "MUSICA");
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
        mvwprintw(TelaImpressao->footer, 1, 1, "Pressione F1 para sair");
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
//IMPRESSAO DA BUSCA:

    int ImprimePorBusca(NodoLP *aux) {
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


    void desenhaImpressaoBusca(float largura, float altura, struct TelaExec *TelaImpressao, NodoLP *aux){
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
            mvwprintw(TelaImpressao->header, 1, (header_larg-strlen("Musica"))/2, "MUSICA");
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
            mvwprintw(TelaImpressao->footer, 1, 1, "Pressione F1 para sair");
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


int ImprimeAlbum(DescPilha *album) {
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
        
        desenhaAlbum(largura, altura, TelaMusicas, album);
        getch();

    }
    endwin();
    free(TelaMusicas);
    clear();
    return 0;
}



void desenhaAlbum(float largura, float altura, struct TelaExec *TelaMusicas, DescPilha *PilhaCorreta){
    int max_lines = altura * 0.85; // Máximo de linhas visíveis na janela de conteúdo
    int header_alt, header_larg, cont_alt, cont_larg, foot_alt, foot_larg;
    NodoLP *aux = PilhaCorreta->Topo;
    int start_line = 0; // Linha inicial para rolagem
    int total_musics = 0; // Total de músicas na lista
    int i = 0, linhas;

    getmaxyx(TelaMusicas->header, header_alt, header_larg);
    getmaxyx(TelaMusicas->content, cont_alt, cont_larg);
    getmaxyx(TelaMusicas->footer, foot_alt, foot_larg);
    //HEADER
        wattron(TelaMusicas->header, A_BLINK);
        mvwprintw(TelaMusicas->header, 1, (header_larg-strlen("ARTISTA ENCONTRADO"))/2, "ARTISTA ENCONTRADO");
        wattroff(TelaMusicas->header, A_BLINK);

    // Calcula o total de músicas
    while (aux != NULL) {
        total_musics++;
        aux = aux->prox;
    }
    aux = PilhaCorreta->Topo; // Reset aux to head

    //CONTENT
    if (total_musics == 0) {
        mvwprintw(TelaMusicas->content, cont_alt / 3, (cont_larg - strlen("Playlist Vazia")) / 2, "Playlist Vazia");
    } else {
        int i = 0;
        while (aux != NULL && i < start_line + cont_alt - 2) {
            if (i >= start_line) {
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg/4, "Artista: %s", aux->info->artista);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-95, "Letra: %s", aux->info->letra);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-30, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }
            aux = aux->prox;
            i++;
        }
    }


    //FOOTER
        mvwprintw(TelaMusicas->footer, 1, 1, "Press KEY_DOWN/UP para passar conteudo ou F1 para sair");
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
        } else if (ch == KEY_UP && start_line > 0) {
            start_line--;
        } else if (ch == KEY_DOWN && start_line + max_lines < total_musics) {
            start_line++;
        }

        // Limpar a janela de conteúdo antes de redesenhar
        werase(TelaMusicas->content);
        box(TelaMusicas->content, 0, 0);
        // Reimprimir conteúdo atualizado
        int i = 0;
        aux = PilhaCorreta->Topo;
        while (aux != NULL && i < start_line + cont_alt - 2) {
            if (i >= start_line) {
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), 1, "Musica: %s", aux->info->titulo);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg/4, "Artista: %s", aux->info->artista);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-95, "Letra: %s", aux->info->letra);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-30, "Codigo: %d", aux->info->codigo);
                mvwprintw(TelaMusicas->content, 1 + (i - start_line), cont_larg-strlen("Execucoes: ")-6, "Execucoes: %d", aux->info->execucoes);
            }
            aux = aux->prox;
            i++;
        }

        // Atualizar a janela após modificar
        wrefresh(TelaMusicas->content);
    }
}