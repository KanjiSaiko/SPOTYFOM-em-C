#include "bibliotecas.h"


void Relatorio(Playlist *playlist, DescLE *descritor){
    int escolha, loop = 1;
    do{
        printf("Digite: [1] Relatorio do Acervo || [2] Relatorio das Playlists || Qualquer outro numero para voltar\n");
        scanf("%d", &escolha);

        if(escolha == 1){ //RELATORIO DO ACERVO
            NodoLP *aux = descritor->primeiro;
            FILE *arqA = fopen("Relatorio_Acervo.txt", "w");
            
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

        else if(escolha == 2){
            FILE *arqP = fopen("Relatorio_Pessoal.txt", "w");
            FILE *arqR = fopen("Relatorio_Random.txt", "w");
            NodoLP *auxPilha = playlist->PlaylistPilha->Topo;
            NodoFila *auxFila = playlist->PlaylistFila->head;
            
            if(arqP){
                fprintf(arqP, "%d\n", playlist->PlaylistPilha->tamanho);
                while(auxPilha != NULL){
                    fprintf(arqP, "%s;", auxPilha->info->artista);
                    fprintf(arqP, "%d;", auxPilha->info->codigo);
                    fprintf(arqP, "%s;", auxPilha->info->titulo);
                    fprintf(arqP, "%s;", auxPilha->info->letra);
                    fprintf(arqP, "%d\n", auxPilha->info->execucoes);
                    auxPilha = auxPilha->prox;
                }
                fclose(arqP);
                printf("Arquivo Relatorio_Pessoal.txt escrito com sucesso!\n");
            }

            else{
                printf("Erro ao abrir arquivo Relatorio_Pessoal.txt\n");
            }

            if(arqR){
                fprintf(arqR, "%d\n", playlist->PlaylistFila->tamanho);
                while(auxFila != NULL){
                    fprintf(arqR, "%s;", auxFila->info->artista);
                    fprintf(arqR, "%d;", auxFila->info->codigo);
                    fprintf(arqR, "%s;", auxFila->info->titulo);
                    fprintf(arqR, "%s;", auxFila->info->letra);
                    fprintf(arqR, "%d\n", auxFila->info->execucoes);
                    auxFila = auxFila->prox;
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
            printf("Saindo do programa\n");
        }

        
    }while(loop == 1);
    
}