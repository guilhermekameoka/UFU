typedef struct fila *Fila;
typedef struct no* No;

Fila cria_fila();
int fila_vazia(Fila f);
int insere_fim(Fila f, int elem);
int remove_ini(Fila f, int *elem);
int imprime_fila(Fila f);