/* Refaça o exercício anterior utilizando o comando do .. while; 
Discuta por que o do-while não é a melhor estrutura para resolver este exercício. */

#include <stdio.h>

int main()
{

    int contagem;

    printf("<< Contagem progressiva ate 0 >>\n");
    printf("Qual eh o numero inicial? ");
    scanf("%d", &contagem);

    do
    {

        printf("%d..", contagem);
        contagem++;

    } while (contagem <= 0);

    printf("FIM!");
}