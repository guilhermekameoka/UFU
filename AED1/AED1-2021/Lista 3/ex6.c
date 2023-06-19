//Verificar se um número inteiro é um quadrado perfeito, exibindo, nos casosafirmativos, sua raiz quadrada 

#include<stdio.h>
#include<math.h>

    int main(){

        int x;
        float y;

        printf("<< Quadrado perfeito >>\n");

        printf("Digite um numero inteiro: ");
        scanf("%d", &x);

        y=sqrt(x);
        
        printf("A raiz quadrada de %d eh: %.2f\n", x, y);

        if(y*y==x){

            printf("%d eh um quadrado perfeito", x);

        }else{

            printf("%d nao eh um quadrado perfeito.", x);
        }
    }