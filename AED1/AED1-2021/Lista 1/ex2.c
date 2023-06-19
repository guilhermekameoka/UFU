/*Ler uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit. A fórmula de conversão é : F = C ∗ (9.0/5.0)+ 32.0, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius 
Exemplo de saída:
<< Conversor Temperatura>>
Digite a temperatura (em Celsius): 30
30 graus Celsius correspondem a 86 Fahrenheit */

#include<stdio.h>

int main(){

float c;

printf("<< Conversor Temperatura>>\n");
printf("Digite a temperatura (em Celcius): ");
scanf("%f", &c);
printf("%2.f graus em Celcius correspodem a %.2f Fahrenheit", c, c * (9.0/5.0)+ 32.0);


}