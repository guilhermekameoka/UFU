/*
Faça um programa que mostre o valor de 1!, 2!, 3!, até 10!. Utilize somente variáveis inteiras
Exemplo de saída:
<< Fatorial >>
1! = 1
2! = 2
3! = 6
4! = 24
5! = 120
6! = 720
7! = 5040
8! = 40320
9! = 362880
10! = 3628800
*/

#include <stdio.h>

int main()
{

    int fatorial = 1;
    int i;

    printf("<< Fatorial >>\n");

    for (i = 1; i < 11; i++)
    {

        fatorial = i * fatorial;

        printf("%d! = %d\n", i, fatorial);
    }
}