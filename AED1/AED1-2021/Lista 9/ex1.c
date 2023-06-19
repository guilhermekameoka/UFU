#include <stdio.h>

struct telefone
{
    int ddd, numero;
};

int main()
{

    int i;
    struct telefone tel[3];

    for (i = 0; i < 3; i++)
    {

        printf("Digite o DDD: ");
        scanf("%d", &tel[i].ddd);
        printf("\nDigite o telefone: ");
        scanf("%d", &tel[i].numero);
    }

    printf("Telefone**\n");
    for (i = 0; i <= 2; i++)
    {

        printf("DDD: %d................telefone: %d\n", tel[i].ddd, tel[i].numero);
    }
}