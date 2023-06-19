#include <stdio.h>
#include <stdlib.h>
#include "lista_seq_ordenada.h"

#define max 5
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
        lst->fim = 0; // Se a lista estiver vazia, atribui fim na posicao 0

    else
        return lst;
}

int lista_vazia(Lista lst)
{
    if (lst->fim == 0)
        return 1; // Lista esta vazia, retorna sucesso

    else
        return 0; // Lista nao esta vazia, retorna falha
}

int lista_cheia(Lista lst)
{
    if (lst->fim == max) // compara se o fim esta na ultima posicao do vetor
        return 1;        // lista esta cheia, retorna falha

    else
        return 0; // lista nao esta cheia, retorna sucesso
}

int insere_ord(Lista lst, int elem)
{
    // lista nao existe ou esta cheia
    if (lista_cheia(lst) == 1 || lst == NULL) // lista precisa existir e nao pode estar cheia
        return 0;                             // falha

    // lista esta vazia ou elem >= que o ultimo
    if (lista_vazia(lst) == 1 || elem >= lst->no[lst->fim - 1]) // lista vazia ou elem maior que o ultimo
        lst->no[lst->fim] = elem;                               // insere no final

    else // elem estara entre o 1o e o ultimo elemento da lista
    {
        int i, aux = 0;

        while (elem >= lst->no[aux]) // percorrimento na lista
            aux++;

        for (i = lst->fim; i > aux; i--) // deslocamento
            lst->no[i] = lst->no[i - 1];

        lst->no[aux] = elem; // inclui o elemento na lista
    }

    lst->fim++; // incrementa o fim
    return 1;   // sucesso
}

int insere_inicio(Lista lst, int elem)
{
    if (lst == NULL || lista_cheia(lst) == 1)
    {
        return 0;
    }

    for (int i = lst->fim; i > 0; i--)
    {
        lst->no[i] = lst->no[i - 1];
    }

    lst->fim += 1;
    lst->no[0] = elem;
    return 1;
}

int remove_ord(Lista lst, int elem)
{
    int i, aux = 0;

    if (lst == NULL || lista_vazia(lst) == 1 || elem < lst->no[0] || elem > lst->no[lst->fim - 1])
    {
        return 0; // falha
    }

    // percorre ate achar o elemento ou no maior, ou final da lista
    while (aux < lst->fim && lst->no[aux] < elem)
    {
        aux++;
    }
    if (aux == lst->fim || lst->no[aux] > elem)
    {
        return 0; // falha, elem nao existe
    }

    // deslocamento a esquerda do sucessor ate o final da lsita
    for (i = aux + 1; i < lst->fim; i++)
    {
        lst->no[i - 1] = lst->no[i];
    }
    lst->fim--; // decremento do fim
    return 1;   // sucesso
}

int remove_impares(Lista lst)
{
    int i, aux = 0, R;

    if (lst == NULL || lista_vazia(lst) == 1) // a lista precisa existir e nao pode estar vazia
        return 0;                             // falha

    else
    {
        for (aux; aux < lst->fim; aux++)
            if (lst->no[aux] % 2 == 1)
                break;

        if (aux == lst->fim) // a lista precisa existir e nao pode estar vazia
            return 1;

        for (i = aux + 1; i < lst->fim; i++) // deslocamento a esquerda do sucessor ate o final da lista
            lst->no[i - 1] = lst->no[i];

        lst->fim--; // decrementa o fim

        R = remove_impares(lst);
        return R;
    }
    return 1; // sucesso
}

int menor_elem(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;

    int menor, aux;

    for (aux = 0; aux < lst->fim; aux++)
    {
        if (aux == 0)
            menor = lst->no[aux];

        else if (lst->no[aux] < menor)
            menor = lst->no[aux];
    }

    printf("O menor elemento da lista eh: %d\n", menor);
    return menor;
}

int maior_elem(Lista lst)
{
    if (lst == NULL || lista_vazia(lst) == 1)
        return 0;

    int maior, aux;

    for (aux = 0; aux < lst->fim; aux++)
    {
        if (aux == 0)
            maior = lst->no[aux];

        else if (lst->no[aux] > maior)
            maior = lst->no[aux];
    }

    printf("O maior eh: %d\n", maior);

    return maior;
}

int tamanho(Lista lst)
{
    return lst->fim;
}

int mostrar_lista(Lista lst)
{
    if (lista_vazia(lst) == 1 || lst == NULL)
        return 0;

    int i;
    printf("Lista: {");
    for (i = 0; i < lst->fim; i++)
    {
        if (i + 1 == lst->fim)
            printf("%d}", lst->no[i]);

        else
            printf("%d, ", lst->no[i]);
    }

    return 1;
}

void concatena(Lista *lst)
{
   
    int i = 0, j = 0, elem;
    printf("Insira o tamanho da Lista 1: ");
    scanf("%d", &i);

    printf("Insira o tamanho da Lista 2: ");
    scanf("%d", &j);

    if ((i + j) > max)
    {
        printf("Tamanho maior que max!\n");
        return;
    }

    Lista lst1 = criar_lista();
    Lista lst2 = criar_lista();

    printf("\n\n\tLista 1");
    for (int aux = 0; aux < i; aux++)
    {
        printf("\nDigite o [%d] elemento: ", aux + 1);
        scanf("%d", &elem);
        insere_ord(lst1, elem);
    }

    printf("\n\n\tLista 2");
    for (int aux = 0; aux < j; aux++)
    {
        printf("\nDigite o [%d] elemento: ", aux + 1);
        scanf("%d", &elem);
        insere_ord(lst2, elem);
    }

    // Lista 1
    for (int aux = 0; aux < lst1->fim; aux++)
        insere_ord((*lst), lst1->no[aux]);

    // Lista 2
    for (int aux = 0; aux < lst2->fim; aux++)
        insere_ord((*lst), lst2->no[aux]);

    printf("Lista concatenada com SUCESSO!");

    return;
}

void ordena_lista(Lista *lst)
{
    int elem = 0, aux[max], aux1, j = 0;

    Lista lst1 = *lst;

    // Copia lista para aux
    for (int i = 0; i < (*lst)->fim; i++)
        aux[i] = (*lst)->no[i];

    // Ordena aux
    while (j < (*lst)->fim)
    {
        for (int a = 0; a < (*lst)->fim; a++)
        {
            if (aux[a] < aux[a + 1])
                continue;

            else
            {
                aux1 = aux[a];
                aux[a] = aux[a + 1];
                aux[a + 1] = aux1;
            }
        }
        j++;
    }
    // Lista copia aux
    for (int i = 0; i < (*lst)->fim; i++)
        (*lst)->no[i] = aux[i];

    printf("Lista ordenada com SUCESSO!");
    return;
}
