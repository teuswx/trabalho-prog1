#include "Cliente.h"

void cadastrarCliente(Cliente *cliente, char nome[100], char cpf[12], int prioridade, int nItens) {
    if (cliente == NULL) return;

    // Copiar o nome para o campo nome
    strncpy(cliente->nome, nome, sizeof(cliente->nome) - 1);
    cliente->nome[sizeof(cliente->nome) - 1] = '\0'; // Garante que está terminada em '\0'

    // Copiar o CPF para o campo cpf
    strncpy(cliente->cpf, cpf, sizeof(cliente->cpf) - 1);
    cliente->cpf[sizeof(cliente->cpf) - 1] = '\0'; // Garante que está terminada em '\0'

    // Configurar os demais campos
    cliente->prioridade = prioridade;
    cliente->nItens = nItens;
}

int validarCPF(const char *cpf) {
    // Verifica se todos os caracteres do CPF são números e se tem 11 dígitos
    if (strlen(cpf) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) return 0;
    }
    return 1;
}


