#include <stdio.h>
#include <math.h>

int main (){

    float x1, y1, x2, y2, a, b, dist, soma, pot1, pot2;

    scanf("%f %f %f %f", &x1, &y1, &x2, &y2);
    a = (x2-x1);
    b = (y2-y1);
    pot1 = pow(a,2); 
    pot2 = pow(b,2);
    soma = (pot1) + (pot2);
    dist = sqrt (soma);
    printf("%.4f\n", dist);
}