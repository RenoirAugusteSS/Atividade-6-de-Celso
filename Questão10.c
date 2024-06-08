#include <stdio.h>
#include <string.h>
typedef struct{
    char Nome[100];
    char Endereco[200];
    char Telefone[15];
}Pessoa;

void Troca(Pessoa *a, Pessoa *b){
    Pessoa temp = *a;
    *a = *b;
    *b = temp;
}

void OrdenAlfabatica(Pessoa pessoas[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(strcmp(pessoas[i].Nome, pessoas[j].Nome) > 0){
                Troca(&pessoas[i], &pessoas[j]);
            }
        }
    }
}

int main(){
    Pessoa pessoas[5];
    for(int i = 0; i < 5; i++){
        printf("Digite o Nome da pessoa %d: ", i + 1);
        fgets(pessoas[i].Nome, sizeof(pessoas[i].Nome), stdin);
        pessoas[i].Nome[strcspn(pessoas[i].Nome, "\n")] = 0;
        printf("Digite o Endereco da pessoa %d: ", i + 1);
        fgets(pessoas[i].Endereco, sizeof(pessoas[i].Endereco), stdin);
        pessoas[i].Endereco[strcspn(pessoas[i].Endereco, "\n")] = 0;
        printf("Digite o Telefone da pessoa %d: ", i + 1);
        fgets(pessoas[i].Telefone, sizeof(pessoas[i].Telefone), stdin);
        pessoas[i].Telefone[strcspn(pessoas[i].Telefone, "\n")] = 0;
    }
    OrdenAlfabatica(pessoas, 5);
    printf("\nDados das pessoas em ordem alfabética:\n");
    for(int i = 0; i < 5; i++){
        printf("Nome: %s\n", pessoas[i].Nome);
        printf("Endereco: %s\n", pessoas[i].Endereco);
        printf("Telefone: %s\n\n", pessoas[i].Telefone);
    }
    return 0;
}
