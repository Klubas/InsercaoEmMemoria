#include <stdio.h>
#include "includes/memoria.h"

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

	criar_mem(10, &mem.ff);
	criar_mem(20, &mem.bf);
	listar_mem(&mem.ff);
    listar_mem(&mem.bf);


	/*while(menu() > 0);*/


	return 0;	
}