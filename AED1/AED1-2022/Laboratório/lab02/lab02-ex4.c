#include <stdio.h>

int main()
{

    int *v[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;

    for (i = 9; i >= 0; i--)
    {
        i > 0 ? printf("%d, ", *(v + i)) : printf("%d ", *(v + i));
    }
}