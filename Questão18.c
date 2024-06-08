#include <stdio.h>
#include <string.h>
#define NUM_PRODUTOS 5
typedef struct {
    int CodigoDoProduto;
    char NomeDoProduto[16];  // Máximo de 15 caracteres + '\0' para a string
    float PresoDoProduto;
    int QuantidadeDeProduto;
} Produto;

int main(){
    Produto produtos[NUM_PRODUTOS];
    for(int i = 0; i < NUM_PRODUTOS; i++){
        printf("Digite o código do produto %d: ", i + 1);
        scanf("%d", &produtos[i].CodigoDoProduto);
        getchar();
        printf("Digite o nome do produto %d: ", i + 1);
        fgets(produtos[i].NomeDoProduto, 16, stdin);
        produtos[i].NomeDoProduto[strcspn(produtos[i].NomeDoProduto, "\n")] = 0;
        printf("Digite o preço do produto %d: ", i + 1);
        scanf("%f", &produtos[i].PresoDoProduto);
        printf("Digite a quantidade do produto %d: ", i + 1);
        scanf("%d", &produtos[i].QuantidadeDeProduto);
    }
    int CodigoDePedido;
    int QuantidadeDoPedido;
    while(1){
        printf("Digite o código do produto (ou 0 para sair): ");
        scanf("%d", &CodigoDePedido);
        if(CodigoDePedido == 0){
            printf("Saindo...");
            break;
        }
        printf("Digite a quantidade de produto desejada: ");
        scanf("%d", &QuantidadeDoPedido);
        int encontrado = 0;
        for(int i = 0; i < NUM_PRODUTOS; i++){
            if(produtos[i].CodigoDoProduto == CodigoDePedido){
                encontrado = 1;
                if(produtos[i].QuantidadeDeProduto >= QuantidadeDoPedido){
                    produtos[i].QuantidadeDeProduto -= QuantidadeDoPedido;
                    printf("Pedido atendido. Novo estoque do produto %s: %d\n", produtos[i].NomeDoProduto, produtos[i].QuantidadeDeProduto);
                }else{
                    printf("Quantidade insuficiente no estoque para o produto %s.\n", produtos[i].NomeDoProduto);
                }
                break;
            }
        }
        if(!encontrado){
            printf("Código de produto não encontrado.\n");
        }
    }

    return 0;
}
