/*
TRABALHO PRÁTICO
Desenvolver uma aplicação que simule os métodos básicos de alocação de processos (first fit, best fit, worst fit e circular fit) em lacunas de memória com particionamento dinâmico.
Para isso, criar uma estrutura que simule um espaço de memória definido inicialmente pelo usuário. Uma estrutura independente para cada método de alocação (quatro "memórias").
Após, criar um conjunto de opções como segue:
Opção 1 - Inserir Processo em memória
Opção 2 - Remover processo em memória
Opção 3 - Listar estado das memórias
Opção 4 - Finalizar aplicação
Observações:
	a) considerar uma estrutura de memória independente para cada método de alocação;
	b) para cada inserção definir uma identificação de processo e perguntar ao usuário seu tamanho;
	c) para cada remoção questionar ao usuário a identificação do processo a ser removido;
	d) para cada inserção/remoção, realizar - SE POSSÍVEL - nas quatro memórias (independentemente);
	e) ao listar a memória, tratar o estado de maneira independente para cada uma das quatro memórias (os quatro algoritmos de alocação);
	f) entender como "estado da memória" uma situação em que ela possui processos e lacunas. Aquele com identificação de processo e tamanho e esta com um tamanho;
	g) trabalho com apresentação para o dia 27/06/18, valor 1,0 ponto que pode ser desenvolvido de maneira individual ou em duplas.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "memoria.h"

void criar_mem(int tam_mem, No *mem) {
	int i;
	for(i=0; i<tam_mem; i++){
		insereLista(i, mem);
	}
}

//retornar numero da memoria, e se der erro retornar numero da memoria *(-1)
int criar_processo(int tam, int tipo){
	
	return 0;
}

int matar_processo(int pid) {
	
	return 0;
}

void listar_mem(No *mem) {
	imprimeLista(mem);
}




