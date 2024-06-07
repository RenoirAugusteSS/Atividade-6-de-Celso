#include <stdio.h>

typedef struct {
    char nomeCliente[50];
    char dataReserva[11];
    int numeroQuarto;
} Reserva;

int main() {
    Reserva reservas[5];
    int i;

    for (i = 0; i < 5; i++) {
        printf("Digite o nome do cliente da reserva %d: ", i + 1);
        fgets(reservas[i].nomeCliente, 50, stdin);
        printf("Digite a data da reserva (dd/mm/aaaa): ");
        scanf("%s", reservas[i].dataReserva);
        printf("Digite o número do quarto: ");
        scanf("%d", &reservas[i].numeroQuarto);
        getchar(); // Limpar o buffer
    }

    printf("\nReservas cadastradas:\n");
    for (i = 0; i < 5; i++) {
        printf("Nome do Cliente: %s", reservas[i].nomeCliente);
        printf("Data da Reserva: %s\n", reservas[i].dataReserva);
        printf("Número do Quarto: %d\n\n", reservas[i].numeroQuarto);
    }

    return 0;
}
