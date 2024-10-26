#ifndef CLIENTE_H
#define CLIENTE_H
#include "string.h"

typedef struct{
    char nome[100];
    int* cpf[11];
    int prioridade;
    int nItens;
}Cliente;

void inicializaCliente(Cliente* c, char nome[], int cpf[], int prioridade, int nItens);
#endif