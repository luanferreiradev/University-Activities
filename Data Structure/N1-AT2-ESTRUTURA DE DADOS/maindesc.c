#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Codigo feito por Luan Ferreira, Victor Davidson, João Gabriel, Rebeca Maria*/
/*24/04/2024*/

// Estrutura de dados para armazenar o nome e o saldo do cliente
typedef struct _cliente {
    char nome[51]; 
    float saldo;   
} Cliente;

typedef struct _no {
    Cliente *cliente; // Nó da lista encadeada que contém um cliente
    struct _no *prox; // Ponteiro para o próximo nó
} No;

No *listaClientes = NULL; // Lista encadeada de clientes


// Cria um novo cliente com o nome e o saldo fornecidos
Cliente *criarCliente(const char *nome, float saldo) {
    
    Cliente *novoCliente = (Cliente *)malloc(sizeof(Cliente));
    
    if (novoCliente == NULL) {
        printf("Erro ao alocar memória para o cliente.\n");
        return 1;
    }
    
    strcpy(novoCliente->nome, nome);
    
    novoCliente->saldo = saldo;
    
    return novoCliente;
}

// Realiza um saque na conta do cliente, se o saldo for suficiente
void sacar(Cliente *cliente, float valor) {
    
    if (valor > cliente->saldo) {
        printf("Saldo insuficiente para saque.\n");
    } else {
        
        cliente->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
    }
}

// Realiza um deposito na conta do cliente
void depositar(Cliente *cliente, float valor) {
    
    cliente->saldo += valor;
    printf("Depósito de %.2f realizado com sucesso.\n", valor);
}

// Transfere um valor da conta do remetente para a conta do destinatario
void transferir(Cliente *remetente, Cliente *destinatario, float valor) {
    
    if (valor > remetente->saldo) {
        printf("Saldo insuficiente para transferência.\n");
    } else {
        
        remetente->saldo -= valor;
        destinatario->saldo += valor;
        printf("Transferência de %.2f realizada com sucesso.\n", valor);
    }
}

// Exibe as informações do cliente
void displayCliente(const Cliente *cliente) {
    printf("Nome: %s\n", cliente->nome);
    printf("Saldo: R$ %.2f\n", cliente->saldo);
}

/* Desaloca a memoria alocada para um cliente

´desalocaCliente´, que recebe um ponteiro para um ponteiro de Cliente como argumento|

*cliente_ref é usado para acessar o valor apontado pelo ponteiro cliente_ref, que é um ponteiro
 para um Cliente. Esse valor é então passado para a função free, que desaloca a memória associada ao cliente.
  Basicamente, esta linha libera a memória alocada para o cliente.

  Este trecho define o ponteiro original cliente_ref como NULL. Isso é feito para evitar que o ponteiro
   continue apontando para uma área de memória que não é mais válida
*/
void desalocaCliente(Cliente **cliente_ref) { 
    free(*cliente_ref);
    *cliente_ref = NULL; 
}

// Adiciona um novo cliente à lista de clientes
void adicionarCliente(const char *nome, float saldo) {
    Cliente *novoCliente = criarCliente(nome, saldo);

    No *novoNo = (No *)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória para o novo cliente.\n");
        return 1;
    }
    novoNo->cliente = novoCliente;
    novoNo->prox = NULL;


    if (listaClientes == NULL) {
        listaClientes = novoNo;
    } else {
        No *temp = listaClientes;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novoNo;
    }
}

// Exibe todos os clientes cadastrados
void exibirClientes() {
    printf("-- Lista de Clientes --\n");
    No *temp = listaClientes;
    while (temp != NULL) {
        displayCliente(temp->cliente);
        printf("\n");
        temp = temp->prox;
    }
}

// Procura um cliente pelo nome na lista de clientes
Cliente *encontrarCliente(const char *nome) {
    No *temp = listaClientes;
    while (temp != NULL) {
        if (strcmp(temp->cliente->nome, nome) == 0) {
            return temp->cliente;
        }
        temp = temp->prox;
    }
    return NULL;
}

// Exclui um cliente da lista de clientes
void excluirCliente(const char *nome) {
    No *atual = listaClientes;
    No *anterior = NULL;
    while (atual != NULL) {
        if (strcmp(atual->cliente->nome, nome) == 0) {
            if (anterior == NULL) { // Se é o primeiro nó
                listaClientes = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            desalocaCliente(&(atual->cliente));
            free(atual);
            printf("Cliente %s excluído com sucesso.\n", nome);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Cliente %s não encontrado.\n", nome);
}

// Menu de operações para interagir com a conta de um cliente
void menuOperacoes(Cliente *cliente) {

    int opcao;
    float valor;

    // Loop principal do menu de operaçoes
    do {
        printf("\n-- Menu de Operações --\n");
        printf("1. Sacar\n");
        printf("2. Depositar\n");
        printf("3. Transferir\n");
        printf("4. Visualizar saldo\n");
        printf("5. Voltar ao menu principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o valor a ser sacado: ");
                scanf("%f", &valor);
                sacar(cliente, valor);
                break;
            case 2:
                printf("Digite o valor a ser depositado: ");
                scanf("%f", &valor);
                depositar(cliente, valor);
                break;
            case 3:
                printf("Digite o valor a ser transferido: ");
                scanf("%f", &valor);
                char destinatario[51];
                printf("Digite o nome do destinatário: ");
                getchar(); // Limpa o buffer do teclado
                fgets(destinatario, sizeof(destinatario), stdin); // Le o nome do destinatario
                destinatario[strcspn(destinatario, "\n")] = 0; // Remove o caractere de nova linha
                Cliente *destinatarioCliente = encontrarCliente(destinatario);
                if (destinatarioCliente == NULL) {
                    printf("Destinatário não encontrado.\n");
                } else {
                    transferir(cliente, destinatarioCliente, valor);
                }
                break;
            case 4:
                displayCliente(cliente);
                break;
            case 5:
                printf("Voltando ao menu principal...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);
}

// Funçao principal
int main() {
    int opcao;
    float valor;
    char nome[51]; // <-- Isto foi pedido pelo professor 

    // Loop principal do programa
    do {
        printf("\n-- Menu Principal --\n");
        printf("1. Criar novo cliente\n");
        printf("2. Visualizar clientes cadastrados\n");
        printf("3. Entrar em uma conta\n");
        printf("4. Excluir conta\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o nome do novo cliente: ");
                getchar(); // Limpa o teclado
                fgets(nome, sizeof(nome), stdin); // Le o nome do cliente
                nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha
                printf("Digite o saldo inicial do novo cliente: ");
                scanf("%f", &valor);
                adicionarCliente(nome, valor);
                break;
            case 2:
                exibirClientes();
                break;
            case 3:
                printf("Digite o nome da conta para entrar: ");
                getchar(); // Limpa o buffer do teclado
                fgets(nome, sizeof(nome), stdin); // Le o nome da conta
                nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha
                Cliente *cliente = encontrarCliente(nome);
                if (cliente == NULL) {
                    printf("Conta não encontrada.\n");
                } else {
                    menuOperacoes(cliente);
                }
                break;
            case 4:
                printf("Digite o nome da conta a ser excluída: ");
                getchar(); // Limpa o teclado
                fgets(nome, sizeof(nome), stdin); // Le o nome da conta a ser excluida
                nome[strcspn(nome, "\n")] = 0; // Remove o caractere de nova linha
                excluirCliente(nome);
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    // Libera a memoria alocada para todos os clientes
    No *atual = listaClientes;
    No *prox;  
    while (atual != NULL) {
        prox = atual->prox;
        desalocaCliente(&(atual->cliente));
        free(atual);
        atual = prox;
    }

    return 0;
}