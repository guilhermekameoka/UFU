#include <stdio.h>

int main()
{

    double fat = 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2;

    for (int n = 10; n <= 15; n++)
    {
        fat = fat * n;
        printf("%d! = %.0lf\n", n, fat);
    }

    return 0;
}

/* O motivo do erro é o estouro da memória da tipagem INT. Para resolvermos o problema será necessário utilizar a tipagem DOUBLE para armazenarmos números maiores. */