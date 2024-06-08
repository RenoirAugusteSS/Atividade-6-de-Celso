#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_CARTAS 52
#define CARTAS_POR_JOGADOR 5
typedef struct{
    char valor[3];
    char naipe[10];
}Carta;
typedef struct{
    Carta cartas[CARTAS_POR_JOGADOR];
}Jogador;

void CriarDoBaralho(Carta baralho[]){
    char *valores[] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
    char *naipes[] = {"Copas", "Ouros", "Espadas", "Paus"};
    int k = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            sprintf(baralho[k].valor, "%s", valores[j]);
            sprintf(baralho[k].naipe, "%s", naipes[i]);
            k++;
        }
    }
}

void EmbaralharBaralho(Carta baralho[]){
    srand(time(NULL));
    for(int i = 0; i < NUM_CARTAS; i++){
        int r = rand() % NUM_CARTAS;
        Carta temp = baralho[i];
        baralho[i] = baralho[r];
        baralho[r] = temp;
    }
}

void DistribuirCartas(Carta baralho[], Jogador jogadores[], int numJogadores){
    int k = 0;
    for(int i = 0; i < numJogadores; i++){
        for(int j = 0; j < CARTAS_POR_JOGADOR; j++){
            jogadores[i].cartas[j] = baralho[k++];
        }
    }
}

void ExibirCartasJogador(Jogador jogador, int numCartas){
    for(int i = 0; i < numCartas; i++){
        printf("%s de %s\n", jogador.cartas[i].valor, jogador.cartas[i].naipe);
    }
}

int main(){
    Carta baralho[NUM_CARTAS];
    Jogador jogadores[2];
    CriarDoBaralho(baralho);
    EmbaralharBaralho(baralho);
    DistribuirCartas(baralho, jogadores, 2);
    for(int i = 0; i < 2; i++){
        printf("Cartas do Jogador %d:\n", i + 1);
        ExibirCartasJogador(jogadores[i], CARTAS_POR_JOGADOR);
        printf("\n");
    }
    return 0;
}
