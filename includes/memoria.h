#ifndef MEMORIA_H  
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "processo.h"

//define estrutura de uma memória
 struct mem{
	int tam = 0;
	int tam_ocupado = 0;
	char tipo;
	int lacunas = 1;
	int processos = 0;
	No inicio;
};

struct lacuna{
	int tam;
	No inicio;
	No prox;
};

typedef struct no Lacuna;
typedef struct mem Mem ;

//cria o espaço na memoria desejada
void criar(Mem *mem); 

//cria um novo processo na memoria desejada
int novo_processo(Processo *proc, Mem *mem); 

//elimina um processo na memoria desejada
int matar_processo(int, Mem *mem); 

//retorna qual é o estado da memória
void estado(Mem *);	

//lista todos os processos criados e não-matados
void lista_processos();

#endif