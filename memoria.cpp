#include <stdio.h>
#include <stdlib.h>

#include "includes/lista.h"
#include "includes/memoria.h"
#include "includes/processo.h"

#define VAZIO 0

No processos; 
Lacuna lacunas;

//instancia a memoria vazia
void criar(Mem *mem) {
	int i;
	for(i = 0; i < mem->tam; i++){
		insereLista(0, &mem->inicio, 0)	;
	}
}

//cria um novo processo na memória informada
int novo_processo(Processo *proc, Mem *mem) {
	int i = 0, j = 0;
	No *aux = &mem->inicio;
	
	if(proc->tam > mem->tam || proc->tam > mem->tam - mem->tam_ocupado){
		return -1;
	}

	switch (mem->tipo){
		case 'f': //first fit
			while(i < mem->tam){

			/*	if(i == proc->tam){
					recuperaLista(i - proc->tam, aux);
				}

				if (proc->pid == VAZIO) i++;
				else i = 0;




			}*/
			for(i = 0; i < proc->tam; i++){
				if(proc->pid == VAZIO){
					alteraDado(proc->pid, aux);
				}
				aux=aux->prox;
			}
			return 1;
			break;
		case 'b': //best fit
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		case 'w': //worst fit
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		case 'n': //next fit
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		default: printf("Erro\n");
	}

	//int tam, int pid, No no
	insereLista(proc->pid, &processos, 1);
	return 0;
}

//mata o processo desejado na memória informada
int matar_processo(int pid, Mem *mem) {
	No *aux;
	aux = &mem->inicio;

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(VAZIO, aux);
		}
		aux = aux->prox;
	}
	removeLista(buscaListaPos(pid, &processos), &processos);
}

//exibe estado da memoria
void estado(Mem *mem) {
	imprimeLista(&mem->inicio);
}

//lista todos os processos criados e não-matados
void lista_processos(){	
	printf("Processos: ");
	imprimeLista(&processos);
}

void contar_lacunas(Mem *mem){
	int i = 0;
	No aux = mem->inicio;
	while(i < mem->tam){
		if(aux->dado == VAZIO) i++;
		else {
			insereLista(i, &lacunas, 1);
			i = 0;
		}
	}
}