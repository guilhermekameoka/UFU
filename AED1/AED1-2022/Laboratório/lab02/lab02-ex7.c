#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{

    int x, y;

} ponto;

int main()
{

    int n, *v;

    printf("Quantos pontos deseja digitar: ");
    scanf("%d", &n);

    v = (int *)malloc(n * sizeof(ponto));

    ponto vet[n];
    v = vet;

    for (int i = 0; i < n; i++)
    {
        printf("Entre com a coordenada x do ponto %d: ", i + 1);
        scanf("%d", &vet[i].x);
        printf("Entre com a coordenada y do ponto %d: ", i + 1);
        scanf("%d", &vet[i].y);
    }

    printf("Pontos digitados: ");

    for (int i = 0; i < n; i++)
    {
        i < (n-1) ? printf("(%d,%d);", vet[i].x, vet[i].y) : printf("(%d,%d)", vet[i].x, vet[i].y);
    }
}