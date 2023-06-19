#include <stdio.h>
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

int mostra_pilha(Pilha p)
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

void mostra_conv(Pilha p)
{
    printf("Binario: [");
    for (int i = p->topo; i >= 0; i--)
        printf((i != 0) ? "%d" : "%d]", p->vetor[i]);
}

int decimal_binario(Pilha p)
{
    int dec = 0, tam = 0, rest;

    Pilha bin;
    bin = cria_pilha();

    if (pilha_vazia(p))
        return 0;

    // Acumulando o numero decimal
    for (int i = 0; i <= p->topo; i++)
        dec = p->vetor[i] + dec;

    rest = dec; // Passando o valor para calcular o tam.

    // Mensura o Tamanho do binario
    while (rest != 1 && rest != 0)
    {
        if (rest % 2 != 0)
            rest--;

        rest = rest / 2;
        tam++;
    }

    // Conversão
    for (int i = 0; i <= tam; i++)
    {
        // Caso esteja Par
        if (dec % 2 == 0)
            empilha(bin, 0);

        // Caso esteja impar
        else
        {
            dec--;
            empilha(bin, 1);
        }

        dec = dec / 2;
    }

    mostra_conv(bin);

    return 1;
}