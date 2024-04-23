#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura de uma conta bancária
typedef struct {
    int conta_id;
    char nome[50];
    double saldo;
} ContaBancaria;

// Protótipos de funções
void criarConta(ContaBancaria contas[], int *numContas);
void listarContas(ContaBancaria contas[], int numContas);
void atualizarSaldo(ContaBancaria contas[], int numContas);
void excluirConta(ContaBancaria contas[], int *numContas);

int main() {
    ContaBancaria contas[100]; // Capacidade para 100 contas
    int numContas = 0;
    int opcao;

    do {
        printf("\nBanco - Escolha uma opção:\n");
        printf("1. Criar conta\n");
        printf("2. Listar contas\n");
        printf("3. Atualizar saldo\n");
        printf("4. Excluir conta\n");
        printf("5. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarConta(contas, &numContas);
                break;
            case 2:
                listarContas(contas, numContas);
                break;
            case 3:
                atualizarSaldo(contas, numContas);
                break;
            case 4:
                excluirConta(contas, &numContas);
                break;
            case 5:
                printf("Encerrando o programa. Obrigado!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

void criarConta(ContaBancaria contas[], int *numContas) {
    if (*numContas < 100) {
        ContaBancaria novaConta;
        novaConta.conta_id = *numContas + 1;
        printf("Digite o nome do titular da conta: ");
        scanf("%s", novaConta.nome);
        novaConta.saldo = 0.0;
        contas[*numContas] = novaConta;
        (*numContas)++;
        printf("Conta criada com sucesso!\n");
    } else {
        printf("Capacidade máxima de contas atingida.\n");
    }
}

void listarContas(ContaBancaria contas[], int numContas) {
    printf("\nListagem de contas:\n");
    for (int i = 0; i < numContas; i++) {
        printf("Conta %d: Titular: %s, Saldo: %.2lf\n", contas[i].conta_id, contas[i].nome, contas[i].saldo);
    }
}

void atualizarSaldo(ContaBancaria contas[], int numContas) {
    int id;
    double novoSaldo;
    printf("Digite o número da conta que deseja atualizar o saldo: ");
    scanf("%d", &id);

    for (int i = 0; i < numContas; i++) {
        if (contas[i].conta_id == id) {
            printf("Digite o novo saldo da conta: ");
            scanf("%lf", &novoSaldo);
            contas[i].saldo = novoSaldo;
            printf("Saldo atualizado com sucesso!\n");
            return;
        }
    }
    printf("Conta não encontrada.\n");
}

void excluirConta(ContaBancaria contas[], int *numContas) {
    int id;
    printf("Digite o número da conta que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *numContas; i++) {
        if (contas[i].conta_id == id) {
            // Movendo as contas restantes para preencher o espaço da conta excluída
            for (int j = i; j < *numContas - 1; j++) {
                contas[j] = contas[j + 1];
            }
            (*numContas)--;
            printf("Conta excluída com sucesso!\n");
            return;
        }
    }
    printf("Conta não encontrada.\n");
}
S