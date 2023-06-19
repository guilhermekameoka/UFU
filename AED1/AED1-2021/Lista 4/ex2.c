// Refaça o exercício anterior utilizando o comando do .. while;

#include <stdio.h>

int main()
{

    int contagem;

    printf("<< Contagem regressiva >>\n");
    contagem = 10;

    do
    {

        printf("%d..", contagem);
        contagem--;

    } while (contagem >= 0);

    printf("FIM!");
}