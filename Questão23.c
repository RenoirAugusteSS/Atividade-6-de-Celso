#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    char cpf[15];
    char dataNascimento[11];
    int codigoSetor;
    char cargo[30];
    double salario;
} Funcionario;

int main() {
    Funcionario funcionarios[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do funcionário %d: ", i + 1);
        fgets(funcionarios[i].nome, 50, stdin);
        printf("Digite a idade do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].idade);
        getchar(); // Limpar o buffer
        printf("Digite o sexo do funcionário %d (M/F): ", i + 1);
        scanf("%c", &funcionarios[i].sexo);
        getchar(); // Limpar o buffer
        printf("Digite o CPF do funcionário %d: ", i + 1);
        fgets(funcionarios[i].cpf, 15, stdin);
        printf("Digite a data de nascimento do funcionário %d: ", i + 1);
        scanf("%s", funcionarios[i].dataNascimento);
        getchar(); // Limpar o buffer
        printf("Digite o código do setor do funcionário %d: ", i + 1);
        scanf("%d", &funcionarios[i].codigoSetor);
        getchar(); // Limpar o buffer
        printf("Digite o cargo do funcionário %d: ", i + 1);
        fgets(funcionarios[i].cargo, 30, stdin);
        printf("Digite o salário do funcionário %d: ", i + 1);
        scanf("%lf", &funcionarios[i].salario);
        getchar(); // Limpar o buffer
    }

    printf("\nFuncionários cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s", funcionarios[i].nome);
        printf("Idade: %d\n", funcionarios[i].idade);
        printf("Sexo: %c\n", funcionarios[i].sexo);
        printf("CPF: %s", funcionarios[i].cpf);
        printf("Data de Nascimento: %s\n", funcionarios[i].dataNascimento);
        printf("Código do Setor: %d\n", funcionarios[i].codigoSetor);
        printf("Cargo: %s", funcionarios[i].cargo);
        printf("Salário: %.2lf\n\n", funcionarios[i].salario);
    }

    return 0;
}
