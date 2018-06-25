#include <stdio.h>
#include <string.h>

#include "../includes/memoria.h"
#include "../includes/processo.h"
#include "../includes/view.h"

int pid = 10;

Mem mem0, mem1, mem2, mem3;

//funcao usada para tratar o retorno das funcoes de memoria.cpp
void retorno(int func, const char* nome, char mem, int pid){
	if(func == 0){
		printf("Mem [%cf] { Falha   : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Memória Insuficiente.\n");
		else if (strcmp(nome, "matar_processo") == 0) printf("Processo não existe.\n");
	} else if (func > 0) {
		printf("Mem [%cf] { Sucesso : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Processo criado.\n");
		else if (strcmp(nome, "matar_processo") == 0) printf("Processo morto.\n");
	} else if (func < 0) {
		printf("Mem [%cf] { Error   : %s (%d) : Retorno [%d] } ", mem, nome, pid, func);
		if(strcmp(nome, "novo_processo") == 0) printf("Erro ao criar processo.\n");
		else if (strcmp(nome, "matar_processo") == 0) printf("Erro ao matar processo\n");
	}
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

	mem0.lacunas.prox = NULL;
	mem1.lacunas.prox = NULL;
	mem2.lacunas.prox = NULL;
	mem3.lacunas.prox = NULL;

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

	/*mem0.lacunas = *mem0.lacunas.prox;
	mem1.lacunas = *mem1.lacunas.prox;
	mem2.lacunas = *mem2.lacunas.prox;
	mem3.lacunas = *mem3.lacunas.prox;*/
}

//mostra qual o estado das memórias
void mostrar_mem(int mostrar){
	printf("-----------------------------------------------------------------------------------\n");
	estado(&mem0, mostrar);
	printf("-----------------------------------------------------------------------------------\n");
	estado(&mem1, mostrar);
	printf("-----------------------------------------------------------------------------------\n");
	estado(&mem2, mostrar);
	printf("-----------------------------------------------------------------------------------\n");
	estado(&mem3, mostrar);
	printf("-----------------------------------------------------------------------------------\n");
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

int menu(){
	int op, aux;
	char c;
	printf("-------------------------\n");
	printf("| 1 - Criar Processo    |\n");
	printf("| 2 - Matar Processo    |\n");
	printf("| 3 - Mostrar Memória   |\n");
	printf("| 0 - Sair              |\n");
	printf("-------------------------\n > ");
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
			/*if(mem0.tam > 200){
				printf("Memória muito grande, tem certeza que deseja exibir a representação? (s/n) ");
				c = getc(stdin);
				//scanf("%c", &c);
				switch(c){
					case 's' : aux = 1; break;
					case 'S' : aux = 1; break;
					default : aux = 0; break;
				}
			}*/
			printf("\nMemórias:\n");
			mostrar_mem(aux); 
			return 3;
		default:	
			if(op==0) 
				return 0;
			else {
				printf("\nTente novamente.\n"); 
				return -1;
			}
	}
	
}