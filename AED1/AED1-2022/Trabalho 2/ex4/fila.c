#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define max 20

struct fila
{
    int vetor[max]; // max = 20
    int ini;        // inicio
    int fim;        // fim
    int qnt;        // quantidade
};

Fila cria_fila()
{
    // Aloca memoria
    Fila f = (Fila)malloc(sizeof(struct fila));

    // Se a alocacao der certo:
    if (f != NULL)
    {
        // atribui fila no estado de vazia (ini = fim)
        f->ini = 0; // atribui inicio = 0
        f->fim = 0; // atribui fim = 0
        f->qnt = 0; // atribui qnt = 0
    }
    return f;
}

int fila_vazia(Fila f) // verifica se ini = fim
{
    if (f->ini == f->fim)
    {
        return 1; // fila vazia
    }
    else
    {
        return 0; // fila nao vazia
    }
}

int fila_cheia(Fila f) // verifica se a fila esta cheia (ini = fim + 1)
{
    if (f->ini == (f->fim + 1) % max)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int insere_fim(Fila f, int elem) // insere no final e incrementa o campo fim
{
    if (f == NULL || fila_cheia(f) == 1)
    {
        return 0; // fila nao alocada ou fila cheia!
    }

    f->vetor[f->fim] = elem;     // insere no final do vetor
    f->fim = (f->fim + 1 % max); // incremento circular
    f->qnt++;                    // incrementa a quantidade
    return 1;
}

int remove_ini(Fila f, int *elem) // retorna o elemento removido do inicio  e incrementa o campo ini
{
    if (f == NULL || fila_vazia(f) == 1)
    {
        return 0; // fila nao alocada ou fila vazia!
    }

    *elem = f->vetor[f->ini];    //  elemento a ser remomvido
    f->ini = (f->ini + 1) % max; // incremento circular
    f->qnt--;                    // decrementa a quantidade
    return 1;
}

void imprime_fila(Fila f)
{
    if (f == NULL || fila_vazia(f) == 1)
    {
        printf("ERRO: Fila vazia ou nao alocada !");
        return; // fila nao alocada ou vazia
    }

    printf("Fila: { ");

    int i;

    for (i = 0; i < f->qnt; i = (i + 1) % max)
    {
        printf((i != f->qnt - 1) ? "%d, " : "%d }", f->vetor[i]);
    }
}
