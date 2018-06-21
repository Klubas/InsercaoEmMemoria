#ifndef LISTA_H  
#define LISTA_H

#include <stdio.h>
#include <stdlib.h>

//estrutura da lista, formada por nós
struct no{
	int dado;
	struct no *prox;
};

typedef struct no No;

//insere dado na lista de forma ordenada ou não
int insereLista(int valor, No *lista, int ordenada); 

//procura um valor na lista e retorna qual o nó
No buscaLista(int valor, No *lista); 

//procura um valor e retorna a posição
int buscaListaPos(int, No *); 

//encontra um valor na posicao informada
int recuperaListaValor(int posicao, No *lista); 

//retorna o no na posicao informada
No recuperaLista(int posicao, No *lista);

//modifica um valor em um no da lista
void alteraDado(int novo_valor, No *lista);	

//imprime toda a lista

void imprimeLista(No *lista); 

//remove o valor na posicao informada
int removeLista(int posicao, No *lista); 


#endif
