#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h> // Inclua esta biblioteca para inicializar a semente do gerador de números aleatórios

// Definindo a estrutura do usuário
struct Usuario {
    int id;
    char nome[50], sexo, cpf[12], dataNascimento[11], email[50], telefone[15], nomeMae[50], cpfMae[12];
};

// Função para verificar a idade com base na data de nascimento
int calcularIdade(const char *dataNascimento) {
    // Implemente lógica para calcular a idade aqui
    // Neste exemplo a data de nascimento está no formato "dd/mm/aaaa"
    // e calcularemos a idade com base no ano atual.
    // pode usar bibliotecas de data para uma implementação mais precisa.
    // Para fins de demonstração, usaremos 2023 como ano atual.
    int anoAtual = 2023;
    int anoNascimento;
    sscanf(dataNascimento, "%*d/%*d/%d", &anoNascimento);
    return anoAtual - anoNascimento;
}

// Função para gerar um ID único aleatório
int gerarIdUnico(struct Usuario *usuarios, int totalUsuarios) {
    int novoId;
    bool idUnico;

    do {
        novoId = rand(); // Gere um ID aleatório
        idUnico = true;

        // Verificar se o ID já está em uso
        for (int i = 0; i < totalUsuarios; i++) {
            if (usuarios[i].id == novoId) {
                idUnico = false;
                break;
            }
        }
    } while (!idUnico);

    return novoId;
}

int main() {
    struct Usuario usuarios[100]; // Tamanho máximo de 100 usuários
    int totalUsuarios = 0;

    // Inicialize a semente do gerador de números aleatórios com base no horário atual
    srand(time(NULL));

    while (1) {
        printf("Cadastro de Usuário\n");
        printf("Nome: ");
        scanf(" %[^\n]s", usuarios[totalUsuarios].nome);

        printf("Sexo (M/F): ");
        scanf(" %c", &usuarios[totalUsuarios].sexo);

        printf("CPF: ");
        scanf(" %s", usuarios[totalUsuarios].cpf);

        printf("Data de Nascimento (dd/mm/aaaa): ");
        scanf(" %s", usuarios[totalUsuarios].dataNascimento);

        printf("Email: ");
        scanf(" %s", usuarios[totalUsuarios].email);

        printf("Telefone: ");
        scanf(" %s", usuarios[totalUsuarios].telefone);

        int idade = calcularIdade(usuarios[totalUsuarios].dataNascimento);
        if (idade < 18) {
            printf("Usuário menor de idade. Informe os dados da mãe:\n");
            printf("Nome da mãe: ");
            scanf(" %[^\n]s", usuarios[totalUsuarios].nomeMae);

            printf("CPF da mãe: ");
            scanf(" %s", usuarios[totalUsuarios].cpfMae);
        } else {
            strcpy(usuarios[totalUsuarios].nomeMae, "");
            strcpy(usuarios[totalUsuarios].cpfMae, "");
        }

        // Gerar um ID único aleatório
        usuarios[totalUsuarios].id = gerarIdUnico(usuarios, totalUsuarios);

        totalUsuarios++;

        char continuar;
        printf("Deseja cadastrar outro usuário? (S/N): ");
        scanf(" %c", &continuar);
        if (continuar != 'S' && continuar != 's') {
            break;
        }
    }

    // Exibir os dados cadastrados
    printf("\nUsuários Cadastrados:\n");
    for (int i = 0; i < totalUsuarios; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Sexo: %c\n", usuarios[i].sexo);
        printf("CPF: %s\n", usuarios[i].cpf);
        printf("Data de Nascimento: %s\n", usuarios[i].dataNascimento);
        printf("Email: %s\n", usuarios[i].email);
        printf("Telefone: %s\n", usuarios[i].telefone);
        if (strlen(usuarios[i].nomeMae) > 0) {
            printf("Nome da mãe: %s\n", usuarios[i].nomeMae);
            printf("CPF da mãe: %s\n", usuarios[i].cpfMae);
        }
        printf("\n");
    }

    return 0;
}
