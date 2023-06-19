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
            printf(" 3. Verificar Pilha cheia\n");
            printf(" 4. Empilhar elemento\n");
            printf(" 5. Desempilhar elemento\n");
            printf(" 6. Mostrar Topo\n");
            printf(" 7. Mostrar Pilha\n");
            printf(" 8. Palindromo\n");
            printf(" 9. Par e impar\n");
            printf(" 10. Elimina\n");
            printf(" 11. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);

            if (op > 11)
            {
                printf("\nOpcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }

        } while ((op < 1) || (op > 11));

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
            if (pilha_cheia(pl))
                printf("\n\nPilha esta cheia!\n");

            else
                printf("\n\nPilha NAO esta cheia!\n");

            getch();
            break;

        case 4:
            printf("\nDigite um numero: ");
            scanf("%d", &num);

            if (empilha(pl, num))
                printf("\nElemento inserido com SUCESSO!\n");

            else
                printf("\n\nERRO!");

            getch();
            break;

        case 5:
            if (desempilha(pl, &num))
                printf("\nElemento removido %d com SUCESSO!\n", num);

            else
                printf("\n\nERRO!");

            getch();
            break;

        case 6:
            if (le_topo(pl, &num))
                printf("\nElemento no topo: %d", num);

            else
                printf("\n\nPilha Vazia!");

            getch();
            break;

        case 7:
            if (imprimir(pl))
                printf("\n\n-- FIM Pilha! -- \n");

            else
                printf("\n\nPilha Vazia!");

            getch();
            break;

        case 8:
            char vet[50];

            setbuf(stdin, NULL);
            scanf("%[^\n]s", vet);

            if (palindromo(vet))
                printf("\n\n-- E PALINDROMO! -- \n");

            else
                printf("\n\n-- NAO E PALINDROMO! -- \n");

            getch();
            break;

        case 9:
            if (par_e_impar())
                printf("\n\nEmpilhado com sucesso! \n");

            else
                printf("\n\nTamanho Maior que maximo!");

            getch();
            break;

        case 10:
            if (elimina(pl, &num))
                printf("\n\n%d removido com sucesso! \n", num);

            else
                printf("\n\nPilha Vazia ou Elemento nao existe!");

            getch();
            break;

        default:
            printf("\nENCERRANDO...");
        }
    } while (op != 11);

    return 0;
}
