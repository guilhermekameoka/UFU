#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *ant;
    struct no *prox;
};

Lista cria_lista()
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

int insere_ord(Lista *lst, int elem)
{
    Lista N = (Lista) malloc(sizeof(struct no));

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

int remove_ord(Lista *lst, int elem)
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

int tamanho(Lista *lst)
{
    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no da lista
    int tam = 0;

    while (aux->prox != NULL) // percorre a lista
    {
        aux = aux->prox;
        tam++;
    }

    printf("O tamanho da lista eh: %d", tam + 1);
    return tam + 1;
}

float media(Lista *lst)
{
    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no da lista
    int ac = aux->info, tam;
    float media;

    while (aux->prox != NULL) // percorre a lista
    {
        aux = aux->prox;
        ac += aux->info;
    }

    tam = tamanho(lst);
    media = ac / tam;

    printf("\nMedia total: %.2f\n", media);

    return media;
}

int iguais(Lista *lst1, Lista *lst2)
{
    if (lst1 == NULL || lista_vazia(*lst1) == 1 || lst2 == NULL || lista_vazia(*lst2) == 1)
        return 0; // falha

    Lista aux = *lst1;  // ponteiro auxiliar para percorrimento da 1 lista
    Lista aux1 = *lst2; // ponteiro auxiliar para percorrimento da 2 lista

    while (aux->prox != NULL && aux->prox->info == aux1->prox->info) // percorre ate o fim
    {
        if (aux->prox == NULL)
            return 1; // sucesso. As listas sao iguais

        else if (aux->prox->info != aux1->prox->info)
            return 0; // falha. listas diferentes

        aux = aux->prox;   // avanca
        aux1 = aux1->prox; // avanca
    }
}

int remove_todos(Lista *lst)
{
    int R;

    if (lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    while (aux->prox != NULL)
        aux = aux->prox;

    if (aux->prox == NULL) 
        return 0;                                                         // falha

    else
    {
        if (aux->prox != NULL)
            (aux)->prox->ant = aux->ant;

        if (aux->ant != NULL)
            (aux)->ant->prox = aux->prox;

        if (aux == *lst)
            *lst = aux->prox;

        free(aux);

        R = remove_todos(lst);
        return R;
    }
    return 1;
}

int remove_maior(Lista *lst)
{
    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst; // ponteiro auxiliar
    int maior = aux->info;

    // Remove apenas 1 elemento
    if (aux->prox == aux)
    {
        maior = aux->info; // atual no da list
        return 1;
    }

    // Encontrando o maior elemento
    for (aux->prox; aux->prox != NULL; aux = aux->prox)
        if (aux->info > maior)
            maior = aux->info;

    // Posiciona a lista
    while (aux->ant != NULL && maior != aux->info)
        aux = aux->ant;

    if (aux->prox != NULL)
        (aux)->prox->ant = aux->ant;

    if (aux->ant != NULL)
        (aux)->ant->prox = aux->prox;

    if (aux == *lst)
        *lst = aux->prox;

    free(aux);
    return 1;
}

void mostra_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}
