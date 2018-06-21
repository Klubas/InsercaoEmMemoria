#ifndef LISTA_H  
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *prox;
};

typedef struct no No;

int insereLista(int valor, No *lista);

No buscaLista(int valor, No *lista);

void alteraDado(int novo_valor, No *lista);

void imprimeLista(No *lista);


int removeLista(int valor, No *lista);

int recuperaLista(int posicao, No *lista);

#endif
