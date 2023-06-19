// 1009

#include <stdio.h>

int main(){

    char Nome[30];
    double Salario, Vendas;
    
    scanf("%s", &Nome);
    scanf("%lf %lf", &Salario, &Vendas);

    printf("TOTAL = R$ %.2lf\n", Salario + (0.15*Vendas));
}