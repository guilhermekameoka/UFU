#include <stdio.h>

int main()
{

    int a[3], b[3], c[3], i, j;

    printf("<< Subtracao de vetores >>\n");

    for (i = 0; i < 3; i++)
    {
        printf("Digite o valor %d de A: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("\n");

    for (j = 0; j < 3; j++)
    {
        printf("Digite o valor %d de B: ", j + 1);
        scanf("%d", &b[j]);
    }

    c[0] = a[0] - (b[0]);
    c[1] = a[1] - (b[1]);
    c[2] = a[2] - (b[2]);
    printf("O vetor C, definido como C = A-B: (");

    for (i = 0; i < 2; i++)
    {
        printf("%d, ", c[i]);
    }
    printf("%d)", c[2]);

    return 0;
}

/*
Faça um programa que receba do usuário dois arrays  A e B, com 3 números inteiros cada. Crie um novo array C calculando C = A - B. Mostre na tela os dados do array C.

Exemplo de saída:
<< Subtracao de vetores >>
Digite o valor 1 de A: 50
Digite o valor 2 de A: 60
Digite o valor 3 de A: 70

Digite o valor 1 de B: 30
Digite o valor 2 de B: 0
Digite o valor 3 de B: -10

O vetor C, definido como C = A-B:  (20, 60, 80) 
*/