#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 
int main(void)
{
    int i;
    printf("intervalo da rand: [0,%d]\n", RAND_MAX);
 
    for(i=1 ; i <= 10 ; i++) 
        printf("Numero %d: %d\n",i, rand()%100);
 
}
