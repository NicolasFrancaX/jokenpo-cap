#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "html.h" // Onde esta a parte HTML do jogo

int main() {
    srand(time(NULL));

    char escolha[3][10] = {"papel", "pedra", "tesoura"};
    char *dados;
    int jogador, maquina;
    int jogo[3][3] = {
        {1, 2, 0},
        {0, 1, 2},
        {2, 0, 1}
    };

    dados = getenv("QUERY_STRING");
    sscanf(dados, "jogada=%d", &jogador);

    maquina = rand() % 3;

    HTML(escolha, jogo, jogador, maquina);

    return 0;
}
