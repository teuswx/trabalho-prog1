#ifndef CLIENTE_H
#define CLIENTE_H
#include "Cliente.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct CLiente
{
    char nome[100];
    char cpf[12];
    int prioridade;
    int nItens;
}Cliente;

void cadastrarCliente(Cliente *cliente,char nome[100],char cpf[12], int prioridade, int nItens);
int validarCPF(const char *cpf);
#endif
