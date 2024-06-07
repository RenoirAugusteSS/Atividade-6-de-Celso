#include <stdio.h>
#include <math.h>

typedef struct{
    char Nome[50];
    int Matricula;
    float Nota1, Nota2, Nota3;
}Aluno;

int main(){
    Aluno A[5];
    int i, j, maxNota1Index = 0, maxMediaIndex = 0, minMediaIndex = 0;
    float media[5], maxNota1 = 0, maxMedia = 0, minMedia = 100;

    for(i = 0; i < 5; i++){
        printf("Digite o Nome do %dº aluno: ", i+1);
        fgets(A[i].Nome, sizeof(A[i].Nome), stdin);

        printf("Digite a Matricula do %dº aluno: ", i+1);
        scanf("%d", &A[i].Matricula);
        getchar();

        printf("Digite a nota da primeira prova do %dº aluno: ", i+1);
        scanf("%f", &A[i].Nota1);
        getchar();

        printf("Digite a nota da segunda prova do %dº aluno: ", i+1);
        scanf("%f", &A[i].Nota2);
        getchar();

        printf("Digite a nota da terceira prova do %dº aluno: ", i+1);
        scanf("%f", &A[i].Nota3);
        getchar();

        media[i] = (A[i].Nota1 + A[i].Nota2 + A[i].Nota3) / 3;

        if(A[i].Nota1 > maxNota1){
            maxNota1 = A[i].Nota1;
            maxNota1Index = i;
        }

        if(media[i] > maxMedia){
            maxMedia = media[i];
            maxMediaIndex = i;
        }

        if(media[i] < minMedia){
            minMedia = media[i];
            minMediaIndex = i;
        }
    }

    printf("\nForam cadastrados os seguintes alunos: ");
    for(i = 0; i < 5; i++){
        printf("\n%dº Aluno.", i+1);
        printf("\nNome: %s", A[i].Nome);
        printf("Matricula: %d\n", A[i].Matricula);
        printf("Média: %.2f\n", media[i]);
        printf("%s\n", media[i] >= 6 ? "Aprovado" : "Reprovado");
    }

    printf("\nO aluno com maior nota da primeira prova foi: %s", A[maxNota1Index].Nome);
    printf("\nO aluno com maior média geral foi: %s", A[maxMediaIndex].Nome);
    printf("\nO aluno com menor média geral foi: %s", A[minMediaIndex].Nome);

    return 0;
}
