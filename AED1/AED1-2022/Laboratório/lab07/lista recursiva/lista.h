typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
void lista_cheia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
void obtem_valor_elem(Lista lst);