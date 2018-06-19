#include <stdio.h>
#include <stdlib.h>
#include "includes/lista.h"
#include "includes/memoria.h"

void criar(int tam_mem, No *mem) {
	int i;
	for(i=0; i<tam_mem; i++){
		insereLista(i, mem);
	}
}

//retornar numero da memoria, e se der erro retornar numero da memoria *(-1)
int novo_processo(int tam, int tipo){
	
	return 0;
}

int matar_processo(int pid) {
	
	return 0;
}

void estado(No *mem) {
	imprimeLista(mem);
}


