#include <stdio.h>

typedef struct {
    char modelo[50];
    char placa[10];
    int ano;
    double valorDiaria;
} Carro;

typedef struct {
    Carro carro;
    char dataInicio[11];
    char dataFim[11];
    double valorTotal;
} Aluguel;

int main() {
    Carro carros[5];
    Aluguel alugueis[5];
    int i, dias;

    // Cadastro de carros
    for (i = 0; i < 5; i++) {
        printf("Digite o modelo do carro %d: ", i + 1);
        fgets(carros[i].modelo, 50, stdin);
        printf("Digite a placa do carro %d: ", i + 1);
        fgets(carros[i].placa, 10, stdin);
        printf("Digite o ano do carro %d: ", i + 1);
        scanf("%d", &carros[i].ano);
        printf("Digite o valor da diária do carro %d: ", i + 1);
        scanf("%lf", &carros[i].valorDiaria);
        getchar(); // Limpar o buffer
    }

    // Registro de alugueis
    for (i = 0; i < 5; i++) {
        alugueis[i].carro = carros[i];
        printf("\nAluguel %d\n", i + 1);
        printf("Digite a data de início (dd/mm/aaaa): ");
        scanf("%s", alugueis[i].dataInicio);
        printf("Digite a data de fim (dd/mm/aaaa): ");
        scanf("%s", alugueis[i].dataFim);
        printf("Digite o número de dias de aluguel: ");
        scanf("%d", &dias);
        alugueis[i].valorTotal = dias * alugueis[i].carro.valorDiaria;
        getchar(); // Limpar o buffer
    }

    // Exibição dos alugueis
    for (i = 0; i < 5; i++) {
        printf("\nDetalhes do Aluguel %d:\n", i + 1);
        printf("Modelo: %s", alugueis[i].carro.modelo);
        printf("Placa: %s", alugueis[i].carro.placa);
        printf("Ano: %d\n", alugueis[i].carro.ano);
        printf("Valor da Diária: %.2lf\n", alugueis[i].carro.valorDiaria);
        printf("Data de Início: %s\n", alugueis[i].dataInicio);
        printf("Data de Fim: %s\n", alugueis[i].dataFim);
        printf("Valor Total: %.2lf\n\n", alugueis[i].valorTotal);
    }

    return 0;
}
