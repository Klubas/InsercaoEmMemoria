#ifndef PROCESSO_H
#define PROCESSO_H

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct processo{
    int pid;
    int tam;
    No *inicio;
};

typedef struct processo Processo;

#endif
