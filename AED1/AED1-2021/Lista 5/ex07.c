#include <stdio.h>

int main()
{

    int nota[5], i, maior, incremento;

    printf("<< Normalizando as notas >>\n");

    for (i = 0; i < 5; i++)
    {

        printf("Entre com a nota do aluno %d: ", i + 1);
        scanf("%d", &nota[i]);
    }
    printf("\nNotas normalizadas\n\n");

    if (nota[0] > nota[1] && nota[0] > nota[2] && nota[0] > nota[3] && nota[0] > nota[4])
    {

        maior = nota[0];
    }
    if (nota[1] > nota[0] && nota[1] > nota[2] && nota[1] > nota[3] && nota[1] > nota[4])
    {

        maior = nota[1];
    }
    if (nota[2] > nota[0] && nota[2] > nota[1] && nota[2] > nota[3] && nota[2] > nota[4])
    {

        maior = nota[2];
    }
    if (nota[3] > nota[1] && nota[3] > nota[2] && nota[3] > nota[0] && nota[3] > nota[4])
    {

        maior = nota[3];
    }
    if (nota[4] > nota[0] && nota[4] > nota[1] && nota[4] > nota[2] && nota[4] > nota[3])
    {

        maior = nota[4];
    }

    incremento = ((100 - maior) / maior) + 1;

    for (i = 0; i <= 4; i++)
    {

        printf("A nota do aluno %d eh %d\n", i+1, nota[i] * incremento);
    }


    return 0;
}

/*
Elabore um algoritmo para normalizar as notas de uma turma de 5 alunos.
A maior nota deve virar 100 e as demais devem ser modificadas 
proporcionalmente (pense em regra de três).

Exemplo de Saída
<< Normalizando as notas >>
Entre com a nota do aluno 1: 16
Entre com a nota do aluno 2: 20
Entre com a nota do aluno 3: 30
Entre com a nota do aluno 4: 45
Entre com a nota do aluno 5: 50

Notas normalizadas

A nota do aluno 1 é 32
A nota do aluno 2 é 40
A nota do aluno 3 é 60
A nota do aluno 4 é 90
A nota do aluno 5 é 100
*/