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
            printf(" 5. tamanho lista\n");
            printf(" 6. Remover impares\n");
            printf(" 7. Media de elemento da lista\n");
            printf(" 8. Teste da igualdade\n");
            printf(" 9. intercalar listas\n");
            printf(" 10. Inverte a lista\n");
            printf(" 11. Gera impares\n");
            printf(" 12. mostrar lista\n");
            printf(" 13. SAIR\n");
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
            lst = criar_lista();

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

            if (insere_elem(&lst, num1))
                printf("Elemento inserido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 4:
            int num;

            printf("\n Digite um numero a ser removido: \n");
            scanf("%d", &num);

            if (remove_elem(&lst, num))
                printf("Elemento removido com SUCESSO!\n \n");

            else
                printf("ERRO!\n\n");

            getch();
            break;

        case 5:
            a = tamanho(lst);

            if (a == 0)
                printf("\n LISTA VAZIA!\n \n");

            else
                printf("\nTamanho = %d\n", a);
            
            getch();
            break;

        case 6:
            if (gera_impares(&lst))
                printf("\n0 Impares na lista!\n \n");

            getch();
            break;

        case 7:
            float med;
            med = media(&lst);

            printf("A media dos elementos da lista eh: %.2f", med);
            getch();
            break;

        case 8:

            if (verifica_igual(&lst, &lst3))
                printf("\nSao iguais!");

            else
                printf("\nNao sao iguais!");

            getch();
            break;

            // case 9:   intercalar  lista

        case 10:
            Lista lst2 = inverte_lista(&lst);

            if (lst2 != NULL)
                printf("\nLista invertida!\n");

            else
                printf("\nERRO!\n");

            getch();
            break;

        case 11:
            Lista lst1 = gera_impares(&lst);

            printf("Lista gerada com sucesso: ");

            mostra_lista(lst1);
            getch();
            break;

        case 12:
            mostra_lista(lst);
            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...\n");
        }
    } while (op != 13);

    return 0;
}
