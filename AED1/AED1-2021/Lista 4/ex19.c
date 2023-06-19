#include <stdio.h>

int main()
{
    float jose = 50000, carlos = 25000;
    int mes = 0, ano;

    while (jose > carlos)
    {
        jose = jose + 800;
        carlos = carlos + 3000;
        mes++;
    }
    ano = mes / 12;
    printf("Levara(ao) %d ano(s) para que Carlos fique com mais dinheiro que Jose\n", ano);
}