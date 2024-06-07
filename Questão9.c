#include <stdio.h>
#include <math.h>

// Definindo a estrutura para representar um número complexo
typedef struct {
    double real;
    double imaginaria;
} Complexo;

// Função para somar dois números complexos
Complexo soma(Complexo z, Complexo w) {
    Complexo resultado;
    resultado.real = z.real + w.real;
    resultado.imaginaria = z.imaginaria + w.imaginaria;
    return resultado;
}

// Função para subtrair dois números complexos
Complexo subtracao(Complexo z, Complexo w) {
    Complexo resultado;
    resultado.real = z.real - w.real;
    resultado.imaginaria = z.imaginaria - w.imaginaria;
    return resultado;
}

// Função para multiplicar dois números complexos
Complexo multiplicacao(Complexo z, Complexo w) {
    Complexo resultado;
    resultado.real = z.real * w.real - z.imaginaria * w.imaginaria;
    resultado.imaginaria = z.real * w.imaginaria + z.imaginaria * w.real;
    return resultado;
}

// Função para calcular o módulo de um número complexo
double modulo(Complexo z) {
    return sqrt(z.real * z.real + z.imaginaria * z.imaginaria);
}

int main() {
    Complexo z, w, resultadoSoma, resultadoSubtracao, resultadoMultiplicacao;
    double moduloZ, moduloW;

    // Lendo o primeiro número complexo
    printf("Digite a parte real de z: ");
    scanf("%lf", &z.real);
    printf("Digite a parte imaginária de z: ");
    scanf("%lf", &z.imaginaria);

    // Lendo o segundo número complexo
    printf("Digite a parte real de w: ");
    scanf("%lf", &w.real);
    printf("Digite a parte imaginária de w: ");
    scanf("%lf", &w.imaginaria);

    // Realizando as operações
    resultadoSoma = soma(z, w);
    resultadoSubtracao = subtracao(z, w);
    resultadoMultiplicacao = multiplicacao(z, w);
    moduloZ = modulo(z);
    moduloW = modulo(w);

    // Exibindo os resultados
    printf("\nSoma: %.2lf + %.2lfi\n", resultadoSoma.real, resultadoSoma.imaginaria);
    printf("Subtração: %.2lf + %.2lfi\n", resultadoSubtracao.real, resultadoSubtracao.imaginaria);
    printf("Multiplicação: %.2lf + %.2lfi\n", resultadoMultiplicacao.real, resultadoMultiplicacao.imaginaria);
    printf("Módulo de z: %.2lf\n", moduloZ);
    printf("Módulo de w: %.2lf\n", moduloW);

    return 0;
}
