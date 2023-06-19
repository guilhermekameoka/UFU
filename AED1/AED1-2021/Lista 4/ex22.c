/* Altere o programa anterior para calcular o10! até 15!. É esperado que ocorra um erro. 
Explique o motivo do erro e qual a solução.
Exemplo de saída:
<< Fatorial >>
11 ! = 39 916 800
12 ! = 479 001 600
13 ! = 6 227 020 800
14 ! = 87 178 291 200
15 ! = 1 307 674 368 000
*/

#include <stdio.h>

int main() {


    long long int fatorial=1;
    long long int i;

    printf ("<< Fatorial >>\n");

    for (i = 1; i < 16; i++)
    {
        
        fatorial = i*fatorial;
        
        printf ("%lld! = %lld\n", i, fatorial);
    } 

}

// O motivo do erro é a limitação do int que estoura o valor da memoria. Já o long int consegue armazenar valores maiores que o int.