#include <stdio.h>
#include <locale.h>

#include "../includes/view.h"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int tam;
	printf("|-----------------------------------------------------------------------------------\n");
	printf("|\n");
	printf("|  Definir o tamanho das memórias:\n");
	printf("|\n > ");
	scanf("%d", &tam);
	
	if(tam <= 0) {
		printf("|\n");
		printf("|  Tamanho invalido, saindo...\n");
		printf("|\n");
		printf("|-----------------------------------------------------------------------------------\n");
		return 0;
	}

	init_mem(tam);

	while(menu() != 0);
	
	return 0;	
}