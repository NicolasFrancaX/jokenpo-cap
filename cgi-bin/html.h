#include <stdio.h>

// Funcao que, dependendo do valor pego na matriz "jogo", vai mostrar se ganhou, perdeu ou empatou.
void condicaoHTML(int matriz[3][3], int player, int cpu) {
    switch(matriz[player][cpu]) {
        case 0:
            printf("Você perdeu!");
            break;
        case 1:
            printf("Você empatou!");
            break;
        case 2:
            printf("Você ganhou!");
            break;
    }
}

// Funcao que faz o processamento do HTML com CGI/C.
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
    printf("<h1>");
    condicaoHTML(matriz, player, cpu);
    printf("</h1>");
    printf("<div id=\"escolha\">");
    printf("<p> Você:       &nbsp; &nbsp; &nbsp;       PC:</p>");
    printf("</div>");
    printf("<div id=\"imagens\">");
    printf("<img src=\"../images/%s_jogador.png\">", strings[player]);
    printf("<img src=\"../images/%s_cpu.png\">", strings[cpu]);
    printf("</div>");
    printf("</div>");
    printf("<br />");
    printf("<div id=\"reiniciar\">");
    printf("<p><a href='http://cap.dc.ufscar.br/~727350/jokenpo.html'>Jogar novamente</a></p>");
    printf("</div>");
    printf("</body>");
    printf("</html>");
}
