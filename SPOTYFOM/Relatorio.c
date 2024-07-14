#include "./Arquivos-h/bibliotecas.h"


void Relatorio(Playlist *playlist, DescLE *descritor){
    int loop = 1;
    char escolha;
    do{
        printf("Digite: [1] Relatorio do Acervo || [2] Relatorio das Playlists || Qualquer outro numero para voltar\n");
        scanf(" %c", &escolha);

        if(escolha == '1'){ //RELATORIO DO ACERVO
            NodoLP *aux = descritor->primeiro;
            FILE *arqA = fopen("./musicas/Relatorio_Acervo.txt", "w");
            
            if(arqA){
                fprintf(arqA, "%d\n", descritor->tamanho);
                while(aux != NULL){
                    fprintf(arqA, "Artista: [%s]\n", aux->info->artista);
                    fprintf(arqA, "Codigo: [%d]\n", aux->info->codigo);
                    fprintf(arqA, "Titulo [%s]\n", aux->info->titulo);
                    fprintf(arqA, "Letra: [%s]\n", aux->info->letra);
                    fprintf(arqA, "Vezes escutada: [%d]\n", aux->info->execucoes);
                    fprintf(arqA, "===========================\n\n");
                    aux = aux->prox;
                }
                fclose(arqA);
                printf("Arquivo Relatorio_Acervo.txt escrito com sucesso!\n");
            }

            else{
                printf("Erro ao abrir arquivo.");
            }
        }

        else if(escolha == '2'){
            FILE *arqP = fopen("./musicas/Relatorio_Pessoal.txt", "w");
            FILE *arqR = fopen("./musicas/Relatorio_Random.txt", "w");
            DescPilha *playlistsPilhas = playlist->primeiroPilha;
            NodoLP *auxPilha;
            DescFila *playlistsFila = playlist->primeiroFila;
            NodoFila *auxFila;
            if(arqP){
                while(playlistsPilhas != NULL){
                    auxPilha = playlistsPilhas->Topo;
                    fprintf(arqP, "Playlist: %s\n", playlistsPilhas->nome);
                    fprintf(arqP, "%d\n", playlistsPilhas->tamanho);
                    while(auxPilha != NULL){
                        fprintf(arqP, "Artista: [%s]\n", auxPilha->info->artista);
                        fprintf(arqP, "Codigo: [%d]\n", auxPilha->info->codigo);
                        fprintf(arqP, "Titulo: [%s]\n", auxPilha->info->titulo);
                        fprintf(arqP, "Letra: [%s]\n", auxPilha->info->letra);
                        fprintf(arqP, "Vezes escutada: [%d]\n", auxPilha->info->execucoes);
                        fprintf(arqP, "===========================\n\n");
                        auxPilha = auxPilha->prox;
                    }
                    fprintf(arqP, "\n\n");
                    playlistsPilhas = playlistsPilhas->prox;
                }
                
                
                fclose(arqP);
                printf("Arquivo Relatorio_Pessoal.txt escrito com sucesso!\n");
            }

            else{
                printf("Erro ao abrir arquivo Relatorio_Pessoal.txt\n");
            }

            if(arqR){

                while(playlistsFila != NULL){
                    auxFila = playlistsFila->head;
                    fprintf(arqR, "Playlist: %s\n", playlistsFila->nome);
                    fprintf(arqR, "%d\n", playlistsFila->tamanho);
                    while(auxFila != NULL){
                        fprintf(arqR, "Artista: [%s]\n", auxFila->info->artista);
                        fprintf(arqR, "Codigo: [%d]\n;", auxFila->info->codigo);
                        fprintf(arqR, "Titulo: [%s]\n", auxFila->info->titulo);
                        fprintf(arqR, "Letra: [%s]\n", auxFila->info->letra);
                        fprintf(arqR, "Vezes escutada: [%d]\n", auxFila->info->execucoes);
                        fprintf(arqR, "===========================\n\n");
                        auxFila = auxFila->prox;
                    }
                    fprintf(arqR, "\n\n");
                    playlistsFila = playlistsFila->prox;
                }
                
                fclose(arqR);
                printf("Arquivo Relatorio_Randomico.txt escrito com sucesso!\n");
            }

            else{
                printf("Erro ao abrir arquivo Relatorio_Pessoal.txt\n");
            }
        }

        else {
            loop = 0;
        }

        
    }while(loop == 1);
    
}