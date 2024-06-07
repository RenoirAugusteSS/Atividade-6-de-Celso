#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    double preco;
} Produto;

typedef struct {
    Produto produto;
    int quantidade;
} ItemVenda;

typedef struct {
    int codigoVenda;
    ItemVenda itens[5];
    double total;
} Venda;

int main() {
    Produto produtos[5];
    Venda vendas[5];
    int i, j;

    // Cadastro de produtos
    for (i = 0; i < 5; i++) {
        printf("Digite o código do produto %d: ", i + 1);
        scanf("%d", &produtos[i].codigo);
        printf("Digite o nome do produto %d: ", i + 1);
        getchar(); // Limpar o buffer
        fgets(produtos[i].nome, 50, stdin);
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%lf", &produtos[i].preco);
    }

    // Registro de vendas
    for (i = 0; i < 5; i++) {
        vendas[i].codigoVenda = i + 1;
        vendas[i].total = 0;
        printf("\nVenda %d\n", i + 1);
        for (j = 0; j < 5; j++) {
            vendas[i].itens[j].produto = produtos[j];
            printf("Digite a quantidade vendida do produto %s: ", produtos[j].nome);
            scanf("%d", &vendas[i].itens[j].quantidade);
            vendas[i].total += vendas[i].itens[j].produto.preco * vendas[i].itens[j].quantidade;
        }
    }

    // Exibição das vendas
    for (i = 0; i < 5; i++) {
        printf("\nDetalhes da Venda %d:\n", vendas[i].codigoVenda);
        for (j = 0; j < 5; j++) {
            printf("Produto: %s", vendas[i].itens[j].produto.nome);
            printf("Quantidade: %d\n", vendas[i].itens[j].quantidade);
        }
        printf("Total da Venda: %.2lf\n", vendas[i].total);
    }

    return 0;
}
