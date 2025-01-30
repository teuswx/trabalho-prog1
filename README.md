# Sistema de Gerenciamento de Caixas e Clientes

Este é um sistema simples desenvolvido em C que simula o gerenciamento de caixas em um estabelecimento, onde os clientes são atendidos de acordo com a prioridade e o número de itens. O sistema permite o cadastro de clientes, a alocação deles para caixas específicos e a gestão do estado dos caixas (abertos ou fechados).

## Funcionalidades

- **Cadastrar Cliente:** O sistema permite o cadastro de um cliente com informações como nome, CPF, prioridade de atendimento (alta, média ou baixa) e o número de itens.
- **Atender Cliente:** O cliente é atendido por um caixa aberto. A fila de atendimento é organizada pela prioridade e o número de itens.
- **Abrir/Fechar Caixa:** Permite abrir ou fechar um caixa, transferindo clientes de caixas fechados para os caixas com menos fila.
- **Visualizar Estado dos Caixas:** Exibe o estado (aberto ou fechado) de cada caixa.
- **Visualizar Lista de Clientes em Espera:** Exibe os clientes que estão na fila de espera para atendimento.

## Estrutura do Projeto

O projeto é dividido em várias partes, com as seguintes funcionalidades principais:

### 1. **Caixa**

- Controla o estado de cada caixa (aberto ou fechado).
- Cada caixa possui uma fila de clientes.
- Ao fechar um caixa, os clientes são movidos para o caixa com a menor fila de espera.

### 2. **Cliente**

- Armazena informações sobre o cliente, como nome, CPF, prioridade e número de itens.
- A prioridade é usada para organizar a fila de espera de atendimento.

### 3. **Fila de Prioridade**

- A fila é implementada de forma que os clientes com maior prioridade sejam atendidos primeiro.
- Utiliza uma estrutura de lista encadeada para organizar os clientes na fila.


## Compilação e Execução 

O código possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

