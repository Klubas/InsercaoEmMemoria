#ifndef LISTA_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

struct no{
	int dado;
	struct no *prox;
};

typedef struct no No;

int insereLista(int valor, No *);

void imprimeLista(No *);

int removeLista(int, No *);

int buscaLista(int, No *);

int recuperaLista(int, No *);

#endif
