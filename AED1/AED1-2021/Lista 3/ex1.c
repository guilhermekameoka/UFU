/*Faça um algoritmo que calcule a média ponderada das notas de 3 provas.
A primeira e a segunda prova têm peso 1 e a terceira tem peso 2.
Antes de o usuário entrar com as notas do aluno ele entre com a inicialdo nome do aluno (mais adiante aprenderemos como entrar com o nome completo do aluno – por enquanto nesta lista vamos identificar o aluno somente com uma letra).
Ao final, mostrar o nome do aluno juntamente com a sua média e indicar se o aluno foi aprovado ou reprovado.

Exemplo de saída:
<< Cálculo da Média >>
Digite a inicial do nome do aluno: T
Digite a nota da prova 1: 40
Digite a nota da prova 2: 40
Digite a nota da prova 3: 80
A nota média do aluno T.é60=> APROVADO! */


#include<stdio.h>

int main(){

    int n1, n2, n3;
    int media;
    char nome;

    printf("<<Calculo da Media>>\n");
    
    setbuf(stdin, NULL);
    printf("Digite a inicial do nome do aluno: ");
    scanf("%c", &nome);

    printf("Digite a nota da prova 1: ");
    scanf("%d", &n1);

    printf("Digite a nota da prova 2: ");
    scanf("%d", &n2);

    printf("Digite a nota da prova 3: ");
    scanf("%d", &n3);


    media=(n1 + n2 + (n3*2))/4;

    if(media>=60){

        printf("A nota media do aluno %c. eh %d ==> APROVADO!", nome, media);
        
    } else{
        
        printf("A nota media do aluno %c. eh %d ==> REPROVADO!", nome, media);
    }

}