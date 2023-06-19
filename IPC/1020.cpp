//1020

#include <stdio.h>

    int main(){

        int i, anos, meses, dias;
        scanf("%d", &i);
        anos = i/365;
        meses = (i%365)/30;
        dias = (i%365)%30;
        printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n", anos, meses, dias);
    }