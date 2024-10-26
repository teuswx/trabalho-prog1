#ifndef CAIXA_H
#define CAIXA_H
#include "FilaPrioridade.h"
#include "string.h"
#include "Cliente.h"
typedef struct{
    int nIdentCaixa;
    int estado;
    FilaPrioridade *filaCaixa;
}Caixa;

void inicializarCaixa(Caixa *c, int nIdentCaixa);
void adicionarCliente(Caixa* c, Cliente *cliente, FilaPrioridade *fila);
void imprimirCaixa(Caixa *c);
#endif