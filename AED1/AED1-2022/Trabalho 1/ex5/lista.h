typedef struct no * Lista;

Lista cria_lista();

int lista_vazia(Lista lst);
int insere_final(Lista *lst, int elem);
int remove_inicio(Lista *lst, int *elem);
int insere(Lista *lst, int elem);
int insere_posicao(Lista *lst, int elem, int pos);
int remove_posicao(Lista *lst, int pos);
int tamanho(Lista *lst);
int maior_elem(Lista *lst);
int remover_pares(Lista *lst);
