#include "fila.h"
#include <stdio.h>

int main()
{
    int elem, op = 0;
    Fila f;

    while (1)
    {
        printf("----------\t\tMENU\t\t----------\n");
        printf("1 - Inicializar fila.\n");
        printf("2 - Inserir elemento.\n");
        printf("3 - Remover elemento.\n");
        printf("4 - Mostrar final.\n");
        printf("5 - Imprimir fila.\n");
        printf("9 - SAIR.\n");
        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        printf("\n");

        if (op == 1)
        {
            f = criar_fila();
            printf("\nfila criada com sucesso!\n");
        }

        if (op == 2)
        {
            printf("\nDigite o elemento a ser INSERIDO: ");
            scanf("%d", &elem);

            if (insere_final(f, elem))
            {
                printf("\nElemento inserido com sucesso!\n\n");
            }
            else
            {
                printf("\nFALHA!\n");
            }
        }

        if (op == 3)
        {
            if (remove_inicio(f, &elem))
            {
                printf("\nElemento %d REMOVIDO com sucesso!\n", elem);
            }
            else
            {
                printf("\nFALHA!\n");
            }
        }

        if (op == 4)
        {
            if (le_final(f))
            {
                printf("\n----- FIM -----\n");
            }
            else
            {
                printf("\nFALHA!\n");
            }
        }

        if (op == 5)
        {
            if (mostrar_fila(f))
            {
                printf("\n----- FIM -----\n");
            }
            else
            {
                printf("\nFALHA!\n");
            }
        }

        if (op == 9)
            break;

        printf("\n");
    }
    return 0;
}