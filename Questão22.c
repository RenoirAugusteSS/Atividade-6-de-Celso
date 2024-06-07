#include <stdio.h>

typedef struct {
    char nome[50];
    int matricula;
    char curso[50];
} Estudante;

int main() {
    Estudante estudantes[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do estudante %d: ", i + 1);
        fgets(estudantes[i].nome, 50, stdin);
        printf("Digite a matrícula do estudante %d: ", i + 1);
        scanf("%d", &estudantes[i].matricula);
        getchar(); // Limpar o buffer
        printf("Digite o curso do estudante %d: ", i + 1);
        fgets(estudantes[i].curso, 50, stdin);
    }

    printf("\nEstudantes matriculados:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s", estudantes[i].nome);
        printf("Matrícula: %d\n", estudantes[i].matricula);
        printf("Curso: %s\n\n", estudantes[i].curso);
    }

    return 0;
}
