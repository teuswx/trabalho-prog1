#include "Fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarFila(FilaPrioridade* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
}

bool filaVazia(FilaPrioridade* fila) {
    return fila->inicio == NULL;
}

void inserirCliente(FilaPrioridade* fila, Cliente cliente) {
    No* novo = (No*)malloc(sizeof(No));
    if (!novo) {
        printf("Erro ao alocar memória para o cliente.\n");
        return;
    }
    novo->cliente = cliente;
    novo->proximo = NULL;

    // Inserção ordenada por prioridade
    if (filaVazia(fila)) {
        fila->inicio = novo;
        fila->fim = novo;
    } else {
        No* atual = fila->inicio;
        No* anterior = NULL;

        // Procurar posição correta baseado na prioridade
        while (atual && atual->cliente.prioridade <= cliente.prioridade) {
            anterior = atual;
            atual = atual->proximo;
        }

        if (anterior == NULL) {  // Inserção no início
            novo->proximo = fila->inicio;
            fila->inicio = novo;
        } else {  // Inserção no meio ou final
            anterior->proximo = novo;
            novo->proximo = atual;

            if (atual == NULL) {  // Atualizar o fim da fila
                fila->fim = novo;
            }
        }
    }
}

Cliente removerCliente(FilaPrioridade* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        exit(EXIT_FAILURE); // Opcional: retorne um Cliente "inválido" se preferir evitar sair do programa.
    }

    No* removido = fila->inicio;
    Cliente cliente = removido->cliente;
    fila->inicio = removido->proximo;

    if (fila->inicio == NULL) {  // Atualizar o fim se a fila ficou vazia
        fila->fim = NULL;
    }

    free(removido);
    return cliente;
}

void imprimirFila(FilaPrioridade* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    No* atual = fila->inicio;
    printf("Fila de Clientes:\n");
    while (atual) {
        printf("Nome: %s, Prioridade: %d, Itens: %d\n",
               atual->cliente.nome,
               atual->cliente.prioridade,
               atual->cliente.nItens);
        atual = atual->proximo;
    }
}

int tamanhoFila(FilaPrioridade* fila) {
    int contador = 0;
    No* atual = fila->inicio;

    while (atual != NULL) {
        contador++;
        atual = atual->proximo;
    }

    return contador;
}