#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void condicaoHTML(int matriz[3][3], int player, int cpu) {
    switch(matriz[player][cpu]) {
        case 0:
            printf("<h1>Você perdeu!</h1>");
            break;
        case 1:
            printf("<h1>Você empatou!</h1>");
            break;
        case 2:
            printf("<h1>Você ganhou!</h1>");
            break;
    }
}

void HTML(char strings[3][10], int matriz[3][3], int player, int cpu) {
    printf("%s%c%c\n", "Content-Type:text/html;charset=UTF-8", 13, 10);
    printf("<!DOCTYPE html PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\" \"http://www.w3.org/TR/html4/loose.dtd\">");
    printf("<html>");
    printf("<head>");
    printf("<meta charset=\"utf-8\" />");
    printf("<title>Jo-ken-pô!</title>");
    printf("<link href=\"../style.css\" rel=\"stylesheet\" type=\"text/css\" />");
    printf("<link href='https://fonts.googleapis.com/css?family=Lobster' rel='stylesheet' type='text/css'>");
    printf("<link href='https://fonts.googleapis.com/css?family=Anton' rel='stylesheet' type='text/css'>");
    printf("</head>");
    printf("<body>");

    condicaoHTML(matriz, player, cpu);

    printf("<div id=\"escolha\">");
    printf("<p> Você:       &nbsp; &nbsp; &nbsp;       PC:</p>");
    printf("</div>");
    printf("<div id=\"imagens\">");
    printf("<img src=\"../images/%s_jogador.png\">", strings[player]);
    printf("<img src=\"../images/%s_cpu.png\">", strings[cpu]);
    printf("</div>");
    printf("</div>");
    printf("</body>");
    printf("</html>");
}

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
