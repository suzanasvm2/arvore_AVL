#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Função para imprimir a árvore
void printTree(struct Node* root, int space) {
    // Caso base
    if (root == NULL)
        return;

    // Incremento do espaço para próximo nível
    space += 10;

    // Processamento do nó direito
    printTree(root->right, space);

    // Impressão do nó atual após o espaçamento
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);

    // Processamento do nó esquerdo
    printTree(root->left, space);
}

void printArray(int array[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main() {
    struct Node* root = NULL;

    // Inserindo valores de um array, para uma árvore AVL
    int valores[] = {15, 27, 49,10,8,67,59,9,13,20};
    int numValores = sizeof(valores) / sizeof(valores[0]);
    for (int i = 0; i < numValores; i++) {
        root = insert(root, valores[i]);
    }

    int escolha;
    int valor;

    do {
        printf("\n******** ALGORITMOS E ESTRUTURA DE DADOS *********\n");
        printf("-------- ÁRVORES AVL ---------------\n");
        printf("ÁRVORE AVL DEFAULT ");
        printArray(valores, numValores);
        printf("\nMenu:\n");
        printf("1. Adicionar um nó\n");
        printf("2. Verificar se um valor existe na árvore\n");
        printf("3. Remover um nó\n");
        printf("4. Mostrar a árvore\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor a ser adicionado: ");
                scanf("%d", &valor);
                root = insert(root, valor);
                printf("Valor %d adicionado com sucesso.\n", valor);
                break;
            case 2:
                printf("Digite o valor a ser procurado: ");
                scanf("%d", &valor);
                if (search(root, valor)) {
                    printf("O valor %d está presente na árvore.\n", valor);
                } else {
                    printf("O valor %d não está presente na árvore.\n", valor);
                }
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                root = deleteNode(root, valor);
                printf("Valor %d removido com sucesso.\n", valor);
                break;
            case 4:
                printTree(root,0);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}
