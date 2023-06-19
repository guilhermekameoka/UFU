#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

// Arquivo User.c = Implementacao da main

int main()
{
    Ponto *p1, *p2;
    float x1, y1, x2, y2, dist;
    int teste;

    p1 = gera_pto(); // Aloca memoria para p1;
    p2 = gera_pto(); // Aloca memoria para p2;

    printf("Digite o valor de x1: ");
    scanf("%f", &x1);
    printf("Digite o valor de y1: ");
    scanf("%f", &y1);

    printf("Digite o valor de x2: ");
    scanf("%f", &x2);
    printf("Digite o valor de y2: ");
    scanf("%f", &y2);

    set_pto(p1, x1, y1);
    set_pto(p2, x2, y2);

    dist = distancia_pto(p1, p2);
    printf("A distancia entre p1 e p2 eh: ");
    return dist;
    system("pause");
}
