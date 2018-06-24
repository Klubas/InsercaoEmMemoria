
#include <stdio.h>
#include <string.h>

#include "../includes/memoria.h"
#include "../includes/processo.h"
#include "../includes/view.h"

int pid = 1;

Mem mem0, mem1, mem2, mem3;

int menu(){
	int op, aux;

	printf("\n1 - Criar Processo\n");
	printf("2 - Matar Processo\n");
	printf("3 - Mostrar Memória\n");
	printf("4 - Mostrar Processos\n");
	printf("0 - Sair\n\n > ");
	scanf("%d", &op);

	switch (op) {
		case 1: 
			printf("\nInforme o tamanho:\n > ");
			scanf("%d", &aux);
			if(aux>0) inserir_processos(aux);
			return 1;
		case 2: 
			printf("\nInforme o PID:\n > ");
			scanf("%d", &aux);
			if(aux>0) matar_processos(aux); 
			return 2;
		case 3:
			printf("\nMemórias:\n");
			mostrar_mem(); 
			return 3;
		case 4:
			printf("\n");
			mostrar_processos();
			return 4;
		default:
			if(op==0) 
				return 0;
			else {
				printf("\nTente novamente.\n"); 
				return -1;
			}
	}
	
}

//funcao usada para tratar o retorno das funcoes de memoria.cpp
void retorno(int func, const char* nome, char mem, int pid){
	if(func == 0) printf("Mem [%cf] { Falha : %s (%d) : Retorno [%d] }\n", mem , nome ,pid, func);
	else if (func > 0) printf("Mem [%cf] { Sucesso : %s (%d) : Retorno [%d] }\n", mem , nome ,pid,  func);
	else if (func < 0) printf("Mem [%cf] { Error : %s (%d) : Retorno [%d] }\n", mem, nome,pid, func);
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
	lista_lacunas(&mem0); 
	//lista_processos(&mem0);
	estado(&mem1);
	lista_lacunas(&mem1); 
	//lista_processos(&mem1);
	estado(&mem2);
	lista_lacunas(&mem2); 
	//lista_processos(&mem2);
	estado(&mem3);
	lista_lacunas(&mem3); 
	//lista_processos(&mem3);
	printf("\n-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-/\\-\n\n");
}

//insere um novo processo em todas as memórias
void inserir_processos(int tam_processo){
	printf("\n");
	Processo* p = construir_processo(tam_processo, pid);
	retorno(novo_processo(p, &mem0), "novo_processo", mem0.tipo, pid);
	retorno(novo_processo(p, &mem1), "novo_processo", mem1.tipo, pid);
	retorno(novo_processo(p, &mem2), "novo_processo", mem2.tipo, pid);
	retorno(novo_processo(p, &mem3), "novo_processo", mem3.tipo, pid);
	printf("\n");
	pid = pid + 1;
}

//mata o processo desejado em todas as memórias
void matar_processos(int pid){
	printf("\n");
	retorno(matar_processo(pid, &mem0), "matar_processo", mem0.tipo, pid);
	retorno(matar_processo(pid, &mem1), "matar_processo", mem1.tipo, pid);
	retorno(matar_processo(pid, &mem2), "matar_processo", mem2.tipo, pid);
	retorno(matar_processo(pid, &mem3), "matar_processo", mem3.tipo, pid);
	printf("\n");
}

void mostrar_processos(){
	lista_processos(&mem0);
	lista_processos(&mem1);
	lista_processos(&mem2);
	lista_processos(&mem3);
}

