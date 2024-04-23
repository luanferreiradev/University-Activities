#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do livro
struct Book {
    int id;
    char title[100];
    char author[100];
    char publisher[100];
    int availableCopies;
};

// Variável global para manter a lista de livros
struct Book library[100];
int bookCount = 0;

// Função para adicionar um novo livro à biblioteca
void addBook() {
    struct Book newBook;
    newBook.id = bookCount + 1;

    printf("Digite o título do livro: ");
    scanf(" %[^\n]s", newBook.title);

    printf("Digite o autor do livro: ");
    scanf(" %[^\n]s", newBook.author);

    printf("Digite a editora do livro: ");
    scanf(" %[^\n]s", newBook.publisher);

    printf("Digite o número de exemplares disponíveis: ");
    scanf("%d", &newBook.availableCopies);

    library[bookCount] = newBook;
    bookCount++;

    printf("Livro adicionado com sucesso.\n");
}

// Função para listar todos os livros na biblioteca
void listBooks() {
    printf("Lista de Livros:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Título: %s | Autor: %s | Editora: %s | Exemplares Disponíveis: %d\n",
               library[i].id, library[i].title, library[i].author, library[i].publisher, library[i].availableCopies);
    }
}

// Função principal
int main() {
    int choice;

    printf("Bem-vindo à Biblioteca Universitária!\n");

    do {
        printf("\nEscolha uma opção:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Sair\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                listBooks();
                break;
            case 3:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (choice != 3);

    return 0;
}
