#ifndef LISTA_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct mem{
	int tam;
	No bf;		//best fit
	No ff;		//first fit
	No wf;		//worst fit
	No nf;		//next fit
} Mem;

void criar_mem(int, No *);

int criar_processo(int, int);

int matar_processo(int);

void listar_mem();

#endif