/*Faça um algoritmo que calcule a média ponderada das notas de 3 provas.
A primeira e a segunda prova têm peso 1 e a terceira tem peso 2.
Antes de o usuário entrar com as notas do aluno ele deve informar a letra inicial do nome do aluno.
Ao final, mostrar o a letra inicial do nome do aluno juntamente com a sua média.

Exemplo de saída:
<< Cálculo da Média >>
Digite o nome do aluno: T 
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota média do aluno T.é 60 */

#include<stdio.h>

int main(){

    float n1, n2, n3;
    float media;
    int peso1, peso2, peso3;
    char nome;

    printf("<<Calculo da Media>>\n");

    printf("Digite a inicial do nome do aluno: ");
    scanf("%c", &nome);

    printf("Digite a nota da prova 1: ");
    scanf("%f", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &n2);

    printf("Digite a nota da prova 3: ");
    scanf("%f", &n3);

    printf("Digite o peso da prova 1: ");
    scanf("%d", &peso1);

    printf("Digite o peso da prova 2: ");
    scanf("%d", &peso2);

    printf("Digite o peso da prova 3: ");
    scanf("%d", &peso3);

    media=((n1*peso1) + (n2*peso2) + (n3* peso3))/(peso1 + peso2 + peso3);

    printf("A nota media do aluno %c. eh %.2f", nome, media);
}


