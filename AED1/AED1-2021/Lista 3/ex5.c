/*Faça um algoritmo que calcule o IMC de uma pessoa e mostre sua classificação de acordo com a tabela abaixo
IMC = massa(kg) / altura (m)2

  IMC            CLASSIFICACAO
<18.5              Magreza
18.5-25.9          Saudavel
25.0 - 29.9        Sobrepeso
30.0-34.9         Obesidade grau I
35.0 - 39.9       Obesidade grau II
>=40.0            Obesidade grau III */

#include<stdio.h>

    int main(){

        float massa, altura, imc;

        printf("Digite sua massa em kg: " );
        scanf("%f", &massa);

        printf("Digite sua alta em metros:" );
        scanf("%f", &altura);

        imc=massa/(altura*altura);

        if(imc<=18.5){

            printf("Classificacao: Magreza");

        } else if(imc>=18.5 && imc<= 24.9){

            printf("Classificacao: Saudavel");

        } else if(imc>=25.0 && imc<= 29.9){

            printf("Classificacao: Sobrepeso");

        } else if(imc>=30.0 && imc<=34.9){

            printf("Classificacao: Obesidade grau I");

        } else if(imc>=35.0 && imc<=39.9){

            printf("Classificacao: Obesidade grau II");

        }else if(imc>=40.0){

            printf("Classificacao: Obesidade grau III (morbida)");

        }
    }