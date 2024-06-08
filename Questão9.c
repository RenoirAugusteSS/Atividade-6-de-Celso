#include <stdio.h>
#include <math.h>
typedef struct{
    double NumeroReal;
    double NumeroImaginaria;
}Complexo;

Complexo soma(Complexo z, Complexo w){
    Complexo resultado;
    resultado.NumeroReal = z.NumeroReal + w.NumeroReal;
    resultado.NumeroImaginaria = z.NumeroImaginaria + w.NumeroImaginaria;
    return resultado;
}

Complexo subtracao(Complexo z, Complexo w) {
    Complexo resultado;
    resultado.NumeroReal = z.NumeroReal - w.NumeroReal;
    resultado.NumeroImaginaria = z.NumeroImaginaria - w.NumeroImaginaria;
    return resultado;
}

Complexo multiplicacao(Complexo z, Complexo w) {
    Complexo resultado;
    resultado.NumeroReal = z.NumeroReal * w.NumeroReal - z.NumeroImaginaria * w.NumeroImaginaria;
    resultado.NumeroImaginaria = z.NumeroReal * w.NumeroImaginaria + z.NumeroImaginaria * w.NumeroReal;
    return resultado;
}

double modulo(Complexo z){
    return sqrt(z.NumeroReal * z.NumeroReal + z.NumeroImaginaria * z.NumeroImaginaria);
}

int main(){
    Complexo z, w, resultadoSoma, resultadoSubtracao, resultadoMultiplicacao;
    double moduloZ, moduloW;
    printf("Digite um número real para z: ");
    scanf("%lf", &z.NumeroReal);
    printf("Digite um número imaginario de z: ");
    scanf("%lf", &z.NumeroImaginaria);
    printf("Digite um número real de w: ");
    scanf("%lf", &w.NumeroReal);
    printf("Digite um imaginária de w: ");
    scanf("%lf", &w.NumeroImaginaria);
    resultadoSoma = soma(z, w);
    resultadoSubtracao = subtracao(z, w);
    resultadoMultiplicacao = multiplicacao(z, w);
    moduloZ = modulo(z);
    moduloW = modulo(w);
    printf("\nSoma: %.2lf + %.2lfi\n", resultadoSoma.NumeroReal, resultadoSoma.NumeroImaginaria);
    printf("Subtração: %.2lf + %.2lfi\n", resultadoSubtracao.NumeroReal, resultadoSubtracao.NumeroImaginaria);
    printf("Multiplicação: %.2lf + %.2lfi\n", resultadoMultiplicacao.NumeroReal, resultadoMultiplicacao.NumeroImaginaria);
    printf("Módulo de z: %.2lf\n", moduloZ);
    printf("Módulo de w: %.2lf\n", moduloW);
    return 0;
}
