#include <stdio.h>
#include "FilaPrioridade.h"


// Função para inicializar a fila de prioridade
void inicializarFila(FilaPrioridade *fila) {
    fila->frente = NULL;
}

// Função para criar um novo nó
No* criarNo(Cliente *cliente) {
    No* novoNo = (No*) malloc(sizeof(No));
    novoNo->cliente = *cliente;
    novoNo->proximo = NULL;
    return novoNo;
}

// Função para enfileirar um elemento com prioridade
void enfileirar(FilaPrioridade *fila, Cliente *cliente) {
    No* novoNo = criarNo(cliente);

    // Caso a fila esteja vazia ou o novo nó tenha prioridade maior que o primeiro nó
    if (fila->frente == NULL || cliente->prioridade < fila->frente->cliente.prioridade) {
        novoNo->proximo = fila->frente; // se a prioridade do novo cliente for maior que o priemiro no , ai ele envia esse cliente para o primeiro lugar da fila
        fila->frente = novoNo;
    } else {
        // Insere o nó na posição correta com base na prioridade
        No* atual = fila->frente;
        while (atual->proximo != NULL && atual->proximo->cliente.prioridade <= cliente->prioridade) {
            atual = atual->proximo;
        }
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;
    }
}

// Função para desenfileirar o elemento de maior prioridade (menor valor de prioridade)
Cliente desenfileirar(FilaPrioridade *fila) {
    if (fila->frente == NULL) {
        printf("A fila está vazia.\n");
        Cliente vazio  = { .nome = "", .cpf = {-1}, .prioridade = -1, .nItens=-1};
        return vazio; // Retorno de erro
    }
    Cliente cliente = fila->frente->cliente;
    No* temp = fila->frente;
    fila->frente = fila->frente->proximo;
    free(temp);
    return cliente;
}

// Função para exibir a fila de prioridade
void exibirFila(FilaPrioridade *fila) {
    No* atual = fila->frente;
    while (atual != NULL) {
        printf("Nome: %s | Prioridade: %d  | Numero de itens: %d | CPF:", atual->cliente.nome, atual->cliente.prioridade, atual->cliente.nItens);
        for (size_t i = 0; i < 11; i++)
        {
            printf("%d", atual->cliente.cpf[i]);
        }
        printf("\n");
        
        atual = atual->proximo;
    }
}
