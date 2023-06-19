#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista_seq_ordenada.h"

int main()
{
    int op;
    Lista lst, lst2, lst3;
    int a;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTA ESTATICA SEQUENCIAL NAO ORDENADA --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Inicializar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Remover elemento\n");
            printf(" 5. Remover impares\n");
            printf(" 6. Menor elemento da lista\n");
            printf(" 7. Ordenar lista\n");
            printf(" 8. tamanho lista\n");
            printf(" 9. Concatenar listas\n");
            printf(" 10. mostrar lista\n");
            printf(" 11. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);

            if (op > 11)
            {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }

        } while ((op < 1) || (op > 11));

        switch (op)
        {
        case 1:
            lst = criar_lista();
            printf("\n Lista criada com sucesso!\n");
            getch();
            break;

        case 2:
            if (lista_vazia(lst))
                printf("Lista esta vazia!\n \n");

            else
                printf("Lista NAO esta vazia!\n\n");

            getch();
            break;

        case 3:
            int num1;

            printf("\n Digite um numero: \n");
            scanf("%d", &num1);

            if (insere_ord(lst, num1))
                printf("Elemento inserido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 4:
            int num;

            printf("\n Digite um numero a ser removido: \n");
            scanf("%d", &num);

            if (remove_ord(lst, num))
                printf("Elemento removido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 5:
            a = remove_impares(lst);

            if (a == 1)
                printf("\n0 Impares na lista!\n \n");

            getch();
            break;

        case 6:
            a = menor_elem(lst);

            getch();
            break;

        case 7:
            ordena_lista(&lst);

            getch();
            break;

        case 8:
            a = tamanho(lst);

            if (a == 0)
                printf("\n LISTA VAZIA!\n \n");

            else
                printf("\n TAMANHO da lista eh: %d\n", a);

            getch();
            break;

        case 9:
            concatena(&lst);

            getch();
            break;

        case 10:
            a = mostrar_lista(lst);

            if (a == 0)
                printf("\n LISTA VAZIA!\n \n");

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...\n");
        }
    } while (op != 11);

    return 0;
}
