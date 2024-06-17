#include "bibliotecas.h"


int main(void){
    DescLE *descritorLE = NULL;
    DescFila *descritorFila = NULL;
    DescPilha *descritorPilha = NULL;
    NodoLP *nodoLista = NULL, *nodoPilha = NULL;
    NodoFila *nodoFila = NULL;
    char escolha;
    int escolhaaux = 1;
    do{ 
        printf("\n======================\n");
        printf("Digite:\n[C]arregar Arquivo\n[E]xecutar\n[P]laylist\n[I]mprimir\n[R]elatorio\n[B]ackup\n[S]air\n");
        scanf(" %c", &escolha);
        switch(escolha){
            case 'C':
                descritorLE = 
                descritorLE = parser();
                break;
            
            case 'E':

                break;
            
            case 'P':

                break;

            case 'I':
                imprime(descritorLE);
                break;

            case 'R':

                break;

            case 'B':

                break;

            case 'S':
                escolhaaux = 0;
                break;
        }
    }while(escolhaaux != 0);

    return 0;
}