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
	int i = 0, pos = 0, buraco = 0, tentativa = 0, melhor_pos = 0, diferenca = 0;
	No *aux = &mem->inicio;
	
	if(proc->tam > mem->tam /*|| proc->tam > maior_lacuna(mem)*/ || proc->tam <= 0){
		return 0; //impossivel inserir
	}
	switch (mem->tipo){
		case 'f': //first fit | i = tamanho livre
			while(aux != NULL){
				if(aux->dado == VAZIO){
					buraco = buraco + 1;
					if(buraco == proc->tam){
						//*aux = recuperaLista(pos - buraco, aux);
						aux = &mem->inicio;
						for(i = 0; i <= pos - buraco; i++){
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
					
				} else {
					buraco = 0;
				}
				aux = aux->prox;
				pos = pos + 1;
			}
			return -1; //falha ao inserir
		case 'b': //best fit
			while(aux != NULL){
				if(aux->dado == VAZIO){
					buraco = buraco + 1;
				} else {
					if(buraco - proc->tam > 0){
						melhor_pos = pos;
					}
					if(buraco - proc->tam < diferenca){
						diferenca = buraco - proc->tam;
					}
					buraco = 0;
				}
				aux=aux->prox;
				pos = pos + 1;
			}
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
			printf("ultima pos=%d\n", mem->ultima_pos);
			for(pos = 0; pos <= mem->ultima_pos; pos++){
				aux=aux->prox;
			}

			insere:
			while(aux != NULL) {
				if(aux->dado == VAZIO){
					buraco = buraco + 1;
					if(buraco == proc->tam){
						aux = &mem->inicio;
						for(i = 0; i <= pos - buraco; i++){
							aux=aux->prox;
						}
						for(i = 0; i <proc->tam; i++){
							alteraDado(proc->pid, aux);
							aux=aux->prox;
						}
						mem->tam_ocupado = mem->tam_ocupado + proc->tam;
						mem->ultima_pos = pos;
						insereLista(proc->pid, &mem->processos, 1);
						return 1; //sucesso
					}
					
				} else {
					buraco = 0;
				}
				aux = aux->prox;
				pos = pos + 1;
			}
			if(tentativa == 0) {
				tentativa = 1;
				aux = &mem->inicio;
				mem->ultima_pos = 0;
				pos = 0;
				goto insere;
			}
			return -1; //falha ao inserir
		default: printf("Erro\n");
	}
	return 2; //sucesso ao inserir
}

//mata o processo desejado na memória informada
int matar_processo(int pid, Mem *mem) {
	No *aux;
	int alt = 0;
	aux = &mem->inicio;

	if(pid <= VAZIO){
		return -1; //pid inválido
	}

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(VAZIO, aux);
			alt = 1;
		}
		aux = aux->prox;
	}
	if(alt == 1){
		removeLista(buscaListaPos(pid, &mem->processos), &mem->processos);
		return 1; //processo removido
	}
	else 
		return 0; // processo não existe
}

//exibe estado da memoria
void estado(Mem *mem) {
	contar_lacunas(mem);
	printf("Mem [%cf] : ", mem->tipo); imprimeLista(&mem->inicio);
	printf("Menor lacuna: %d \nMaior Lacuna: %d\n", menor_lacuna(mem), maior_lacuna(mem));
}

//lista todos os processos criados e não-matados
void lista_processos(Mem *mem){	
	printf("Processos Mem %cf : ", mem->tipo );
	imprimeLista(&mem->processos);
	//imprime_sem_repetir(&mem->processos);
}

void lista_lacunas(Mem *mem){
	contar_lacunas(mem);
	mem->lacunas=*mem->lacunas.prox;
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

	if(tamLista(aux) == 1){
		return 0;
	}

	while(aux != NULL){
		if(aux->dado < menor && aux->dado != 0){
			menor = aux->dado;
		}
		aux=aux->prox;
	}
	if(maior_lacuna(mem) == mem->tam) {
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
	No *aux = mem->inicio.prox;

	limpaLista(&mem->lacunas);

	while(aux != NULL){
		if(aux->dado == VAZIO && aux->prox != NULL){
			tam++; 
		} else if(tam > 0 || aux->prox == NULL){
			if(aux->prox == NULL) tam = tam + 1;
			insereLista(tam, &mem->lacunas, 0);
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


