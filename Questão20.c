#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    char sexo;
    char endereco[100];
    char telefone[15];
    char dataConsulta[11];
} Paciente;

int main() {
    Paciente pacientes[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do paciente %d: ", i + 1);
        fgets(pacientes[i].nome, 50, stdin);
        printf("Digite a idade do paciente %d: ", i + 1);
        scanf("%d", &pacientes[i].idade);
        getchar(); // Limpar o buffer
        printf("Digite o sexo do paciente %d (M/F): ", i + 1);
        scanf("%c", &pacientes[i].sexo);
        getchar(); // Limpar o buffer
        printf("Digite o endereço do paciente %d: ", i + 1);
        fgets(pacientes[i].endereco, 100, stdin);
        printf("Digite o telefone do paciente %d: ", i + 1);
        fgets(pacientes[i].telefone, 15, stdin);
        printf("Digite a data da consulta (dd/mm/aaaa): ");
        scanf("%s", pacientes[i].dataConsulta);
        getchar(); // Limpar o buffer
    }

    printf("\nPacientes cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s", pacientes[i].nome);
        printf("Idade: %d\n", pacientes[i].idade);
        printf("Sexo: %c\n", pacientes[i].sexo);
        printf("Endereço: %s", pacientes[i].endereco);
        printf("Telefone: %s\n", pacientes[i].telefone);
        printf("Data da Consulta: %s\n\n", pacientes[i].dataConsulta);
    }

    return 0;
}
