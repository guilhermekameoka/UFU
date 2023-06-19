typedef struct lista *Lista;

Lista criar_lista();

void ordena_lista(Lista *lst);
void concatena(Lista *lst);

int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_elem(Lista lst, int elem);
int insere_inicio(Lista lst, int elem);
int remove_elem(Lista lst, int elem);
int remove_impares(Lista lst);
int menor_elem(Lista lst);
int maior_elem(Lista lst);
int tamanho(Lista lst);
int mostrar_lista(Lista lst);
