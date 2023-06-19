typedef struct pilha * Pilha;

Pilha cria_pilha();
int pilha_vazia(Pilha p);
int pilha_cheia(Pilha p);

int empilha(Pilha p, int elem);
int desempilha(Pilha p, int * elem);
int le_topo(Pilha p, int * elem);
int mostra_pilha(Pilha p);

void mostra_conv(Pilha p);

int decimal_binario(Pilha p);