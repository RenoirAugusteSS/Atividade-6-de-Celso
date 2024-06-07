#include <stdio.h>

typedef struct {
    char titulo[50];
    char diretor[50];
    int anoLancamento;
    char genero[20];
} Filme;

int main() {
    Filme filmes[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o título do filme %d: ", i + 1);
        fgets(filmes[i].titulo, 50, stdin);
        printf("Digite o diretor do filme %d: ", i + 1);
        fgets(filmes[i].diretor, 50, stdin);
        printf("Digite o ano de lançamento do filme %d: ", i + 1);
        scanf("%d", &filmes[i].anoLancamento);
        getchar(); // Limpar o buffer
        printf("Digite o gênero do filme %d: ", i + 1);
        fgets(filmes[i].genero, 20, stdin);
    }

    printf("\nFilmes cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Título: %s", filmes[i].titulo);
        printf("Diretor: %s", filmes[i].diretor);
        printf("Ano de Lançamento: %d\n", filmes[i].anoLancamento);
        printf("Gênero: %s\n\n", filmes[i].genero);
    }

    return 0;
}
