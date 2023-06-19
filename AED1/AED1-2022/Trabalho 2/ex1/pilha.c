#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pilha.h"

#define max 20
struct pilha
{
    int vetor[max];
    int topo;
};

Pilha cria_pilha()
{
    Pilha p;
    p = (Pilha)malloc(sizeof(struct pilha));

    if (p != NULL)
        p->topo = -1;
    return p;
}

int pilha_vazia(Pilha p)
{
    if (p->topo == -1)
        return 1;
    else
        return 0;
}

int pilha_cheia(Pilha p)
{
    if (p->topo == max - 1)
        return 1;
    else
        return 0;
}

int empilha(Pilha p, int elem)
{
    if (p == NULL || pilha_cheia(p) == 1)
        return 0;

    p->topo++;
    p->vetor[p->topo] = elem;
    return 1;
}

int desempilha(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return 0;

    *elem = p->vetor[p->topo];
    p->topo--;
    return 1;
}

int le_topo(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p))
        return 0;

    *elem = p->vetor[p->topo];
    return 1;
}

int imprimir(Pilha p)
{
    if (pilha_vazia(p) == 1)
        return 0;

    else
    {
        printf("Pilha: {");
        for (int i = p->topo; i >= 0; i--)
            printf((i != 0) ? "%d, " : "%d}", p->vetor[i]);

        return 1;
    }
}

void empilha1(Pilha p, int elem)
{
    if (p == NULL || pilha_cheia(p) == 1)
        return;

    p->topo++;
    p->vetor[p->topo] = elem;
}

void desempilha1(Pilha p, int *elem)
{
    if (p == NULL || pilha_vazia(p) == 1)
        return;

    *elem = p->vetor[p->topo];
    p->topo--;
}

int elimina(Pilha p, int *elem)
{
    Pilha aux = cria_pilha();

    int i, j = 0, elem1, num, k = 0;

    printf("\nDigite o elem: ");
    scanf("%d", &num);

    // Verifica se elem existe
    while (p->vetor[k] != num && k < max)
        k++;

    // Verifica pilha vazia ou se elem existe
    if (p == NULL || pilha_vazia(p) == 1 || p->vetor[k] != num)
        return 0;

    // desempilha e empilha no aux
    for (i = p->topo; i >= 0; i--)
    {
        desempilha1(p, &elem1);

        if (num == p->vetor[i])
        {
            *elem = num;
            break;
        }

        empilha1(aux, elem1);
        j++;
    }

    // empilha novamente em p
    for (i; i < j; i++)
    {
        desempilha1(aux, &elem1);
        empilha1(p, elem1);
    }

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
        empilha1(p, vet[i]);

    i = ((len % 2) != 0) ? i + 1 : i;

    while (vet[i] != '\0')
    {
        desempilha1(p, &elem);

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
            empilha1(par, p[j]);

        // Caso seja impar
        else
            empilha1(imp, p[j]);
    }

    // Mostrando ambas as pilhas
    printf("\nPilha par\n");
    imprimir(par);

    printf("\n\nPilha impar\n");
    imprimir(imp);

    return 1;
}
