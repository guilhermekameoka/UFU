// Ler quatro notas e mostrar as notas e a média aritmética obtida.

/* Exemplo de saída: << Média aritmética>>
Digite a 1a nota: 30Digite a 2a nota: 40
Digite a 3a nota: 60
Digite a 4a nota: 30
===Notas==
Nota 1: 30; 
Nota 2: 40; 
Nota 3:60; 
Nota 4: 30
Média:40 */

#include<stdio.h>

int main(){

    int a, b, c, d;

    printf("===Notas==\n");
    printf("Digite a 1a nota: ");
    scanf("%d", &a);  

    printf("Digite a 2a nota: ");
    scanf("%d", &b);

    printf("Digite a 3a nota: ");
    scanf("%d", &c);

    printf("Digite a 4a nota: ");
    scanf("%d", &d);

    printf("===Notas==");
    printf("Nota 1: ", a);
    printf("Nota 2: ", b);
    printf("Nota 3: ", c);
    printf("Nota 4: \n", d);
    printf("Media: %d", (a+b+c+d)/4);

}