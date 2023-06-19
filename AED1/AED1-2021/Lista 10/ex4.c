#include <stdio.h>

int main()
{
    int val[5] = {2, 4, 5, 8, 10}, i;
    int *end_val;

    end_val = &val;

    for (i = 0; i < 5; i++)
    {
        end_val[i] = end_val[i] - 1;
    }

    for (i = 0; i < 5; i++)
    {
        printf("%d ", end_val[i]);
    }
}