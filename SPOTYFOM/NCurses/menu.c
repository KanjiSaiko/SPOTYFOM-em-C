#include "../Arquivos-h/menu.h"

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
            case '0':
                escolha = '0';
                break;
            case '1':
                escolha = '1';
                break;
            case '2':
                escolha = '2';
                break;
            case '3':
                escolha = '3';
                break;
            case '4':
                escolha = '4';
                break;
            case '5':
                escolha = '5';
                break;
            case '6':
                escolha = '6';
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
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    //TEXTO CINZA ESCURO E FUNDO VERMELHO ESCURO
    init_pair(2, 1, 234);
    //TEXTO AMARELO DOURADO E FUNDO CINZA ESCURO
    init_pair(3, 178, 234);
    
    //puts("Debug");
    // Criação dos contêineres
    tela->header = newwin(*altura*0.10, *largura*0.5 + *largura*0.5, 0, 0);
    tela->menu = newwin(*altura*0.80, *largura*0.5, *altura*0.10, 0);
    tela->content = newwin(*altura*0.80, *largura*0.5+1, *altura*0.10, *largura*0.5);
    tela->footer = newwin(*altura*0.10, *largura, *altura*0.9, 0);
    
    // Aplicar o par de cores a toda a janela e preencher com espaço
        wbkgd(tela->header, COLOR_PAIR(3) | ' ');
        wbkgd(tela->menu, COLOR_PAIR(3) | ' ');
        wbkgd(tela->content, COLOR_PAIR(3) | ' ');
        wbkgd(tela->footer, COLOR_PAIR(3) | ' ');

        // Redesenhar as janelas para aplicar o fundo
        wrefresh(tela->header);
        wrefresh(tela->menu);
        wrefresh(tela->content);
        wrefresh(tela->footer);

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
    int header_alt, header_larg, menu_alt, menu_larg, cont_alt, cont_larg, foot_alt, foot_larg, maximoR, maximoP;
    int i, tamanhoColunaF, tamanhoColunaP, linhaR = 8, linhaP;
    char nomeAntP[300], nomeAntF[300];
    DescFila *auxFila = playlist->primeiroFila;
    DescPilha *auxPilha = playlist->primeiroPilha;
    nomeAntP[0] = '\0';
    nomeAntF[0] = '\0';


    //coleto a largura e altura das janelas
    getmaxyx(tela->header, header_alt, header_larg);
    getmaxyx(tela->menu, menu_alt, menu_larg);
    getmaxyx(tela->content, cont_alt, cont_larg);
    getmaxyx(tela->footer, foot_alt, foot_larg);

    tamanhoColunaF = ((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1;
    tamanhoColunaP = ((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1;

    //HEAR
    wattron(tela->header, A_BLINK);
    mvwprintw(tela->header, 1, (largura-strlen("BEM-VINDO AO SPOTYFOM"))/2, "BEM-VINDO AO SPOTYFOM");
    wattron(tela->header, A_BLINK);

    //MENU
    mvwprintw(tela->menu, menu_alt/4,  ((largura/2)-strlen("|----------MENU----------|"))/2, "|----------MENU----------|");
    mvwprintw(tela->menu, menu_alt/4+2,  ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "1     EXECUTAR");
    mvwprintw(tela->menu, menu_alt/4+3,  ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "2     ADICIONAR PLAYLIST");
    mvwprintw(tela->menu, menu_alt/4+4,  ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "3     IMPRIMIR");
    mvwprintw(tela->menu, menu_alt/4+5,  ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "4     RELATORIO");
    mvwprintw(tela->menu, menu_alt/4+6,  ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "5     BUSCA");
    mvwprintw(tela->menu, menu_alt/4+7, ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "6     BACKUP");
    mvwprintw(tela->menu, menu_alt/4+8, ((largura/2)-strlen("2     ADICIONAR PLAYLIST"))/2, "0     ENCERRAR");

        //CONTENT
        mvwprintw(tela->content, 2, (cont_larg-strlen("=== PLAYLISTS ==="))/2, "=== PLAYLISTS ===");

        mvwprintw(tela->content, 4, (cont_larg-strlen("--------------------"))/2, "--------------------");

        //PLAYLIST RANDOM
            mvwprintw(tela->content, 5, (cont_larg-strlen("PLAYLIST RANDOMICA"))/2, "PLAYLIST RANDOMICA");
            mvwprintw(tela->content, 7,  (cont_larg-strlen("|-----------------------------------------------------|"))/2, "|-----------------------------------------------------|");
            //se nao existir playlists aleatorias:
                if(playlist->primeiroFila == NULL){
                    mvwprintw(tela->content, 8, (cont_larg-strlen("Sem playlists adicionadas"))/2, "Sem playlists adicionadas");
                }
            //caso exista:
                else{
                    while(auxFila != NULL){
                        
                        //se a coluna estourar o layout, preciso aumentar uma linha pra baixo
                            if(tamanhoColunaF >= (((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1)+strlen("|-----------------------------------------------------|")){
                                linhaR+=2;
                                tamanhoColunaF = ((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1;
                        }

                        wattron(tela->content, A_REVERSE | A_BOLD);//REVERTE AS CORES DO FUNDO COM O TEXTO E DEIXA EM NEGRITO
                        mvwprintw(tela->content, linhaR, tamanhoColunaF, "%s-%d", auxFila->nome, auxFila->tamanho);
                        wattroff(tela->content, A_REVERSE | A_BOLD); // DESLIGA OS EFEITOS

                        
                        //copio o nome anterior para saber o espaçamento
                            snprintf(nomeAntF, sizeof(nomeAntF), "%s-%d", auxFila->nome, auxFila->tamanho);
                            tamanhoColunaF = tamanhoColunaF + strlen(nomeAntF) + 2;
                        auxFila = auxFila->prox;
                    }
                }
            linhaR+=2;
            mvwprintw(tela->content, linhaR, (cont_larg-strlen("|-----------------------------------------------------|"))/2, "|-----------------------------------------------------|");

            linhaP = linhaR;
            mvwprintw(tela->content, linhaP+2, (cont_larg-strlen("-----------------"))/2, "-----------------");

        //PLAYLIST PESSOAL  
            mvwprintw(tela->content, linhaP+3, (cont_larg-strlen("PLAYLIST PESSOAL"))/2, "PLAYLIST PESSOAL");
            mvwprintw(tela->content,  linhaP+5, (cont_larg-strlen("|-----------------------------------------------------|"))/2, "|-----------------------------------------------------|");
            //se nao existir playlists aleatorias:
                if(playlist->primeiroPilha== NULL){
                    //tamanho padrao da linha P = 12;
                    mvwprintw(tela->content, linhaP+6, (cont_larg-strlen("Sem playlists adicionadas"))/2, "Sem playlists adicionadas");
                }
            //caso exista:
                else{
                    while(auxPilha != NULL){
                        //se a coluna estourar o layout, preciso aumentar uma linha pra baixo
                            if(tamanhoColunaP >= (((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1)+strlen("|-----------------------------------------------------|")){
                                linhaP+=2;
                                tamanhoColunaP = ((cont_larg-strlen("|-----------------------------------------------------|"))/2)+1;
                        }
                        wattron(tela->content, A_REVERSE | A_BOLD);//REVERTE AS CORES DO FUNDO COM O TEXTO E DEIXA EM NEGRITO
                        mvwprintw(tela->content, linhaP+6, tamanhoColunaP, "%s-%d", auxPilha->nome, auxPilha->tamanho);
                        wattroff(tela->content, A_REVERSE | A_BOLD);

                        //copio o nome anterior para saber o espaçamento
                            snprintf(nomeAntP, sizeof(nomeAntP), "%s-%d", auxPilha->nome, auxPilha->tamanho);
                            tamanhoColunaP = tamanhoColunaP + strlen(nomeAntP) + 2;
                        auxPilha = auxPilha->prox;
                    }
                }
            linhaP+=2;
            mvwprintw(tela->content, linhaP+6, (cont_larg-strlen("|-----------------------------------------------------|"))/2, "|-----------------------------------------------------|");

    //FOOTER
    mvwprintw(tela->footer, 1, largura/2, "AUTOR");
    mvwprintw(tela->footer, 1, (largura-strlen("Henrqiue de Lima Bortolomiol"))/2, "Henrique de Lima Bortolomiol");

    // Atualização das janelas
    wrefresh(tela->header);
    wrefresh(tela->menu);
    wrefresh(tela->content);
    wrefresh(tela->footer);
}

