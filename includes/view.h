#ifndef VIEW_H  
#define VIEW_H

#include <stdio.h>

int menu();

void init_mem(int tam);

void mostrar_mem();

void inserir_processos(int tam_processo);

void matar_processos(int pid);

void mostrar_processos();

void mostrar_lacunas();

void retorno(int func, const char* nome, char mem, int pid);

#endif