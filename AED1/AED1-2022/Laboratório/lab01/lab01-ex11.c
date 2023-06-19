#include <stdio.h>

int main()
{
    menu();
}

typedef struct
{
    char nome[100];
    char email[100];
    char rua[100];
    int numero;
    char complemento[100];
    char bairro[100];
    char cep[9];
    char cidade[100];
    char estado[100];
    char pais[100];
    char telefone[11];
    char datanasc[10];
} pessoa;

pessoa agenda[100]

    void
    menu()
{
    int opcao;

    while (1)
    {
        printf("\nBem vindo ao Sistema de agenda!\n");
        printf("\nSelecione uma das opcoes:\n");
        printf("\nBuscar pelo 1o nome.");
        printf("\nBuscar pelo mes de aniversario.");
        printf("\nBuscar pelo dia e mes de aniversario.");
        printf("\nInserir pessoa.");
        printf("\nRetirar pessoa.");
        printf("\nImprimir nomes, telefones e emails.");
        printf("\nImprimir todos os dados.");
        printf("\n6- Sair.\n ");
        printf("\nDigite opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
        }
        if (opcao == 2)
        {
        }
        if (opcao == 3)
        {
        }
        if (opcao == 4)
        {
        }
        if (opcao == 5)
        {
        }
        if (opcao == 6)
        {
        }
        if (opcao == 7)
        {
        }
        if (opcao == 8)
        {
        }
        if (opcao == 9)
        {
        }
        if (opcao == 0)
            return;
    }
}
