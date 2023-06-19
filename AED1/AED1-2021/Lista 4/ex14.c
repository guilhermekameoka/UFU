/*
 Dado um inteiro positivo p, verificar se p é primo.
Exemplo de saída:
<< Números primos >>
Entre com o valor: 15
O número 15 não é primo
*/

#include <stdio.h>

int main()
{

    int p, i, resultado;

    printf("<< Numeros primos >>\n");
    printf("Entre com o valor: ");
    scanf("%d", &p);

    for (i = 2; i <= p / 2; i++)
    {
        if (p % i == 0)
        {

            resultado++;
            break;

        }
    }

    if (resultado == 0)
    {

        printf("O numero %d eh primo", p);

    }
    else
    {

        printf("O numero %d nao eh primo\n", p);

    }

}
