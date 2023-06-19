#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista.h"

int main()
{
    int op;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Inserir elemento no final\n");
            printf(" 4. Remover elemento no inicio\n");
            printf(" 5. Imprimir lista\n");
            printf(" 9. SAIR\n");
            printf(" Opcao: ");
            scanf("%d", &op);
            if ((op < 1) || (op > 9))
            {
                printf("\n\n Opcao Invalida! Tente novamente...");
                getch();
                system("CLS || clear");
            }
        } while ((op < 1) || (op > 9));

        switch (op)
        {
        case 1:
            Lista N;

            N = cria_lista();
            if (N == NULL)
            {
                printf("Lista criada com sucesso!\n");
            }
            else
            {
                printf("Falha na criacao da lista!\n");
            }
            getch();
            break;

        case 2:
            if (lista_vazia(N) == 1)
            {
                printf("Lista vazia!\n");
            }
            else
            {
                printf("Lista NAO vazia!\n");
            }
            getch();
            break;

        case 3:
            int elemento;

            printf("Digite o elemento a ser inserido: ");
            scanf("%d", &elemento);

            if (insere_final(&N, elemento) == 1)
            {
                printf("\nElemento inserido com sucesso!\n");
            }
            else
            {
                printf("Falha ao tentar inserir o elemento!\n");
            }

            getch();
            break;

        case 4:
            int elemento;

            printf("\nDigite o elemento a ser removido: ");
            scanf("%d", &elemento);

            if (remove_inicio(&N, elemento) == 1)
            {
                printf("\nElemento removido com sucesso!\n");
            }
            else
            {
                printf("Falha ao tentar remover o elemento!\n");
            }
            getch();
            break;

        case 5:
            imprime_lista(N);
            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 9);

    return 0;
}