/*Faça um programa que tem como entrada as iniciais do nome de três alunos e suas respectivas notas.
Ao final, o programa deve mostrar o nome e a nota do aluno que tirou a maior nota e o nome e a nota do aluno que tirou a menor nota (em caso de notas iguais mostrar somente um nome).

Exemplo de saída:
<< Notasda Turma >>
Entre com o nome do aluno #1: M
Entre com a nota do aluno #1:  10.0
Entre com o nome do aluno #2: J
Entre com a nota do aluno #2: 6.5
Entre com o nome do aluno #3: R
Entre com a nota do aluno #3: 7.0
M. tem a maior nota (10.0) e J. a menor (6.5) */

#include<stdio.h>

    int main(){

        char a, b, c;
        float na, nb, nc;

        printf("<< Notas da Turma >>\n");

        setbuf(stdin, NULL);
        printf("Entre com o nome do aluno #1: ");
        scanf("%c", &a);
        printf("Entre com a nota do aluno #1: ");
        scanf("%f", &na);

        setbuf(stdin, NULL);
        printf("Entre com o nome do aluno #2: ");
        scanf("%c", &b);
        printf("Entre com a nota do aluno #2: ");
        scanf("%f", &nb);

        setbuf(stdin, NULL);
        printf("Entre com o nome do aluno #3: ");
        scanf("%c", &c);
        printf("Entre com a nota do aluno #3: ");
        scanf("%f", &nc);

    if(na>nb && nb>nc){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", a, na, c, nc);

    } else if(na>nc && nc>nb){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", a, na, b, nb);

    } else if(nb>na && na>nc){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", b, nb, c, nc);

    } else if(nb>nc && nc>na){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", b, nb, a, na);

    } else if(nc>na && na>nb){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", c, nc, b, nb);

    } else if(nc>nb && nb>na){

        printf("%c tem a maior nota (%.1f) e %c a menor (%.1f)", c, nc, a, na);

    } else if (na==nb && nb==nc){

        printf("%c tem a maior nota (%.1f)", a, na);
    }
}