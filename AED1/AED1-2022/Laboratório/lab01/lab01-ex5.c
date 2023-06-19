#include <stdio.h>

int main()
{
    int n, i, j, k = 1;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) // linha
    {
        for (j = 1; j <= i; j++) // coluna
            printf("%d ", k++);

        printf("\n");
    }

    return 0;
}