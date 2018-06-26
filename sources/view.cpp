#include <stdio.h>
#include <string.h>

#include "../includes/memoria.h"
#include "../includes/processo.h"
#include "../includes/view.h"

//declaração das memórias
Mem mem0, mem1, mem2, mem3;

int pid = 10, mostrar = 1;

//define o tamanho das memórias
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

}

//insere um novo processo em todas as memórias
void inserir_processos(int tam_processo){
	printf("|\n");
	Processo* p = construir_processo(tam_processo, pid);
	retorno(novo_processo(p, &mem0), "novo_processo", mem0.tipo, pid);
	retorno(novo_processo(p, &mem1), "novo_processo", mem1.tipo, pid);
	retorno(novo_processo(p, &mem2), "novo_processo", mem2.tipo, pid);
	retorno(novo_processo(p, &mem3), "novo_processo", mem3.tipo, pid);
	printf("|\n");
	pid = pid + 1;
}

//mata o processo desejado em todas as memórias
void matar_processos(int pid){
	printf("|\n");
	retorno(matar_processo(pid, &mem0), "matar_processo", mem0.tipo, pid);
	retorno(matar_processo(pid, &mem1), "matar_processo", mem1.tipo, pid);
	retorno(matar_processo(pid, &mem2), "matar_processo", mem2.tipo, pid);
	retorno(matar_processo(pid, &mem3), "matar_processo", mem3.tipo, pid);
	printf("|\n");
}

//mostra qual o estado das memórias
void mostrar_mem(int mostrar){
	printf("|-----------------------------------------------------------------------------------\n");
	estado(&mem0, mostrar);
	printf("|-----------------------------------------------------------------------------------\n");
	estado(&mem1, mostrar);
	printf("|-----------------------------------------------------------------------------------\n");
	estado(&mem2, mostrar);
	printf("|-----------------------------------------------------------------------------------\n");
	estado(&mem3, mostrar);
	printf("|-----------------------------------------------------------------------------------\n");
}

//funcao usada para tratar o retorno das funcoes de memoria.cpp
void retorno(int func, const char* nome, char mem, int pid){
	if(func == 0){
		printf("|  Mem [%cf] { Falha   : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Memória Insuficiente.\n");
		else if (strcmp(nome, "matar_processo") == 0) printf("Processo PID[%d] não existe.\n", pid);
	} else if (func > 0) {
		printf("|  Mem [%cf] { Sucesso : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Processo PID[%d] criado.\n", pid);
		else if (strcmp(nome, "matar_processo") == 0) printf("Processo PID[%d] morto.\n", pid);
	} else if (func < 0) {
		printf("|  Mem [%cf] { Error   : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Erro ao criar processo.\n");
		else if (strcmp(nome, "matar_processo") == 0) printf("Erro ao matar o processo %d.\n", pid);
	}
}

//menu
int menu(){
	int op, aux = 1;
	char x;

	if(mostrar == 1) x = 'x';
	else x = ' ';
	
	printf("|\n");
	printf("|  1 - Criar Processo \t\n");
	printf("|  2 - Matar Processo \t\n");
	printf("|  3 - Mostrar Memória\t\n");
	printf("|  4 - Mapa de memória (%c) \t\n", x);
	printf("|  0 - Sair           \t\n");
	printf("|\n > ");
	scanf("%d", &op);

	switch (op) {
		case 1: 
			printf("|\n");
			printf("|  Informe o tamanho:\n");
			printf("|\n > ");
			scanf("%d", &aux);
			if(aux > 0) inserir_processos(aux);
			return 1;
		case 2: 
			printf("|\n");
			printf("|  Informe o PID:\n");
			printf("|\n > ");
			scanf("%d", &aux);
			if(aux > 0) matar_processos(aux); 
			return 2;
		case 3:
			printf("|\n");
			printf("|  Memórias:\n");
			mostrar_mem(mostrar); 
			return 3;
		case 4:
			if(mostrar == 1) mostrar = 0;
			else mostrar = 1;
			return 4;
		default:	
			if(op == 0) return 0;
			else {
				printf("|\n");
				printf("|  Tente novamente.\n"); 
				return -1;
			}
	}
	
}
