#include <stdio.h>
#include "includes/memoria.h"
#include "includes/processo.h"

int pid = 1;

Mem mem0, mem1, mem2, mem3;


int menu(){
	/*criar_mem(mem0, 1000);
	imprime(mem0)
	criar_processo(100, tipo);
	matar_processo(0);
	listar_mem(mem0);*/
	return 0;
}

//define o tamanho das memórias
void init_mem(int tam){
	mem0.tam = tam;
	mem1.tam = tam;
	mem2.tam = tam;
	mem3.tam = tam;

	mem0.inicio.prox = NULL;
	mem1.inicio.prox = NULL;
	mem2.inicio.prox = NULL;
	mem3.inicio.prox = NULL;

	mem0.tipo = 'f';
	mem1.tipo = 'b';
	mem2.tipo = 'w';
	mem3.tipo = 'n';

	criar(&mem0);
	criar(&mem1);	
	criar(&mem2);	
	criar(&mem3);

	mem0.inicio = *mem0.inicio.prox;
	mem1.inicio = *mem1.inicio.prox;
	mem2.inicio = *mem2.inicio.prox;
	mem3.inicio = *mem3.inicio.prox;
}

//mostra qual o estado das memórias
void mostrar_mem(){
	estado(&mem0);
	estado(&mem1);
	estado(&mem2);
	estado(&mem3);
}

//insere o processo criado em todas as memórias
void inserir_processos(int tam_processo){
	Processo* p = construir_processo(tam_processo, pid);
	novo_processo(p, &mem0);
	novo_processo(p, &mem1);
	novo_processo(p, &mem2);
	novo_processo(p, &mem3);
	pid = pid + 1;
	lista_processos();
}

//mata o processo desejado em todas as memórias
void matar_processos(int pid){
	matar_processo(pid, &mem0);
	matar_processo(pid, &mem1);
	matar_processo(pid, &mem2);
	matar_processo(pid, &mem3);
	lista_processos();
}

int main(){

	init_mem(50);

	mostrar_mem();

	inserir_processos(6);


	mostrar_mem();

	/*while(menu() > 0);*/

	return 0;	
}