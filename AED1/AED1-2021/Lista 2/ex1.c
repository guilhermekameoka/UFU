/*
Faça um algoritmo que calcula a média das notas de 2 provas.
Exemplo de saída
<< Cálculo da Média >>
Digite a nota da prova 1: 80
Digite a nota da prova 2: 90
A nota média é  85 
*/

#include<stdio.h>

int main(){

    int n1, n2, media;

    printf("<<Calculo da Media>>\n");
    
    printf("Digite a nota da prova 1: ");
    scanf("%d", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%d", &n2);

    media=(n1+n2)/2;

    printf("A nota media eh %d", media);
}

