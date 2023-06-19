#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

#define max 20

struct pilha
{
    int info;
    struct pilha *prox;
};

Pilha cria_pilha()
{
    return NULL;
}

int pilha_vazia(Pilha p)
{
    if (p == NULL)
        return 1;
    else
        return 0;
}

int empilha(Pilha *p, int elem)
{
    Pilha topo = (Pilha)malloc(sizeof(struct pilha));

    if (topo == NULL)
        return 0;

    topo->info = elem;
    topo->prox = *p;
    *p = topo;

    return 1;
}

int desempilha(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return 0;

    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);

    return 1;
}

int le_topo(Pilha *p, int *elem)
{
    if (pilha_vazia(*p))
        return 0;

    Pilha aux = *p;

    while (aux->prox != NULL)
        aux = aux->prox;

    *elem = (*p)->info;
    return 1;
}

int imprimir(Pilha p)
{
    if (pilha_vazia(p) == 0)
    {
        printf("Pilha: {");
        for (p; p != NULL; p = p->prox)
            printf((p->prox != NULL) ? "%d, " : "%d}", p->info);

        return 1;
    }

    else
        return 0;
}

void empilha1(Pilha *p, int elem)
{
    Pilha topo = (Pilha)malloc(sizeof(struct pilha));

    if (topo == NULL)
        return;

    topo->info = elem;
    topo->prox = *p;
    *p = topo;
}

void desempilha1(Pilha *p, int *elem)
{
    if (pilha_vazia(*p) == 1)
        return;

    Pilha aux = *p;
    *elem = aux->info;
    *p = aux->prox;
    free(aux);
}

int elimina(Pilha *p, int *elem)
{

    int i, j = 0, elem1, num, k = 0;

    printf("\nDigite o elem: ");
    scanf("%d", &num);

    Pilha aux = *p;

    // Verifica pilha vazia
    if (aux == NULL || pilha_vazia(*p) == 1)
        return 0;

    // Encontra elemento
    while (aux->prox != NULL && num != aux->prox->info)
        break;

    // Verifica elemento existe ou nao
    if (aux->prox == NULL)
        return 0;

    // desempilha e empilha no aux
    for (aux; num != aux->prox->info; aux = aux->prox)
    {
        desempilha1(&(*p), &elem1);
        empilha1(&aux, elem1);
        k++;
    }

    // Elimina o elemento desejado
    desempilha1(&(*p), &elem1);

    printf("\nSUCESSO!\n");


    // empilha novamente em p
    for (int j = 0; j < k; j++)
    {
        desempilha1(&aux, &elem1);
        empilha1(&(*p), elem1);
    }

    *elem = num;
    return 1;
}

int palindromo(char *vet)
{

    int len, mid, elem, i;

    Pilha p;
    p = cria_pilha();

    len = strlen(vet);
    mid = len / 2;

    for (i = 0; i < mid; i++)
        empilha1(&p, vet[i]);

    i = ((len % 2) != 0) ? i + 1 : i;

    while (vet[i] != '\0')
    {
        desempilha1(&p, &elem);

        if (elem != vet[i])
            return 0;

        i++;
    }

    return 1;
}

int par_e_impar(void)
{
    int i, p[max];

    printf("\n\nDigite a quantidade de inteiros: ");
    scanf("%d", &i);

    if (i > (2 * max))
        return 0;

    // Digitando a seq de inteiros
    for (int j = 0; j < i; j++)
    {
        printf("\n%d digito: ", j + 1);
        scanf("%d", &p[j]);
    }

    Pilha par, imp;
    par = cria_pilha();
    imp = cria_pilha();

    // Organizando | Desempilhando para pares e impares
    for (int j = 0; j < i; j++)
    {

        // Caso seja par
        if (p[j] % 2 == 0)
            empilha1(&par, p[j]);

        // Caso seja impar
        else
            empilha1(&imp, p[j]);
    }

    // Mostrando ambas as pilhas
    printf("\nPilha par\n");
    imprimir(par);

    printf("\n\nPilha impar\n");
    imprimir(imp);

    return 1;
}
