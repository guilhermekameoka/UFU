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
    // Aloca no cabecalho
    Lista cab;
    cab = (Lista) malloc(sizeof(struct no));

    // Coloca lista no estado de vazia
    if(cab != NULL){  // Se a alocacao nao falahar...
        cab -> prox = NULL;
        cab -> info = 0 // guarda o tamanho da lista
        return cab;
    }
}

int lista_vazia(Lista lst)
{
    if (lst->prox == NULL)
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
    Lista aux = *lst; // faz aux apontar para no cabecalho
    while(aux -> prox != NULL && aux -> prox -> info < elem)
        aux = aux -> prox // avanca

    // insere novo no na lista

    N -> prox = aux -> prox;
    aux -> prox = N
    lst -> info++;
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(lst) == 1)
    {
        return 0; // falha
    }
    Lista aux = *lst; // ponteiro auxiliar para o 1 no

    while (aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    }
    if (aux->prox == NULL || aux -> prox -> info > elem) // trata o final da lista
        return 0;          // falha
    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    (*lst)->info-- // decrementa o tamanho da lista
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
