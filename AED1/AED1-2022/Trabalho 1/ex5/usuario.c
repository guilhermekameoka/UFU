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
            printf(" 3. Inserir no final\n");
            printf(" 4. Remover no inicio\n");
            printf(" 5. Inserir elemento no inicio\n");
            printf(" 6. Inserir em posicao\n");
            printf(" 7. Remove em posicao\n");
            printf(" 8. Tamanho\n");
            printf(" 9. Maior\n");
            printf(" 10. Remove pares\n");
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
            int num1;

            printf("\n Digite um numero: \n");
            scanf("%d", &num1);

            if (insere_final(&lst, num1))
                printf("Elemento inserido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 4:
            int num;

            printf("\n Digite um numero a ser removido: \n");
            scanf("%d", &num);

            if (remove_inicio(&lst, &num))
                printf("Elemento removido %d com SUCESSO!\n", num);

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 5:

            int num2;

            printf("\n Digite um numero: \n");
            scanf("%d", &num2);

            a = insere(&lst, num2);

            if (a == 0)
                printf("\n Elemento nao inserido!\n \n");

            else
                printf("\nInserido com SUCESSO!\n\n");

            getch();
            break;

        case 6:
            int num3, pos;

            printf("\n Digite um numero: \n");
            scanf("%d", &num3);

            printf("\n Digite a posicao: \n");
            scanf("%d", &pos);

            a = insere_posicao(&lst, num3, pos);

            if (a == 0)
                printf("\n Elemento nao inserido!\n \n");

            else
                printf("\nInserido com SUCESSO!\n\n");

            getch();
            break;

        case 7:
            int num4;

            printf("\n Digite a posicao a ser removido: \n");
            scanf("%d", &num4);

            if (remove_posicao(&lst, num4))
                printf("Elemento removido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 8:
            a = tamanho(&lst);

            if (a == 0)
                printf("\nLISTA VAZIA!");

            else
                printf("\nTamanho = %d!", a);

            getch();
            break;

        case 9:
            a = maior_elem(&lst);

            if (a == 0)
                printf("\nLISTA VAZIA!");

            else
                printf("\nMaior = %d!", a);

            getch();
            break;

        case 10:
            a = remover_pares(&lst);

            if (a == 0)
                printf("\nERRO!");

            else
                printf("\nSUCESSO!");

            getch();
            break;

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...\n");
        }
    } while (op != 11);

    return 0;
}
