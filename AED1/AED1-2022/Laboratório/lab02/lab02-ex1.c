#include <stdio.h>

int main (){

int a = 40;
int *p;
p = &a;

printf("O endereco de 'a' eh: %d\n", &a); // mostra o endereco de 'a' usando o operador &
printf("O endereco de 'a' eh: %d\n", p); //mostra o endereco de 'a' usando ponteiro

printf("Digite um novo valor para a variavel 'a': ");
scanf("%d", p);
printf("O novo valor de 'a' eh: %d\n", a);
}





