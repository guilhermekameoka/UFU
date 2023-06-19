#include <stdio.h>
#include <math.h>

int main()
{
    int binario_1, binario_2, binario_3, binario_4, decimal;

    printf("== Conversor de números binários ==\n");

    printf("Digite o 1o. bit: ");
    scanf("%d", &binario_1);

    printf("Digite o 2o. bit: ");
    scanf("%d", &binario_2);

    printf("Digite o 3o. bit: ");
    scanf("%d", &binario_3);

    printf("Digite o 4o. bit: ");
    scanf("%d", &binario_4);

    decimal = 8 * binario_1 + 4 * binario_2 + 2 * binario_3 + 1 * binario_4;

    printf("O numero binario %d%d%d%d corresponde ao numero decimal %d\n", binario_1, binario_2, binario_3, binario_4, decimal);
}