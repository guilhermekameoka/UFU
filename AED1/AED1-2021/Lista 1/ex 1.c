/* Efetuar a leitura de um número real e apresentar o resultado do quadrado desse número.

Exemplo de saída
<< Cálculo da Quadrado de n>>Digite um número: 2.5O valor de 2.5 ao quadrado é 6.25 */

#include <stdio.h>
#include <math.h>

int main(){

float n;

printf("<< Calculo da Quadrado de n>>\n");
printf("Digite um numero: ");
scanf("%f", &n);
printf("O valor de %.2f ao quadrado eh: %.2f", n, pow(n,2));
}
