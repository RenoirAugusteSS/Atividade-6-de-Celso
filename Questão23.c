#include <stdio.h>
struct DiaMesAno {
    int dia;
    int mes;
    int ano;
};

int Bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int DiasNoMes(int mes, int ano) {
    switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return Bissexto(ano) ? 29 : 28;
        default:
            return 0;
    }
}

int DiasBase(struct DiaMesAno data) {
    int dias = 0;
    for (int ano = 0; ano < data.ano; ano++) {
        dias += Bissexto(ano) ? 366 : 365;
    }
    for (int mes = 1; mes < data.mes; mes++) {
        dias += DiasNoMes(mes, data.ano);
    }
    dias += data.dia;
    return dias;
}

int diferencaEmDias(struct DiaMesAno data1, struct DiaMesAno data2) {
    return DiasBase(data2) - DiasBase(data1);
}

int main() {
    struct DiaMesAno data1 = {1, 1, 2020};
    struct DiaMesAno data2 = {1, 1, 2021};
    printf("A diferença em dias é: %d\n", diferencaEmDias(data1, data2));
    return 0;
}
