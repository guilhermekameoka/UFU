/*Faça um algoritmo que leia o valor de duas variáveis A e B e troque os valores dessas variáveis.
Exemplo de saída:
== Troca do conteúdo de variáveis ==
Entre com o valor de A: 5
Entre com o valor de B: 6
Após a troca, o valor de A é  6 e o de B é  5 */

#include<stdio.h>

int main(){

    int a,b;

    printf("== Troca do conteúdo de variáveis ==\n");
    
    printf("Entre com o valor de A: ");
    scanf("%d",&a);

    printf("Entre com o valor de B: ");
    scanf("%d",&b);

    printf("Apos a troca, o valor de A eh %d e o de B eh %d", b,a);

}
