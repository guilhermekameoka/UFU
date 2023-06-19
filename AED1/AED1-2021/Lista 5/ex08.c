#include <stdio.h>

int main()
{

    int i, valor[5], media;
    float dp, dp2, vdp0, vdp1, vdp2, vdp3, vdp4;

    printf("<< Media e desvio-padrao >>\n");

    for (i = 0; i < 5; i++)
    {

        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valor[i]);
    }

    media = (valor[0] + valor[1] + valor[2] + valor[3] + valor[4]) / 5;
    vdp0 = (valor[0] - media) * (valor[0] - media);
    vdp1 = (valor[1] - media) * (valor[1] - media);
    vdp2 = (valor[2] - media) * (valor[2] - media);
    vdp3 = (valor[3] - media) * (valor[3] - media);
    vdp4 = (valor[4] - media) * (valor[4] - media);
    dp = (vdp0 + vdp1 + vdp2 + vdp3 + vdp4)/4;
    dp2 = sqrt(dp);

    printf("A media eh %d e o desvio-padrao eh %.2f", media, dp2);

    return 0;
}

/*
Calcular a média e o desvio padrão amostral de 5 números informados pelo usuário.
obs: desvio-padrão (amostral, normalizado por N-1)

Exemplo de saída:
<< Media e desvio-padrao >>
Digite o valor 1: 50
Digite o valor 2: 60
Digite o valor 3: 70
Digite o valor 4: 80
Digite o valor 5: 60
A media eh 64 e o desvio-padrao eh 11.40
*/
