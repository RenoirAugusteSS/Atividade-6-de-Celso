#include <stdio.h>

typedef struct {
    char titulo[50];
    char autor[50];
    int anoPublicacao;
} Livro;

typedef struct {
    Livro livro;
    char dataEmprestimo[11];
    char dataDevolucao[11];
} Emprestimo;

int main() {
    Livro livros[5];
    Emprestimo emprestimos[5];
    int i;

    // Cadastro de livros
    for (i = 0; i < 5; i++) {
        printf("Digite o título do livro %d: ", i + 1);
        fgets(livros[i].titulo, 50, stdin);
        printf("Digite o autor do livro %d: ", i + 1);
        fgets(livros[i].autor, 50, stdin);
        printf("Digite o ano de publicação do livro %d: ", i + 1);
        scanf("%d", &livros[i].anoPublicacao);
        getchar(); // Limpar o buffer
    }

    // Registro de empréstimos
    for (i = 0; i < 5; i++) {
        emprestimos[i].livro = livros[i];
        printf("\nEmprestimo %d\n", i + 1);
        printf("Digite a data do empréstimo (dd/mm/aaaa): ");
        scanf("%s", emprestimos[i].dataEmprestimo);
        printf("Digite a data de devolução (dd/mm/aaaa): ");
        scanf("%s", emprestimos[i].dataDevolucao);
        getchar(); // Limpar o buffer
    }

    // Exibição dos empréstimos
    for (i = 0; i < 5; i++) {
        printf("\nDetalhes do Empréstimo %d:\n", i + 1);
        printf("Título: %s", emprestimos[i].livro.titulo);
        printf("Autor: %s", emprestimos[i].livro.autor);
        printf("Ano de Publicação: %d\n", emprestimos[i].livro.anoPublicacao);
        printf("Data do Empréstimo: %s\n", emprestimos[i].dataEmprestimo);
        printf("Data de Devolução: %s\n\n", emprestimos[i].dataDevolucao);
    }

    return 0;
}
