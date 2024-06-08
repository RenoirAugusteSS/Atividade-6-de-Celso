#include <stdio.h>

#define NUM_ELETRODOMESTICOS 5

typedef struct{
    char NomeDoEletro[16];
    float PotenciaDoEletro;
    float TempoDeAtivo;
} Eletrodomestico;

int main(){
    Eletrodomestico eletrodomesticos[NUM_ELETRODOMESTICOS];
    float ConsumoTotal = 0;
    float Consumo[NUM_ELETRODOMESTICOS];
    for (int i = 0; i < NUM_ELETRODOMESTICOS; i++) {
        printf("Digite o nome do eletrodoméstico %d: ", i + 1);
        fgets(eletrodomesticos[i].NomeDoEletro, 16, stdin);
        eletrodomesticos[i].NomeDoEletro[strcspn(eletrodomesticos[i].NomeDoEletro, "\n")] = 0;
        printf("Digite a potência (em kW) do eletrodoméstico %d: ", i + 1);
        scanf("%f",&eletrodomesticos[i].PotenciaDoEletro);
        printf("Digite o tempo ativo por dia (em horas) do eletrodoméstico %d: ", i + 1);
        scanf("%f",&eletrodomesticos[i].TempoDeAtivo);
        getchar();
    }
    float t;
    printf("Digite o tempo (em dias): ");
    scanf("%f",&t);
    for(int i = 0; i < NUM_ELETRODOMESTICOS; i++){
        Consumo[i] = eletrodomesticos[i].PotenciaDoEletro * eletrodomesticos[i].TempoDeAtivo * t;
        ConsumoTotal += Consumo[i];
    }
    printf("Consumo total na casa em %.2f dias: %.2f kWh\n", t, ConsumoTotal);
    for(int i = 0; i < NUM_ELETRODOMESTICOS; i++){
        float consumoRelativo = (Consumo[i] / ConsumoTotal) * 100;
        printf("Consumo relativo do eletrodoméstico %s: %.2f%%\n", eletrodomesticos[i].NomeDoEletro, consumoRelativo);
    }
    return 0;
}
