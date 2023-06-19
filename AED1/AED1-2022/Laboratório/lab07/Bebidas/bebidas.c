#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int volume;
    float preco;
    char nome[20];
    struct no *prox;
};

Lista criar_lista()
{
    Lista cab;
    cab = (Lista)malloc(sizeof(struct no));

    if (cab != NULL)
    {
        cab->prox = NULL;
        cab->preco = 0;
        cab->volume = 0;
        *cab->nome = NULL;
    }

    return cab;
}

int lista_vazia(Lista lst)
{
    if (lst == NULL)
        return 1; // Lista vazia

    else
        return 0;
}

int insere_elem(Lista *lst)
{
    // Aloca
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    printf("Digite o nome da bebida: ");
    setbuf(stdin, NULL);
    scanf("%s", N->nome);

    printf("Digite o volume da bebida: ");
    scanf("%d", &N->volume);

    printf("Digite o preco da bebida: R$ ");
    scanf("%f", &N->preco);

    N->prox = (*lst)->prox;
    (*lst)->prox = N;
    return 1;
}

int remove_elem(Lista *lst)
{
    if (lista_vazia(lst) == 1)
        return 0; // Lista vazia

    Lista aux = *lst;

    if (aux->prox == NULL)
    {
        *aux->nome = NULL;
        aux->preco = 0;
        aux->volume = 0;

        free(aux);
        return 1;
    }

    while (aux->prox->prox != NULL)
        aux = aux->prox;

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;

    free(aux2);
    return 1;
}

void obtem_valor_elem(Lista lst)
{
    printf("-----------------");
    printf("\tLista De Bebidas");
    printf("\t-----------------\n");

    int i = 0;
    for (lst; lst != NULL; lst = lst->prox, i++)
    {
        if (lst->nome != NULL && i > 0)
        {
            printf("Bebida: %d\n", i);
            printf("\nNome: %s", lst->nome);
            printf("\nVolume: %d", lst->volume);
            printf("\nPreco: R$%.2f", lst->preco);
        }

        else
            continue;
        printf((lst->prox != NULL) ? "\n\n" : "\n\n-----------------\n\n");
    }
}