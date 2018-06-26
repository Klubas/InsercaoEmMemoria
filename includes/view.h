#ifndef VIEW_H  
#define VIEW_H

#include <stdio.h>
#include "../includes/memoria.h"

//menu
int menu();

//inicializa as 4 memórias Mem
void init_mem(int tam);

//mostra o estado das memórias
void mostrar_mem();

//insere um novo processo em todas as memórias
void inserir_processos(int tam_processo);

//mata o processo PID em todas as memórias
void matar_processos(int pid);

//retorna qual é o estado da memória
void estado(Mem *, int);	

//faz o tratamento do retorno das funcoes de inserir e matar processos
void retorno(int func, const char* nome, char mem, int pid);

#endif
