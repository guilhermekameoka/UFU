typedef struct no *Lista;

Lista cria_lista();
int lista_vazia(Lista lst);
int insere_elemento(Lista *lst, int elem);
int remove_elemento(Lista *lst, int elem);
void imprime_lista(Lista lst);
