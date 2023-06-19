#include <stdio.h>

int main()
{
    double v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i;

    for (i = 0; i <= 9; i++)
    {
        printf("v[%d]=%.1lf\n", i, *(v + i));
    }
}