#include <stdio.h>

int main(void)
{
    int i, tamanho = 6;
    char nome[10] = "0123456789";
    nome[0] = 'B';
    nome[1] = 'r';
    nome[2] = 'a';
    nome[3] = 's';
    nome[4] = 'i';
    nome[5] = 'l';
    nome[6] = '\0';

    printf("Usando %%c: ");
    for (i = 0; i < tamanho; i++)
    {
        printf("%c", nome[i]);
    }

    printf("\nUsando %%s: %s\n", nome);

    return 0;
}