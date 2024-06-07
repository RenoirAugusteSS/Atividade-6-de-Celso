#include <stdio.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
    int quantidade;
} Livro;

int main() {
    Livro livros[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o título do livro %d: ", i + 1);
        fgets(livros[i].titulo, 50, stdin);
        printf("Digite o autor do livro %d: ", i + 1);
        fgets(livros[i].autor, 50, stdin);
        printf("Digite o ano de publicação do livro %d: ", i + 1);
        scanf("%d", &livros[i].anoPublicacao);
        printf("Digite a quantidade do livro %d: ", i + 1);
        scanf("%d", &livros[i].quantidade);
        getchar(); // Limpar o buffer
    }

    printf("\nLivros cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Título: %s", livros[i].titulo);
        printf("Autor: %s", livros[i].autor);
        printf("Ano de Publicação: %d\n", livros[i].anoPublicacao);
        printf("Quantidade: %d\n\n", livros[i].quantidade);
    }

    return 0;
}
