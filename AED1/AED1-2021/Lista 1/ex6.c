/* A importância de R$ 780.000,00 será dividida entre três ganhadores de um concurso, sendo que da quantia total:
•O primeiro ganhador receberá 46%;
•O segundo receberá 32%;
•O terceiro receberá o restante;
Calcule e imprima a quantia ganha por cada um dos ganhadores.

Exemplo de saída:
<< Loteria >>
Valor total do prêmio: 780000 
Primeiro vencedor: 358800 
Segundo vencedor: 249600
Terceiro vencedor: 171600 */

#include<stdio.h>

int main(){
 int a;
 int b;
 int c;

    printf("<< Loteria >>\n");
    printf("Valo total do premio: 780000\n");
    printf("Primeiro vencedor: %d\n", a = 780000*0.46);
    printf("Segundo vencedor: %d\n", b = 780000*0.32);
    printf("Terceiro vencedor: %d\n", c = 780000*0.22);
}