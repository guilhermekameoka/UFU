#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Ponto.h"

// Arquivo Ponto.c = Implementacao das funcoes

// Definicao do tipo de dados
struct ponto
{
    float x, y;
};
typedef struct ponto Ponto; // Define apelido para "struct ponto" = Ponto

Ponto *gera_pto() // cria uma instância de um ponto sem valores
{
    Ponto *p;
    // Alocacao dinamica de memoria
    p = (Ponto *)malloc(sizeof(Ponto)); // p é um ponteiro para struct ponto
    return p;
}

int set_pto(Ponto *p, float x, float y) // atribui os valores das coordenadas x e y de um ponto
{
    if (p == NULL)
    {
        return 0; // falha
    }

    p->x = x; // atribui valor ao x (*p).x
    p->y = y; // atribui valor ao y (*p).y
    return 1;
}

int get_pto(Ponto *p, float *x, float *y) // retorna os valores das coordenadas x e y de um ponto
{

    if (p == NULL) // Se o ponteiro estiver vazio, entao nao existe um ponto para ser lido
    {
        return 0; // falha
    }

    *x = p->x; // O conteudo de x vai ser p->x
    *y = p->y; // O conteudo de y vai ser p->y
    return 1;
}

void libera_pto(Ponto **p) // operação que elimina um ponto criado
{

    free(*p);  // Libera memomria
    *p = NULL; // Limpa o ponteiro
}

float distancia_pto(Ponto *p1, Ponto *p2) // calcula a distância entre dois pontos
{
    float dx = p1->x - p2->x; // Diferenca entre o x de p1 com o x de p2
    float dy = p1->y - p2->y; // Diferenca entre o y de p1 com o y de p2
    float resultado = sqrt(dx * dx + dy * dy);
    return resultado;
}