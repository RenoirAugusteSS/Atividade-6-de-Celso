#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Vetor {
  float x;
  float y;
  float z;
};

struct Vetor somaVetores(struct Vetor vt1, struct Vetor vt2) {
  struct Vetor vt3;
  vt3.x = vt1.x + vt2.x;
  vt3.y = vt1.y + vt2.y;
  vt3.z = vt1.z + vt2.z;
  return vt3;
}

struct Vetor VetorDeNumerosSorteados(void) {
  struct Vetor v;
  srand(time(NULL));
  v.x = rand() % 100;
  v.y = rand() % 100;
  v.z = rand() % 100;
  return v;
}

int main() {
  struct Vetor vetor1 = VetorDeNumerosSorteados();
  struct Vetor vetor2 = VetorDeNumerosSorteados();
  struct Vetor vetor3 = somaVetores(vetor1, vetor2);
  printf("O Valor dos vetores de números sorteados resulta em: %.2f, %.2f, %.2f\n", vetor3.x, vetor3.y, vetor3.z);
  return 0;
}