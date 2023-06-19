/*
Dado um número inteiro positivo n, calcular a soma dos n primeiros números naturais (faça a soma 
utilizando while .

Exemplo de saída:
<< Soma de n valores naturais >>
Quantos números deseja somar? 5
A soma dos 5 primeiros números naturais é : 15

*/

#include <stdio.h>

int main()
{

    int n, contagem, soma;

    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos numeros deseja somar? ");
    scanf("%d", &n);

    contagem = 0;
    soma = 0;

    while (contagem < n)
    {
        
        contagem = contagem + 1;
        soma = contagem + soma;

    }
    printf("A soma dos %d primeiros numeros naturais eh: %d", n, soma);
}
