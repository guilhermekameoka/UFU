#include <stdio.h>

int main()
{
    int i = 0, j = 0, k, aux = 0;
    char nome1[50], nome2[50];

    printf("<< Compara nomes>>\n");
    printf("Digite o nome 1: ");
    while ((nome1[i] = getchar()) != '\n')
    {
        i++;
    }
    printf("Digite o nome 2: ");
    fflush(stdin);
    while ((nome2[j] = getchar()) != '\n')
    {
        j++;
    }

    if (i == j)
    {
        for (k = 0; k < i; k++)
        {
            if (nome1[k] != nome2[k])
                aux += 1;
        }
    }
    else
    {
        printf("Os nomes digitados sao diferentes\n");
    }

    if (aux == 0 && i == j)
        printf("Os nomes digitados sao iguais\n");

    else if (aux > 0)
        printf("Os nomes digitados sao diferentes\n");
}