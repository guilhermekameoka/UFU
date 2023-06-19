typedef struct pilha * Pilha;

Pilha cria_pilha();

int pilha_vazia(Pilha p);

int empilha(Pilha *p, int elem);
int desempilha(Pilha *p, int * elem);

void empilha1(Pilha *p, int elem);
void desempilha1(Pilha *p, int * elem);

int le_topo(Pilha *p, int * elem);
int imprimir(Pilha p);
int palindromo(char *vet);
int par_e_impar(void);

int elimina(Pilha *p, int *elem);
