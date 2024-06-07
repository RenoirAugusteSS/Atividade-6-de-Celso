#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    double preco;
} Produto;

int main() {
    Produto produtos[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o código do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);
        printf("Digite o nome do produto %d: ", i + 1);
        getchar(); // Limpar o buffer
        fgets(produtos[i].nome, 50, stdin);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].quantidade);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%lf", &produtos[i].preco);
    }

    printf("\nProdutos cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Código: %d\n", produtos[i].codigo);
        printf("Nome: %s", produtos[i].nome);
        printf("Quantidade: %d\n", produtos[i].quantidade);
        printf("Preço: %.2lf\n\n", produtos[i].preco);
    }

    return 0;
}
