#include <stdio.h>

int main()
{

    int n, i, j, k = 0, l = 1;

    printf("<< Multiplos >>\n");

    printf("Entre com o valor de n: ");
    scanf("%d", &n);

    printf("Entre com o valor de i: ");
    scanf("%d", &i);

    printf("Entre com o valor de j: ");
    scanf("%d", &j);

    printf("Os multiplos de i ou j sao: ");

    while (l <= n)
    {

        if (k % i == 0 || k % j == 0)
        {

            printf("%d", k);

            l = l + 1;
            if (l <= n)
            {
                printf(",");
            }
        }

        k = k + 1;
    }

    return 0;
}