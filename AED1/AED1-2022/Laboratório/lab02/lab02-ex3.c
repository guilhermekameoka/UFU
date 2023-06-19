#include <stdio.h>

int main(){

double vet[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int i;

for(i = 0; i<10; i++){

  i<9?  printf("%.0f, ", *(vet +i)) : printf("%.0f", *(vet +i));
}
}

