// Refaça o exercício anterior utilizando o comando do .. while;

#include <stdio.h>

int main()
{

    int n, contagem, soma;

    printf("<< Soma de n valores naturais >>\n");
    printf("Quantos numeros deseja somar? ");
    scanf("%d", &n);

    contagem = 0;
    soma = 0;

    do{

        contagem = contagem + 1;
        soma = contagem + soma;

    }while (contagem < n);
        
    printf("A soma dos %d primeiros numeros naturais eh: %d", n, soma);
}
