#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

Lista cria_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // Lista esta vazia

    else
        return 0; // Lista nao esta vazia
}

int insere_final(Lista *lst, int elem)
{
    Lista N = (Lista) malloc(sizeof(struct no));

    if (N == NULL)
        return 0;   // No nao alocado
    N->info = elem; // Insere elemento

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }

    else
    {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }

    return 1;
}

int remove_inicio(Lista *lst, int *elem)
{
    if (lista_vazia(*lst) == 1)
        return 0; // ListaVazia

    Lista aux = (*lst)->prox;
    *elem = aux->info;

    if (*lst == (*lst)->prox)
        *lst = NULL;

    else
        (*lst)->prox = aux->prox;
    free(aux);
    return 1;
}

int insere(Lista *lst, int elem)
{
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0; // No nao alocado

    N->info = elem; // Insere elemento

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }

    else
    {
        N->prox = (*lst)->prox;
        *lst = N;
    }

    return 1;
}

int insere_posicao(Lista *lst, int elem, int pos)
{
    int loc = 0;

    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0; // No nao alocado

    N->info = elem; // Insere elemento

    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }

    else
    {
        Lista aux = *lst;

        // Busca a posicao
        while (aux->prox != NULL && pos != loc)
        {
            N = N->prox;
            loc++;
        }

        if (N->prox == NULL)
        {
            printf("\nposicao inexistente.");
            return 0;
        }

        N->prox = aux->prox;
        aux->prox = N;
    }

    return 1;
}

int remove_posicao(Lista *lst, int pos)
{
    int loc = 0;

    if (lista_vazia(*lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no
    // trata elemento = 1 no da lista
    if (pos == 0)
    {
        *lst = aux->prox; // lista aponta para o 2 no
        free(aux);
        return 1;
    }

    // percorrimento ate o final da lista ou ate achar a posicao
    while (aux->prox != NULL && pos != loc)
    {
        aux = aux->prox;
        loc++;
    }

    if (aux->prox == NULL) // trata o final da lista
        return 0;          // falha

    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    return 1;
}

int tamanho(Lista *lst)
{
    int tam = 0;

    Lista aux = *lst; // ponteiro auxiliar

    while (aux->prox != NULL)
    {
        aux = aux->prox; // atual no da list
        tam++;
    }

    return tam + 1;
}

int maior_elem(Lista *lst)
{
    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst; // ponteiro auxiliar
    int maior = aux->info;

    if (aux->prox == NULL)
    {
        maior = aux->info; // atual no da list
        return maior;
    }

    for (aux->prox; aux->prox != NULL; aux = aux->prox)
    {
        if (aux->info > maior)
            maior = aux->info;
    }

    printf("\nO maior eh: %d\n", maior);

    return maior;
}

int remover_pares(Lista *lst)
{
    int R;

    if (lista_vazia(*lst) == 1)
        return 0; // ListaVazia

    else
    {
        Lista aux = (*lst)->prox;

        for (aux->prox; aux->prox != NULL; aux = aux->prox)
            if (aux->info % 2 == 0)
                break;

        if (*lst == (*lst)->prox)
            *lst = NULL;

        else
            (*lst)->prox = aux->prox;

        free(aux);

        R = remover_pares(lst);
        return R;
    }       
    return 1; // sucesso
}
