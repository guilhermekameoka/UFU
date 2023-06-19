#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "lista_seq_nao_ord.h"
#include "lista_seq_ord.h"

int main()
{
    int op;
    int lst;
    int elem;
    Lista lista;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- LISTAS ESTATICAS SEQUENCIAIS --- \n\n");
            printf(" Escolha uma opcao\n");
            printf(" 1. Criar lista\n");
            printf(" 2. Verificar lista vazia\n");
            printf(" 3. Verificar lista cheia\n");
            printf(" 4. Inserir elemento\n");
            printf(" 5. Inserir elemento ordenado\n");
            printf(" 6. Excluir elemento\n");
            printf(" 7. Excluir elemento ordenado\n");
            printf(" 8. Imprimir lista\n");
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
            lista = cria_lista();
            printf("Lista criada com sucesso!\n");
            getch();
            break;

        case 2:
            lista = lista_vazia(lista);
            getch();
            break;

        case 3:
            lista = lista_cheia(lista);
            getch();
            break;

        case 4:
            elem = insere_elem(lista, elem);
            getch();
            break;

        case 5:
            elem = insere_ord(lista, elem);
            getch();
            break;

        case 6:
            elem = remove_elem(lista, elem);
            getch();
            break;

        case 7:
            elem = remove_ord(lista, elem);
            getch();
            break;

        case 8:
            elem = obtem_valor_elem(lista, elem);
            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 9);

    return 0;
}