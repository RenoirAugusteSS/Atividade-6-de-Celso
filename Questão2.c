#include <stdio.h>

typedef struct{
    char Nome[50];
    int Idade;
    char Endereco[100];
}Dados;

int main(){
    Dados pessoa;

    printf("Digire seu nome: ");
    fgets(pessoa.Nome,sizeof(pessoa.Nome),stdin);
    printf("Digite sua idade: ");
    scanf("%d",&pessoa.Idade);
    getchar();
    printf("Digite seu endereço: ");
    fgets(pessoa.Endereco,sizeof(pessoa.Endereco),stdin);
    
    printf("\nNome: %s",pessoa.Nome);
    printf("Sua idade: %d",pessoa.Idade);
    printf("\nSeu endereço é: %s",pessoa.Endereco);

}