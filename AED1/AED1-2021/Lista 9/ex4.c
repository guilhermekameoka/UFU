#include <stdio.h>

struct telefone
{
    int ddd, numero;
};

struct data
{
    int dia, mes, ano;
    char nasc, ing;
};

struct endereco
{
    char rua[30], cidade[30], estado[30], complemento[30];
    int numero, cep;
};

typedef struct
{
    char nome[30], cpf[15], sexo[10], est_civil[10], identidade[15];
    float salario;
    struct endereco comercial, residencial;
    struct telefone tel, cel;
    struct data nasc, ing;
} cadastro;

void imprimir_cadastro(){



}

void novo_cadastro(){


    
}

void menu()
{
    int opcao;

    while (1)
    {
        printf("<<<< Menu >>>>\n");
        printf("\nSelecione uma das opcoes:\n");
        printf("\n1- Listar todos os cadastros.");
        printf("\n2- Cadastrar/Sobrescrever nova pessoa (pedir em qual posição do vetor ela será cadastrada 0,1,2,3, ou 4) ");
        printf("\n3- Listar as pessoas que nasceram depois de 1990. ");
        printf("\n4- Copiar dados de um cadastro para outro.");
        printf("\n5- Sair.");
        printf("\nDigite uma opcao: ");
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
    }

    int main()
    {
        menu();
    }