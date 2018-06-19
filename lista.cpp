#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int insereLista(int valor, No *lista){
	No *atual;
	No *anterior = NULL;
	No *aux;
	atual = lista;

	while(atual != NULL && atual->dado < valor) {
		anterior = atual;
    	atual = atual->prox;
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
	if (aux == NULL) {
		printf("Lista vazia.\n");
	} else {
		printf("[ ");
		do{
			printf("%d ", aux->dado);
			aux = aux->prox;
		}while(aux != NULL);
		printf(" ]");
	}
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

	printf("Elemento %d removido.\n", posicao);
	delete(aux);
	return 0;
}

int buscaLista(int valor, No *lista){
	int i = 0;
	No *aux = lista;
	while(aux != NULL){
		if(aux->dado == valor){
			return i; //achou valor (primeira vez) i++;
		}
		aux=aux->prox;
	}
}

int recuperaLista(int posicao, No *lista){
	int i = 1;
	No *aux = lista;

	if(aux == NULL) return -1; ///lista vazia
	if(posicao < 0) return -2; //posicao invalida 

	while(aux != NULL && i <= posicao){
		aux=aux->prox;
		i++;
	}

	if (aux != NULL) return aux->dado; //achou
	else return -2; //posicao invalida
}
