#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define max 20

struct fila
{
    int vet[max];
    int ini, cont;
};

Fila criar_fila()
{
    Fila f = (Fila)malloc(sizeof(struct fila));

    if (f != NULL)
    {
        f->ini = 0;
        f->cont = 0;
    }

    return f;
}

int fila_vazia(Fila f)
{
    if (f->cont == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int fila_cheia(Fila f)
{
    if (f->cont == max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insere_final(Fila f, int elem)
{
    if (fila_cheia(f) == 1)
    {
        return 0;
    }
    f->vet[(f->ini + f->cont) % max] = elem;
    f->cont++;
    return 1;
}

int remove_inicio(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
    {
        return 0;
    }
    *elem = f->vet[f->ini];
    f->ini = (f->ini + 1) % max;
    f->cont--;
    return 1;
}

int le_final(Fila f)
{
    if (fila_vazia(f))
    {
        return 0;
    }
    else
    {
        printf("\nElemento: {%d}\n", (f)->vet[(f)->cont - 1]);
    }
}

int mostrar_fila(Fila f)
{
    if (fila_vazia(f))
    {
        return 0;
    }
    else
    {
        printf("\nFila: {");
        for (int i = f->ini; i < f->cont; i++)
        {
            if (i + 1 != f->cont)
            {
                printf("%d, ", f->vet[i]);
            }
            else
            {
                printf("%d}", f->vet[i]);
            }
        }
    }
}