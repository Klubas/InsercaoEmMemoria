#include <stdio.h>
#include "includes/memoria.h"
#include "includes/processo.h"


int pid = 0;
Mem mem0, mem1, mem2, mem3;
Processo proc;

int menu(){
	/*criar_mem(mem0, 1000);
	imprime(mem0)
	criar_processo(100, tipo);
	matar_processo(0);
	listar_mem(mem0);*/
	return 0;
}

void init_mem(int tam){
	mem0.tam = tam;
	mem1.tam = tam;
	mem2.tam = tam;
	mem3.tam = tam;

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

void mostrar_mem(){
	estado(&mem0);
	estado(&mem1);
	estado(&mem2);
	estado(&mem3);
}
/*
void construir_processo(int tam, int pid){
	proc.pid = pid;
	proc.tam = tam;
}
*/
void inserir_processos(int tam_processo){

	/*novo_processo(&proc, &mem0);
	/*novo_processo(&p, &mem1);
	novo_processo(&p, &mem2);
	novo_processo(&p, &mem3);*/
	//pid = pid + 1;
}

int main(){
	init_mem(10);

	mostrar_mem();

//	proc.pid = pid;
//	proc.tam = 5;

	inserir_processos(3);

	mostrar_mem();

	matar_processo(1, &mem0);

	mostrar_mem();

	/*while(menu() > 0);*/

	return 0;	
}