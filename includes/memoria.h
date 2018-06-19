#ifndef MEMORIA_H  
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

void criar(int, No *);

int novo_processo(int, int);

int matar_processo(int);

void estado(No *);

#endif