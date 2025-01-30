#include "Caixa.h"

void inicializarCaixa(Caixa *c[]) {
    for (int i = 0; i < MAX_CAIXAS; i++) { 
        c[i] = malloc(sizeof(Caixa));
        if (c[i] == NULL) { 
            printf("Erro na alocação de memória\n");
            exit(1); 
        }
        c[i]->estado = 1;              
        c[i]->nIdentCaixa = i + 1; 
        // para cada caixa eu inicializo uma fila de clientes
        inicializarFila(&(c[i]->filaClientes));
    }
}

void imprimirEstado(Caixa *c[]){
     for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: Estado = %d\n", 
                i + 1, c[i]->estado);
    }
}

void abrirFecharCaixa(Caixa *c[], int nIdent, int nEstado){
    for (int i = 0; i < MAX_CAIXAS; i++) {
        if (c[i]->nIdentCaixa == nIdent) {
            if (nEstado == 1 && c[i]->estado == 0) {
                c[i]->estado = 1;
            } else if (nEstado == 0 && c[i]->estado == 1) {
                c[i]->estado = 0;
                int tamanhoInicial = tamanhoFila(&(c[i]->filaClientes));

                while (tamanhoInicial > 0) { 
                    int menorFila = -1;
                    int menorTamanho = INT_MAX;

                    for (int j = 0; j < MAX_CAIXAS; j++) {
                        if (c[j]->estado != 0) { 
                            int tamanhoAtual = tamanhoFila(&(c[j]->filaClientes));
                            if (tamanhoAtual < menorTamanho) {
                                menorFila = j;
                                menorTamanho = tamanhoAtual;
                            }
                        }
                    }
                    
                    if (menorFila != -1) {
                        // Move o próximo cliente para o caixa com a menor fila
                        Cliente cliente = removerCliente(&(c[i]->filaClientes));
                        inserirCliente(&(c[menorFila]->filaClientes), cliente);
                        tamanhoInicial--;
                    } else {
                        printf("\n!!! Atenção !!!\n");
                        printf("\nVocê não pode fechar este caixa, primeiro atenda todos os clientes, ou abra outros caixas!\n");
                        c[i]->estado = 1;
                        break; 
                    }
                }   
            }
        }
    }
}


int retornaSeCaixasVazios(Caixa *c[]){
    int cont=0;
    for(int i = 0; i < MAX_CAIXAS; i++){
        if(c[i]->estado == 0){
            cont++;
        }
    }
    if(cont == 5){
        return 1;
    }else{
        return 0;
    }
    
}
