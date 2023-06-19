//Escreva um programa que, dado o valor da venda, imprima a comissão que deverá ser paga ao vendedor.

#include<stdio.h>

    int main(){

        float venda, comissao1, comissao2, comissao3, comissao4, comissao5, comissao6;

        printf("Digite o valor da venda mensal:");
        scanf("%f", &venda);

        if(venda>=100000){

            comissao1=700+(0.16*venda);

            printf("Sua comissao sera de R$: %.2f", comissao1);

        } else if(venda<100000 && venda>=80000){
            
            comissao2=650+(1.14*venda);

            printf("Sua comissao sera de R$: %.2f", comissao2);

        } else if(venda<80000 && venda>=60000){

            comissao3=600+(0.14*venda);

            printf("Sua comissao sera de R$: %.2f", comissao3);
            
        } else if(venda<60000 && venda>=40000){

            comissao4=550+(0.14*venda);

            printf("Sua comissao sera de R$: %.2f", comissao4);

        } else if(venda<40000 && venda>=20000){

            comissao5=500+(0.14*venda);

            printf("Sua comissao sera de R$: %.2f", comissao5);

        }else{

            comissao6=400+(0.14*venda);

            printf("Sua comissao sera de R$: %.2f", comissao6);
            
        }
    }