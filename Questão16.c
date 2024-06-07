#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    float mediaFinal;
} Estudante;

int main() {
    Estudante estudantes[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do estudante %d: ", i + 1);
        fgets(estudantes[i].nome, 50, stdin);
        printf("Digite a matrícula do estudante %d: ", i + 1);
        scanf("%d", &estudantes[i].matricula);
        printf("Digite a média final do estudante %d: ", i + 1);
        scanf("%f", &estudantes[i].mediaFinal);
        getchar(); // Limpar o buffer
    }

    printf("\nEstudantes cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s", estudantes[i].nome);
        printf("Matrícula: %d\n", estudantes[i].matricula);
        printf("Média Final: %.2f\n\n", estudantes[i].mediaFinal);
    }

    return 0;
}
