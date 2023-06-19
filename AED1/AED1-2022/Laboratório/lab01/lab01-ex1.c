#include <stdio.h>

int main()
{

    int amigo[3], i, total = 0;
    float val_premio, recebe[3];

    for (i = 0; i < 3; i++)
    {

        printf("Bolao jogador %d R$: ", i + 1);
        scanf("%d", &amigo[i]);
        total += amigo[i];
    }

    printf("Informe o valor do premio: ");
    scanf("%f", &val_premio);

    for (i = 0; i < 3; i++)
    {
        recebe[i] = amigo[i] * val_premio / total;
        printf("Jogador %d recebera R$: %.1f\n", i + 1, recebe[i]);
    }

    return 0;
}