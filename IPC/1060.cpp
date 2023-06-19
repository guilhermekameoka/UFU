// 1060

#include <stdio.h>

    int main(){

        int i=0, cont=0;
        double n;

        while(i<6){
            scanf("%lf", &n);
            if(n>0){
                cont++;
            }
            printf("%d valores positivos\n", cont);
        }
        

    }