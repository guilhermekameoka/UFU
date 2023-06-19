typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
void lista_cheia(Lista lst);
int insere_elem(Lista *lst);
int remove_elem(Lista *lst);
void obtem_valor_elem(Lista lst);