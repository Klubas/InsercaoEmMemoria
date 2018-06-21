#include <stdio.h>
#include <stdlib.h>

#include "includes/lista.h"
#include "includes/memoria.h"
#include "includes/processo.h"

No processos;

void criar(Mem *mem) {
	int i;
	for(i = mem->tam; i > 0; i--){
		insereLista(-1, &mem->inicio, 0)	;
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
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);	
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

int matar_processo(int pid, Mem *mem) {
	No *aux;
	aux = &mem->inicio;

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(-1, aux);
		}
		aux = aux->prox;
	}
	removeLista(buscaListaPos(pid, &processos), &processos);
}

void estado(Mem *mem) {
	imprimeLista(&mem->inicio);
}

void lista_processos(){
	imprimeLista(&processos);
}


