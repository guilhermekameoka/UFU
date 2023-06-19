typedef struct no * Lista;

Lista cria_lista();
Lista multiplos_tres(Lista *lst);

int lista_vazia(Lista lst);
int insere_ord(Lista *lst, int elem);
int remove_ord(Lista *lst, int elem);
int tamanho(Lista *lst);
float media(Lista *lst);
int iguais(Lista *lst1, Lista *lst2);
int remove_todos(Lista *lst);
int remove_maior(Lista *lst);

void mostra_lista(Lista lst);
