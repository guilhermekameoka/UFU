#include <stdio.h>

int main()
{
    int i = 0;
    int j;
    char nome[50];

    printf("<<Vetor de char>>\n");
    printf("Digite um nome: ");
    while ((nome[i] = getchar()) != '\n')
    {
        i++;
    }

    printf("O nome digitado eh: ");
    for (j = 0; j < i; j++)
    {
        if (nome[j] >= 97)
        {

            printf("%c", nome[j] - 32);
        }
        else
        {
            printf("%c", nome[j]);
        }
    }
}