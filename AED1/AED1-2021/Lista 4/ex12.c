// Refaça o exercício anterior utilizando o comando for.

#include <stdio.h>

int main()
{

    int n, contagem, soma;

    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos numeros deseja somar? ");
    scanf("%d", &n);

    contagem = 0;
    soma = 0;

    for(contagem; contagem<=n; contagem++){

        soma = contagem + soma;
        
    }
        
    printf("A soma dos %d primeiros numeros naturais eh: %d", n, soma);

}