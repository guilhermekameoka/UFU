/*Um contador percebeu que o cálculo de IR do encanador estava errado, pois estava sendo calculado sobre o valor bruto que ele recebeu. 
Refaça o programa anterior, considerando que o IR é sobre o valor bruto após o desconto do ISS. 

Exemplo de saída
<< Pagamento encanador >>
Digite o número de dias trabalhados: 30
Valor bruto R$: 900
Valor líquido R$: 794.88
ISS R$: 36
IR R$: 69.12
*/

#include<stdio.h>

int main(){

    int dias, vb, iss;
    float vl, ir;

    printf("<< Pagamento encanador >>\n");

    printf("Digite o numero de dias trabalhados: ");
    scanf("%d", &dias);

    vb=dias*30;
    iss=0.04*vb;
    ir=(vb-iss)*0.08;
    vl=vb-(iss+ir);

    printf("Valor bruto R$: %d\n", vb);
    printf("Valor liquido: R$: %.2f\n", vl);
    printf("ISS R$: %d\n", iss);
    printf("IR R$: %.2f\n", ir);
}