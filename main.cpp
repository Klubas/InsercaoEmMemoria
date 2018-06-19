#include <stdio.h>
#include "memoria.h"
#include "lista.h"

No memff, membf;

int menu(){
	/*criar_mem(mem0, 1000);
	imprime(mem0)
	criar_processo(100, tipo);
	matar_processo(0);
	listar_mem(mem0);*/
	
	return 0;
}

int main(){
	int tam = 10;
/*	Mem memoria;
	memoria.tam = tam;
	memoria.ff = NULL;
	memoria.bf = NULL;
	memoria.wf = NULL;
	memoria.nf = NULL;
	Mem *mptr = &memoria;
*/

	criar_mem(10, &memff);
	criar_mem(20, &membf);
	listar_mem(&memff);
    listar_mem(&membf);


	//printf("[%d]", mem0.dado);

	//criar_mem(15, mem0ptr);

	//criar_mem(9, memoria.bf);
	//criar_mem(8, memoria.nf);
	//criar_mem(7, memoria.wf);
	//imprime(memoria.wf);

	/*while(menu() > 0);*/
	//	printf("teste0");
	//criar_mem(100);
	//printf("teste1");
	//imprime(mem0);

	return 0;	
}