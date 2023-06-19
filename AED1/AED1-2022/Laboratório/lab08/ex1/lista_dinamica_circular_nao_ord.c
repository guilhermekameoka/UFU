#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

// cria_lista() e lista_vazia() sao IGUAIS ao encadeamento simples
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

int insere_final(Lista *lst, int elem)
{

    // Aloca um novo no e preenche campo info
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
    {
        return 0;
    }

    N->info = elem; // insere o elemento

    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N; // Faz o novo no apontar para ele mesmo
        *lst = N;    // Faz a lista apontar para o novo no (ultimo no)
    }
    else
    // Trata lista com 1 ou mais elementos
    {
        N->prox = (*lst)->prox; // Faz o novo no apontar para o primeiro no
        (*lst)->prox = N;       // Faz o ultimo no apontar para o novo no
        *lst = N;               // Faz a lista apontar para o novo no (ultimo no)
    }
    return 1;
}

int remove_inicio(Lista *lst, int *elem)
{

    // Trata lista vazia
    if (lista_vazia(*lst) == 1)
    {
        return 0; // Falha. Nao tem o que remover.
    }

    Lista aux = (*lst)->prox; // Faz aux apontar para o primeiro no
    *elem = aux->info;        // Retorna valor do no a ser removido

    // Trata lista com um UNICO no
    if (*lst == (*lst)->prox)
    {
        *lst = NULL;
    }
    else
    // Trata lista com mais de um elemento
    {
        (*lst)->prox = aux->prox;
        free(aux);
        return 1;
    }
}

void imprime_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}