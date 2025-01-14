#ifndef CAIXA_H
#define CAIXA_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Fila.h"
#define MAX_CAIXAS 5

typedef struct Caixa {
    int nIdentCaixa;
    int estado;
    FilaPrioridade filaClientes;
} Caixa;

void inicializarCaixa(Caixa *c[]);
void imprimirEstado(Caixa *c[]);
void abrirFecharCaixa(Caixa *c[], int nIdent, int nEstado);
#endif
