#include <stdio.h>

#include "../includes/lista.h"

//insere valor na lista e retorna o struct criado
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
	} else if (!ordenada){
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

//mostra os valores da lista
void imprimeLista(No *lista){
	No *aux;
	int i = 0;
	aux = lista;
	printf(" [ ");
	while(aux != NULL){
		if(i == 25) { printf("\n|   "); i = 0; }
		printf("%3d ", aux->dado); i++;
		aux = aux->prox;
	}
	printf("  ]");
}

//remove o valor na POSICAO da lista
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

//remove todos os valores da lista
void limpaLista(No *lista){
	int i = 0, tam = tamLista(lista);
	for(i = tam; i > 0; i--) 
		removeLista(i, lista);
}

//altera o valor em no por novo_valor
void alteraDado(int novo_valor, No *no){
	no->dado=novo_valor;	//troca o dado do No por novo_valor
}

//retorna o no do VALOR
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

//retorna a posicao do VALOR
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

//retorna o valor da POSICAO
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

//retorna a struct da POSICAO
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

//retorna a quantidade de itens da lista
int tamLista(No *lista){
	No *aux = lista;
	int i = 0;
	while(aux != NULL){
		aux = aux->prox; i++;
	}
	return i;
}

//retorna a quantidade de elementos e tem na lista
int contaElementos(No *lista, int e){
	No *aux = lista;
	int i = 0;

	while(aux != NULL){
		if(aux->dado == e){
			i++; 
		}
		aux=aux->prox;
	}	
	return i;
}