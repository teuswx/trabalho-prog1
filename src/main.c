#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Caixa.h"
#include "Cliente.h"
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int main(){

    Caixa *c[MAX_CAIXAS]; 
    Cliente cliente;
    // inicializa o vetor de caixas com os estados como aberto(1)
    inicializarCaixa(c);

    int opcao;
    do {
        printf("\nMenu:\n");
        printf("1. Cadastrar Cliente\n");
        printf("2. Atender Cliente\n");
        printf("3. Abrir/Fechar Caixa\n");
        printf("4. Imprimir Lista de Clientes em Espera\n");
        printf("5. Imprimir Estado dos Caixas\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        limparBufferEntrada();
        switch (opcao) {
            case 1: {
                
                char nome[100];
                char cpf[12];
                int prioridade;
                int nItens;
                
                if(retornaSeCaixasVazios(c) ==1){
                    printf("\n!Para cadastrar novos clientes, você precisa abrir caixas!\n");
                }

                if(retornaSeCaixasVazios(c) !=1){
                    
                    do {
                        printf("Digite o nome do cliente: ");
                        fgets(nome, sizeof(nome), stdin);
                        nome[strcspn(nome, "\n")] = '\0'; 
                        if (strlen(nome) == 0) {
                            printf("Erro: O nome não pode estar vazio.\n");
                        }
                    } while (strlen(nome) == 0);
                    do {
                        printf("\nDigite o CPF do cliente (apenas números, 11 dígitos): ");
                        scanf("%11s", cpf);
                        while (getchar() != '\n');
                        if (!validarCPF(cpf)) {
                            printf("Erro: CPF inválido. Deve conter exatamente 11 dígitos numéricos.\n");
                        }
                    } while (!validarCPF(cpf));

                    do {
                        printf("\nDigite a prioridade do cliente (1-Alta, 2-Média, 3-Baixa): ");
                        scanf("%d", &prioridade);
                        while (getchar() != '\n'); 
                        if (prioridade < 1 || prioridade > 3) {
                            printf("Erro: Prioridade inválida. Deve ser 1, 2 ou 3.\n");
                        }
                    } while (prioridade < 1 || prioridade > 3);

                    do {
                        printf("\nDigite o número de itens do cliente: ");
                        scanf("%d", &nItens);
                        while (getchar() != '\n');
                        if (nItens <= 0) {
                            printf("Erro: O número de itens deve ser maior que zero.\n");
                        }
                    } while (nItens <= 0);

                    cadastrarCliente(&cliente, nome, cpf, prioridade, nItens);
                    int numCaixa = 0;
                    do{
                        printf("\nEm qual caixa você deseja adicionar o cliente? (1 a 5): ");
                        scanf("%d", &numCaixa);
                        if(numCaixa < 1 || numCaixa > 5){
                            printf("\n!!! Digite um caixa válido !!!\n");
                        }else if(c[numCaixa-1]->estado == 0){
                            printf("\n!Este caixa está fechado!\n");
                            printf("\n!Abra este caixa, ou cadastre em outro!\n");
                        }

                    }while(numCaixa < 1 || numCaixa > 5 || c[numCaixa-1]->estado == 0);
                    
                    inserirCliente(&(c[numCaixa-1]->filaClientes), cliente);
                    
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                    printf("\nCliente cadastrado com sucesso:\n");
                    printf("Nome: %s\n", cliente.nome);
                    printf("CPF: %s\n", cliente.cpf);
                    printf("Prioridade: %d\n", cliente.prioridade);
                    printf("Número de itens: %d\n", cliente.nItens);
                    printf("\n-----------------------------------------------------------------------------------------------\n");
                }
                

    
                break;
            }
            case 2: {
                int numCaixa = 0;
                do{
                    printf("\nEm qual caixa você deseja atender um cliente? (1 a 5): ");
                    scanf("%d", &numCaixa);
                   
                    if(numCaixa < 1 || numCaixa > 5 || c[numCaixa-1]->estado !=1){
                        printf("\n!!! Digite um caixa válido !!!\n");
                    }
                    if(tamanhoFila(&c[numCaixa-1]->filaClientes) == 0){
                        printf("\n!!! O caixa esta vazio !!!\n");
                    }
                }while(numCaixa < 1 || numCaixa > 5 || c[numCaixa-1]->estado !=1 || tamanhoFila(&c[numCaixa-1]->filaClientes) == 0);

                Cliente *clienteAux = malloc(sizeof(Cliente));

                *clienteAux = removerCliente(&(c[numCaixa-1]->filaClientes));
                printf("\n-----------------------------------------------------------------------------------------------\n");
                printf("\nCliente %s atendido!\n", clienteAux->nome);
                printf("\n-----------------------------------------------------------------------------------------------\n");
                break;
            }
            case 3: {
                int nIdent = 0;
                int nEstado = 0;
                do
                {
                    printf("\nDigite o numero do caixa que você deseja alterar(1..5): ");
                    scanf("%d", &nIdent);
                    printf("\nDigite o estado do caixa 1(Abrir), 0(Fechar): ");
                    scanf("%d", &nEstado);
                    if((nIdent < 1 || nIdent > 5) || (nEstado !=0 && nEstado !=1)){
                        printf("\n!!!Atenção digite as informações corretas!!!\n");
                    }
                } while ((nIdent < 1 || nIdent > 5) || (nEstado != 0 && nEstado != 1));
                
                abrirFecharCaixa(c,nIdent,nEstado);
    
                break;
            }
            case 4:{

                for(int i = 0; i < MAX_CAIXAS; i ++){
                    printf("\nCAIXA NUMERO %d\n", i+1);
                    imprimirFila(&(c[i]->filaClientes));
                }
                                
                break;
            }
            case 5:{
                imprimirEstado(c);
                break;
            }
            case 0:{
                printf("Saindo...\n");
                break;
            }
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    return 0;
}