#include <stdio.h>

int main()
{

    int numero[8], i, repetidos;

    printf("<< Valores iguais >>\n");

    for (i = 0; i < 8; i++)
    {

        printf("Entre com o numero %d: ", i + 1);
        scanf("%d", &numero[i]);

    }
        if(numero[0] == numero[1])
        printf("Valores repetidos: ");

    return 0;
}

/*
Faça um programa que leia um vetor de 8 posições e verifique se existem 
valores iguais e os escreva (cada número repetido deve aparecer somente 
uma vez na resposta)

Exemplo de saída:
<< Valores iguais >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 5
Entre com o numero 5: -3 
Entre com o numero 6: -3
Entre com o numero 7: -3
Entre com o numero 8: 6


Valores repetidos: 5, 6, -3
*/