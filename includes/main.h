#ifndef MAIN_H  
#define MAIN_H

#include <stdio.h>
#include <string.h>

int menu();

void init_mem(int tam);

void mostrar_mem();

void inserir_processos(int tam_processo);

void matar_processos(int pid);

void mostrar_processos();

void retorno(int func, const char* nome, char mem, int pid);

#endif