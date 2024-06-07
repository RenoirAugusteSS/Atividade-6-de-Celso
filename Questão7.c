#include <stdio.h>
#include <math.h>

typedef struct {
    double r;
    double a;
} Polar;

typedef struct {
    double x;
    double y;
} Cartesiana;

Cartesiana polarParaCartesiana(Polar p) {
    Cartesiana c;
    c.x = p.r * cos(p.a);
    c.y = p.r * sin(p.a);
    return c;
}

int main() {
    Polar pontoPolar;
    Cartesiana pontoCartesiana;

    printf("Digite o valor do raio (r): ");
    scanf("%lf", &pontoPolar.r);
    printf("Digite o valor do argumento (a) em radianos: ");
    scanf("%lf", &pontoPolar.a);

    pontoCartesiana = polarParaCartesiana(pontoPolar);

    printf("Coordenadas cartesianas: \n");
    printf("x = %.2lf\n", pontoCartesiana.x);
    printf("y = %.2lf\n", pontoCartesiana.y);

    return 0;
}
