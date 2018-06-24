#include <stdio.h>
#include <stdlib.h>

#include "includes/lista.h"
#include "includes/memoria.h"
#include "includes/processo.h"

#define VAZIO 0

//instancia a memoria vazia
void criar(Mem *mem) {
	int i;
	for(i = 1; i <= mem->tam; i++){
		insereLista(0, &mem->inicio, 0)	;
	}
}

//cria um novo processo na memória informada
int novo_processo(Processo *proc, Mem *mem) {
	int i = 0, pos = 0, buraco = 0;
	No *aux = &mem->inicio;
	
	if(proc->tam > mem->tam || proc->tam > maior_lacuna(mem)){
		return 0; //impossivel inserir
	}
	switch (mem->tipo){
		case 'f': //first fit | i = tamanho livre
			while(aux != NULL){
				if(aux->dado == VAZIO){
					if(buraco == proc->tam){
						//*aux = recuperaLista(pos - buraco, aux);
						aux = &mem->inicio;
						for(i = 0; i < pos - buraco; i++){
							aux=aux->prox;
						}
						for(i = 0; i <proc->tam; i++){
							alteraDado(proc->pid, aux);
							aux=aux->prox;
						}
						mem->tam_ocupado = mem->tam_ocupado + proc->tam;
						insereLista(proc->pid, &mem->processos, 1);
						return 1; //sucesso
					}
					buraco = buraco + 1;
				} else {
					buraco = 0;
				}
				aux = aux->prox;
				pos = pos + 1;
			}
			return -1; //falha ao inserir
		case 'b': //best fit

			



			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			mem->tam_ocupado = mem->tam_ocupado + proc->tam;
			insereLista(proc->pid, &mem->processos, 1);
			break; //sucesso, implementar e trocar por return 1
			return -1; //falha ao inserir
		
		
		case 'w': //worst fit
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			mem->tam_ocupado = mem->tam_ocupado + proc->tam;
			insereLista(proc->pid, &mem->processos, 1);
			break; //sucesso, implementar e trocar por return 1
			return -1; //falha ao inserir
		case 'n': //next fit
			for(i = 0; i < proc->tam; i++){
				alteraDado(proc->pid, aux);
				aux=aux->prox;
			}
			mem->tam_ocupado = mem->tam_ocupado + proc->tam;
			insereLista(proc->pid, &mem->processos, 1);
			break; //sucesso, implementar e trocar por return 1
			return -1; //falha ao inserir
		default: printf("Erro\n");
	}
	return 2; //sucesso ao inserir
}

//mata o processo desejado na memória informada
int matar_processo(int pid, Mem *mem) {
	No *aux;

	/* NAO FUNCIONA TESTAR SE O PROCESSO EXISTE OU NAO NA MEMÓRIA
	aux = &mem->processos;
	while(aux != NULL){
		if(aux->dado == pid) break;
		aux=aux->prox;
		printf("aux->dado %d", aux->dado);
	}

	if(aux->dado != pid) return 0; //processo não existe
	*/

	aux = &mem->inicio;

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(VAZIO, aux);
		}
		aux = aux->prox;
	}
	removeLista(buscaListaPos(pid, &mem->processos), &mem->processos);
	return 1; //processo removido
}

//exibe estado da memoria
void estado(Mem *mem) {
	printf("Menor lacuna: %d Maior Lacuna: %d\n", menor_lacuna(mem), maior_lacuna(mem));

	printf("Mem %cf : ", mem->tipo); imprimeLista(&mem->inicio);
}

//lista todos os processos criados e não-matados
void lista_processos(Mem *mem){	
	printf("Processos Mem %cf : ", mem->tipo );
	imprimeLista(&mem->processos);
	//imprime_sem_repetir(&mem->processos);
}

void lista_lacunas(Mem *mem){
	contar_lacunas(mem);
	printf("Lacunas   Mem %cf : ", mem->tipo );
	imprimeLista(&mem->lacunas);
}

int maior_lacuna(Mem *mem){
	No *aux;
	int maior = 0;
	contar_lacunas(mem);
	aux = &mem->lacunas;
	while (aux != NULL ) {
		if(aux->dado > maior){
			maior = aux->dado;
		}
		aux=aux->prox;
	}
	return maior;
}	

int menor_lacuna(Mem *mem) {
	No *aux;
	int menor = mem->tam ;
	contar_lacunas(mem);
	
	aux = &mem->lacunas;

	if(tamLista(aux) == 0){
		return 0;
	}

	while(aux != NULL){
		if(aux->dado < menor && aux->dado != 0){
			menor = aux->dado;
		}
		aux=aux->prox;
	}

	if(menor == mem->tam) {
		return 0;
	}

	return menor ;
}

No lacuna(int tam, Mem *mem){
	No *aux = &mem->lacunas;
	int diferenca = 0, pos;
	while (aux != NULL){
		if(aux->dado == tam) break;
		aux=aux->prox;
	}
}

void contar_lacunas(Mem *mem){
	int tam = 0, pos = 0;
	No *aux = &mem->inicio;

	limpaLista(&mem->lacunas);

	while(aux != NULL){
		if(aux->dado == VAZIO && aux->prox != NULL){
			tam++; 
		} else if(tam > 0 ){
			insereLista(tam + 1, &mem->lacunas, 0);
			tam = 0;
		}
		aux=aux->prox; 
	}
	return;
}
	
void imprime_sem_repetir(No *no){
	int dado;
	No *aux;
	aux = no;
	printf("[ ");
	dado = aux->dado;
	while(aux != NULL){
		if(dado != aux->dado)
			printf("%d ", aux->dado);
		dado = aux->dado;
		aux = aux->prox;
	}
	printf("]\n");
}


