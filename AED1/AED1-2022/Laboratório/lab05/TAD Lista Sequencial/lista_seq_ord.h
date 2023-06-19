typedef struct lista *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, int elem);
int remove_ord(Lista lst, int elem);
int obtem_valor_elem(Lista lst, int elem);
