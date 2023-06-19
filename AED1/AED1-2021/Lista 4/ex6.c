// Refaça o exercício anterior utilizando o comando for

#include <stdio.h>

int main()
{

    int contagem;

    printf("<< Contagem regressiva >>\n");
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contagem);

    for (contagem; contagem >= 0; contagem--)
    {

        printf("%d..", contagem);
        
    }

    printf("FIM!");
}
