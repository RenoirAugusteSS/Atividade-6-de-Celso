#include <stdio.h>
#include <string.h>

// Definindo a estrutura para armazenar os dados das pessoas
typedef struct {
    char nome[100];
    char endereco[200];
    char telefone[15];
} Pessoa;

// Função para trocar duas pessoas de lugar
void troca(Pessoa *a, Pessoa *b) {
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

// Função para ordenar as pessoas pelo nome em ordem alfabética
void ordenarPessoas(Pessoa pessoas[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(pessoas[i].nome, pessoas[j].nome) > 0) {
                troca(&pessoas[i], &pessoas[j]);
            }
        }
    }
}

int main() {
    Pessoa pessoas[5];

    // Lendo os dados das 5 pessoas
    for (int i = 0; i < 5; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].nome, sizeof(pessoas[i].nome), stdin);
        // Remover o newline do final da string
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = 0;

        printf("Digite o endereco da pessoa %d: ", i + 1);
        fgets(pessoas[i].endereco, sizeof(pessoas[i].endereco), stdin);
        // Remover o newline do final da string
        pessoas[i].endereco[strcspn(pessoas[i].endereco, "\n")] = 0;

        printf("Digite o telefone da pessoa %d: ", i + 1);
        fgets(pessoas[i].telefone, sizeof(pessoas[i].telefone), stdin);
        // Remover o newline do final da string
        pessoas[i].telefone[strcspn(pessoas[i].telefone, "\n")] = 0;
    }

    // Ordenando as pessoas pelo nome
    ordenarPessoas(pessoas, 5);

    // Exibindo os dados das pessoas em ordem alfabética
    printf("\nDados das pessoas em ordem alfabética:\n");
    for (int i = 0; i < 5; i++) {
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Endereco: %s\n", pessoas[i].endereco);
        printf("Telefone: %s\n\n", pessoas[i].telefone);
    }

    return 0;
}
