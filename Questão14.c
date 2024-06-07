#include <stdio.h>

typedef struct {
    char nome[50];
    char endereco[100];
    char telefone[15];
} Cliente;

int main() {
    Cliente clientes[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do cliente %d: ", i + 1);
        fgets(clientes[i].nome, 50, stdin);
        printf("Digite o endereço do cliente %d: ", i + 1);
        fgets(clientes[i].endereco, 100, stdin);
        printf("Digite o telefone do cliente %d: ", i + 1);
        fgets(clientes[i].telefone, 15, stdin);
    }

    printf("\nClientes cadastrados:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome: %s", clientes[i].nome);
        printf("Endereço: %s", clientes[i].endereco);
        printf("Telefone: %s\n\n", clientes[i].telefone);
    }

    return 0;
}
