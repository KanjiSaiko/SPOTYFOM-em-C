#include "./Arquivos-h/bibliotecas.h"


DescLE *parser(int *tamLinhas){
    DescLE *descritorLista = inicializaLE();
    Musica *musica;
    NodoLP *nodo;
    int opcao, linhaN;
    char nome_arquivo[200], linhaS[1024], *token, codigo[20];
    FILE *arq;

        printf("\nDigite 1 para utilizar o diretorio padrao ou 2 para entrar com o diretorio do arquivo: ");
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                arq = fopen("./musicas/musicas.txt", "r");
                break;

            case 2:
                printf("Entre com o caminho/nome do arquivo incluindo a extenção .mem\n");
                scanf(" %[^\n]", nome_arquivo);
                arq = fopen(nome_arquivo, "r");
                break;

            default:
                printf("Opcao inexistente. Utilizando o diretorio padrao.\n");
                arq = fopen("./musicas/musicas.txt", "r");
                break;
        } 
    
    if(arq){
        if (fgets(linhaS, sizeof(linhaS), arq) != NULL) {
            linhaN = atoi(linhaS); //converte para inteiro -> 5000 armazenado na variavel linhaN
        }
        *tamLinhas = linhaN;
        for(int i = 0; i < linhaN; i++){
            if (fgets(linhaS, sizeof(linhaS), arq) == NULL)
                    break;
            musica = (Musica *)malloc(sizeof(Musica));

            token = strtok(linhaS, ";"); //percorre a string ate encontrar ;
            strcpy(musica->artista, token);
            token = strtok(NULL, ";"); //limpa o que foi lido e continua de onde parou
            //strcpy(codigo, token);
            musica->codigo = i;
            token = strtok(NULL, ";"); //limpa o que foi lido e continua de onde parou
            strcpy(musica->titulo, token);
            token = strtok(NULL, ";"); //limpa o que foi lido e continua de onde parou
            strcpy(musica->letra, token);
            token = strtok(NULL, ";"); //limpa o que foi lido e continua de onde parou

            nodo = criaNodo();
            nodo->info = musica;
            descritorLista = addMusica(descritorLista, nodo);
    }

        printf("Arquivo carregado com sucesso.\n");
        fclose(arq);
        return descritorLista;
    }
    else{
        printf("Erro ao abrir arquivo.\n");
        return NULL;
    }
}