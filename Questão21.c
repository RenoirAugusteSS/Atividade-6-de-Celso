#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIRETORES 5
#define MAX_NOME 20
#define MAX_FILMES 10

struct Filme {
    char NomeDoFilme[MAX_NOME];
    int AnoDePublicacao;
    int Duracao;
};

struct Diretor {
    char NomeDoDiretor[MAX_NOME];
    int QuantidadeDeFilmes;
    struct Filme* filmes;
};

void preencherDiretores(struct Diretor diretores[], int tam){
    for(int i = 0; i < tam; i++){
        printf("Diretor %d:\n", i + 1);
        printf("Nome: ");
        scanf(" %[^\n]", diretores[i].NomeDoDiretor);
        printf("Quantidade de filmes: ");
        scanf("%d", &diretores[i].QuantidadeDeFilmes);
        diretores[i].filmes = (struct Filme*) malloc(diretores[i].QuantidadeDeFilmes * sizeof(struct Filme));
        for(int j = 0; j < diretores[i].QuantidadeDeFilmes; j++){
            printf("Filme %d:\n", j + 1);
            printf("Nome: ");
            scanf(" %[^\n]", diretores[i].filmes[j].NomeDoFilme);
            printf("Ano: ");
            scanf("%d", &diretores[i].filmes[j].AnoDePublicacao);
            printf("Duração (minutos): ");
            scanf("%d", &diretores[i].filmes[j].Duracao);
        }
    }
}

void procurarDiretor(struct Diretor diretores[], int tam, char nome[]){
    for(int i = 0; i < tam; i++){
        if(strcmp(diretores[i].NomeDoDiretor, nome) == 0){
            printf("Filmes de %s:\n", diretores[i].NomeDoDiretor);
            for(int j = 0; j < diretores[i].QuantidadeDeFilmes; j++){
                printf("Filme %d:\n", j + 1);
                printf("Nome: %s\n", diretores[i].filmes[j].NomeDoFilme);
                printf("Ano: %d\n", diretores[i].filmes[j].AnoDePublicacao);
                printf("Duração: %d minutos\n", diretores[i].filmes[j].Duracao);
            }
            return;
        }
    }
    printf("Diretor %s não encontrado.\n", nome);
}

int main(){
    struct Diretor diretores[MAX_DIRETORES];
    char nome[MAX_NOME];
    preencherDiretores(diretores, MAX_DIRETORES);
    getchar();
    while (1) {
        printf("Digite o nome do diretor (ou enter para sair): ");
        fgets(nome, MAX_NOME, stdin);
        nome[strcspn(nome, "\n")] = '\0';
        if (strlen(nome) == 0) {
            printf("Saindo...\n");
            break;
        }
        procurarDiretor(diretores, MAX_DIRETORES, nome);
    }
    for (int i = 0; i < MAX_DIRETORES; i++) {
        free(diretores[i].filmes);
    }
    return 0;
}
