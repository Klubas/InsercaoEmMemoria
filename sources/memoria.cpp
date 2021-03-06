#include <stdio.h>

#include "../includes/lista.h"
#include "../includes/memoria.h"
#include "../includes/processo.h"

#define VAZIO 0

//instancia a memoria vazia
void criar(Mem *mem) {
	int i;
	limpaLista(&mem->inicio);
	limpaLista(&mem->processos);
	limpaLista(&mem->lacunas);
	for(i = 1; i < mem->tam; i++){
		insereLista(0, &mem->inicio, 0);
	}
}

//cria um novo processo na memória informada
int novo_processo(Processo *proc, Mem *mem) {	
	if (proc->tam > maior_lacuna(mem) || proc->tam <= 0) 
		return 0; //impossivel inserir
	switch (mem->tipo){
		case 'f': 
		case 'n': return position_fit(mem, proc, mem->tipo); break;
		case 'b':
		case 'w': return quality_fit(mem, proc, mem->tipo); break;
		default : break;
	}
	return -1;
}

//encontra a posicao para gravar pelos metodos best e worst fit
int quality_fit(Mem *mem, Processo *proc, const char tipo_fit){
	int buraco = 0, pos = 0, i;
	int melhor_lacuna = maior_lacuna(mem), diferenca = melhor_lacuna;
	No *aux = &mem->inicio;

	switch(tipo_fit){
		case 'b': //best fit
			aux = mem->lacunas.prox;
			while(aux != NULL){
				if(melhor_lacuna - proc->tam > aux->dado - proc->tam && aux->dado >= proc->tam)
					melhor_lacuna = aux->dado;
				aux=aux->prox;
			}
		case 'w': // worst fit
			break;
		default: return -2; //erro ao inserir
	}

	aux=&mem->inicio;
	while (aux != NULL){
		if(aux->dado == VAZIO){
			buraco = buraco + 1;
			if(buraco ==  melhor_lacuna && (aux->prox == NULL || aux->prox->dado != VAZIO)){
				grava_memoria(mem, proc, pos - buraco + 1);
				return 1; //sucesso
			}
		} else buraco = 0;
		aux=aux->prox; 
		pos = pos + 1;
	}
	return -1; // falha ao inserir
}

//encontra a posicao a gravar pelos metodos first e next fit
int position_fit(Mem *mem, Processo *proc, const char tipo_fit){
	int pos = 0, buraco = 0, tentativa = 0, i;
	No *aux = &mem->inicio;

	switch(tipo_fit){
		case 'n' : // next fit
			for(pos = 0; pos <= mem->ultima_pos; pos++) aux=aux->prox;
		case 'f' : // first fit
			if(tipo_fit == 'f') tentativa = 1;
			insere: 
				while(aux != NULL) {
					if(aux->dado == VAZIO){
						buraco = buraco + 1;
						if(buraco == proc->tam){
							grava_memoria(mem, proc, pos - buraco + 1);
							return 1; //sucesso
						}
					} else buraco = 0;

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
		default: return -1; //falha ao inserir
	}
}

//grava o processo na posicao informada
void grava_memoria(Mem *mem, Processo *proc, int pos){
	int i;
	No *aux = &mem->inicio;

	for(i = 0; i < pos; i++) aux=aux->prox;

	for(i = 0; i <proc->tam; i++){
		alteraDado(proc->pid, aux);
		aux=aux->prox;
	}
	mem->ultima_pos = pos;
	mem->tam_ocupado = mem->tam_ocupado + proc->tam;
	mem->qtd_processos = mem->qtd_processos + 1;
	insereLista(proc->pid, &mem->processos, 1);
}

//mata o processo desejado na memória informada
int matar_processo(int pid, Mem *mem) {
	No *aux;
	int alt = 0, tam = 0;
	aux = &mem->inicio;

	while(aux != NULL ){
		if(aux->dado == pid){
			alteraDado(VAZIO, aux);
			alt++;
		}
		aux = aux->prox;
	}

	if(alt > 0){
		removeLista(buscaListaPos(pid, &mem->processos), &mem->processos);
		mem->qtd_processos = mem->qtd_processos - 1;
		mem->tam_ocupado = mem->tam_ocupado - alt;
		contar_lacunas(mem);
		return 1; //processo removido
	}
	else 
		return 0; // processo não existe
}

//testa se a memória esta vazia (1) ou não (0)
int vazio(Mem *mem){
	if(contaElementos(&mem->inicio, VAZIO) == mem->tam) return 1;
	else return 0;
}

//testa se a memória esta cheia (1) ou não (0)
int cheio(Mem *mem){
	if(contaElementos(&mem->inicio, VAZIO) == 0) return 1;
	else return 0;
}

//lista todos os pids de processos (inicia em prox para omitir o pid '0')
void lista_processos(Mem *mem){	
	imprimeLista(mem->processos.prox);
}

//lista todas as lacunas (inicia em .prox pra omitir o tamanho '0')
void lista_lacunas(Mem *mem){
	contar_lacunas(mem);
	imprimeLista(mem->lacunas.prox);
}

void lista_memoria(Mem *mem){
	imprimeLista(&mem->inicio);
}

//retorna o tamanho da maior lacuna
int maior_lacuna(Mem *mem){
	int i, tam;
	No *aux;

	contar_lacunas(mem);
	aux = &mem->lacunas;
	tam = tamLista(aux);

	if(tam <= 1){
		return 0;
	} else {
		for(i=0; i<tam-1; i++) aux=aux->prox;
		return aux->dado;
	}
}

//retorna o tamanho da menor lacuna
int menor_lacuna(Mem *mem) {
	No *aux;
	contar_lacunas(mem);
	aux = &mem->lacunas;
	if (tamLista(aux) <= 1) return 0;
	else return aux->prox->dado;
}

//conta a quantidad de lacunas na memoria
void contar_lacunas(Mem *mem){
	int tam = 0, i;
	No *aux = &mem->inicio;

	mem->qtd_lacunas = 0;
	limpaLista(&mem->lacunas);

	for(i = 0; i < mem->tam; i++){
		if(aux->dado == VAZIO) 
			tam++;
		else {
			insereLista(tam, &mem->lacunas, 1); 
			tam = 0;	
		}
		aux=aux->prox;
	}
	if(tam > 0) insereLista(tam, &mem->lacunas, 1); 
	
	mem->qtd_lacunas = tamLista(&mem->lacunas) - 1;
}
