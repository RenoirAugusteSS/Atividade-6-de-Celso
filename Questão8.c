#include <stdio.h>
typedef struct {
    char NomeDoFuncionario[100];
    int IdadeDoFuncionario;
    char SexoDoFuncionario;
    char CPF[12];
    char DataNascimento[11];
    int CodigoDoSetor;
    char CargoDoFuncionario[31];
    double SalarioDoFuncionario;
} Funcionario;

int main() {
    Funcionario funcionarios;
    printf("Digite o nome do funcionário: ");
    fgets(funcionarios.NomeDoFuncionario, sizeof(funcionarios.NomeDoFuncionario), stdin);
    printf("Digite a idade do funcionário: ");
    scanf("%d", &funcionarios.IdadeDoFuncionario);
    getchar(); 
    printf("Digite o sexo do funcionário (M/F): ");
    scanf("%c", &funcionarios.SexoDoFuncionario);
    getchar();
    printf("Digite o CPF do funcionário (somente números): ");
    scanf("%s", funcionarios.CPF);
    getchar();
    printf("Digite a data de nascimento do funcionário (dd/mm/aaaa): ");
    scanf("%s", funcionarios.DataNascimento);
    getchar();
    printf("Digite o código do setor onde o funcionário trabalha (0-99): ");
    scanf("%d", &funcionarios.CodigoDoSetor);
    getchar();
    printf("Digite o cargo que o funcionário ocupa: ");
    fgets(funcionarios.CargoDoFuncionario, sizeof(funcionarios.CargoDoFuncionario), stdin);
    printf("Digite o salário do funcionário: ");
    scanf("%lf", &funcionarios.SalarioDoFuncionario);
    printf("\nDados do Funcionário:\n");
    printf("Nome: %s", funcionarios.NomeDoFuncionario);
    printf("Idade: %d\n", funcionarios.IdadeDoFuncionario);
    printf("Sexo: %c\n", funcionarios.SexoDoFuncionario);
    printf("CPF: %s\n", funcionarios.CPF);
    printf("Data de Nascimento: %s\n", funcionarios.DataNascimento);
    printf("Código do Setor: %d\n", funcionarios.CodigoDoSetor);
    printf("Cargo: %s", funcionarios.CargoDoFuncionario);
    printf("Salário: %.2lf\n", funcionarios.SalarioDoFuncionario);
    return 0;
}
