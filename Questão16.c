#include <stdio.h>
#include <string.h>
#define NUM_COMPROMISSOS 5
typedef struct{
    int Dia;
    int Mes;
    int Ano;
}Data;
typedef struct{
    char DescricaoDoCompromisso[61];
    Data DataDoCompromisso;
}Compromisso;

int main() {
    Compromisso agenda[NUM_COMPROMISSOS];
    for(int i = 0; i < NUM_COMPROMISSOS; i++){
        printf("Digite a descrição do sue compromisso %d: ", i + 1);
        fgets(agenda[i].DescricaoDoCompromisso, 61, stdin);
        agenda[i].DescricaoDoCompromisso[strcspn(agenda[i].DescricaoDoCompromisso, "\n")] = 0;
        printf("Digite o Dia do seu compromisso %d: ", i + 1);
        scanf("%d", &agenda[i].DataDoCompromisso.Dia);
        printf("Digite o mês do seu compromisso %d: ", i + 1);
        scanf("%d", &agenda[i].DataDoCompromisso.Mes);
        printf("Digite o Ano do seu compromisso %d: ", i + 1);
        scanf("%d", &agenda[i].DataDoCompromisso.Ano);
        getchar();
    }
    int Mes, Ano;
    while(1){
        printf("Digite o mês (ou 0 para sair): ");
        scanf("%d", &Mes);
        if (Mes == 0) {
            printf("Saindo...");
            break;
        }
        printf("Digite o Ano: ");
        scanf("%d", &Ano);
        printf("Compromissos para %02d/%d:\n", Mes, Ano);
        int encontrouCompromisso = 0;
        for(int i = 0; i < NUM_COMPROMISSOS; i++){
            if (agenda[i].DataDoCompromisso.Mes == Mes && agenda[i].DataDoCompromisso.Ano == Ano) {
                printf("%02d/%02d/%d - %s\n", agenda[i].DataDoCompromisso.Dia, agenda[i].DataDoCompromisso.Mes, agenda[i].DataDoCompromisso.Ano, agenda[i].DescricaoDoCompromisso);
                encontrouCompromisso = 1;
            }
        }
        if(!encontrouCompromisso){
            printf("Nenhum compromisso encontrado para %02d/%d.\n", Mes, Ano);
        }
    }
    return 0;
}
