#ifndef MEMORIA_H  
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "processo.h"

typedef struct mem{
	int tam;
	char tipo;
	int lacunas;
	int processos;
	No inicio;
} Mem;

void criar(Mem *mem);

int novo_processo(Processo *proc, Mem *mem);

int matar_processo(int, Mem *mem);

void estado(Mem *);

#endif