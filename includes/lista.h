#ifndef LISTA_H  
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
