#include <stdio.h>

int main()
{
    int val[5] = {2, 4, 5, 8, 10};
    int *p;

    p = &val;

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", p[i]);
    }
}