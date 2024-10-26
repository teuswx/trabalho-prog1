#include <stdio.h>
#include "Cliente.h"

void inicializaCliente(Cliente* c, char nome[], int *cpf, int prioridade, int nItens){
    strcpy(c->nome, nome);
    for (int i = 0; i < 11; i++) {
        c->cpf[i] = cpf[i];
    }
    c->prioridade = prioridade;
    c->nItens = nItens;
}