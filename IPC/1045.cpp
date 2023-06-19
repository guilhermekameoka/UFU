// 1045

#include <stdio.h>

    int main(){

        double a, b, c;

        scanf("%lf %lf %lf", &a, &b, &c);

        if(a>=b+c){
            printf("NAO FORMA TRIANGULO\n");
        }
        else if((a*a)==(b*b)+(c*c)){
            printf("TRIANGULO RETANGULO\n");
        }
        else if((a*a)>(b*b)+(c*c)){
            printf("TRIANGULO OBTUSANGULO\n");
        }
        else if((a*a)<(b*b)+(c*c)){
            printf("TRIANGULO ACUTANGULO\n");
        }
        else if(a==b && a==c){
            printf("TRIANGULO EQUILATERO\n");
        }
        else if((a==b) || (a==c) || (b==c){
            printf("TRIANGULO ISOCELES\n");
        }
    }