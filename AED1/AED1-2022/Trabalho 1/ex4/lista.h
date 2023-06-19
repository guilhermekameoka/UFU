typedef struct no *Lista;

Lista criar_lista();

int lista_vazia(Lista lst);
int insere_elem(Lista *lst, int elem);
int remove_elem(Lista *lst, int elem);

void imprime_lista (Lista lst);
float media(Lista *lst);
int tamanho(Lista lst);
int inverte_lista(Lista *lst);
int remove_impares(Lista *lst);
Lista gera_impares(Lista *lst);

void mostra_lista(Lista lst);
