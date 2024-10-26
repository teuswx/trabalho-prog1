#ifndef MINHEAP_H
#define MINHEAP_H
#include "Cliente.h"
#include <stdio.h>
#include <stdlib.h>

// Estrutura para o nó da fila
typedef struct No {
    Cliente cliente;
    struct No *proximo;
} No;

// Estrutura para a fila de prioridade
typedef struct {
    No *frente;
} FilaPrioridade;


void inicializarFila(FilaPrioridade *fila);
No* criarNo(Cliente *cliente);
void enfileirar(FilaPrioridade *fila, Cliente *cliente);
Cliente desenfileirar(FilaPrioridade *fila);
void exibirFila(FilaPrioridade *fila);

#endif
