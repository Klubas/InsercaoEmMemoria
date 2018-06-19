#ifndef MEMORIA_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct mem{
	int tam;
	No bf;
	No ff;
	No wf;
	No nf;
};

typedef struct mem Mem;

void criar_mem(int, No *);

int criar_processo(int, int);

int matar_processo(int);

void listar_mem(No *);

#endif