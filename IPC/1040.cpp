// 1040

#include <stdio.h>

    int main(){

        double n1, n2, n3, n4, media, notaexame, notafinal;
        scanf("%lf %lf %lf %lf", &n1, &n2, &n3, &n4);
        media=((n1*2)+(n2*3)+(n3*4)+n4)/4;
        if(media<5){
            printf("Aluno reprovado\n");
        }
        else if(media>=5 && media<=6.9){
            printf("Aluno em exame\n");
        }

    }