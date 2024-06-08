#include <stdio.h>
#include <string.h>
#define NUM_LIVROS 5
typedef struct{
    char TituloDoLivro[31]; // Máximo de 30 caracteres + '\0' para a string
    char AutorDoLivro[16];  // Máximo de 15 caracteres + '\0' para a string
    int AnoDePublicacao;
}Livro;

int main(){
    Livro livros[NUM_LIVROS];
    for(int i = 0; i < NUM_LIVROS; i++){
        printf("Digite o título do livro %d: ", i + 1);
        fgets(livros[i].TituloDoLivro, 31, stdin);
        livros[i].TituloDoLivro[strcspn(livros[i].TituloDoLivro, "\n")] = 0;
        printf("Digite o autor do livro %d: ", i + 1);
        fgets(livros[i].AutorDoLivro, 16, stdin);
        livros[i].AutorDoLivro[strcspn(livros[i].AutorDoLivro, "\n")] = 0;
        printf("Digite o ano de publicação do livro %d: ", i + 1);
        scanf("%d", &livros[i].AnoDePublicacao);
        getchar();
    }
    char TituloBuscado[31];
    while (1){
        printf("Digite o título do livro que deseja buscar (ou 'sair' para sair): ");
        fgets(TituloBuscado, 31, stdin);
        TituloBuscado[strcspn(TituloBuscado, "\n")] = 0;
        if (strcmp(TituloBuscado, "sair") == 0) {
            printf("Saindo...");
            break;
        }
        printf("Livros encontrados com o título '%s':\n", TituloBuscado);
        int encontrouLivro = 0;
        for (int i = 0; i < NUM_LIVROS; i++) {
            if (strcmp(livros[i].TituloDoLivro, TituloBuscado) == 0) {
                printf("Título: %s, Nome do Autor: %s, Ano de Publicação: %d\n", livros[i].TituloDoLivro, livros[i].AutorDoLivro, livros[i].AnoDePublicacao);
                encontrouLivro = 1;
            }
        }
        if (!encontrouLivro) {
            printf("Nenhum livro encontrado com esse título '%s'.\n", TituloBuscado);
        }
    }
    return 0;
}
