#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "pilha.h"

int main()
{
    int op, num, a;
    Pilha lst;

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
            printf(" 7. Imprime Pilha\n");
            printf(" 8. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);

            if (op > 8)
            {
                printf("\nOpcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }

        } while ((op < 1) || (op > 8));

        switch (op)
        {
        case 1:
            lst = cria_pilha();

            if (lst != NULL)
            {
                printf("\nPilha inicializada com sucesso!");
            }

            getch();
            break;

        case 2:
            if (pilha_vazia(lst))
            {
                printf("\nPilha vazia!\n");
            }

            else
            {
                printf("\nPilha NAO vazia!\n");
            }

            getch();
            break;

        case 3:
            if (pilha_cheia(lst))
            {
                printf("\nPilha cheia!\n");
            }
            else
            {
                printf("\nPilha NAO cheia!\n");
            }

            getch();
            break;

        case 4:

            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &num);

            if (push(lst, num))
            {
                printf("\nElemento inserido com SUCESSO!\n");
            }
            else
            {
                printf("\nERRO!");
            }

            getch();
            break;

        case 5:
            if (pop(lst, &num))
            {
                printf("\nElemento removido %d com SUCESSO!\n", num);
            }
            else
            {
                printf("\nERRO!");
            }

            getch();
            break;

        case 6:
            if (le_topo(lst, &num))
            {
                printf("\nElemento no topo: %d", num);
            }
            else
            {
                printf("\nPilha Vazia!");
            }

            getch();
            break;

        case 7:
            if (mostra_pilha(lst))
            {
                printf("\n\n-- FIM Pilha! -- \n");
            }
            else
            {
                printf("\nPilha Vazia!");
            }

            getch();
            break;

        default:
            printf("\nPressione qualquer tecla para FINALIZAR...");
        }
    } while (op != 8);

    return 0;
}