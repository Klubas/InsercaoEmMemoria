#include <stdio.h>
#include "includes/memoria.h"

int pid;
Mem mem0, mem1, mem2, mem3;

typedef struct processo Processo;

int menu(){
	/*criar_mem(mem0, 1000);
	imprime(mem0)
	criar_processo(100, tipo);
	matar_processo(0);
	listar_mem(mem0);*/
	
	return 0;
}

int main(){

	criar(10, &mem0);
	criar(20, &mem1);
	estado(&mem0);
    estado(&mem1);


	/*while(menu() > 0);*/


	return 0;	
}