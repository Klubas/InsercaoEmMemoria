#include <stdio.h>
#include <stdlib.h>

#include "../includes/lista.h"
#include "../includes/memoria.h"
#include "../includes/processo.h"

#define VAZIO 0

//instancia a memoria vazia
void criar(Mem *mem) {
	int i;
	for(i = 1; i <= mem->tam; i++){
		insereLista(0, &mem->inicio, 0);
	}
	contar_lacunas(mem);
}

//cria um novo processo na memória informada
int novo_processo(Processo *proc, Mem *mem) {
	No *aux = &mem->inicio;
	int i = 0, pos = 0, buraco = 0, tentativa = 0;
	int melhor_lacuna = maior_lacuna(mem), diferenca = melhor_lacuna;
	
	if(proc->tam > mem->tam || proc->tam > melhor_lacuna || proc->tam <= 0){
		return 0; //impossivel inserir
	}
	
	switch (mem->tipo){
		case 'f': //first fit
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
							mem->qtd_processos = mem->qtd_processos + 1;
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
				if(!vazio(mem)){
					aux = mem->lacunas.prox;
					while(aux != NULL){
						diferenca = aux->dado - proc->tam ;
						if(diferenca <= melhor_lacuna){
							melhor_lacuna = aux->dado;
						}
						aux=aux->prox;
					}
					aux=&mem->inicio;
					while (aux != NULL){
						if(aux->dado == VAZIO){
							buraco = buraco + 1;
							if(buraco ==  melhor_lacuna){
								if(aux->prox != NULL){
									if(aux->prox->dado != VAZIO){
										pos = pos - proc->tam - 1;
										break;
									}
								} else {
									if(melhor_lacuna >= proc->tam){
										pos = pos - buraco;
									} else {
										pos = 0;
									}
								}
							}
						} else {
							buraco = 0;
						}
						aux=aux->prox; 
						pos = pos + 1;
					}
					aux=&mem->inicio;
				}
				if (pos != mem->tam) for(i=0; i < pos; i++) aux=aux->prox;

				while(aux != NULL){
					if(aux->dado == VAZIO){
						for(i = 0; i < proc->tam; i++){
							alteraDado(proc->pid, aux);
							aux=aux->prox;
						}
						mem->tam_ocupado = mem->tam_ocupado + proc->tam;
						mem->qtd_processos = mem->qtd_processos + 1;
						insereLista(proc->pid, &mem->processos, 1);
						return 1; //sucesso
					}
					aux=aux->prox;
				}	
				return -1; //falha ao inserir
			case 'w': //worst fit
				if(!vazio(mem)){
					aux = mem->lacunas.prox;
					while(aux != NULL){
						diferenca = aux->dado - proc->tam ;
						if(diferenca > melhor_lacuna){
							melhor_lacuna = aux->dado;
						}
						aux=aux->prox;
					}
					aux=&mem->inicio;
					while (aux != NULL){
						if(aux->dado == VAZIO){
							buraco = buraco + 1;
							if(buraco ==  melhor_lacuna){
								if(aux->prox != NULL){
									if(aux->prox->dado != VAZIO){
										pos = pos - proc->tam - 1;
										break;
									}
								} else {
									if(melhor_lacuna >= proc->tam){
										pos = pos - buraco;
									} else {
										pos = 0;
									}
								}
							}
						} else {
							buraco = 0;
						}
						aux=aux->prox; 
						pos = pos + 1;
					}
					aux=&mem->inicio;
				}
				for(i=0; i < pos; i++) aux=aux->prox;

				while(aux != NULL){
					if(aux->dado == VAZIO){
						for(i = 0; i < proc->tam; i++){
							alteraDado(proc->pid, aux);
							aux=aux->prox;
						}
						mem->tam_ocupado = mem->tam_ocupado + proc->tam;
						mem->qtd_processos = mem->qtd_processos + 1;
						insereLista(proc->pid, &mem->processos, 1);
						return 1; //sucesso
					}
					aux=aux->prox;
				}	
				return -1; //falha ao inserir
		case 'n': //next fit
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
							mem->qtd_processos = mem->qtd_processos + 1;
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
		default:
			printf("Erro\n");
			break;
		return -1;
	}

}

//mata o processo desejado na memória informada
int matar_processo(int pid, Mem *mem) {
	No *aux;
	int alt = 0, tam = 0;
	aux = &mem->inicio;

	if(pid <= VAZIO){
		return -1; //pid inválido
	}

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(VAZIO, aux);
			alt++;
		}
		aux = aux->prox;
	}
	if(alt > 0){
		removeLista(buscaListaPos(pid, &mem->processos), &mem->processos);
		mem->qtd_processos=mem->qtd_processos - 1;
		mem->tam_ocupado=mem->tam_ocupado-alt;
		contar_lacunas(mem);
		return 1; //processo removido
	}
	else 
		return 0; // processo não existe
}

//exibe estado da memoria
void estado(Mem *mem, int mostrar) {
	contar_lacunas(mem);
	printf("Mem [%cf] : ", mem->tipo); 
	if(mostrar) imprimeLista(&mem->inicio);
	printf("\nTamanho      :	%d\nOcupado      :	%d\n\nProcessos    :	%d\nLacunas      :	%d\n", mem->tam, mem->tam_ocupado, mem->qtd_processos, mem->qtd_lacunas);
	printf("\n"); lista_processos(mem);
	lista_lacunas(mem);
	//	printf("Menor lacuna: %d Maior Lacuna: %d\n", menor_lacuna(mem), maior_lacuna(mem));
}

int vazio(Mem *mem){
	if(contaElementos(&mem->inicio, VAZIO) == mem->tam) return 1;
	else return 0;
}

//lista todos os ativos
void lista_processos(Mem *mem){	
	printf("Processos    : ");
	imprimeLista(mem->processos.prox);
	//imprime_sem_repetir(&mem->processos);
}

void lista_lacunas(Mem *mem){
	contar_lacunas(mem);
	printf("Lacunas      : ");
	imprimeLista(mem->lacunas.prox);
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

void contar_lacunas(Mem *mem){
	int tam = 0, pos = 0;
	No *aux = &mem->inicio;

	limpaLista(&mem->lacunas);
	mem->qtd_lacunas = 0;

	while(aux != NULL){
		if(aux->dado == VAZIO && aux->prox != NULL){
			tam++; 
		} else if(tam > 0){
			if(aux->prox == NULL) tam = tam + 1;
			insereLista(tam, &mem->lacunas, 0);
			mem->qtd_lacunas = mem->qtd_lacunas + 1;
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