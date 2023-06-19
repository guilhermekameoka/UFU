/*Faça um algoritmo que realiza a conversão entre de graus Celsius para Fahrenheit e vice-versa.
O usuário deve digitar o valor da temperatura e a unidade de medida usada. O programa se encarrega de converter de uma unidade para a outra. 
Se a unidade digitada não for válida, mostrar uma mensagem de erro.
Exemplo de saída:

<< Conversor de Temperatura >>
Digite a temperatura: 30
Digite a unidade: c
30 graus Celsius equivale a 86 graus Fahrenheit
Exemplo de saída:

<< Conversor de Temperatura >>
Digite a temperatura: 86
Digite a unidade: f
86 graus Fahrenheitequivale a 30 graus Celsius  */

#include<stdio.h>

int main(){

    int t, fahrenheit, celcius;
    char unidade;

    printf("<< Conversor de Temperatura >>\n");

    printf("Digite a temperatura: ");
    scanf("%d", &t);

    setbuf(stdin, NULL);
    printf("Digite a unidade: ");
    scanf("%c", &unidade);

    if(unidade == 'c'){

        fahrenheit = (1.8*t) + 32.0;

        printf("%d graus Celcius equivale a %d Fahenheit", t, fahrenheit);

    }  else if (unidade == 'f'){

        celcius = (t-32)/1.8;

        printf("%d graus Fahrenheit equivale a %d graus Celcius", t, celcius);

    }  else { 

    printf("ERRO: Unidade diferente de C e F");

    }

}