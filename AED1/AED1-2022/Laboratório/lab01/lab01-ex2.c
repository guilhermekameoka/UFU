#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int x, y;
    float dist;

    printf("Entre com a coordenada x: ");
    scanf("%d", &x);

    printf("Entre com a coordenada y: ");
    scanf("%d", &y);

    dist = sqrt(pow((0 - x), 2) + pow((0 - y), 2));
    printf("A distancia entre os pontos (%d,%d) e (0,0) eh %.1f", x, y, dist);
}
