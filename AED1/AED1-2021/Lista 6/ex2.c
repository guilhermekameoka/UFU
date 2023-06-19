/*
Utilizando os conceitos aprendidos até o momento (vetores e tipo char), crie um 
programa que leia o nome de uma pessoa e, em seguida, mostre o nome lido. Utilizar 
getchar() para entrada dos dados (veja acima um exemplo de como usar o getchar()).
O nome pode ter no máximo 50 caracteres. Não usar as funções de string.h
Exemplo de saída:
<< Vetor de char>>
Digite um nome: Bruno
O nome digitado é: Bruno
*/

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
        printf("%c", nome[j]);
    }
}