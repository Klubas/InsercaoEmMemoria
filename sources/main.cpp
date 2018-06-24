#include <stdio.h>
#include <locale.h>
#include "../includes/view.h"

int main(){
	setlocale(LC_ALL, "Portuguese");

	int tam=20;

	/*printf("Definir o tamanho das memórias:\n > ");
	scanf("%d", &tam);
	if(tam <= 0) {
		printf("Tamanho invalido, saindo...\n");
		return 0;
	}*/

	init_mem(tam);

	while(menu() != 0);
	return 0;	
}