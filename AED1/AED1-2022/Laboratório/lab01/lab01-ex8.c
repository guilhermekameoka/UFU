#include <stdio.h>
#include <math.h>

int main()
{

    int soma = 0;
    float num[5], media, dp;

    for (int i = 0; i < 5; i++)
    {

        printf("Digite o valor %d: ", i + 1);
        scanf("%f", &num[i]);
        soma += num[i];
    }

    media = soma / 5;
    dp = sqrt(((num[0] - media) * (num[0] - media) + (num[1] - media) * (num[1] - media) + (num[2] - media) * (num[2] - media) + (num[3] - media) * (num[3] - media) + (num[4] - media) * (num[4] - media)) / 4);

    printf("A media eh %.0f e o desvio-padrao eh %f", media, dp);
}