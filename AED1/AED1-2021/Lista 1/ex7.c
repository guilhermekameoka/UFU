/* Uma empresa contrata um encanador a R$ 30,00 por dia. 
Crie um programa que solicite o número de dias trabalhados pelo encanador e imprima o valor bruto, o imposto, e a quantia líquida que deverá ser paga ao encanador,
sabendo-se que são descontados 8% para imposto de renda e 4% de ISS. 

Exemplo de saída
<< Pagamento encanador >>
Digite o número de dias trabalhados: 30
Valor bruto R$: 900
Valor líquido R$: 792
ISS R$: 36
IR R$: 72*/

#include<stdio.h>

int main(){

    int dias, vb, iss, ir, vl;

    printf("<< Pagamento encanador >>\n");
    
    printf("Digite o numero de dias trabalhados: ");
    scanf("%d", &dias);

    vb=dias*30;
    iss=0.04*vb;
    ir=0.08*vb;
    vl=vb-(iss+ir);


    printf("Valor bruto R$: %d\n", vb);
    printf("Valor liquido: R$: %d\n", vl);
    printf("ISS R$: %d\n", iss);
    printf("IR R$: %d\n", ir);
}