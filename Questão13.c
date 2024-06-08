#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_NOME 50
#define MAX_ENDERECO 100
#define MAX_CIDADE 50
#define MAX_CEP 10
#define MAX_EMAIL 50
#define MAX_DATA 11

typedef struct{
    char Nome[MAX_NOME];
    char Endereco[MAX_ENDERECO];
    char DataDeNascimento[MAX_DATA];
    char Cidade[MAX_CIDADE];
    char CEP[MAX_CEP];
    char Email[MAX_EMAIL];
} DadosPessoais;

int ValidarData(char data[]){
    int dia, mes, ano;
    if(sscanf(data, "%d/%d/%d", &dia, &mes, &ano) != 3){
        return 0;
    }
    if(dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900 || ano > 2100){
        return 0;
    }
    return 1;
}

int ValidarCep(char cep[]) {
    if(strlen(cep) != 8){
        return 0;
    }
    for(int i = 0; i < 8; i++){
        if (!isdigit(cep[i])) {
            return 0;
        }
    }
    return 1;
}

int ValidarEmail(char email[]){
    int atPos = -1;
    int dotPos = -1;
    int length = strlen(email);
    for(int i = 0; i < length; i++){
        if(email[i] == '@'){
            atPos = i;
        }else if (email[i] == '.'){
            dotPos = i;
        }
    }
    if(atPos == -1 || dotPos == -1 || atPos > dotPos){
        return 0;
    }
    return 1;
}

int main(){
    DadosPessoais dados;
    printf("Digite seu nome: ");
    fgets(dados.Nome, MAX_NOME, stdin);
    dados.Nome[strcspn(dados.Nome, "\n")] = 0;
    printf("Digite seu endereço: ");
    fgets(dados.Endereco, MAX_ENDERECO, stdin);
    dados.Endereco[strcspn(dados.Endereco, "\n")] = 0;
    printf("Digite sua data de nascimento (dd/mm/yyyy): ");
    fgets(dados.DataDeNascimento, MAX_DATA, stdin);
    dados.DataDeNascimento[strcspn(dados.DataDeNascimento, "\n")] = 0;
    printf("Digite sua cidade: ");
    fgets(dados.Cidade, MAX_CIDADE, stdin);
    dados.Cidade[strcspn(dados.Cidade, "\n")] = 0;
    printf("Digite seu CEP (apenas números): ");
    fgets(dados.CEP, MAX_CEP, stdin);
    dados.CEP[strcspn(dados.CEP, "\n")] = 0;
    printf("Digite seu E-mail: ");
    fgets(dados.Email, MAX_EMAIL, stdin);
    dados.Email[strcspn(dados.Email, "\n")] = 0;
    int dataValida = ValidarData(dados.DataDeNascimento);
    int cepValido = ValidarCep(dados.CEP);
    int emailValido = ValidarEmail(dados.Email);
    if(dataValida && cepValido && emailValido){
        printf("Informações corretas:\n");
        printf("Nome: %s\n", dados.Nome);
        printf("Endereço: %s\n", dados.Endereco);
        printf("Data de Nascimento: %s\n", dados.DataDeNascimento);
        printf("Cidade: %s\n", dados.Cidade);
        printf("CEP: %s\n", dados.CEP);
        printf("E-mail: %s\n", dados.Email);
    }else{
        printf("Alguma informação está errada:\n");
        if (!dataValida) {
            printf("Data de Nascimento inválida.\n");
        }
        if (!cepValido) {
            printf("CEP inválido.\n");
        }
        if (!emailValido) {
            printf("E-mail inválido.\n");
        }
    }
    return 0;
}
