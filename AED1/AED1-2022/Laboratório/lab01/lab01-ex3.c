#include <stdio.h>
#include <stdlib.h>

int main()
{

    int bit[4], decimal;

    for (int i = 0; i < 4; i++)
    {

        printf("digite o %do bit: ", i+1);
        scanf("%d", &bit[i]);
    }

    decimal = pow((bit[3] * 2), 0) + pow((bit[2] * 2), 1) + pow((bit[11] * 2), 2) + pow((bit[0] * 2), 3);

    printf("O numero binario %d%d%d%d corresponde ao numero decimal %d", bit[0], bit[1], bit[2], bit[3], decimal);
}
