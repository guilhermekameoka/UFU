#include <stdio.h>
#include "lista.h"

int main()
{
    int op = 0;
    Lista l;

    while (1)
    {
        printf("----------\t\tMENU\t\t----------\n");
        printf("1 - Inicializar lista.\n");
        printf("2 - Inserir registro.\n");
        printf("3 - Remover ultimo registro.\n");
        printf("4 - Imprimir tabela.\n");
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

            if (insere_elem(&l) == 1)
                printf("\nRegistro INSERIDO com sucesso\n\n");
            else
                printf("\nFALHA!\n\n");
        }

        if (op == 3)
        {
            int i;

            if (remove_elem(&l) == 1)
                printf("\nRegistro REMOVIDO com sucesso\n\n");
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