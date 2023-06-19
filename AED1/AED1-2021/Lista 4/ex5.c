// Refaça o exercício anterior utilizando o comando do .. while;

#include <stdio.h>

int main()
{

    int contagem;

    printf("<< Contagem regressiva >>\n");
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contagem);

    do
    {
        printf("%d..", contagem);
        contagem--;
        
    } while (contagem >= 0);

    printf("FIM!");
}
