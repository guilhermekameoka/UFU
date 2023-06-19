#include <stdio.h>
#include <stdlib.h>
#include "lista_din_ord.h"

struct no
{
    int info;
    struct no *prox;
};

Lista criar_lista()
{
    return NULL;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0; // lista nao vazia
    }
}
/*void lista_cheia(){
 na pratica, tamanho da lista � limitado pelo espaco de memoria
 fazemos a verificacao durante a inserecao */

int insere_ord(Lista *lst, int elem)
{
    // aloca um novo no
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0; // falha: no nao alocado
    }
    N->info = elem;
    if (lista_vazia(*lst) || elem <= (*lst)->info)
    {
        N->prox = *lst; // aponta para o 1o no atual da lista
        *lst = N;       // faz a lista apontar para o novo no
        return 1;
    }
    // percorrimento da lista (elem > 1o no da lista)
    Lista aux = *lst; // faz o aux apontar para o 1o no
    while (aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox; // avanca
    }
    // insere o novo elemento na lista
    N->prox = aux->prox;
    aux->prox = N;
    return 1;
}

int remove_ord(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1 || elem < (*lst)->info)
    {
        return 0; // falha
    }
    Lista aux = *lst; // ponteiro auxiliar para o 1 no
    // trata elemento = 1 no da lista
    if (elem == (*lst)->info)
    {
        *lst = aux->prox; // lista aponta para o 2 no
        free(aux);
        return 1;
    }
    // percorrimento ate o final da lista, ate achar o elemento ou um no maior
    while (aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL || aux->prox->info < elem) // trata o final da lista
        return 0;                                    // falha
    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    return 1;
}

void obtem_valor_elem(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}