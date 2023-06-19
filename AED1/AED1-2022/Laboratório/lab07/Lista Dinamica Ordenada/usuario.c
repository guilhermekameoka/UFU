#include <stdio.h>
#include "lista_din_nao_ord.h"

int main()
{
    int op = 0;
    Lista lst;

    while (1)
    {
        printf("----------\t\tMENU\t\t----------\n");
        printf("1 - Inicializar lista.\n");
        printf("2 - Inserir elemento.\n");
        printf("3 - Remover elemento.\n");
        printf("4 - Imprimir lista.\n");
        printf("5 - SAIR.\n");

        printf("\nDigite sua opcao: ");
        scanf("%d", &op);
        printf("\n");

        if (op == 1)
        {
            lst = criar_lista();
            printf("\nLista criada com sucesso!\n");
        }

        if (op == 2)
        {
            int i;

            printf("\nDigite o elemento a ser inserido: ");
            scanf("%d", &i);

            if (insere_elem(lst, i) == 1)
            {

                printf("\nElemento inserido com sucesso!\n");
            }
            else
            {

                printf("\nFalha ao alocar elemento!\n");
            }
        }

        if (op == 3)
        {
            int i;

            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &i);

            if (remove_elem(&lst, i) == 1)
            {

                printf("\nElemento removido com sucesso!\n");
            }
            else
            {

                printf("\nFalha ao remover elemento!\n");
            }
        }

        if (op == 4)
            obtem_valor_elem(lst);

        if (op == 5)
            break;

        printf("\n");
    }

    free(lst);
    return 0;
}
