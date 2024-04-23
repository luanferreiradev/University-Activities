#include <stdio.h>
#include <stdlib.h>

// Estrutura de um nó da árvore
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Função para criar um novo nó da árvore
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Função para realizar uma travessia em ordem na árvore
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main() {
    // Construindo uma árvore binária de exemplo
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Travessia em ordem: ");
    inOrderTraversal(root);

    return 0;
}
