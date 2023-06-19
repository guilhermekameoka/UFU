#include <stdio.h>
#include <stdlib.h>
#include "lista_din_nao_ord.h"

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

int insere_elem(Lista *lst, int elem)
{
    // aloca um novo no
    Lista N = (Lista)malloc(sizeof(struct no));
    if (N == NULL)
    {
        return 0; // falha: no nao alocado
    }
    // preenche os campos do novo no
    N->info = elem; // insere o conteudo
    N->prox = *lst; // aponta para o 1 no atual da lista
    *lst = N;       // faz a lista apontar para o novo no
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1)
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
    while (aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL) // trata o final da lista
        return 0;          // falha
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