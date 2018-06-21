#include <stdio.h>
#include <stdlib.h>

#include "includes/lista.h"
#include "includes/memoria.h"
#include "includes/processo.h"

void criar(Mem *mem) {
	int i;
	for(i = 0; i < mem->tam; i++){
		insereLista(-1, &mem->inicio);
	}
}

int novo_processo(Processo *proc, Mem *mem) {
	int i;
	No *aux = &mem->inicio;

	if(proc->tam > mem->tam){
		return -1;
	}

	switch (mem->tipo){
		case 'f': //first fit
			proc->inicio = aux;
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		case 'b': //best fit
			proc->inicio = aux;
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		case 'w': //worst fit
			proc->inicio = aux;
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		case 'n': //next fit
			proc->inicio = aux;
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			break;
		default: printf("Erro\n");
	}

	//int tam, int pid, No no
	return 0;
}

int matar_processo(int pid, Mem *mem) {
	No *aux, *tmp;
	aux = &mem->inicio;

	while(aux->dado != pid){
		aux = aux->prox;
	}

	while(aux->dado == pid){
		*tmp = buscaLista(pid, aux);
		alteraDado(-1, tmp);
		aux = aux->prox;
	}
	return 0;
}

void estado(Mem *mem) {
	imprimeLista(&mem->inicio);
}


