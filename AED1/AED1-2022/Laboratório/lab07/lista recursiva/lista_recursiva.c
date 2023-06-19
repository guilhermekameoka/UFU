#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

Lista criar_lista(Lista lst)
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1;
    else
        return 0;
}

void lista_cheia(Lista lst);

int insere_ord(Lista *lst, int elem)
{
    int R;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        Lista N = (Lista)malloc(sizeof(struct no));

        if (N == NULL)
            return 0;

        N->info = elem;
        N->prox = *lst;
        *lst = N;
        return 1;
    }
    else
    {
        R = insere_ord(&(*lst)->prox, elem);
        return R;
    }
}

int remove_ord(Lista *lst, int elem)
{
    int R;
    if (lista_vazia(lst) == 1 || elem < (*lst)->info)
        return 0;

    else
    {
        if (elem == (*lst)->info)
        {
            Lista aux = *lst;
            *lst = aux->prox;
            free(aux);
            return 1;
        }
        else
        {
            R = remove_ord(&(*lst)->prox, elem);
            return R;
        }
    }
}

void obtem_valor_elem(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}