#include <stdio.h>
#include <stdlib.h>
#include "includes/lista.h"

int insereLista(int valor, No *lista, int ordenada){
	No *atual;
	No *anterior = NULL;
	No *aux;
	atual = lista;

	if (ordenada && atual->dado < valor){
		while(atual != NULL){
			anterior = atual;
			atual = atual->prox;
		}
	} else {
		while(atual != NULL){
			anterior = atual;
			atual = atual->prox;
		}
	}

  	aux = new(No);
  	aux->dado = valor;
  	aux->prox=atual;

	if(atual==lista) {
		lista=aux;
	} else {
		anterior->prox=aux;
	}
	return 0; //sucesso
}

void imprimeLista(No *lista){
	No *aux;
	aux = lista;
	printf("[ ");
	if (aux == NULL) {
		printf("Lista vazia.\n");
	} else {
		while(aux != NULL){
			printf("%d ", aux->dado);
			aux = aux->prox;
		}
		
	}
	printf("]\n");
}

int removeLista(int posicao, No *lista){
	int i = 0;
	No *anterior = lista;
	No *aux = lista;

	if(aux == NULL) return -1; //lista vazia
	if(posicao < 0) return -2; //posicao invalida
	if(posicao == 0) {
		lista = lista->prox;
	} else {
		while(aux != NULL){
			if(i == posicao){
				anterior->prox = aux->prox;
			}

			anterior=aux;
			aux = aux->prox;
			i++;
		}
		if(posicao >= i) return -3; //posicao invalida
	}
	delete(aux);
	return 0; //elemento removido
}

void alteraDado(int novo_valor, No *no){
	no->dado=novo_valor;	//troca o dado do No por novo_valor
}

No buscaLista(int valor, No *lista){
	No *aux = lista;
	while(aux != NULL){
		if(aux->dado == valor){
			return *aux; //achou valor (primeira vez) i++;
		}
		aux=aux->prox;
	}
	return *aux;
}

int buscaListaPos(int valor, No *lista){
	int i = 0;
	No *aux = lista;
	while(aux != NULL){
		if(aux->dado == valor){
			return i; //achou valor (primeira vez) i++;
		}
		aux=aux->prox;
		i++;
	}
	return -1;
}

int recuperaLista(int posicao, No *lista){
	int i = 1;
	No *aux = lista;

	if(aux == NULL) return -1; 			//lista vazia
	if(posicao < 0) return -2; 			//posicao invalida 

	while(aux != NULL && i <= posicao){
		aux=aux->prox;
		i++;
	}

	if (aux != NULL) return aux->dado; 	//achou
	else return -2; 					//posicao invalida
}
