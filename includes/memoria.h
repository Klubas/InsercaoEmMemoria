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
	int qtd_lacunas = 1;
	int qtd_processos = 0;
	int ultima_pos = -1;
	No inicio;
	No lacunas;
	No processos;
};

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
void lista_processos(Mem *);

void lista_lacunas(Mem *);

void imprime_sem_repetir(No *no);

int maior_lacuna(Mem *mem);

int menor_lacuna(Mem *mem);

void contar_lacunas(Mem *mem);

#endif