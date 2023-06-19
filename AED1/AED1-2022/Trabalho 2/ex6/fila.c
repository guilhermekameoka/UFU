#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no
{
    int info;
    struct no *prox;
};

struct fila
{
    struct no *ini; // inicio
    struct no *fim; // fim
};

Fila cria_fila()
{
    // Aloca memoria
    Fila f;
    f = (Fila)malloc(sizeof(struct fila));

    // Se a alocacao der certo:
    if (f != NULL)
    {
        // Coloca fila no estado de vazia
        f->ini == NULL;
        f->fim == NULL;
    }
    return f;
}

int fila_vazia(Fila f)
{
    if (f == NULL || f->ini == NULL) // poderia ser f->fim tambem (tanto faz, pois ambos sao NULL quando vazia)
        return 1;                    // vazia

    else
        return 0; // nao vazia
}

int insere_fim(Fila f, int elem)
{
    struct no *N;
    N = (No)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info = elem;
    N->prox = NULL;

    if (fila_vazia(f) == 1)
        f->ini = N;
    else
        (f->fim)->prox = N;

    f->fim = N;
    return 1;
}

int remove_ini(Fila f, int *elem)
{
    if (fila_vazia(f) == 1)
        return 0;

    struct no *aux = f->ini;
    *elem = aux->info;

    if (f->ini == f->fim)
        f->fim = NULL;

    f->ini = aux->prox;
    free(aux);
    return 1;
}

int imprime_fila(Fila f)
{
    if (fila_vazia(f))
        return 0;

    No aux;

    printf("\nFila: {");

    for (aux = f->ini; aux != f->fim; aux = aux->prox)
        printf((aux->prox != f->fim) ? "%d, " : "%d}", aux->info);

    return 1;
}
