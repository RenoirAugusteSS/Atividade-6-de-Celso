#include <stdio.h>

typedef struct{
    char Nome[50];
    int Matricula;
    char Curso[100];
}Aluno;

int main(){
    Aluno A[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o Nome do %dº aluno: ", i+1);
        fgets(A[i].Nome, sizeof(A[i].Nome), stdin);
        printf("Digite a Matricula do %dº aluno: ", i+1);
        scanf("%d", &A[i].Matricula);
        getchar();
        printf("Digite o Curso do %dº aluno: ", i+1);
        fgets(A[i].Curso, sizeof(A[i].Curso), stdin);
        printf("\n");
    }
    printf("\nForam cadastrados os seguintes alunos: ");
    for(int i = 0; i < 5; i++){
        printf("\n%dº Aluno.", i+1);
        printf("\nNome: %s", A[i].Nome);
        printf("Matricula: %d\n", A[i].Matricula);
        printf("Curso: %s\n", A[i].Curso);
    }
    return 0;
}