#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTAS 52
#define CARTAS_POR_JOGADOR 5

// Definindo a estrutura para representar uma carta
typedef struct {
    char valor[3];
    char naipe[10];
} Carta;

// Definindo a estrutura para representar um jogador
typedef struct {
    Carta cartas[CARTAS_POR_JOGADOR];
} Jogador;

// Função para criar o baralho
void criarBaralho(Carta baralho[]) {
    char *valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    char *naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};
    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            sprintf(baralho[k].valor, "%s", valores[j]);
            sprintf(baralho[k].naipe, "%s", naipes[i]);
            k++;
        }
    }
}

// Função para embaralhar o baralho
void embaralharBaralho(Carta baralho[]) {
    srand(time(NULL));
    for (int i = 0; i < NUM_CARTAS; i++) {
        int r = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}

// Função para distribuir cartas para os jogadores
void distribuirCartas(Carta baralho[], Jogador jogadores[], int numJogadores) {
    int k = 0;
    for (int i = 0; i < numJogadores; i++) {
        for (int j = 0; j < CARTAS_POR_JOGADOR; j++) {
            jogadores[i].cartas[j] = baralho[k++];
        }
    }
}

// Função para exibir as cartas de um jogador
void exibirCartasJogador(Jogador jogador, int numCartas) {
    for (int i = 0; i < numCartas; i++) {
        printf("%s de %s\n", jogador.cartas[i].valor, jogador.cartas[i].naipe);
    }
}

int main() {
    Carta baralho[NUM_CARTAS];
    Jogador jogadores[2];

    // Criar e embaralhar o baralho
    criarBaralho(baralho);
    embaralharBaralho(baralho);

    // Distribuir as cartas para os jogadores
    distribuirCartas(baralho, jogadores, 2);

    // Exibir as cartas dos jogadores
    for (int i = 0; i < 2; i++) {
        printf("Cartas do Jogador %d:\n", i + 1);
        exibirCartasJogador(jogadores[i], CARTAS_POR_JOGADOR);
        printf("\n");
    }

    return 0;
}
