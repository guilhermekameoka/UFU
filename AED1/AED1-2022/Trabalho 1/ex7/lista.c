#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

struct no
{
    int info;
    char nome[50];
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

int insere_varios(Lista *lst)
{
    int qtd;
    char nome[50];

    printf("\nQuantos soldados deseja inserir?");
    printf("\nR: ");
    scanf("%d", &qtd);

    printf("\n------------\tINSERINDO\t------------\n");

    for (int i = 0; i < qtd; i++)
    {
        printf("\nDigite o nome do soldado [%d]: ", i + 1);
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);

        if (inserir(&lst, nome, i))
            print("\nSoldado %s inserido com sucesso!\n", &nome);

        else
            printf("\nErro!\n");
    }

    printf("\n\n------------\tFIM!!!\t------------");

    return qtd;
}

int insere(Lista *lst, char nome[50], int elem)
{

    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    // Copia elementos para o no
    setbuf(stdin, NULL);
    strcpy(N->nome, nome);

    N->info = elem;

    // Nao ha elementos
    if (lista_vazia(*lst) == 1)
    {
        N->prox = N;
        *lst = N;
    }

    // Existe elementos
    else
    {
        N->prox = (*lst)->prox;
        (*lst)->prox = N;
        *lst = N;
    }

    return 1;
}

int remove(Lista *lst, Eliminado *eli, int elem)
{
    int i = 0;

    if (lista_vazia(*lst) == 1)
        return 0;

    Lista aux = *lst;

    if (elem == (*lst)->info)
    {
        *lst = aux->prox;
        free(aux);
        return 1;
    }

    // Percorre até a posicao do elemento
    while (aux->prox->info != elem && i < elem)
    {
        aux = aux->prox;
        i++;
    }

    // Nao existe a posicao elemento na lista
    if (i > elem)
        return 0;

    // Armazena em uma nova lista
    eliminado(&eli, aux->nome, elem);

    Lista aux2 = aux->prox;
    aux->prox = aux2->prox;
    free(aux2);
    return 1;
}

int sortear(Lista *lst, Eliminado *eli, int *qtd)
{
    int op, ger, elem;
    int sold;
    char nome[50];

    printf("\n------------\tSORTEIO\t------------\n");
    printf("\n1- A partir do primeiro soldado");
    printf("\n2- Soldado aleatorio");
    printf("\n3- Informar o nome do soldado");
    printf("\nDigite a sua opcao:");
    scanf("%d", &op);

    // Lista auxiliar
    Lista aux = *lst;

    // Gerando o numero
    ger = gera_numero(qtd);

    if (op == 1)
    {
        printf("\nA partir do primeiro soldado");

        for (int i = 0; i < qtd - 1; i++)
        {
            for (int j = 0; j < ger; j++)
                aux = aux->prox;

            remove(&lst, &eli, aux->info);
        }
    }

    if (op == 2)
    {
        printf("\nSoldado aleatorio");
        sold = gera_numero(ger);

        // Aponta a posicao do no desejado
        for (int i = 0; i < qtd; i++)
        {
            if (aux->info == sold)
                break;
            aux = aux->prox;
        }

        // Continua ate restar 1
        for (int i = 0; i < qtd - 1; i++)
        {
            for (int j = 0; j < ger; j++)
                aux = aux->prox;

            remove(&lst, &eli, aux->info);
        }
    }

    if (op == 3)
    {
        printf("\nInforme o nome do soldado: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nome);

        // Informe o nome do soldado e posiciona
        for (int i = 0; i < qtd; i++)
        {
            if (strcmp(aux->nome, nome) == 0)
                break;
            aux = aux->prox;
        }

        // Continua ate restar 1
        for (int i = 0; i < qtd - 1; i++)
        {
            for (int j = 0; j < ger; j++)
                aux = aux->prox;

            remove(&lst, &eli, aux->info);
        }

        *lst = aux;
    }

    else
    {
        printf("\nOpcao invalida!\n");
        return 0;
    }
}

int gera_numero(int qtd)
{
    int s = rand() % qtd;
}

int eliminado(Eliminado *eli, char nome[50], int elem){
    
    Lista N = (Lista)malloc(sizeof(struct no));

    if (N == NULL)
        return 0;

    // Copia elementos para o no
    setbuf(stdin, NULL);
    strcpy(N->nome, nome);

    N->info = elem;

    // Nao ha elementos
    if (lista_vazia(*eli) == 1)
    {
        N->prox = N;
        *eli = N;
    }

    // Existe elementos
    else
    {
        N->prox = (*eli)->prox;
        (*eli)->prox = N;
        *eli = N;
    }

    return 1;
}
