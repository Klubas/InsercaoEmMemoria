#ifndef PROCESSO_H
#define PROCESSO_H

#include <stdio.h>

//define a estrutura de um processo
struct processo{
    int pid = 0;
    int tam = 0;
};

typedef struct processo Processo;

//construtor de um processo
Processo* construir_processo(int tam, int pid); 

#endif
