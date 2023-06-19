typedef struct fila * Fila;

Fila criar_fila();
int fila_vazia(Fila f);
int fila_cheia(Fila f);
int insere_final(Fila f, int elem);
int remove_inicio(Fila f, int *elem);
int le_final(Fila f);
int mostrar_fila(Fila f);