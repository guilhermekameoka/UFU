#include <stdio.h>

int main()
{
    int num1;
    double num2;
    void *n[2];

    n[0] = &num1;
    n[1] = &num2;

    printf("Entre com o primeiro valor (int): ");
    scanf("%d", n[0]);

    printf("Entre com o segundo valor (double): ");
    scanf("%lf", n[1]);
 
    printf("Primeiro valor (int): %d\n", *(int *)n[0]);
    printf("Segundo valor (double): %.1lf\n", *(double *)n[1]);
}