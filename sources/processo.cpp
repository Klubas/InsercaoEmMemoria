#include <stdio.h>

#include "../includes/processo.h"

Processo proc;

//cria um processo e retorna
Processo* construir_processo(int tam, int pid){
	proc.pid = pid;
	proc.tam = tam;
	return &proc;
}
