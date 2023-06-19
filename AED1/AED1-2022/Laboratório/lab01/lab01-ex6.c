#include <stdio.h>

int main()
{

    int fat = 1;

    for (int n = 1; n <= 10; n++)
    {
        fat = fat * n;
        printf("%d! = %d\n", n, fat);
    }

    return 0;
}