#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct no
{
    int info;
    struct no *prox;
};

Lista criar_lista()
{
    // Aloca no cabecalho
    Lista cab = (Lista)malloc(sizeof(struct no));

    // Coloca lista no estado de vazia
    if (cab != NULL)
    { // Se a alocacao nao falahar...
        cab->prox = NULL;
        cab->info = 0; // guarda o tamanho da lista
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
    while (aux->prox != NULL && aux->prox->info < elem)
    {
        aux = aux->prox; // avanca
    }
    N->prox = aux->prox; // insere novo no na lista
    aux->prox = N;
    (*lst)->info++;
    return 1;
}

int remove_elem(Lista *lst, int elem)
{
    if (lista_vazia(*lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para o 1 no

    while (aux->prox != NULL && aux->prox->info != elem)
    {
        aux = aux->prox;
    }

    if (aux->prox == NULL || aux->prox->info > elem) // trata o final da lista
        return 0;                                    // falha

    // remove elemento diferente do 1 no da lista
    Lista aux2 = aux->prox; // aponta no a ser removido
    aux->prox = aux2->prox; // retira no da lista
    free(aux2);             // libera memoria alocada
    (*lst)->info--;         // decrementa o tamanho da lista
    return 1;
}

void imprime_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
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

int tamanho(Lista lst)
{
    if (lista_vazia(lst) == 1 || lst == NULL)
        return 0; // falha
    else
    {
        // printf("O tamanho da lista eh: %d", lst->info);
        return lst->info;
    }
}

int verifica_igual(Lista *lst1, Lista *lst2)
{
    if (lst1 == NULL || lista_vazia(*lst1) == 1 || lst2 == NULL || lista_vazia(*lst2) == 1 || (*lst1)->info < (*lst2)->info || (*lst1)->info > (*lst2)->info)
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

int inverte_lista(Lista *lst)
{
    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0; // falha

    Lista lista = criar_lista(); // aloca mem pra nova_lista
    Lista aux = *lst;

    int max=0, aux1[max], info, i=0;

    // Define o max
    while (aux->prox != NULL)
    {
        aux1[i] = aux->info; // copia
        max++;
        aux = aux->prox; // avanca
    }

    // Insere na nova_lista
    while (max != 0)
    {
        insere_elem(&lista, aux1[max]);
        max--;
    }

    lst = &lista; //NAO SEI

    return 1;
}

Lista gera_impares(Lista *lst)
{
    Lista nova_lista = criar_lista();

    if (lst == NULL || lista_vazia(*lst) == 1)
        return 0; // falha

    Lista aux = *lst; // ponteiro auxiliar para percorrimento da lista

    while (aux->prox != NULL) // percorre ate o fim
    {
        if (aux->info % 2 != 0) // se for impar, adicionar elemento na nova lista...
            insere_elem(&nova_lista, aux->info);

        aux = aux->prox; // avanca
    }
    return nova_lista;
}

int remove_impares(Lista *lst)
{
    int i, aux = 0, R;

    if (*lst == NULL || lista_vazia(*lst) == 1) // a lista precisa existir e nao pode estar vazia
        return 0;                               // falha

    else
    {
        Lista aux = *lst; // ponteiro auxiliar para percorrimento

        for (aux->prox; aux->prox != NULL; aux = aux->prox)
            if (aux->info % 2 == 1)
                break;

        if (aux->prox == NULL) // a lista precisa existir e nao pode estar vazia
            return 1;

        remove_elem(*lst, aux->info);

        R = remove_impares(lst);
        return R;
    }
    return 1; // sucesso
}

void mostra_lista(Lista lst)
{
    printf("Lista: {");
    for (lst; lst != NULL; lst = lst->prox)
    {
        printf((lst->prox != NULL) ? "%d, " : "%d}", lst->info);
    }
}
