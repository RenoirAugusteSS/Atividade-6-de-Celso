#include <stdio.h>
#include <math.h>

typedef struct {
  char Nome[50];
  int Matricula;
  int CodigoDisciplina;
  int Nota1;
  int Nota2;
  float Media; // Changed data type to float for weighted average
}Aluno;

float mediaPonderada(float nota1, float nota2) {
  return (nota1 * 1.0 + nota2 * 2.0) / 3.0;
}

int main() {
  Aluno A[10];

  for (int i = 0; i < 10; i++) {
    printf("Digite o nome do %dº aluno: ", i + 1);
    fgets(A[i].Nome, sizeof(A[i].Nome), stdin);
    printf("Digite a matrícula do %dº aluno: ", i + 1);
    scanf("%d", &A[i].Matricula);
    getchar();
    printf("Digite o código da disciplina do aluno %s: ", A[i].Nome);
    scanf("%d", &A[i].CodigoDisciplina);
    getchar();
    printf("Digite a primeira nota do aluno %s: ", A[i].Nome);
    scanf("%d", &A[i].Nota1);
    printf("Digite a segunda nota do aluno %s: ", A[i].Nome);
    scanf("%d", &A[i].Nota2);
    printf("\n\n");
  }

  printf("\nForam cadastrados os seguintes alunos: ");
  for (int i = 0; i < 10; i++) {
    printf("\n%dº Aluno.", i + 1);
    printf("\nNome: %s", A[i].Nome);
    printf("Matricula: %d\n", A[i].Matricula);
    printf("Código da Disciplina: %d\n", A[i].CodigoDisciplina);
    printf("Primeira Nota: %d", A[i].Nota1);
    printf("Segunda Nota: %d", A[i].Nota2);
    printf("\n\n");
  }

  printf("\nAs médias ponderadas e seus pesos de cada aluno:");
  for (int i = 0; i < 10; i++) {
    A[i].Media = mediaPonderada(A[i].Nota1, A[i].Nota2);

    printf("\n%dº Aluno.", i + 1);
    printf("\nNome: %s", A[i].Nome);
    printf("Matricula: %d\n", A[i].Matricula);
    printf("Código da Disciplina: %d\n", A[i].CodigoDisciplina);
    printf("Primeira Nota com peso 1.0: %d", A[i].Nota1);
    printf("Segunda Nota com peso 2.0: %d", A[i].Nota2);
    printf("\nMédia Ponderada: %.2f", A[i].Media);
    printf("\n\n");
  }

  return 0;
}