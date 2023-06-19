#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
    struct no *ant;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insere_elemento(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    N->info = elem;

    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->ant = NULL;
        N->prox = *lst;
        if (lista_vazia(*lst) == 0)
            (*lst)->ant = N;

        *lst = N;
    }

    else
    {
        Lista aux = *lst;

        while (aux->prox != NULL && aux->prox->info < elem)
            aux = aux->prox; // avanca

        // insere o novo elemento na lista
        N->ant = aux;
        N->prox = aux->prox;
        aux->prox = N;
        return 1;
    }
    return 1;
}

int remove_elemento(Lista *lst, int elem)
{
    if (lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    while (aux->prox != NULL && aux->info != elem)
        aux = aux->prox;

    if (aux->info != elem || aux->prox == NULL || aux->prox->info > elem) // trata o final da lista
        return 0;                                                         // falha

    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant;

    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox;

    if (aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

void imprime_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}
