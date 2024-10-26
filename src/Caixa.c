#include<stdio.h>
#include "Caixa.h"

void inicializarCaixa(Caixa *c, int nIdentCaixa){
    c->estado = 1;
    c->nIdentCaixa = nIdentCaixa;
}
void adicionarCliente(Caixa *c, Cliente *cliente, FilaPrioridade *fila){

    enfileirar(fila, cliente);
    c->filaCaixa = fila;
}

void imprimirCaixa(Caixa *c){
    printf("\nEstado: %d | numero do caixa, %d |", c->estado, c->nIdentCaixa);
   exibirFila(c->filaCaixa);
}