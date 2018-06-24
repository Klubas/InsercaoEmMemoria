
#include <stdio.h>
#include "includes/memoria.h"
#include "includes/processo.h"
#include <string.h>

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

//funcao usada para tratar o retorno das funcoes de memoria.cpp
void retorno(int func, const char* nome, char mem, int pid){
	if(func == 0) printf("Mem %cf { Falha : %s (%d) : Retorno [%d] }\n", mem , nome ,pid, func);
	else if (func > 0) printf("Mem %cf { Sucesso : %s (%d) : Retorno [%d] }\n", mem , nome ,pid,  func);
	else if (func < 0) printf("Mem %cf { Error : %s (%d) : Retorno [%d] }\n", mem, nome,pid, func);
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
	printf("\n-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\\/-\n\n");
	estado(&mem0);
	lista_lacunas(&mem0); lista_processos(&mem0);
	estado(&mem1);
	lista_lacunas(&mem1); lista_processos(&mem1);
	estado(&mem2);
	lista_lacunas(&mem2); lista_processos(&mem2);
	estado(&mem3);
	lista_lacunas(&mem3); lista_processos(&mem3);
	printf("\n-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-\n\n");
	
}

//insere um novo processo em todas as memórias
void inserir_processos(int tam_processo){
	Processo* p = construir_processo(tam_processo, pid);
	retorno(novo_processo(p, &mem0), "novo_processo", mem0.tipo, pid);
	retorno(novo_processo(p, &mem1), "novo_processo", mem1.tipo, pid);
	retorno(novo_processo(p, &mem2), "novo_processo", mem2.tipo, pid);
	retorno(novo_processo(p, &mem3), "novo_processo", mem3.tipo, pid);
	pid = pid + 1;
}

//mata o processo desejado em todas as memórias
void matar_processos(int pid){
	retorno(matar_processo(pid, &mem0), "matar_processo", mem0.tipo, pid);
	retorno(matar_processo(pid, &mem1), "matar_processo", mem1.tipo, pid);
	retorno(matar_processo(pid, &mem2), "matar_processo", mem2.tipo, pid);
	retorno(matar_processo(pid, &mem3), "matar_processo", mem3.tipo, pid);
}

int main(){

	init_mem(3);

	mostrar_mem();

	//inserir_processos(55);
	inserir_processos(5);
	//matar_processos(1);/*
	inserir_processos(5);
	inserir_processos(10);

	mostrar_mem();
	/*matar_processos(1);
	mostrar_mem();
	matar_processos(3);
	inserir_processos(3);
	mostrar_mem();
	inserir_processos(10);
	mostrar_mem();
	inserir_processos(5);
	mostrar_mem();

	/*while(menu() > 0);*/

	return 0;	
}