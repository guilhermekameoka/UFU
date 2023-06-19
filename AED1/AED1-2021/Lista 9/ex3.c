#include <stdio.h>
#include <string.h>

struct endereco
{

    char rua[30], cidade[30], estado[30], complemento[30];
    int numero, cep;
};

int main()
{
    int i;
    struct endereco e[3];

    for (i = 0; i < 3; i++)
    {

        setbuf(stdin, NULL);
        printf("Digite a rua: ");
        gets(e[i].rua);
        printf("Digite a numero: ");
        scanf("%d", &e[i].numero);
        setbuf(stdin, NULL);
        printf("Digite a complemento: ");
        gets(e[i].complemento);
        setbuf(stdin, NULL);
        printf("Digite a cidade: ");
        gets(e[i].cidade);
        setbuf(stdin, NULL);
        printf("Digite a estado: ");
        gets(e[i].estado);
        printf("Digite a CEP: ");
        scanf("%d", &e[i].cep);
    }

    for (i = 0; i < 3; i++)
    {

        if (strcmp(e[i].estado, "MG") == 0)
        {

            printf("Digite a rua: %s", e[i].rua);
            printf("\nDigite a numero: %d", e[i].numero);
            printf("\nDigite a complemento: %s ", e[i].complemento);
            printf("\nDigite a cidade: %s", e[i].cidade);
            printf("\nDigite a estado: %s", e[i].estado);
            printf("\nDigite a CEP: %d", e[i].cep);
        }
    }
}
