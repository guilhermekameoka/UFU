#include <stdio.h>

int main()
{
    char nome[10];
    int i = 0;

    printf("Digite um nome: ");
    scanf("%c", &nome);
    printf("O nome digitado eh: ");

    while (nome[i] != '\0')
    {

        if (nome[i] >= 'a' && nome[i] <= 'z')
        {
            nome[i] -= 32;
        }
        i++;

        printf("%c", nome[i]);
    }
    return 0;
}