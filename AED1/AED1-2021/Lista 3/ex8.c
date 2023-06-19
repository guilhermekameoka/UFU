// Determinar as raízes, reais ou complexas, de uma equação de segundo grau.

#include<stdio.h>
#include<math.h>

    int main (){

        float a, b, c, x1, x2;
        int delta;

        printf("Digite os respectivos a b c da equacao do 2 grau: \n");

        printf("Digite o respectivo a da equacao:");
        scanf("%f", &a);

        printf("Digite o respectivo b da equacao:");
        scanf("%f", &b);

        printf("Digite o respectivo c da equacao:");
        scanf("%f", &c);

        delta = pow(b,2) - (4*a*c);

        printf("delta = %d\n", delta);

        x1 = (-b + sqrt(delta))/2*a;
        x2 = (-b - sqrt(delta))/2*a;   

        if(delta<0){

            printf("As raizes sao %.2f*i e %.2f*i.", x1, x2);

        }else{

            printf ("as raizes da equacao sao %.2f e %.2f.", x1, x2);

        }




    }