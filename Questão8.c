#include <stdio.h>

// Definindo a estrutura para armazenar os dados do funcionário
typedef struct {
    char nome[100];
    int idade;
    char sexo;
    char cpf[12];
    char dataNascimento[11];
    int codigoSetor;
    char cargo[31];
    double salario;
} Funcionario;

int main() {
    Funcionario funcionario;

    // Lendo os dados do funcionário
    printf("Digite o nome do funcionário: ");
    fgets(funcionario.nome, sizeof(funcionario.nome), stdin);

    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionario.idade);
    getchar(); // Limpa o buffer do stdin

    printf("Digite o sexo do funcionário (M/F): ");
    scanf("%c", &funcionario.sexo);
    getchar(); // Limpa o buffer do stdin

    printf("Digite o CPF do funcionário (somente números): ");
    scanf("%s", funcionario.cpf);
    getchar(); // Limpa o buffer do stdin

    printf("Digite a data de nascimento do funcionário (dd/mm/aaaa): ");
    scanf("%s", funcionario.dataNascimento);
    getchar(); // Limpa o buffer do stdin

    printf("Digite o código do setor onde o funcionário trabalha (0-99): ");
    scanf("%d", &funcionario.codigoSetor);
    getchar(); // Limpa o buffer do stdin

    printf("Digite o cargo que o funcionário ocupa: ");
    fgets(funcionario.cargo, sizeof(funcionario.cargo), stdin);

    printf("Digite o salário do funcionário: ");
    scanf("%lf", &funcionario.salario);

    // Exibindo os dados do funcionário
    printf("\nDados do Funcionário:\n");
    printf("Nome: %s", funcionario.nome);
    printf("Idade: %d\n", funcionario.idade);
    printf("Sexo: %c\n", funcionario.sexo);
    printf("CPF: %s\n", funcionario.cpf);
    printf("Data de Nascimento: %s\n", funcionario.dataNascimento);
    printf("Código do Setor: %d\n", funcionario.codigoSetor);
    printf("Cargo: %s", funcionario.cargo);
    printf("Salário: %.2lf\n", funcionario.salario);

    return 0;
}
