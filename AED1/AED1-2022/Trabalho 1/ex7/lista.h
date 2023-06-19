typedef struct no * Lista;
typedef struct no * Eliminado;

Lista cria_lista();

int lista_vazia(Lista lst);
int insere_varios(Lista *lst); // Retorna a quantidade
int insere(Lista *lst, char nome[50], int elem);
int remove(Lista *lst, Eliminado *eli, int elem);
int sortear(Lista *lst, Eliminado *eli, int *qtd);
int eliminado(Eliminado *eli, char nome[50], int elem);
