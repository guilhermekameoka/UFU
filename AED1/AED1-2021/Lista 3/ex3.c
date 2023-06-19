/*Uma empresa vende o mesmo produto para quatro diferentes estados. Cada estado possui uma taxa diferente de imposto sobre o produto (1-MG 7%; 2-SP 12%; 3-RJ 15%; 4-MS 8%). 
Faça um programa em que o usuário entre com o valor e o código do estado destino do produto e o programa retorne o preço final do produto acrescido do imposto do estado em que ele será vendido. 
Se o código do estado digitado não for válido, mostrar uma mensagem de erro

Exemplo de saída:
<<  Valor do Produto com imposto >>
Digite o valor do produto R$: 100.00
Digite a unidade da federação: 1
Valor final com impostos R$: 107.00 */

#include <stdio.h>

main(){

    float valor;
    int federacao;

    printf("<<Valor do Produto com imposto >>\n");

    printf("Digite o valor do produto R$: ");
    scanf("%f", &valor);

    printf("Digite a unidade da federacao: ");
    scanf("%d", &federacao);

    if(federacao==1){

        printf("Valor final com impostos R$: %.2f", 1.07*valor);

    } else if(federacao==2){

        printf("Valor final com impostos R$: %.2f", 1.12*valor);

    } else if(federacao==3){

        printf("Valor final com impostos R$: %.2f", 1.15*valor);

    } else if(federacao==4){

        printf("Valor final com impostos R$: %.2f", 1.08*valor);

    } else{

        printf("ERRO: Codigo de unidade de federacao nao existente!");
    }

}