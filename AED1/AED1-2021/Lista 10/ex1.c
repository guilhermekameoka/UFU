#include <stdio.h>

int main()
{
    int val[5] = {2, 4, 5, 8, 10};
    unsigned int endereco_de_val;

    endereco_de_val = &val[2];

    printf("Entre com o novo valor de val[2]: ");
    scanf("%d", endereco_de_val);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", val[i]);
    }
}