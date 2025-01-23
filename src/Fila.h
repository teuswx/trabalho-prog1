#ifndef FILA_H
#define FILA_H
#include "Cliente.h"
#include <stdbool.h>

typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

typedef struct FilaPrioridade {
    No* inicio; 
    No* fim;    
} FilaPrioridade;

void inicializarFila(FilaPrioridade* fila);
bool filaVazia(FilaPrioridade* fila);
void inserirCliente(FilaPrioridade* fila, Cliente cliente);
Cliente removerCliente(FilaPrioridade* fila);
void imprimirFila(FilaPrioridade* fila);
int tamanhoFila(FilaPrioridade* fila);

#endif
