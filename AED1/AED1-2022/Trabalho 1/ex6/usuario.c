#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"

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
            printf(" 5. Tamanho\n");
            printf(" 6. Media\n");
            printf(" 7. Iguais\n");
            printf(" 8. Remove todos\n");
            printf(" 9. Remove maior\n");
            printf(" 10. Mostrar Lista\n");
            printf(" 11. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);

            if (op > 13)
            {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }

        } while ((op < 1) || (op > 13));

        switch (op)
        {
        case 1:
            lst = cria_lista();

            if (lst == NULL)
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
            int num;

            printf("\n Digite um numero: \n");
            scanf("%d", &num);

            if (insere_ord(&lst, num))
                printf("Elemento inserido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 4:
            int num1;

            printf("\n Digite um numero a ser removido: \n");
            scanf("%d", &num1);

            if (remove_ord(&lst, num1))
                printf("Elemento removido %d com SUCESSO!\n", num1);

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 5:
            a = tamanho(&lst);

            if (a == 0)
                printf("\nLISTA VAZIA!");

            else
                printf("\nTamanho = %d!", a);

            getch();
            break;

        case 6:

            float m;
            m = media(&lst);

            if (m == 0)
                printf("\nLISTA VAZIA!\n \n");


            getch();
            break;

        case 7:

            int igual;

            igual = iguais(&lst2, &lst3);

            if (igual == 1)
                printf("\n Lista Iguais!\n \n");

            else
                printf("\nListas diferentes!\n\n");

            getch();
            break;

        case 8:
            if (remove_todos(&lst))
                printf("Elementos removidos com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 9:
            if (remove_maior(&lst) == 0)
                printf("\nLISTA VAZIA!");

            else
                printf("\nRemovido com sucesso!", a);

            getch();
            break;

        case 10:
            mostra_lista(lst);

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...\n");
        }
    } while (op != 11);

    return 0;
}
