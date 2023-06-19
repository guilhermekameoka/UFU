#include <stdio.h>

int main()
{

    char nome[] = "Jose Augusto";
    char *p = &nome;

    while (*p != '\0')
    {
        printf("%c", *p);
        p++;
    }
}