#include <stdio.h>

#define V 5  // Número de voos
#define A 5  // Número de aeroportos

typedef struct {
    int OrigemDoVoo;
    int DestinoDoVoo;
} Voo;

typedef struct {
    int CodigoDoAero;
    int VoosDeSaida;
    int VoosDeChegada;
} Aeroporto;

int main() {
    Voo voos[V];
    Aeroporto aeroportos[A];
    for(int i = 0; i < A; i++){
        aeroportos[i].CodigoDoAero = i;
        aeroportos[i].VoosDeSaida = 0;
        aeroportos[i].VoosDeChegada = 0;
    }
    for(int i = 0; i < V; i++){
        int OrigemDoVoo, DestinoDoVoo;
        printf("Digite o código do aeroporto de origem do voo %d: ", i + 1);
        scanf("%d", &OrigemDoVoo);
        while(OrigemDoVoo < 0 || OrigemDoVoo >= A){
            printf("Código de aeroporto inexistente.");
            printf("Digite um codigo existente (Codigo entre %d): ", A - 1);
            scanf("%d", &OrigemDoVoo);
        }
        printf("Digite o código do aeroporto de destino do voo %d: ", i + 1);
        scanf("%d", &DestinoDoVoo);
        while(DestinoDoVoo < 0 || DestinoDoVoo >= A){
            printf("Código de aeroporto inexistente.");
            printf("Digite um codigo existente (Codigo entre %d): ", A - 1);
            scanf("%d", &DestinoDoVoo);
        }
        voos[i].OrigemDoVoo = OrigemDoVoo;
        voos[i].DestinoDoVoo = DestinoDoVoo;
        aeroportos[OrigemDoVoo].VoosDeSaida++;
        aeroportos[DestinoDoVoo].VoosDeChegada++;
    }
    for(int i = 0; i < A; i++){
        printf("Aeroporto %d: %d voos de saida, %d voos de chegada.\n", aeroportos[i].CodigoDoAero, aeroportos[i].VoosDeSaida, aeroportos[i].VoosDeChegada);
    }
    return 0;
}
