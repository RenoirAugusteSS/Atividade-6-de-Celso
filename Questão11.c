#include <stdio.h>

// Definindo a estrutura para armazenar os dados dos alunos
typedef struct {
    char nome[100];
    int matricula;
    float mediaFinal;
} Aluno;

int main() {
    Aluno alunos[10];
    Aluno aprovados[10];
    Aluno reprovados[10];
    int numAprovados = 0, numReprovados = 0;
    const float MEDIA_MINIMA = 5.0;

    // Lendo os dados dos 10 alunos
    for (int i = 0; i < 10; i++) {
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].nome, sizeof(alunos[i].nome), stdin);
        // Remover o newline do final da string
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].matricula);
        
        printf("Digite a média final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].mediaFinal);
        
        // Limpa o buffer do stdin
        getchar();
    }

    // Separando os alunos em aprovados e reprovados
    for (int i = 0; i < 10; i++) {
        if (alunos[i].mediaFinal >= MEDIA_MINIMA) {
            aprovados[numAprovados++] = alunos[i];
        } else {
            reprovados[numReprovados++] = alunos[i];
        }
    }

    // Exibindo os dados dos alunos aprovados
    printf("\nAlunos Aprovados:\n");
    for (int i = 0; i < numAprovados; i++) {
        printf("Nome: %s\n", aprovados[i].nome);
        printf("Matrícula: %d\n", aprovados[i].matricula);
        printf("Média Final: %.2f\n\n", aprovados[i].mediaFinal);
    }

    // Exibindo os dados dos alunos reprovados
    printf("\nAlunos Reprovados:\n");
    for (int i = 0; i < numReprovados; i++) {
        printf("Nome: %s\n", reprovados[i].nome);
        printf("Matrícula: %d\n", reprovados[i].matricula);
        printf("Média Final: %.2f\n\n", reprovados[i].mediaFinal);
    }

    return 0;
}
