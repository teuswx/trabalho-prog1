#include "Caixa.h"

void inicializarCaixa(Caixa *c[]) {
    // Alocar e inicializar as 5 caixas
    for (int i = 0; i < MAX_CAIXAS; i++) { 
        c[i] = malloc(sizeof(Caixa));  // Alocando memória para cada caixa
        if (c[i] == NULL) {  // Verificando se a alocação foi bem-sucedida
            printf("Erro na alocação de memória\n");
            exit(1);  // Encerra o programa em caso de falha
        }

        // Inicializando o estado e o identificador de cada caixa
        c[i]->estado = 1;               // Estado padrão
        c[i]->nIdentCaixa = i + 1;      // nIdentCaixa de 1 a 5
        inicializarFila(&(c[i]->filaClientes));
    }
}

void imprimirEstado(Caixa *c[]){
     for (int i = 0; i < MAX_CAIXAS; i++) {
        printf("Caixa %d: Estado = %d, nIdentCaixa = %d\n", 
                i + 1, c[i]->estado, c[i]->nIdentCaixa);
    }
}

void abrirFecharCaixa(Caixa *c[], int nIdent, int nEstado){
    for(int i = 0; i < MAX_CAIXAS; i++){
        if(c[i]->nIdentCaixa == nIdent){
            if(nEstado == 1 && c[i]->estado == 0){
                c[i]->estado = 1;
            }else if(nEstado == 0 && c[i]->estado == 1){
                c[i]->estado = 0;
            }
        }
    }
}

