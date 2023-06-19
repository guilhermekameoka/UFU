typedef struct no *Lista;

Lista criar_lista();
int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int insere_elem(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int remove_impares(Lista *lst);

int tamanho(Lista *lst);
float media(Lista *lst);
int verifica_igual(Lista *lst1, Lista *lst2);

Lista intercalar(Lista lst);
int inverte_lista(Lista *lst);
Lista gera_impares(Lista *lst);
void mostra_lista(Lista lst);
