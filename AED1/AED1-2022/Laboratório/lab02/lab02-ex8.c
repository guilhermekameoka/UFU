#include <stdio.h>

int calcula_area(int x1, int y1, int x2, int y2)
{

    int area;
    area = (x1 - x2) * (y1 - y2);
    if (area < 0)
    {

        return (area * (-1));
    }
    else
    {
        return area;
    }
}

int main()
{
    int x1 = 1, x2 = 4, y1 = 4, y2 = 2, resp;

    resp = calcula_area(x1, y1, x2, y2);
    printf("A area do retangulo definido por (%d,%d) e (%d,%d) eh %d", x1, y1, x2, y2, resp);
}