#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, *v, i, acum_par = 0, acum_impar = 0;

    printf("Quantos inteiros serao lidos: ");
    scanf("%d", &n);

    v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {

        printf("%do inteiro: ", i+1);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++)
    {
        if (v[i] & 1)
        {
            acum_impar += 1;
        }
        else
        {
            acum_par += 1;
        }
    }
    free(v);
    printf("Sao pares: %d dos %d inteiros lidos\n", acum_par, n);
    printf("Sao impares: %d dos %d inteiros lidos\n", acum_impar, n);

    return 0;
}