#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int op = 0;
    Lista l;

    while (1)
    {
        printf("----------\t\tMENU\t\t----------\n");
        printf("1 - Inicializar lista.\n");
        printf("2 - Inserir elemento.\n");
        printf("3 - Remover elemento.\n");
        printf("4 - Imprimir lista.\n");
        printf("9 - SAIR.\n");

        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        printf("\n");

        if (op == 1)
        {
            l = criar_lista();
            printf("\nLista criada com sucesso!!!\n\n");
        }

        if (op == 2)
        {
            int i;

            printf("\nDigite o elemento a ser INSERIDO: ");
            scanf("%d", &i);

            if (insere_ord(&l, i) == 1)
                printf("\nElemento INSERIDO com sucesso\n\n");
            else
                printf("\nFALHA!\n\n");
        }

        if (op == 3)
        {
            int i;

            printf("\nDigite o elemento a ser REMOVIDO: ");
            scanf("%d", &i);

            if (remove_ord(&l, i) == 1)
                printf("\nElemento REMOVIDO com sucesso\n\n");
            else
                printf("\nFALHA!\n\n");
        }

        if (op == 4)
            obtem_valor_elem(l);

        if (op == 9)
            break;

        printf("\n");
    }

    free(l);
    return 0;
}