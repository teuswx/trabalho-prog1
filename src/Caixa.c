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
                int cont = 0;
                for(int j = 0; j < MAX_CAIXAS; j++){
                    if(c[j]->estado != 0){
                        int tamanhoInicial =  tamanhoFila(&(c[i]->filaClientes));
                        for (int k = 0; k <tamanhoInicial; k++)
                        {
                            inserirCliente(&(c[j]->filaClientes), (removerCliente(&c[i]->filaClientes)));
                        }
                        break;
                    }
                    int tamanhoFinal = tamanhoFila(&(c[i]->filaClientes));
                    if(cont == 3 && tamanhoFinal!=0){
                        printf("\n!!! Atenção !!!\n");
                        printf("\nvocê não pode fechar este caixa, primeiro atenda todos os clientes, ou abra outros caixas!\n");
                        c[i]->estado = 1;
                    }else if (cont == 3 && tamanhoFinal==0)
                    {
                        c[i]->estado = 0;
                    }
                    
                    cont++;
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
