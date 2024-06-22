#include "bibliotecas.h"


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
                    fprintf(arqA, "%s;", aux->info->artista);
                    fprintf(arqA, "%d;", aux->info->codigo);
                    fprintf(arqA, "%s;", aux->info->titulo);
                    fprintf(arqA, "%s;", aux->info->letra);
                    fprintf(arqA, "%d\n", aux->info->execucoes);
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
                        fprintf(arqP, "%s;", auxPilha->info->artista);
                        fprintf(arqP, "%d;", auxPilha->info->codigo);
                        fprintf(arqP, "%s;", auxPilha->info->titulo);
                        fprintf(arqP, "%s;", auxPilha->info->letra);
                        fprintf(arqP, "%d\n", auxPilha->info->execucoes);
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
                        fprintf(arqR, "%s;", auxFila->info->artista);
                        fprintf(arqR, "%d;", auxFila->info->codigo);
                        fprintf(arqR, "%s;", auxFila->info->titulo);
                        fprintf(arqR, "%s;", auxFila->info->letra);
                        fprintf(arqR, "%d\n", auxFila->info->execucoes);
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