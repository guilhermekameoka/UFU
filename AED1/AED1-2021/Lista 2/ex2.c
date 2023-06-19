/*Altere o algoritmo anterior para que, antes de o usuário entrar com as notas do aluno ele entre com a inicial do nome do aluno. Ao final, mostrar a inicial do nome do aluno juntamente com a sua média.
Exemplo de saída:
<< Cálculo da Média >>
Digite o nome do aluno: C
Digite a nota da prova 1: 70
Digite a nota da prova 2: 85
A nota média do aluno C.é 77.5 */

#include<stdio.h>

int main(){

    float n1, n2;
    float media;
    char nome;

    printf("<<Calculo da Media>>\n");

    printf("Digite o nome do aluno: ");
    scanf("%c", &nome);

    printf("Digite a nota da prova 1: ");
    scanf("%f", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%f", &n2);

    media=(n1+n2)/2;

    printf("A nota media do aluno %c. eh %.1f", nome, media);
}

