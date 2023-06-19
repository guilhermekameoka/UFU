#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n, *v, i;

    printf("Digite o tamanho do seu vetor: ");
    scanf("%d", &n);

    v = (int *)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {

        printf("Digite o valor de v[%d]: ", i);
        scanf("%d", &v[i]);
    }

    for (i = 0; i < n; i++)
    {
        printf("v[%d]=%d\n", i, v[i]);
    }
    free(v);
    return 0;
}