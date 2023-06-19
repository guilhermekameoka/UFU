/* Ler o comprimento dos três lados de um triângulo (A,B,C) e determinar o tipo de triângulo, com base nos seguintes casos:

(i)Se algum dos lados for maior que a soma dos outros dois, nenhum triângulo é formado
(ii)Se A2 = B2 + C2 é   formando um triângulo retângulo
(iii)Se A2 > B2 + C2 é formando um triangulo obtusângulo
(iv)Se A2 < B2 + C2 é formando um triangulo acutângulo
Caso um número negativo seja digitado, mostrar uma mensagem de erro */

#include<stdio.h>


    int main(){

        float cateto1, cateto2, hipotenusa, casoii, casoiii, casoiv;

        printf("Digite os lados do triangulo:\n");

        printf("hipotenusa: ");
        scanf("%f", &hipotenusa);
        printf("\n");

        printf("cateto1: ");
        scanf("%f", &cateto1);
        printf("\n");

        printf("cateto2: ");
        scanf("%f", &cateto2);
        printf("\n");

        casoii = pow(hipotenusa,2) == pow(cateto1,2) + pow(cateto2,2);
        casoiii = pow(hipotenusa,2) > pow(cateto1,2) + pow(cateto2,2);
        casoiv = pow (hipotenusa,2) < pow(cateto1,2) + pow(cateto2,2);

            if (hipotenusa<0 || cateto1<0 || cateto2<0){

            printf("ERRO: Um numero negativo foi digitado!");

        }    else if(cateto1>cateto2+hipotenusa || cateto2>hipotenusa+cateto1 || hipotenusa>cateto1+cateto2){

            printf("Nenhum triangulo eh formado.");

        }   else if(casoii){

            printf("O triangulo formado eh um triangulo retangulo");

        }    else if(casoiii){

            printf("O triangulo formado eh um tiangulo obtusangulo");
        
        }   else if (casoiv){

            printf("O triangulo formado eh um triangulo acutangulo");

        }

    }