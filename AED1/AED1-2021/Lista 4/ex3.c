//  Refaça o exercício anterior utilizando o comando for

#include <stdio.h>

int main()
{

    int n;

    printf("<< Contagem regressiva >>\n");

    for (n = 10; n >= 0; n--)
        printf("%d..", n);
    printf("FIM!");
}