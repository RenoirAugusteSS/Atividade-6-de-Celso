#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char nome[50];
    char email[50];
    char endereco[50];
    int dataNascimento;
    int numeroTelefone;
} Agenda;

Agenda contatos[MAX];
int contador = 0;
void inserePessoa() {
    if (contador >= MAX) {
        printf("Agenda cheia!\n");
        return;
    }
    Agenda p;
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    strtok(p.nome, "\n");
    printf("E-mail: ");
    fgets(p.email, 50, stdin);
    strtok(p.email, "\n");
    printf("Endereço: ");
    fgets(p.endereco, 50, stdin);
    strtok(p.endereco, "\n");
    printf("Data de Nascimento (DDMMAAAA): ");
    scanf("%d", &p.dataNascimento);
    getchar();
    printf("Número de Telefone: ");
    scanf("%d", &p.numeroTelefone);
    getchar();
    int i, j;
    for (i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, p.nome) > 0) {
            break;
        }
    }
    for (j = contador; j > i; j--) {
        contatos[j] = contatos[j - 1];
    }
    contatos[i] = p;
    contador++;
    printf("Pessoa inserida com sucesso!\n");
}

void buscaPorNome() {
    char nome[50];
    printf("Digite o primeiro nome para busca: ");
    fgets(nome, 50, stdin);
    strtok(nome, "\n");
    for(int i = 0; i < contador; i++){
        if(strstr(contatos[i].nome, nome)){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void buscaPorMesAniversario() {
    int mes;
    printf("Digite o mês de aniversário para busca: ");
    scanf("%d", &mes);
    getchar();
    for(int i = 0; i < contador; i++){
        int mesNascimento = (contatos[i].dataNascimento / 1000000) % 100;
        if(mesNascimento == mes){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void buscaPorDiaMesAniversario() {
    int dia, mes;
    printf("Digite o dia e mês de aniversário para busca (dia mês): ");
    scanf("%d %d", &dia, &mes);
    getchar();
    for(int i = 0; i < contador; i++){
        int diaNascimento = contatos[i].dataNascimento / 1000000;
        int mesNascimento = (contatos[i].dataNascimento / 10000) % 100;
        if(diaNascimento == dia && mesNascimento == mes){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void retiraPessoa() {
    char nome[50];
    printf("Digite o nome da pessoa para remover: ");
    fgets(nome, 50, stdin);
    strtok(nome, "\n");
    int i, j, found = 0;
    for(i = 0; i < contador; i++){
        if(strcmp(contatos[i].nome, nome) == 0){
            found = 1;
            break;
        }
    }
    if(found){
        for(j = i; j < contador - 1; j++){
            contatos[j] = contatos[j + 1];
        }
        contador--;
        printf("Pessoa removida com sucesso!\n");
    }else{
        printf("Pessoa não encontrada!\n");
    }
}

void imprimeAgenda(int opcao){
    for(int i = 0; i < contador; i++){
        if(opcao == 6){
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %d\n", contatos[i].numeroTelefone);
            printf("E-mail: %s\n", contatos[i].email);
        }else if (opcao == 7){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
        }
        printf("\n");
    }
}

int main() {
    bool sair = false;
    int opcao;
    do {
        printf("Menu:\n");
        printf("1. Inserir Pessoa\n");
        printf("2. Buscar por Primeiro Nome\n");
        printf("3. Buscar por Mês de Aniversário\n");
        printf("4. Buscar por Dia e Mês de Aniversário\n");
        printf("5. Retirar Pessoa\n");
        printf("6. Imprimir Agenda (Nome, Telefone e E-mail)\n");
        printf("7. Imprimir Agenda (Todos os Dados)\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                inserePessoa();
                break;
            case 2:
                buscaPorNome();
                break;
            case 3:
                buscaPorMesAniversario();
                break;
            case 4:
                buscaPorDiaMesAniversario();
                break;
            case 5:
                retiraPessoa();
                break;
            case 6:
                imprimeAgenda(6);
                break;
            case 7:
                imprimeAgenda(7);
                break;
            case 8:
                printf("Saindo...\n");
                sair = true;
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (!sair);
    return 0;
}

void inserePessoa() {
    if (contador >= MAX) {
        printf("Agenda cheia!\n");
        return;
    }
    Agenda p;
    printf("Nome: ");
    fgets(p.nome, 50, stdin);
    strtok(p.nome, "\n");
    printf("E-mail: ");
    fgets(p.email, 50, stdin);
    strtok(p.email, "\n");
    printf("Endereço: ");
    fgets(p.endereco, 50, stdin);
    strtok(p.endereco, "\n");
    printf("Data de Nascimento (DDMMAAAA): ");
    scanf("%d", &p.dataNascimento);
    getchar();
    printf("Número de Telefone: ");
    scanf("%d", &p.numeroTelefone);
    getchar();
    int i, j;
    for (i = 0; i < contador; i++) {
        if (strcmp(contatos[i].nome, p.nome) > 0) {
            break;
        }
    }
    for (j = contador; j > i; j--) {
        contatos[j] = contatos[j - 1];
    }
    contatos[i] = p;
    contador++;
    printf("Pessoa inserida com sucesso!\n");
}

void buscaPorNome() {
    char nome[50];
    printf("Digite o primeiro nome para busca: ");
    fgets(nome, 50, stdin);
    strtok(nome, "\n");
    for(int i = 0; i < contador; i++){
        if(strstr(contatos[i].nome, nome)){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void buscaPorMesAniversario() {
    int mes;
    printf("Digite o mês de aniversário para busca: ");
    scanf("%d", &mes);
    getchar();
    for(int i = 0; i < contador; i++){
        int mesNascimento = (contatos[i].dataNascimento / 1000000) % 100;
        if(mesNascimento == mes){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void buscaPorDiaMesAniversario() {
    int dia, mes;
    printf("Digite o dia e mês de aniversário para busca (dia mês): ");
    scanf("%d %d", &dia, &mes);
    getchar();
    for(int i = 0; i < contador; i++){
        int diaNascimento = contatos[i].dataNascimento / 1000000;
        int mesNascimento = (contatos[i].dataNascimento / 10000) % 100;
        if(diaNascimento == dia && mesNascimento == mes){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
            printf("\n");
        }else{
            printf("Não foi Encontrado esse contato na sua lista.");
        }
    }
}

void retiraPessoa() {
    char nome[50];
    printf("Digite o nome da pessoa para remover: ");
    fgets(nome, 50, stdin);
    strtok(nome, "\n");
    int i, j, found = 0;
    for(i = 0; i < contador; i++){
        if(strcmp(contatos[i].nome, nome) == 0){
            found = 1;
            break;
        }
    }
    if(found){
        for(j = i; j < contador - 1; j++){
            contatos[j] = contatos[j + 1];
        }
        contador--;
        printf("Pessoa removida com sucesso!\n");
    }else{
        printf("Pessoa não encontrada!\n");
    }
}

void imprimeAgenda(int opcao){
    for(int i = 0; i < contador; i++){
        if(opcao == 6){
            printf("Nome: %s\n", contatos[i].nome);
            printf("Telefone: %d\n", contatos[i].numeroTelefone);
            printf("E-mail: %s\n", contatos[i].email);
        }else if (opcao == 7){
            printf("Nome: %s\n", contatos[i].nome);
            printf("E-mail: %s\n", contatos[i].email);
            printf("Endereço: %s\n", contatos[i].endereco);
            printf("Data de Nascimento: %08d\n", contatos[i].dataNascimento);
            printf("Número de Telefone: %d\n", contatos[i].numeroTelefone);
        }
        printf("\n");
    }
}
