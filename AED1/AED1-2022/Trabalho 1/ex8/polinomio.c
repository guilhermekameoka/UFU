#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "polinomio.h"

struct no
{
    // P(x) = a*x^n
    int info; // Valor  de a;
    int pot;  // Valor de n;
    struct no *prox;
};

int lista_vazia(Polinomio p)
{
    if (p == NULL)
    {
        return 1; // lista vazia
    }
    else
    {
        return 0; // lista nao vazia
    }
}

int cria_polinomio()
{
    // Aloca memoria
    Polinomio p = (Polinomio)malloc(sizeof(struct no));

    if (p == NULL)
    {
        return 0; // Falha na alocacao de memoria
    }
    else
    {
        //  Atribui valores aos campos info e pot P(x) = 0
        p->info = 0; // a = 0
        p->pot = 0;  // n = 0
        p->prox == NULL;
        return 1; // Sucesso
    }
}

int insere_termo(Polinomio *p, int a, int pot)
{
    Polinomio aux = *p;

    while (aux->prox != NULL)
    {
        aux = aux->prox; // avanca
    }

    // Se encontrar a memsma potencia ja existir, somar os termos ao inves de adicionar um novo no
    if (aux->prox->pot == pot)
    {
        (*p)->prox->info += aux->prox->info; // Soma a
        (*p)->prox->pot += aux->prox->pot;   // Soma os expoentes
        return 1;
    }
    else
    {
        // Cria um novo no
        Polinomio N = (Polinomio)malloc(sizeof(struct no));

        if (N == NULL)
        {
            return 0; // Falha: no nao alocado
        }

        // Se P(x)= 0
        if ((*p)->prox == NULL && (*p)->pot == 0 && (*p)->info == 0)
        {
            (*p)->prox = N; // Faz p->prox apontar para o novo no
            N->info = a;    // Recebe valor de a
            N->pot = pot;   // Recebe valor do expoente
            N->prox = NULL; // Faz o novo no apontar para null
            return 1;
        }
    }
}

int elimina_termo(Polinomio *p, int numero)
{
    if (lista_vazia(p) == 1)
    {
        return 0; // falha
    }

    Polinomio aux = *p;

    // Percorre a lista ate achar a o no a ser removido
    while (aux->prox != NULL && aux->prox->pot != numero)
    {
        aux = aux->prox; // Avanca
    }

    // Nao encontrou o no a ser removido
    if (aux->prox == NULL)
    {
        return 0;
    }

    Polinomio aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox;     // retira no da lista
    free(aux2);                 // libera memoria alocada
    return 1;
}

void imprime_polinomio(Polinomio p)
{
    printf("P(x) = ");

    for (p; p != NULL; p = p->prox)
    {
        // +a +exp
        if (p->info >= 0 && p->prox->info >= 0)
        {
            printf("+%dx^%d + ", p->info, p->pot);
        }
        // +a -exp
        else if (p->info >= 0 && p->prox->info < 0)
        {
            printf("+%dx^%d - ", p->info, p->pot);
        }
        // -a -exp
        else if ((p->info < 0 && p->prox->info < 0))
        {
            printf("-%dx^%d - ", p->info, p->pot);
        }
        // -a +exp
        else if ((p->info < 0 && p->prox->info >= 0))
        {
            printf("-%dx^%d + ", p->info, p->pot);
        }
    }
}

Polinomio reinicializar_polinomio(Polinomio p)
{
    free(p); // libera o polinomio

    Polinomio px;
    px = cria_polinomio(); // Inicializa um novo polinomio P(x) = 0
    return px;
}

int calcula_polinomio(Polinomio *p, int x)
{
    int resultado = 0;

    if (p == NULL)
    {
        return 0; // Falha
    }

    Polinomio aux = *p;
    while (aux->prox != NULL)
    {
        aux = aux->prox; // avanca
        resultado += ((*p)->info) * pow(x, ((*p)->pot));
    }
    printf("P(x) = %d", resultado);
    return resultado;
}
