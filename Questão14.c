#include <stdio.h>
#include <string.h>
#define NUM_CARROS 5

typedef struct{
    char MarcaDoCarro[16];
    int AnoDoCarro;
    float PrecoDoCarro;
}Carro;

int main(){
    Carro carros[NUM_CARROS];
    for(int i = 0; i < NUM_CARROS; i++){
        printf("Digite a marca do carro %d: ", i + 1);
        fgets(carros[i].MarcaDoCarro, 16, stdin);
        carros[i].MarcaDoCarro[strcspn(carros[i].MarcaDoCarro, "\n")] = 0;
        printf("Digite o ano do carro %d: ", i + 1);
        scanf("%d", &carros[i].AnoDoCarro);
        printf("Digite o preço do carro %d: ", i + 1);
        scanf("%f", &carros[i].PrecoDoCarro);
        getchar();
    }
    float p;
    while(1){
        printf("Digite um valor p (ou 0 para sair): ");
        scanf("%f", &p);
        if(p == 0){
            break;
        }
        printf("Carros com preço menor que %.2f:\n", p);
        int encontrouCarro = 0;
        for(int i = 0; i < NUM_CARROS; i++){
            if(carros[i].PrecoDoCarro < p){
                printf("Marca: %s, Ano: %d, Preço: %.2f\n", carros[i].MarcaDoCarro, carros[i].AnoDoCarro, carros[i].PrecoDoCarro);
                encontrouCarro = 1;
            }
        }
        if(!encontrouCarro){
            printf("Nenhum carro encontrado com preço menor que %.2f.\n", p);
        }
    }
    return 0;
}
