#include <stdio.h>

int main()
{
    int i = 0, j = 0, k, l = 0;
    char nome[40], p[20], s[20];

    printf("<< Nomes >>\n");
    printf("Digite o primeiro nome e o ultimo nome: ");
    while ((nome[i] = getchar()) != '\n')
    {
        i++;
    }

    while (nome[j] != 32)
    {
        p[j] = nome[j];
        j++;
    }
    for (k = j + 1; k < i; k++)
    {
        s[l] = nome[k];
        l++;
    }

    printf("Nome: ");
    for (i = 0; i < j; i++)
    {
        printf("%c", p[i]);
    }
    printf("\nSobrenome: ");
    for (i = 0; i < l; i++)
    {
        printf("%c", s[i]);
    }
}