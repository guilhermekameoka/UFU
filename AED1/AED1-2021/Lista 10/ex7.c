#include <stdio.h>

int main()
{
    char nome[] = "Jose Augusto";
    int i;
    char *p_nome;

    p_nome = nome;

    for (i = 0; i <= 12; i++)
    {
        printf("%c", *(p_nome + i));
    }
}