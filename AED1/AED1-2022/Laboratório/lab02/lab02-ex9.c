#include <stdio.h>

int multiplica_const1(int a, int c)
{
    int resp;

    resp = (a * c);
    return resp;
}

int multiplica_const2(int a, int c)
{
    int resp;

    resp = (a * c);
    return resp;
}
int main()
{

    int x, y, c, resp1, resp2;

    printf("Digite o ponto: ");
    scanf("%d,%d", &x, &y);

    printf("Digite a constante: ");
    scanf("%d", &c);

    resp1 = multiplica_const1(x, c);
    resp2 = multiplica_const2(y, c);
    printf("Resultado: (%d,%d) * %d = (%d,%d)", x, y, c, resp1, resp2);
}