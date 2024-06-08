#include <stdio.h>
#include <string.h>

typedef struct {
    char NomeDaReceita[25];
} Receita;

typedef struct {
    char NomeDoIngrediente[50];
    int QuantidadeDeIngrediente;
} Ingrediente;

int main() {
    Receita receita[5];
    Ingrediente ingredientes[5][10]; 
    int quantidadesDeIngredientes[5];
    for (int i = 0; i < 5; i++) {
        printf("Digite o Nome da Receita %d: ", i + 1);
        fgets(receita[i].NomeDaReceita, 25, stdin);
        receita[i].NomeDaReceita[strcspn(receita[i].NomeDaReceita, "\n")] = 0;
        printf("Digite a Quantidade de Ingredientes para a Receita %d: ", i + 1);
        scanf("%d", &quantidadesDeIngredientes[i]);
        getchar();
        for(int x = 0; x < quantidadesDeIngredientes[i]; x++){
            printf("Digite o Nome do %dº Ingrediente: ", x + 1);
            fgets(ingredientes[i][x].NomeDoIngrediente, 50, stdin);
            ingredientes[i][x].NomeDoIngrediente[strcspn(ingredientes[i][x].NomeDoIngrediente, "\n")] = 0;
            printf("Digite a quantidade em gramas do %dº Ingrediente: ", x + 1);
            scanf("%d", &ingredientes[i][x].QuantidadeDeIngrediente);
            getchar();
        }
    }
    char pesquisa[25];
    while (1){
        printf("Digite o nome da receita para procurar (ou uma string vazia para sair): ");
        fgets(pesquisa, 25, stdin);
        pesquisa[strcspn(pesquisa, "\n")] = 0;
        if(strlen(pesquisa) == 0){
            printf("Saindo...");
            break;
        }
        int found = 0;
        for(int i = 0; i < 5; i++){
            if(strcmp(receita[i].NomeDaReceita, pesquisa) == 0){
                found = 1;
                printf("Receita encontrada: %s\n", receita[i].NomeDaReceita);
                printf("Ingredientes:\n");
                for (int x = 0; x < quantidadesDeIngredientes[i]; x++) {
                    printf("Nome: %s, Quantidade: %d gramas\n", ingredientes[i][x].NomeDoIngrediente, ingredientes[i][x].QuantidadeDeIngrediente);
                }
                break;
            }
        }
        if (!found) {
            printf("Receita não encontrada.\n");
        }
    }
    return 0;
}
