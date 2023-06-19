// 1038

#include <stdio.h>

int main(){

    int cod, quant;

    scanf("%d %d", &cod, &quant);
    float total, preco;

    if (cod==1) preco=4;
    if (cod==2) preco=4.5;
    if (cod==3) preco=5;
    if (cod==4) preco=2;
    if (cod==5) preco=1.5;

    total = preco * quant;

    printf("Total: R$ %.2f\n", total);
}
