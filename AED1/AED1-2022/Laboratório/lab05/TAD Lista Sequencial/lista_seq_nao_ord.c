#include <stdio.h>
#include <stdlib.h>
#include "lista_seq_nao_ord.h"

#define max 20
struct lista
{
    int no[max];
    int fim;
};

Lista criar_lista()
{
    Lista lst;
    lst = (Lista)malloc(sizeof(struct lista));

    if (lst != NULL)
    {
        lst->fim = 0; // Se a lista estiver vazia, atribui fim na posicao 0
    }
    else
    {
        return lst;
    }
}

int lista_vazia(Lista lst)
{
    if (lst->fim == 0)
    {
        return 1; // Lista esta vazia, retorna falha
    }
    else
    {
        return 0; // Lista nao esta vazia, retorna sucesso
    }
}

int lista_cheia(Lista lst)
{
    if (lst->fim == max) // compara se o fim esta na ultima posicao do vetor
    {
        return 1; // lista esta cheia, retorna falha
    }
    else
    {
        return 0; // lista nao esta cheia, retorna sucesso
    }
}

int insere_elem(Lista lst, int elem)
{
    if (lst == NULL || lista_cheia(lst) == 1) // lista precisa existir e nao pode estar cheia
    {
        return 0; // falha
    }
    else
    {
        lst->no[lst->fim] = elem; // insere elemento na lista
        lst->fim++;               // incrementa o fim
        return 1;                 // sucesso
    }
}

int remove_elem(Lista lst, int elem)
{
    int i, aux = 0;

    if (lst == NULL || lista_vazia(lst) == 1) // a lista precisa existir e nao pode estar vazia
    {
        return 0; // falha
    }

    while ((aux < lst->fim) && (lst->no[aux] != elem)) // percorre a lista ate achar o elem ou o final da lista
    {
        aux++;
    }

    for (i = aux + 1; i < lst->fim; i++) // deslocamento a esquerda do sucessor ate o final da lista
    {
        lst->no[i - 1] = lst->no[i];
    }
    lst->fim--; // decrementa o fim
    return 1;   // sucesso
}

int obtem_valor_elem(Lista lst, int elem)
{
    int aux;

    if (lista_vazia(lst) == 1 || lst == NULL) // lista tem que existir e nao pode estar vazia
    {
        return 0; // Falha
    }

    for (aux = 0; aux <= lst->fim; aux++) // percorre a lista
    {
        if (elem == aux)
        {
            return lst->no[aux]; // Sucesso
        }
        else
        {
            return 0; // Falha
        }
    }
}
