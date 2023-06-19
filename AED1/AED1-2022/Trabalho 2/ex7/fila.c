#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct no
{
    int info;
    struct no *prox;
    int qnt;
};

Fila cria_fila()
{
    return NULL;
}

int fila_vazia(Fila f)
{
    if (f == NULL)
    {
        return 1; // fila vazia
    }
    else
    {
        return 0; // fila nao vazzia
    }
}

int insere_fim(Fila *f, int elem)
{
    // Aloca novo no
    Fila N = (Fila)malloc(sizeof(struct no));

    if (N == NULL)
        return 0; // falha: no nao alocado !

    N->info = elem; // preenche campo info com o elemento

    // Trata fila vazia
    if (fila_vazia(*f) == 1)
    {
        N->prox = N; // Faz o novo no apontar para ele mesmo (circular)
        *f = N;      // Faz a fila apontar para o novo no (ultimo)
    }

    else // Trata fila como +1 elemento
    {
        N->prox = (*f)->prox; // Faz o novo no apontar para o 1 no
        (*f)->prox = N;       // Faz o ultimo no apontar para o novo no
        *f = N;               // Faz a FILA apontar para o novo no (ultimo no)
    }

    return 1;
}

int remove_ini(Fila *f, int *elem)
{
    // Trata fila vazia
    if (fila_vazia(*f) == 1)
    {
        return 0; // falha: lista vazia !
    }

    Fila aux = (*f)->prox; // faz aux apontar para o 1 no
    *elem = aux->info;     // retorna o valor do no a ser removido

    // Trata fila com UNICO no
    if (*f == (*f)->prox)
    {
        *f = NULL;
    }
    else // Trata fila com mais de 1 elemento
    {
        (*f)->prox = aux->prox;
        free(aux);
        return 1;
    }
}

void imprime_fila(Fila f)
{
    if (f == NULL || fila_vazia(f) == 1)
        return;

    struct no *aux = f->prox;

    printf("Fila: {");

    while (aux != f)
    {
        printf("%d, ", aux->info);
        aux = aux->prox;
    }

    printf("%d }", f->info);
    return;
}
