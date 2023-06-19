#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define max 20

struct fila
{
    int vetor[max];
    int ini;  // inicio
    int cont; // contador
};

Fila cria_fila()
{
    // Aloca memoria
    Fila f = (Fila)malloc(sizeof(struct fila));

    // Se a alocacao der certo:
    if (f != NULL)
    {
        f->ini = 0;
        f->cont = 0;
    }
    return f;
}

int fila_vazia(Fila f) // verifica se a fila esta vazia (cont = 0)
{
    // INDEPENDE DOS VALORES DE INI E FIM !!
    if (f->cont == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int fila_cheia(Fila f) // verifica se fila esta cheia (cont = max)
{
    if (f->cont == max)
    {
        return 1; // fila cheia !
    }
    else
    {
        return 0;
    }
}

int insere_fim(Fila f, int elem)
{
    if (f == NULL || fila_cheia(f) == 1)
    {
        return 0; // fila nao alocada ou fila cheia!
    }

    f->vetor[(f->ini + f->cont) % max] = elem;
    f->cont++; // incremento normal
    return 1;
}

int remove_ini(Fila f, int *elem) // retorna o valor de elemento removido (inicio)
{
    if (f == NULL || fila_vazia(f) == 1)
    {
        return 0; // fila nao alocada ou fila vazia!
    }

    *elem = f->vetor[f->ini];
    f->ini = (f->ini + 1) % max; // incremento circular
    f->cont--;                   // decremento nao circular
    return 1;
}

void imprime_fila(Fila f)
{
    if (f == NULL || fila_vazia(f) == 1)
    {
        printf("ERRO: Fila vazia ou nao alocada !");
        return; // fila nao alocada ou vazia
    }

    printf("Fila: { ");

    int i;

    for (i = 0; i < f->cont; i = (i + 1) % max)
    {
        printf((i != f->cont - 1) ? "%d, " : "%d }", f->vetor[i]);
    }
}
