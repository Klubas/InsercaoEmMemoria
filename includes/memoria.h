#ifndef MEMORIA_H  
#define MEMORIA_H

#include <stdio.h>

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

//next e first fit
int position_fit(Mem *, Processo *, const char); 

//best e worst fit
int quality_fit(Mem *, Processo *, const char);

//move até a posição desejada e grava o processo
void grava_memoria(Mem *mem, Processo *proc, int pos);

//elimina um processo na memoria desejada
int matar_processo(int, Mem *mem); 

//retorna qual é o estado da memória
void estado(Mem *, int);	

//lista todos os processos criados e ativos(pids)
void lista_processos(Mem *);

//lista a lacunas (tamanhos)
void lista_lacunas(Mem *);

//retorna a maior lacuna
int maior_lacuna(Mem *mem);

//retorna a menor lacuna
int menor_lacuna(Mem *mem);

//conta a quantidade de lacunas e insere na lista de lacunas da struct mem
void contar_lacunas(Mem *mem);

//retorna 1 ou 0 se a Mem estiver vazia
int vazio(Mem *);

int cheio(Mem *);

#endif