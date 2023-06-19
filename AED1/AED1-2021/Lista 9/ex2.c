#include <stdio.h>

struct data
{
    int dia, mes, ano;
};

int main()
{

    int i, maiorano, comp;
    struct data d[3];

    for (i = 0; i < 3; i++)
    {

        printf("Digite o dia: ");
        scanf("%d", &d[i].dia);
        printf("Digite o mes: ");
        scanf("%d", &d[i].mes);
        printf("Digite o ano: ");
        scanf("%d", &d[i].ano);
        printf("\n");
    }

    for (i = 0; i <= 2; i++)
    {

        if (d[i].ano >= comp)
        {
            maiorano = d[i].ano;
            comp = d[i].ano;
        }
    }

    printf("Data\n");
    printf("Maior ano: %d", maiorano);
}