#include <stdio.h>

int main()
{

    int i = 0, n, nota[100];
    float media, soma=0;

    printf("<< Media de n alunos. Maximo 100 alunos >>\n");
    printf("Entre com o numero de alunos: ");
    scanf("%d", &n);

    if (n > 100)
    {

        printf("Erro! O numero maximo de alunos permitido eh 100.");
        return 0;
    }

    while (i < n)
    {

        printf("Digite a nota do aluno %d: ", i + 1);
        scanf("%d", &nota[i]);
        i++;
    }

    printf("\nRelatorio de Notas\n");

    for (i = 0; i < n; i++)
    {

        printf("Nota do aluno %d: %d \n", i, nota[i]);
    }

    for (i = 0; i < n; i++)
    {

        soma = nota[i] + soma;
    }
    media = soma / n;

    printf("Media da turma:  %.1f", media);

    return 0;
}

/*
Faça um programa que calcula a média das notas dos alunos de uma turma. Note 
que uma turma pode ter no máximo 100 alunos (mostrar uma mensagem de erro 
caso o número escolhido seja maior que 100). Peça para o usuário entrar com 
o número de alunos e ao final mostre a nota de todos os alunos.

Exemplo de Saída
<< Media de n alunos. Maximo 100 alunos >>
Entre com o numero de alunos: 4
Digite a nota do aluno 1: 6
Digite a nota do aluno 2: 7
Digite a nota do aluno 3: 5
Digite a nota do aluno 4: 4

Relatorio de Notas
Nota do aluno 0: 6
Nota do aluno 1: 7
Nota do aluno 2: 5
Nota do aluno 3: 4
Media da turma:  5.5

------------------------------------
Exemplo de Saída 2
<< Media de n alunos. Maximo 100 alunos >>
Entre com o numero de alunos: 400
Erro! O numero maximo de alunos permitido eh 100.
*/
