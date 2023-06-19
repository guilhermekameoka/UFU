#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "fila.h"

int main()
{
    int op;
    Fila f;
    int elem;

    do
    {
        system("CLS || clear");
        do
        {
            printf(" --- FILA DINAMICA/ENCADEADA CIRCULAR --- \n\n");
            printf(" Escolha uma opcao:\n");
            printf(" 1. Criar fila\n");
            printf(" 2. Verificar fila vazia\n");
            printf(" 3. Inserir elemento\n");
            printf(" 4. Remover elemento\n");
            printf(" 5. Imprimir fila\n");
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
            f = cria_fila();

            if (f == NULL)
            {
                printf("Fila criada com sucesso !");
            }
            else
            {
                printf("Falha na criacao da lista !");
            }
            
            getch();
            break;

        case 2:

            if (fila_vazia(f) == 1)
            {
                printf("\n\n Fila vazia !");
            }
            else
            {
                printf("\n\n Fila nao vazia !");
            }

            getch();
            break;

        case 3:

            printf("\n\n Digite o elemento a ser inserido: ");
            scanf("%d", &elem);

            if (insere_fim(&f, elem) == 1)
            {
                printf("\n\n Elemento inserido com sucesso !");
            }
            else
            {
                printf("\n\n Falha na insercao !");
            }

            getch();
            break;

        case 4:

            if (remove_ini(&f, &elem) == 1)
            {
                printf("\n\n O elemento removido foi: %d", elem);
            }
            else
            {
                printf("\n\n Falha na remocao !");
            }

            getch();
            break;

        case 5:

            imprime_fila(f);

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 9);

    return 0;
}
