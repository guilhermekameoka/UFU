#include <stdio.h>

int main()
{
    printf("<< Listando um vetor >>\n");

    int numero[5];

    printf("Entre com o numero 1: ");
    scanf("%d", &numero[0]);
    printf("Entre com o numero 2: ");
    scanf("%d", &numero[1]);
    printf("Entre com o numero 3: ");
    scanf("%d", &numero[2]);
    printf("Entre com o numero 4: ");
    scanf("%d", &numero[3]);
    printf("Entre com o numero 5: ");
    scanf("%d", &numero[4]);
    printf("Entre com o numero 6: ");
    scanf("%d", &numero[5]);

    printf("Valores lidos: %d %d %d %d %d %d", numero[0], numero[1], numero[2], numero[3], numero[4], numero[5]);

    return 0;
}

/*
Crie um programa que lê 6 valores inteiros e em seguida mostra na tela os 
valores lidos. Não utilize loops e utilize vetores para armazenar os números.
 
Exemplo de saída:
<< Listando um vetor >>
Entre com o numero 1: 5
Entre com o numero 2: 6
Entre com o numero 3: 4
Entre com o numero 4: 0
Entre com o numero 5: 3
Entre com o numero 6: 6

Valores lidos: 5 6 4 0 3 6
*/
