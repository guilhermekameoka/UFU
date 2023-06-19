#include <stdio.h>
#include <string.h>

struct eletrodomestico
{
    char nome[15];
    float pot, tempo;
};

int main()
{
    int i, dia;
    struct eletrodomestico eletro[5];
    float consumo[5], consumototal = 0, calc;

    for (i = 0; i < 5; i++)
    {
        printf("Entre com o nome do eletrodomestico %d: ", i + 1);
        setbuf(stdin, NULL);
        gets(eletro[i].nome);
        printf("Entre com a potencia: ");
        scanf("%f", &eletro[i].pot);
        printf("Entre com o tempo de uso diario (horas):  ");
        scanf("%f", &eletro[i].tempo);

        consumo[i] = eletro[i].pot * eletro[i].tempo;
        consumototal = consumototal + consumo[i];
    }

    printf("\nEntre com o numero de dias de uso: ");
    scanf("%d", &dia);

    printf("Consumo total no periodo: %.1f kWh\n", consumototal * dia);

    calc = ((consumo[i] * dia) / (consumototal * dia)) * 100.0;

    for (i = 0; i < 5; i++)
    {
        printf("Consumo relativo do(a) %s: %.1f%%\n", eletro[i].nome, calc);
    }
}
