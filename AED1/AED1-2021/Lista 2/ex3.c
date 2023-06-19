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

    int n1, n2, n3;
    int media;
    char nome;

    printf("<<Calculo da Media>>\n");

    printf("Digite a inicial do nome do aluno: ");
    scanf("%c", &nome);

    printf("Digite a nota da prova 1: ");
    scanf("%d", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%d", &n2);

    printf("Digite a nota da prova 3: ");
    scanf("%d", &n3);


    media=(n1 + n2 + (n3*2))/4;

    printf("A nota media do aluno %c. eh %d", nome, media);
}
