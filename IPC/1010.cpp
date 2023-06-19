// 1010

#include <stdio.h>

int main(){

    int cod1, cod2, qtd1, qtd2;
    double preco1, preco2;
    
    scanf("%d %d %lf", &cod1, &qtd1, &preco1);
    scanf("%d %d %lf", &cod2, &qtd2, &preco2);
    printf("VALOR A PAGAR: R$ %.2lf\n", qtd1*preco1 + qtd2*preco2);
}