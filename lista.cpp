#include <stdio.h>
#include <stdlib.h>
#include "includes/lista.h"

No insereLista(int valor, No *lista, int ordenada){
	No *atual;
	No *anterior = NULL;
	No *aux;
	atual = lista;

	if (ordenada){
		while(atual != NULL && atual->dado < valor){
			anterior = atual;
			atual = atual->prox;
		}
		//if (valor == atual->dado) return 0;
	} else if (!ordenada){ //sem repetição de valores
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
	return *aux; //sucesso
}

void imprimeLista(No *lista){
	No *aux;
	aux = lista;
	printf("[ ");
	while(aux != NULL){
		printf("%d ", aux->dado);
		aux = aux->prox;
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

void limpaLista(No *lista){
	No *aux = lista;
	No *anterior = lista;
	aux->prox = NULL;
	/*while(aux != NULL){
		removeLista(1, aux);
		aux=aux->prox;
	}*/
	
	/*while(aux != NULL){
		anterior = aux;
		aux=aux->prox;
		removeLista(1, anterior);
	}*/
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

int recuperaListaValor(int posicao, No *lista){
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

No recuperaLista(int posicao, No *lista){
	int i = 1;
	No *aux = lista;

	if(aux == NULL) return *aux; 			//lista vazia

	while(aux != NULL && i <= posicao){
		aux=aux->prox;
		i++;
	}
	if (aux != NULL) return *aux; 	//achou
	else printf("NULL\n");
	return *aux->prox; 					//posicao invalida
}

int tamLista(No *lista){
	No *aux = lista;
	int i = 0;
	while(aux != NULL){
		aux = aux->prox; i++;
	}
	return i;
}

int contaElementos(No *lista, int e){
	No *aux;
	int i = 0;
	if(aux == NULL) return 0;

	while(aux != NULL){
		while(aux->dado == e){
			i++;
			aux=aux->prox;
			if(aux->prox->dado != e) return i;
		}

	}	
	return i;
}