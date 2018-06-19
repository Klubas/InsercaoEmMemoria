#include <stdio.h>
#include "includes/memoria.h"

int pid;
Mem mem;

int menu(){
	/*criar_mem(mem0, 1000);
	imprime(mem0)
	criar_processo(100, tipo);
	matar_processo(0);
	listar_mem(mem0);*/
	
	return 0;
}

int main(){

	criar(10, &mem.ff);
	criar(20, &mem.bf);
	estado(&mem.ff);
    estado(&mem.bf);


	/*while(menu() > 0);*/


	return 0;	
}