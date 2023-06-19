#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include "polinomio.h"

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
            printf(" 1. Inicializar polinomio\n");
            printf(" 2. Inserir um novo termo\n");
            printf(" 3. Imprimir P(x)\n");
            printf(" 4. Eliminar termo\n");
            printf(" 5. Reinicializar polinomio\n");
            printf(" 6. Calcular valor de P(x)\n");
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
            cria_polinomio();

            if (cria_polinomio() == 1)
            {
                printf("Polinomio criado com sucesso!\n");
            }
            else
            {
                printf("Falha!\n");
            }

            getch();
            break;

        case 2:
            Polinomio p;
            int coeficiente, exp;

            printf("Digite o coeficiente: ");
            scanf("%d", &coeficiente);

            printf("Digite o expoente: ");
            scanf("%d", &exp);

            insere_termo(p, coeficiente, exp);

            if (insere_termo == 1)
            {
                printf("\nTermo inserido com sucesso!\n");
            }
            else
            {
                printf("\nFalha ao inserir termo!\n");
            }

            getch();
            break;

        case 3:
            imprime_polinomio(p);
            getch();
            break;

        case 4:
            int exp;

            printf("Digite a potencia acossiada ao termo a ser removido: ");
            scanf("%d", &exp);

            elimina_termo(p, exp);

            if (elimina_termo == 1)
            {
                printf("\nTermo eliminado com sucesso!\n");
            }
            else
            {
                printf("\nFalha!\n");
            }

            getch();
            break;

        case 5:
            reinicializar_polinomio(p);

            if (p != NULL)
            {
                printf("Polinomio reinicializado com sucesso!\n");
            }
            else
            {
                printf("Falha!\n");
            }

            getch();
            break;

        case 6:
            int num;

            printf("Digite o valor de x de P(x) a ser calculado\n");
            scanf("%d", &num);

            calcula_polinomio(p, num);

            getch();
            break;

        default:
            printf("\n\n Pressione qualquer tecla para FINALIZAR...");
            getch();
        }
    } while (op != 9);

    return 0;
}