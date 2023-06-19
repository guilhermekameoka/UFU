#include <stdio.h>

int main()
{
    float velocidade;
    char opcao;

    while (opcao != 'q')
    {
        printf("<<Conversor>>\n");
        printf("Digite uma opcao\n");
        printf("1 - para converter de km/h para m/s\n");
        printf("2 - para converter de m/s para km/h\n");
        printf("q - para sair\n");
        setbuf(stdin, NULL);
        scanf("%c", &opcao);

        if (opcao == '1')
        {
            printf("Digite a velocidade (km/h): ");
            scanf("%f", &velocidade);
            printf("A velocidade em m/s e %f\n\n", velocidade / 3.6);
        }
        else if (opcao == '2')
        {
            printf("Digite a velocidade (m/s): ");
            scanf("%f", &velocidade);
            printf("A velocidade em km/h e %.0f\n\n", velocidade * 3.6);
        }
    }
}