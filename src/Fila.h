#ifndef FILA_H
#define FILA_H
#include "Cliente.h"
#include <stdbool.h>

// Estrutura para um nó na fila
typedef struct No {
    Cliente cliente;
    struct No* proximo;
} No;

// Estrutura para a fila de prioridade
typedef struct FilaPrioridade {
    No* inicio;  // Ponteiro para o início da fila
    No* fim;     // Ponteiro para o final da fila
} FilaPrioridade;

// Funções da fila
void inicializarFila(FilaPrioridade* fila);
bool filaVazia(FilaPrioridade* fila);
void inserirCliente(FilaPrioridade* fila, Cliente cliente);
Cliente removerCliente(FilaPrioridade* fila);
void imprimirFila(FilaPrioridade* fila);

#endif
