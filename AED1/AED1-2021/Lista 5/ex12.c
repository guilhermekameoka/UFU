#include <stdio.h>

int main()
{

    int azul, verde, amarelo, vermelho, total;
    float p_azul, p_verde, p_amarelo, p_vermelho;

    printf("<< Probabilidades >>\n");

    printf("\nDigite a quantidade de bolinhas\n");

    printf("Verde: ");
    scanf("%d", &verde);

    printf("Azul: ");
    scanf("%d", &azul);

    printf("Amarela: ");
    scanf("%d", &amarelo);

    printf("Vermelho: ");
    scanf("%d", &vermelho);

    printf("\nProbabilidades\n");

    total = verde + azul + amarelo + vermelho;
    p_azul = (azul * 1.0 / total * 1.0) * 100.0;
    p_verde = (verde * 1.0 / total * 1.0) * 100.0;
    p_amarelo = (amarelo * 1.0 / total * 1.0) * 100.0;
    p_vermelho = (vermelho * 1.0 / total * 1.0) * 100.0;

    if (p_verde > p_azul && p_verde > p_amarelo && p_verde > p_vermelho)
    {
        printf("Verde: %.1f%% << Maior probabilidade\n", p_verde);
        printf("Azul: %.1f%%\n", p_azul);
        printf("Amarela: %.1f%%\n", p_amarelo);
        printf("Vermelha: %.1f%%\n", p_vermelho);
    }
    else if (p_azul > p_verde && p_azul > p_amarelo && p_azul > p_vermelho)
    {
        printf("Verde: %.1f%%\n", p_verde);
        printf("Azul: %.1f%% << Maior probabilidade\n", p_azul);
        printf("Amarela: %.1f%%\n", p_amarelo);
        printf("Vermelha: %.1f%%\n", p_vermelho);
    }
    else if (p_amarelo > p_verde && p_amarelo > p_vermelho && p_amarelo > p_azul)
    {
        printf("Verde: %.1f%%\n", p_verde);
        printf("Azul: %.1f%%\n", p_azul);
        printf("Amarela: %.1f%% << Maior probabilidade\n", p_amarelo);
        printf("Vermelha: %.1f%%\n", p_vermelho);
    }
    else if (p_vermelho > p_azul && p_vermelho > p_amarelo && p_vermelho > p_verde)
    {
        printf("Verde: %.1f%%\n", p_verde);
        printf("Azul: %.1f%%\n", p_azul);
        printf("Amarela: %.1f%%\n", p_amarelo);
        printf("Vermelha: %.1f%% << Maior probabilidade\n", p_vermelho);
    }

    return 0;
}

/*
Uma piscina de bolinhas possui bolas azuis, verdes, amarelas e vermelhas. 
Faça um programa em que o usuário digita a quantidade de bolinhas de cada
cor existente em uma piscina e mostra a probabilidade de ocorrência de cada 
cor, indicando qual possui a maior probabilidade

Exemplo de saída:
<< Probabilidades >>

Digite a quantidade de bolinhas
Verde: 51
Azul: 60
Amarela: 70
Vermelha: 80

Probabilidades
Verde: 19.5%
Azul: 22.9%
Amarela: 26.8%
Vermelha: 30.6% << Maior probabilidade
*/