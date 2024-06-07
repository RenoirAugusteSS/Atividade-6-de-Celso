#include <stdio.h>
#include <time.h>

typedef struct {
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char descricao[100];
} Compromisso;

int main() {
    Compromisso compromisso;

    printf("Digite o nome do seu compromisso: ");
    scanf(" %[^\n]", compromisso.descricao);
    
    printf("Digite agora a data do seu compromisso (dia mes ano): ");
    scanf("%d %d %d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);
    
    printf("Digite agora o horario do seu compromisso (hh mm ss): ");
    scanf("%d %d %d", &compromisso.horario.hora, &compromisso.horario.minutos, &compromisso.horario.segundos);

    printf("\nCompromisso Registrado:\n");
    printf("Descrição: %s\n", compromisso.descricao);
    printf("Data: %02d/%02d/%04d\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Horário: %02d:%02d:%02d\n", compromisso.horario.hora, compromisso.horario.minutos, compromisso.horario.segundos);

    time_t agora = time(NULL);
    struct tm *agora_tm = localtime(&agora);

    Data dataAtual = {agora_tm->tm_mday, agora_tm->tm_mon + 1, agora_tm->tm_year + 1900};
    Horario horarioAtual = {agora_tm->tm_hour, agora_tm->tm_min, agora_tm->tm_sec};

    printf("\nData e Hora Atuais:\n");
    printf("Data: %02d/%02d/%04d\n", dataAtual.dia, dataAtual.mes, dataAtual.ano);
    printf("Hora: %02d:%02d:%02d\n", horarioAtual.hora, horarioAtual.minutos, horarioAtual.segundos);

    return 0;
}
