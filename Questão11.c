#include <stdio.h>
typedef struct{
    char NomeDoAluno[100];
    int MatriculaDoAluno;
    float MediaFinal;
} Aluno;

int main(){
    Aluno alunos[10];
    Aluno aprovados[10];
    Aluno reprovados[10];
    int NumeroDeAlunosAprovados = 0, NumeroDeAlunosReprovados = 0;
    const float MEDIA_MINIMA = 5.0;
    for(int i = 0; i < 10; i++){
        printf("Digite o nome do aluno %d: ", i + 1);
        fgets(alunos[i].NomeDoAluno, sizeof(alunos[i].NomeDoAluno), stdin);
        alunos[i].NomeDoAluno[strcspn(alunos[i].NomeDoAluno, "\n")] = 0;
        printf("Digite a matrícula do aluno %d: ", i + 1);
        scanf("%d", &alunos[i].MatriculaDoAluno);
        printf("Digite a média final do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].MediaFinal);
        getchar();
    }
    for(int i = 0; i < 10; i++){
        if(alunos[i].MediaFinal >= MEDIA_MINIMA){
            aprovados[NumeroDeAlunosAprovados++] = alunos[i];
        }else{
            reprovados[NumeroDeAlunosReprovados++] = alunos[i];
        }
    }
    printf("\nAlunos Aprovados:\n");
    for(int i = 0; i < NumeroDeAlunosAprovados; i++){
        printf("Nome: %s\n", aprovados[i].NomeDoAluno);
        printf("Matrícula: %d\n", aprovados[i].MatriculaDoAluno);
        printf("Média Final: %.2f\n\n", aprovados[i].MediaFinal);
    }
    printf("\nAlunos Reprovados:\n");
    for(int i = 0; i < NumeroDeAlunosReprovados; i++){
        printf("Nome: %s\n", reprovados[i].NomeDoAluno);
        printf("Matrícula: %d\n", reprovados[i].MatriculaDoAluno);
        printf("Média Final: %.2f\n\n", reprovados[i].MediaFinal);
    }
    return 0;
}
