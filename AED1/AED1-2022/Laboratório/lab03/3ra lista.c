#include <stdio.h>

struct individuo
{
    int codigo_genetico[10]; // valores binarios aleatorios
    int aptidao_abs;         // pontencial de cada individuo (0.0 <= aptidao <= 10.0)
    int aptidao_relativa;    // deve ser calculada em tempo de execução...
};

struct populacao
{
    struct individuo *pop; // um vetor de N individuos
    int tamanho;           // tamanho N da população (N = 100)
};
typedef struct populacao populacao;

int main()
{

    struct individuo ind[10];
    populacao pop[10];
    float ap_rel, ap_ind, soma_ap;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite o codigo genetico do individuo %d: ", ind[i].codigo_genetico);
        scanf("%d", &ind->codigo_genetico[i]);
    }
    ap_rel = ap_ind / soma_ap;
}