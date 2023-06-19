// 1021

#include <stdio.h>

    int main (){

        double n;

        scanf("%d", &n);
        printf("NOTAS:\n");
        printf("%d nota(s) de R$ 100.00\n", n);
        n%=100;
        printf("%d nota(s) de R$ 50.00\n", n);
        n=%=50;
        printf("%d nota(s) de R$ 20.00\n", n);
        n%=20;
        printf("%d nota(s) de R$ 10.00\n", n);
        n%=10;
        printf("%d nota(s) de R$ 5.00\n", n);
        n%=5;
        printf("%d nota(s) de R$ 2.00\n", n);
        n%=2;
        printf("MOEDAS\n");





    }