typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);
void obtem_valor_elem (Lista lst);
