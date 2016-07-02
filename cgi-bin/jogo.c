#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Importando arquivo que tem o processamento de HTML do jogo.
#include "html.h"

int main() {

    // Inicializando funcao pra pegar numero aleatorio.
    srand(time(NULL));

    // Pegando string de acordo com os numeros selecionados/randomizados.
    char escolha[3][10] = {"papel", "pedra", "tesoura"};

    // Variaveis que serao usadas para pegar o valor na matriz "jogo".
    int jogador, maquina;

    /*
     * Matriz que, dependendo do resultado pego, define o jogo.
     *
     * Como funciona?
     *
     * Se o jogador pegar o valor n (0 <= n <= 2), e o oponente o valor m
     * vai ser pego o valor da dimensao (n, m) da matriz.
     *
     * Caso seja pego o: 2 - Venceu;
     *                   1 - Empatou;
     *                   0 - Perdeu.
     *
     * Nesse caso:       0 - Papel;
     *                   1 - Pedra;
     *                   2 - Tesoura.
     *
     * Depois, esse mesmo valor vai ser posto em um switch no arquivo html.h
     */
    int jogo[3][3] = {
        {1, 2, 0},
        {0, 1, 2},
        {2, 0, 1}
    };

    // Comandos pra pegar valor no HTML e processar no CGI/C para a variável "jogador".
    char *dados;
    dados = getenv("QUERY_STRING");
    sscanf(dados, "jogada=%d", &jogador);

    // Pegar um número n (0 <= n <= 2)
    maquina = rand() % 3;

    // Usando função HTML do arquivo html.h que faz o processamento do HTML com o CGI/C.
    HTML(escolha, jogo, jogador, maquina);

    return 0;
}
