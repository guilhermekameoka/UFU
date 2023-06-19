/* Três amigos jogaram na loteria. Caso eles ganhem, o prêmio deve ser repartido proporcionalmente ao valor que cada deu para a realização da aposta. 
Faça um programa que lê quanto cada apostador investiu, lê o valor do prêmio, e escreve quanto cada um ganharia. 

<< Loteria >>
Bolão jogador 1 R$: 3
Bolão jogador 2 R$: 3
Bolão jogador 3 R$: 4
Informe o valor do prêmio: 6000.0 
Jogador 1 receberá R$: 1800.0
Jogador 2 receberá R$: 1800.0
Jogador 3 receberá R$: 2400.0 */

#include<stdio.h>

int main(){

    float a,b,c,total,valora,valorb,valorc;
    float premio;

    printf("Bolao jogador 1 R$: ");
    scanf("%f", &a);
    printf("Bolao jogador 2 R$: ");
    scanf("%f", &b);
    printf("Bolao jogador 3 R$: ");
    scanf("%f", &c);

    printf("Informe o valor do premio: ");
    scanf("%f", &premio);

    total=a+b+c;
    valora=(a/total)*premio;
    valorb=(b/total)*premio;
    valorc=(c/total)*premio;

    printf("Jogador 1 recebera R$: %.1f\n", valora);
    printf("Jogador 2 recebera R$: %.1f\n", valorb);
    printf("Jogador 3 recebera R$: %.1f\n", valorc);

}


