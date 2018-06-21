#ifndef MEMORIA_H  
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct mem{
	int tam;
	char tipo;
	No inicio;
};
struct processo{
	int tam;
	No inicio;
	No fim;
};

typedef struct mem Mem;
typedef struct processo Processo;

void criar(int, No *);

int novo_processo(int, int);

int matar_processo(int);

void estado(No *);

#endif