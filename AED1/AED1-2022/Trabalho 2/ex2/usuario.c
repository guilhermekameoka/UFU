#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "pilha.h"

int main()
{
    int op;
    int num;

    Pilha pl;
    int a;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- PILHA ESTATICA/SEQUENCIAL --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Inicializar Pilha\n");
            printf(" 2. Verificar Pilha vazia\n");
            printf(" 3. Empilhar elemento\n");
            printf(" 4. Desempilhar elemento\n");
            printf(" 5. Mostrar Topo\n");
            printf(" 6. Mostrar Pilha\n");
            printf(" 7. Palindromo\n");
            printf(" 8. Par e impar\n");
            printf(" 9. Elimina\n");
            printf(" 10. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);

            if (op > 10)
            {
                printf("\nOpcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }

        } while ((op < 1) || (op > 10));

        switch (op)
        {
        case 1:
            pl = cria_pilha();

            if (pl != NULL)
                printf("\n\nPilha criada com sucesso!");

            getch();
            break;

        case 2:
            if (pilha_vazia(pl))
                printf("\n\nPilha esta vazia!\n");

            else
                printf("\n\nPilha NAO esta vazia!\n");

            getch();
            break;

        case 3:
            printf("\nDigite um numero: ");
            scanf("%d", &num);

            if (empilha(&pl, num))
                printf("\nElemento inserido com SUCESSO!\n");

            else
                printf("\n\nERRO!");

            getch();
            break;

        case 4:
            if (desempilha(&pl, &num))
                printf("\nElemento removido %d com SUCESSO!\n", num);

            else
                printf("\n\nERRO!");

            getch();
            break;

        case 5:
            if (le_topo(&pl, &num))
                printf("\nElemento no topo: %d", num);

            else
                printf("\n\nPilha Vazia!");

            getch();
            break;

        case 6:
            if (imprimir(pl))
                printf("\n\n-- FIM Pilha! -- \n");

            else
                printf("\n\nPilha Vazia!");

            getch();
            break;

        case 7:
            char vet[50];

            setbuf(stdin, NULL);
            scanf("%[^\n]s", vet);

            if (palindromo(vet))
                printf("\n\n-- E PALINDROMO! -- \n");

            else
                printf("\n\n-- NAO E PALINDROMO! -- \n");

            getch();
            break;

        case 8:
            if (par_e_impar())
                printf("\n\nEmpilhado com sucesso! \n");

            else
                printf("\n\nTamanho Maior que maximo!");

            getch();
            break;

        case 9:
            if (elimina(&pl, &num))
                printf("\n\n%d removido com sucesso! \n", num);

            else
                printf("\n\nPilha Vazia ou Elemento nao existe!");

            getch();
            break;

        default:
            printf("\nENCERRANDO...");
        }
    } while (op != 10);

    return 0;
}
