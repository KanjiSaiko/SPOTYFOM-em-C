#ifndef imprimeIM_h
#define imprimeIM_h

#include "bibliotecas.h"
#include "ImprimeExecucoes.h"
#include "menu.h"

int ImprimeMUSICAS(DescLE *descritor);
void desenhaImpressaoMusicas(float largura, float altura, struct TelaExec *TelaImpressao, DescLE *descritor);

int ImprimePorTitulo(NodoLP *aux);
void desenhaImpressaoTitulo(float largura, float altura, struct TelaExec *TelaImpressao, NodoLP *aux);


#endif