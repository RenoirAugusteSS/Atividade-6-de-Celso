#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM 5

// Estrutura para representar o endereço
struct Endereco {
    char rua[50];
    char bairro[50];
    char cidade[50];
    char estado[50];
    char cep[20];
};

// Estrutura para representar o cadastro
struct Cadastro {
    char nome[50];
    struct Endereco endereco;
    float salario;
    char identidade[20];
    char cpf[20];
    char estado_civil[20];
    char telefone[20];
    int idade;
    char sexo[10];
};

void preencherCadastro(struct Cadastro cadastros[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("Cadastro %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", cadastros[i].nome);
        printf("Rua: ");
        scanf(" %[^\n]", cadastros[i].endereco.rua);
        printf("Bairro: ");
        scanf(" %[^\n]", cadastros[i].endereco.bairro);
        printf("Cidade: ");
        scanf(" %[^\n]", cadastros[i].endereco.cidade);
        printf("Estado: ");
        scanf(" %[^\n]", cadastros[i].endereco.estado);
        printf("CEP: ");
        scanf(" %[^\n]", cadastros[i].endereco.cep);
        printf("Salario: ");
        scanf("%f", &cadastros[i].salario);
        printf("Identidade: ");
        scanf(" %[^\n]", cadastros[i].identidade);
        printf("CPF: ");
        scanf(" %[^\n]", cadastros[i].cpf);
        printf("Estado civil: ");
        scanf(" %[^\n]", cadastros[i].estado_civil);
        printf("Telefone: ");
        scanf(" %[^\n]", cadastros[i].telefone);
        printf("Idade: ");
        scanf("%d", &cadastros[i].idade);
        printf("Sexo: ");
        scanf(" %[^\n]", cadastros[i].sexo);
    }
}

// Função para encontrar a pessoa com maior idade
void encontrarMaiorIdade(struct Cadastro cadastros[], int tam) {
    int MaiorIdade = 0;
    int IndicerDaIdade = -1;
    for(int i = 0; i < tam; i++){
        if (cadastros[i].idade > MaiorIdade) {
            MaiorIdade = cadastros[i].idade;
            IndicerDaIdade = i;
        }
    }
    if(IndicerDaIdade != -1){
        printf("Pessoa com maior idade: %s\n", cadastros[IndicerDaIdade].nome);
    }
}

void encontrarMasculino(struct Cadastro cadastros[], int tam) {
    printf("Pessoas do sexo masculino:\n");
    for (int i = 0; i < tam; i++) {
        if (strcmp(cadastros[i].sexo, "masculino") == 0) {
            printf("%s\n", cadastros[i].nome);
        }
    }
}

void encontrarSalarioMaiorQueMil(struct Cadastro cadastros[], int tam) {
    printf("Pessoas com salário maior que 1000 são:\n");
    for(int i = 0; i < tam; i++){
        if(cadastros[i].salario > 1000){
            printf("%s\n", cadastros[i].nome);
            printf("Com salario de: %s\n", cadastros[i].salario);
        }
    }
}

void imprimirDadosIdentidade(struct Cadastro cadastros[], int tam, char identidade[]) {
    for (int i = 0; i < tam; i++) {
        if(strcmp(cadastros[i].identidade, identidade) == 0){
            printf("\n");
            printf("Nome: %s\n", cadastros[i].nome);
            printf("Rua: %s\n", cadastros[i].endereco.rua);
            printf("Bairro: %s\n", cadastros[i].endereco.bairro);
            printf("Cidade: %s\n", cadastros[i].endereco.cidade);
            printf("Estado: %s\n", cadastros[i].endereco.estado);
            printf("CEP: %s\n", cadastros[i].endereco.cep);
            printf("Salario: %.2f\n", cadastros[i].salario);
            printf("Identidade: %s\n", cadastros[i].identidade);
            printf("CPF: %s\n", cadastros[i].cpf);
            printf("Estado civil: %s\n", cadastros[i].estado_civil);
            printf("Telefone: %s\n", cadastros[i].telefone);
            printf("Idade: %d\n", cadastros[i].idade);
            printf("Sexo: %s\n", cadastros[i].sexo);
            return;
        }
    }
    printf("Nenhuma pessoa encontrada com a identidade %s\n", identidade);
}

int main() {
    struct Cadastro cadastros[TAM];
    char identidade[20];
    bool sair = false;
    int opcao;
    do
    {
        printf("Menu:\n");
        printf("1. Cadastra 5 Funcionarios\n");
        printf("2. Encontra Funcionario com Maior Idade\n");
        printf("3. Encontra Todos os Funcionario do Sexo Masculino\n");
        printf("4. Encontra Todos os Funcionario com Salarios Maiores que 1000\n");
        printf("5. Encontra um Funcionario Pelo Sue Número de Indentidade\n");
        printf("6. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
     switch(opcao){
        case 1:
            preencherCadastro(cadastros, TAM);
            break;
        case 2:
            encontrarMaiorIdade(cadastros, TAM);
            break;
        case 3:
            encontrarMasculino(cadastros, TAM);
            break;
        case 4:
            encontrarSalarioMaiorQueMil(cadastros, TAM);
            break;
        case 5:
            printf("Digite o Número da Identidade Do Funcionario: ");
            scanf("%[^\n]", identidade);
            imprimirDadosIdentidade(cadastros, TAM, identidade);
            break;
        case 6:
            printf("Saindo...\n");
            sair = true;
            break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                }
    } while (!sair);
    return 0;
}
