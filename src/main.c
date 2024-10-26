// main.c
#include <stdio.h>
#include "FilaPrioridade.h"
#include "Cliente.h"
#include "Caixa.h"
int main() {
    FilaPrioridade fila;
    
    Caixa caixa;
    int cpf1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0};
    // int cpf2[] = {1, 2, 3, 6, 6, 6, 7, 8, 9, 1, 0};
    // int cpf3[] = {1, 2, 4, 6, 6, 6, 7, 8, 9, 1, 0};
    Cliente c = {"mateus", cpf1, 10, 10};
    inicializarCaixa(&caixa, 78);
    adicionarCliente(&caixa, &c, &fila);
    imprimirCaixa(&caixa);
    // inicializaCliente(&c, "pedro", cpf2, 2, 19);
    // enfileirar(&fila, &c);  // Dado: 30, Prioridade: 3
    // inicializaCliente(&c, "Joao", cpf3, 1, 8);
    // enfileirar(&fila, &c);  // Dado: 30, Prioridade: 

    // printf("Fila de prioridade:\n");
    // exibirFila(&fila);

    // // Remover o elemento de menor prioridade
    // Cliente removido = desenfileirar(&fila);
    // printf("\nRemovido: Nome = %s, Prioridade = %d\n", removido.nome, removido.prioridade);

    // printf("\nFila após remoção:\n");
    // exibirFila(&fila);

    return 0;
}
